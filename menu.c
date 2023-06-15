#include "menu.h"
#include "menu-config.h"
#include "ansi.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static void redraw();
static void clear();
static void put_int(uint_fast16_t);
static void (*menu_send)(uint8_t *buf, uint16_t len) = &cdc_send;
static void (*menu_recv)(uint8_t *buf, uint16_t len) = &cdc_recv;
static int (*menu_putchar)(uint8_t) = &cdc_putchar;
static int (*menu_getchar)(uint8_t *) = &cdc_getchar;

static uint8_t selection = 0;
static uint8_t seq_clear[4] = {"\033[2J"};
static uint8_t seq_bgcolor[7] = BGPURPLE;
static uint8_t seq_reset[4] = {"\033[0m"};
static uint8_t seq_fgcolor[7] = FGWHITE;
void clear() { menu_send(seq_clear, LEN(seq_clear)); }
void reset() { menu_send(seq_reset, LEN(seq_reset)); }
void setbg() { menu_send(seq_bgcolor, LEN(seq_bgcolor)); }

void move(uint_fast16_t y, uint_fast16_t x)
{
  // move function will work only if put_int() is completed
  // you can move the cursor position with this fn before printing a specific text or while setting bg
  menu_putchar(0x1b);
  menu_putchar('[');
  put_int(y);
  menu_putchar(';');
  put_int(x);
  menu_putchar('H');
}
void put_int(uint_fast16_t i)
{
  char buf[4];
  snprintf(buf, sizeof(buf), "%03d", i);
  printf("Formatted string: %s\n", buf);
  menu_send((uint8_t *)buf, 3);
}

void drawline(float mv)
{
  uint_fast16_t x = mv*0.05;
  move(2, x);
  for (uint_fast16_t i = 0; i < 80; i++)
  {
    menu_putchar('-');
  }
}

void drawlabdetials()
{
  // Code for printing the description of the selected item
  Menuitem *m = &menu[selection];
  move(6, 0);
  menu_send("Description: ", 13); // Assuming a fixed length for the "Description: " label
  menu_send(m->title, strlen(m->title));
}

void drawfooter()
{
  move(10, 0); // Adjust the line number as per your desired position

  int lineLength = 80; // Adjust the desired length of the line
  char lineChar = '-'; // Adjust the desired character for the line

  for (int i = 0; i < 2; i++)
  {
    move(10 + 2*i, 0); // Move to the respective line

    for (int j = 0; j < lineLength; j++)
    {
      menu_send(&lineChar, 1); // Print the line character
    }
  }

  move(11, 67); // Move to the next line

  menu_send("bi0s hardware", 13); // Adjust the content as needed
}

void drawlab()
{
  Menuitem *m;
  for (uint_fast16_t i = 0; i < LEN(menu); i++)
  {
    m = &menu[i];
    menu_send("\n\r", 2); // remove this line of code use move() to go to next line
    if (i == selection)
    {
      // move(i, <leftmargin_value>)
      // do this before setting bg and printing lab
      // to avoiding jumping of text down while pressing arrow keys
      setbg();
    }
    menu_send(m->title, m->title_len);
    reset();
  }
}

uint_fast8_t input_handler()
{
  // basically used to detect keypress
  // Changes the selection based on arrow key input
  uint8_t c;
  while (1)
  {
    menu_getchar(&c);
    if (c == '\033')
    {
      menu_getchar(&c);
      if (c == '[')
      {
        menu_getchar(&c);
        if (c == 'A')
        {
          selection = (selection - 1);
          if (selection == -1)
            selection = LEN(menu) - 1;
          return 1;
        }
        else if (c == 'B')
        {
          selection = (selection + 1) % (LEN(menu) - 0);
          return 1;
        }
      }
    }
  }
  return 0;
}
void redraw()
{
  clear();
  drawline(MV);     // Layout
  drawlab();        // Lab list
  drawlabdetials(); // Lab Description
  drawfooter();     // Footer
}
//////////////////////////////////////////////////
// THIS IS THE FIRST FUNCTION EXECUTED IN THIS FILE
//////////////////////////////////////////////////
uint8_t menu_handler()
{
  redraw();
  while (1)
  {
    if (input_handler())
    {
    }
    redraw();
  }
  return 0;
}
