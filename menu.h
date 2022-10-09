#include <stdint.h>
#include <stdio.h>
//////////////////////////////////////
extern int serial_port;
int cdc_send(uint8_t *buf, uint16_t len);
int cdc_send(uint8_t *buf, uint16_t len);
void cdc_putchar(uint8_t);
void cdc_putchar(uint8_t);
//////////////////////////////////////
#define LEN(X) sizeof(X) / sizeof(X[0])

#define ESC \033
#define CLEAR [2J

typedef struct {
  uint8_t *title;
  uint8_t *desc; // desciption
  uint8_t color; // some id for color for later use
  uint8_t title_len;
  uint8_t desc_len; // not used
} menuitem;

uint8_t menu_handler();
