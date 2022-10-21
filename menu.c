#include "menu.h"
#include "menu-config.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void redraw();
void clear();
void put_int(uint_fast16_t);

uint8_t chosen = 0;
uint_fast16_t xmax, ymax; // screen sizee

static uint8_t seq_clear[4] = {"\033[2J"};
static uint8_t seq_curpos[4] = {"\033[6n"};
/* colors */
uint8_t seq_bgcolor[7] = {"\033[42;1m"};
uint8_t seq_reset[4] = {"\033[0m"};

/********STATE VARIABLES********/
int8_t selection = 0;

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
void put_int(uint_fast16_t i) {
  uint_fast16_t ii;

  if (i >= 10) {
    if (i >= 100) {
      ii = i / 100;
      cdc_putchar(ii + '0');
      i -= 100 * ii;
    }

    ii = i / 10;
    cdc_putchar(ii + '0');
    i -= 10 * ii;
  }

  cdc_putchar(i + '0');
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
    if (i > 57 || i < 48)
      continue;
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

  for (uint_fast16_t i = 1; i <= ymax; i++) {
    move(i, xmid);
    cdc_putchar('|');
  }

  for (uint_fast16_t i = xmid + 1; i <= xmax; i++) {
    move(ymid, i);
    cdc_putchar('_');
  }
}

/* return 1 if changed else 0 */
/* TODO: change function name */
uint8_t getxymax() {
  move(399, 399);
  uint_fast16_t x = xmax, y = ymax;
  getxy(&ymax, &xmax);
  return x != xmax || y != ymax;
}
<<<<<<< Updated upstream
void drawlist() {
  move(1, 4);
  cdc_send(seq_bgcolor, LEN(seq_bgcolor));
  cdc_send("hello bro", 7);
  cdc_send(seq_reset, LEN(seq_reset));
}
inline void reset() { cdc_send(seq_reset, LEN(seq_reset)); }
inline void setbg() { cdc_send(seq_bgcolor, LEN(seq_bgcolor)); }
=======
void reset() { cdc_send(seq_reset, LEN(seq_reset)); }
void setbg() { cdc_send(seq_bgcolor, LEN(seq_bgcolor)); }
>>>>>>> Stashed changes
void drawlab() {
  Menuitem *m;
  for (int i = 0; i < LEN(menu); i++) {
    m = &menu[i];
    move((i + 1) * 2, lmargin);
    if (i == selection)
      setbg();
    cdc_send(m->title, m->title_len);
    reset();
  }
}

void redraw() {
  clear();
  drawbox(0.75, 0.5);
  drawlab();
}
uint_fast8_t input_handler() {
  uint8_t c;
  cdc_getchar(&c);
  if (c == '\033') {
    cdc_getchar(&c);
    if (c == '[') {
      cdc_getchar(&c);
      if (c == 'A') {
        selection = (selection + 1) % (LEN(menu) - 0);
        return 1;
      } else if (c == 'B') {
        selection = (selection - 1) % (LEN(menu) - 0);
        return 1;
      }
    }
  }
  return 0;
}
uint8_t menu_handler() {
  // move(6,9);
  // cdc_send("helloo", 6);
  redraw();
  while (1) {
    if (input_handler()) {
    }
    redraw();
  }
  /* HAL_Delay(50); */
  return chosen;
}
