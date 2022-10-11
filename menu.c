#include "menu.h"
#include <stdint.h>

void redraw();
void clear();
void put_int(uint_fast16_t);

uint8_t chosen = 0;
uint_fast16_t xmax, ymax; // screen sizee

static uint8_t seq_clear[4] = {"\033[2J"};
static uint8_t seq_curpos[4] = {"\033[6n"};
void move(uint_fast16_t y, uint_fast16_t x) {
  cdc_putchar(0x1b);
  cdc_putchar('[');
  put_int(y);
  cdc_putchar(';');
  put_int(x);
  cdc_putchar('H');
}
void clear() { cdc_send(seq_clear, LEN(seq_clear)); }
/*print int as string*/
void put_int(uint_fast16_t x) {

  uint_fast8_t i = 0;
  uint_fast8_t remainder;
  uint_fast8_t reverse = 0;
  // x=1;
  while (x != 0) {

    remainder = x % 10;
    if (remainder == 0 && reverse == 0) {
      i++;
    }
    reverse = reverse * 10 + remainder;
    x /= 10;
  } // REVERSING
  x = reverse;
  remainder = i;

  while (x) {
    i = x % 10;
    x = x / 10;
    cdc_putchar(i + '0');

  } // PUTING CHAR FROM BACK

  while (remainder != 0) {
    cdc_putchar('0');
    remainder--;
  }
}

void getxy(uint_fast16_t *y, uint_fast16_t *x) {
  *y = 0;
  *x = 0;
  cdc_send(seq_curpos, LEN(seq_curpos));
  // requested
  uint8_t i;
  while (1) {
    cdc_getchar(&i);
    if (i != 0x1b)
      continue;
    cdc_getchar(&i); //[
    cdc_getchar(&i);
    while (i != ';') {
      *y = ((*y) * 10) + (i - '0');
      cdc_getchar(&i);
    }
    cdc_getchar(&i);
    while (i != 'R') {
      *x = ((*x) * 10) + (i - '0');
      cdc_getchar(&i);
    }
    if (i == 'R') {
      return;
    } else {
      *x = 0;
      *y = 0;
    }
  }
}

void drawbox(float mv, float mh) {
  move(399, 399);
  getxy(&ymax, &xmax);
  uint_fast16_t xmid = xmax * mh;
  uint_fast16_t ymid = ymax * mv;

  for (uint_fast8_t i = 1; i <= ymax; i++) {
    move(i, xmid);
    cdc_putchar('|');
  }

  for (uint_fast8_t i = xmid + 1; i <= xmax; i++) {
    move(ymid, i);
    cdc_putchar('_');
  }
}

void redraw() {
  clear();
  drawbox(0.5, 0.5);
}

uint8_t menu_handler() {
  // move(6,9);
  // cdc_send("helloo", 6);
  redraw();

  return chosen;
}
