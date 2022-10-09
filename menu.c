#include "menu.h"
#include <stdint.h>

void redraw();
void clear();

uint8_t chosen = 0;
uint_fast16_t xmax, ymax; // screen sizee

static uint8_t seq_clear[4] = {"\033[2J"};
static uint8_t seq_curpos[] = {"\033"}

void clear() {
  cdc_send(seq_clear, LEN(seq_clear));
}
/*print int as string*/
void put_int(uint_fast16_t x) {
  uint_fast8_t i;
  while (x) {
    i = x % 10;
    x = x / 10;
    cdc_putchar(i + '0');
  }
}

void getxy(uint_fast16_t ymax, uint_fast16_t xmax) {}

void drawbox(float mv, float mh) { getxy(ymax, xmax); }

void move(uint_fast16_t y, uint_fast16_t x) {
  //  cdc_putchar();
}

uint8_t menu_handler() {
  cdc_send("helloo", 6);
  redraw();
  return chosen;
}

void redraw() {
  clear();
  drawbox(0.5, 0.75);
}
