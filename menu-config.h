#include "menu.h"

// typedef struct {
//   uint8_t *title;
//   uint8_t *desc; // desciption
//   uint8_t color; // some id for color for later use
//   uint8_t title_len;
//   uint8_t desc_len; // not used
// } Menuitem;
uint_fast16_t lmargin = 5;

static uint8_t lab_1_Desc[] ="Lab 1 is simple, but powerful. very pewerful qwertyuiopasdfghjklzxcvbnm";
static uint8_t lab_2_Desc[] ="Lab 2 is simple, but powerful. very pewerful qwertyuiopasdfghjklzxcvbnm, but powerful. very pewerful qwertyuiopasdfghjklzxcvbnm, but powerful. very pewerful qwertyuiopasdfghjklzxcvbnm";
static uint8_t lab_3_Desc[] ="Lab 3 is simple, but powerful. very pewerful qDSFAHSDFKGSDKFHSKDHGDSKFHGSKDJHFklzxcvbnm";
static uint8_t lab_4_Desc[] ="Lab 4 is simple, but powerful. very pewerful qwertyuiopasdfghjklzxcv, but powerful. very pewerful qwertyuiopasdfghjklzxcvbnm, but powerful. very pewerful qwertyuiopasdfghjklzxcvbnmbnm";
static uint8_t lab_5_Desc[] ="Lab 5 is simple, but powerful. very pewerful qwertyuiopasdfghjklzxcvbnm";
static uint8_t lab_6_Desc[] ="Lab 6 is simple, but powerful. very pewerful qwertyuiopasdfghjklzxcvbnm";
static uint8_t lab_7_Desc[] ="Lab 7 is simple, but powerful. very pewerful qwertyuiopasdfghjklzxcvbnm";
static uint8_t lab_8_Desc[] ="Lab 8 is simple, ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";


Menuitem menu[] = {
    {"Lab - 01", lab_1_Desc, 4, 8, LEN(lab_1_Desc)},
    {"Lab - 02", lab_2_Desc, 4, 8, LEN(lab_2_Desc)},
    {"Lab - 03", lab_3_Desc, 4, 8, LEN(lab_3_Desc)},
    {"Lab - 04", lab_4_Desc, 4, 8, LEN(lab_4_Desc)},
    {"Lab - 05", lab_5_Desc, 4, 8, LEN(lab_5_Desc)},
    {"Lab - 06", lab_6_Desc, 4, 8, LEN(lab_6_Desc)},
    {"Lab - 07", lab_7_Desc, 4, 8, LEN(lab_7_Desc)},
    {"Lab - 08", lab_8_Desc, 4, 8, LEN(lab_8_Desc)}};


