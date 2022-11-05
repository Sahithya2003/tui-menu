#include "menu.h"

// typedef struct {
//   uint8_t *title;
//   uint8_t *desc; // desciption
//   uint8_t color; // some id for color for later use
//   uint8_t title_len;
//   uint8_t desc_len; // not used
// } Menuitem;
uint_fast16_t lmargin = 5;

static uint8_t lab_1_Desc[] ="Lab 1 is simple, but powerful. UART Identification Method 1 using micro-controller pins and DMM (Digital Multimeter) conductivity test. The objective is to identify UART pinouts on the PCB board provided we have the knowledge of microcontroller UART pins, which can be found in the datasheet of the microcontroller.";
static uint8_t lab_2_Desc[] ="Lab 2 is simple, but powerful. UART Identification Method 2 using DMM Voltage tests on the board pinouts. The objective is to identify UART pinouts on the PCB board when we do not have the knowledge of the microcontroller UART pins and the datasheet of the microcontroller.";
static uint8_t lab_3_Desc[] ="Lab 3 is simple, but powerful. Once the UART port is identified, communicate with the target device to further analyze read/write access to the device. The objective is to understand the process of interfacing with the target device, identifying the correct baud rate that it uses to communicate and analyze the read/write access.";
static uint8_t lab_4_Desc[] ="Lab 4 is simple, but powerful. JTAG Debug port identification method 1 using micro-controller pins and DMM (Digital Multimeter) conductivity test. The objective is to identify JTAG pinouts on the PCB board provided we have the knowledge of microcontroller JTAG pins, which can be found in the datasheet of the microcontroller.";
static uint8_t lab_5_Desc[] ="Lab 5 is simple, but powerful. Automated JTAG Pin scanning and Identification using JtagEnum on Arduino. The objective is to understand the process and perform automated JTAG scanning using JtagEnum running on Arduino.";
static uint8_t lab_6_Desc[] ="Lab 6 is simple, but powerful. Use the JTAG Debug port to access the microcontroller and extract the firmware. The objective is to understand how to connect over JTAG with the target board and how to extract data from the internal memory of the microcontroller.";
static uint8_t lab_7_Desc[] ="Lab 7 is simple, but powerful. Find out the hardcoded password from the extracted firmware, modify it, write it back, and log in. The objective is to familiarize yourself with firmware extraction, analyze hard coded data, and patch the firmware on the fly.";
static uint8_t lab_8_Desc[] ="Lab 8 is simple, but powerful. Use JTAG Debug port to manipulate GPIOs of microcontrollers and generate LED patterns with onboard LEDs. The objective is to understand how to control the GPIOs of the micro-controller over JTAG to change the behavior of the target as per your needs.";


Menuitem menu[] = {
    {"Lab - 01", lab_1_Desc, 4, 8, LEN(lab_1_Desc)},
    {"Lab - 02", lab_2_Desc, 4, 8, LEN(lab_2_Desc)},
    {"Lab - 03", lab_3_Desc, 4, 8, LEN(lab_3_Desc)},
    {"Lab - 04", lab_4_Desc, 4, 8, LEN(lab_4_Desc)},
    {"Lab - 05", lab_5_Desc, 4, 8, LEN(lab_5_Desc)},
    {"Lab - 06", lab_6_Desc, 4, 8, LEN(lab_6_Desc)},
    {"Lab - 07", lab_7_Desc, 4, 8, LEN(lab_7_Desc)},
    {"Lab - 08", lab_8_Desc, 4, 8, LEN(lab_8_Desc)}};


