//     >>>>>  MEGA COMPILATION for ESP8266/ESP8285  GPL v3 <<<<
//                    >>>>>  MEGA Tiny Joypad  <<<<
//                  Programmer: Daniel C 2019
//            Contact EMAIL: electro_l.i.b@tinyjoypad.com
//              official website: www.tinyjoypad.com
//       or  https://sites.google.com/view/arduino-collection

//  MEGA COMPILATION is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <avr/pgmspace.h>

typedef struct Sprite_TBIKE{
uint8_t ACTIVE;
uint8_t TypeofSprite;
int8_t xPOS;
int8_t yPOS;
int8_t Y_START;
int8_t Y_END;
}Sprite_TBIKE;

const uint8_t  STEP_BIKE_TRACKRUN_TBIKE [] PROGMEM= {23,28,33,38};

uint8_t DScroll0=0;
uint8_t DScroll1=0;
uint8_t DScroll2=0;
uint8_t DScroll3=0;
uint8_t BScroll0=0;
uint8_t BScroll1=0;
uint8_t BScroll2=0;
uint8_t BScroll3=0;

const uint8_t  Level0_TBIKE [] PROGMEM= {
54,23,
0b10100010,
0b11110010,
0b00110000,
0b11110010, 
0b00000010, 
0b00001101,
0b10100010,
0b00001101,
0b11110010, 
0b00110000,
0b00001101,
0b10100010,
0b00010101, 
0b00110001,
0b00001101, 
0b11110010,
0b10100010,
0b00110001, 
0b00001101,
0b00110001,
0b00110001, 
0b00001101, 

0b00110011, 
0b00001111,

56,16,
0b00000010,
0b10100010,
0b00110000, 
0b01010010,
0b10110101,
0b11110010,
0b00110001,

0b00110000, 
0b11110010, 
0b00110001, 
0b10100010,
0b00110000,
0b00110001,
0b00110001, 
0b00110001, 
0b01010010,
0b01010010,
0b00110001,
0b01100101,
0b01010110,
0b10100110,
0b00110000, 
0b00110011,
0b00001111,

65,18,
0b00110000,
0b00110000,
0b00110000,
0b00001101,
0b10100010,
0b00010101,
0b11110010,
0b00110000,
0b00000110, 
0b01010110,
0b00010101, 
0b10100110,
0b01010110, 
0b10110101,
0b11110111, 
0b00010101,
0b10100010, 
0b00110001,
0b10110101,
0b00110001,
0b00110001,
0b00010101,
0b00110001,
0b11110110,
0b00110001,
0b00110000,
0b00110011, 
0b00001111,


65,18,
0b00110001,
0b00110001,
0b00110000,
0b00000110,
0b01010110, 
0b00010101,
0b10100010,
0b00010101,
0b11110010,
0b10100110,
0b11110110,
0b00110000, 
0b00000110, 
0b11110010,
0b01010110,
0b00010101,
0b00110001,
0b01010110,
0b10100010,
0b00110001,
0b10110101,
0b00110001,
0b00110001,
0b00010101,
0b00110001,
0b00110001,
0b00110000,
0b00110011,
0b00001111,

72,23,
0b00110000,
0b00000110,
0b01010110,
0b10100110,
0b11110110, 
0b00110000,
0b10100010, 
0b00010101,
0b01010110,
0b00000110,
0b11110110, 
0b10100110,
0b00110000,
0b00000010,
0b01010010,
0b00110000, 
0b10100010,
0b11110010,
0b00110001,
0b01010010,
0b10100010,
0b10110101,
0b01010110,
0b10100110,
0b00110001, 
0b11110110,
0b00110001, 
0b00110000,
0b00000110,
0b00110011, 
0b00001111,


96,28,
0b00110000, 
0b00010101,
0b01010110,
0b10110101,
0b00000110,
0b01100101,
0b10100110, 
0b11110110,
0b00110001,
0b00110000,
0b01010110,
0b10100110, 
0b10100110,
0b11110110,
0b00110000,
0b00000110,
0b01010110,
0b11110111,
0b11110110,
0b00110000,

0b10110101,

0b11110110,
0b00110001,
0b01010110,
0b10110101,
0b00000110,
0b01100101, 
0b00110000, 
0b01010110,
0b10100010, 
0b11110010,
0b10100110,
0b00000110,
0b00110001,
0b11110010,
0b10100110,
0b00110000,
0b01010010, 
0b10110101,
0b00110011, 
0b00001111,


96,28,
0b00010101,
0b00000110, 
0b01010110,
0b10100110,
0b11110110, 
0b10110101,
0b00000110, 
0b01010110,
0b10100110, 
0b11110110,
0b00110001,
0b10110101,
0b00110000,
0b10110101,
0b00110001,
0b10100110,
0b11110110, 
0b00110000,
0b00000110,
0b00110000, 

0b00010101,

0b11110110,
0b10100110,
0b01010110, 
0b10110101,
0b00000110,
0b01100101, 
0b10100110,
0b01010110,
0b00110001, 
0b00110001,
0b10100110,
0b00000110,
0b00110001,
0b00110001, 
0b10100110, 
0b00110000,
0b00000110,
0b10110101, 
0b00110011,
0b00001111,

110,34,
0b00000010,
0b00010101,
0b01010110, 
0b01100101,
0b10100110,
0b10110101,
0b00110000,
0b00110000,
0b00110000,
0b00110001,
0b00000110, 
0b00110001,
0b01010110, 
0b00110001,
0b10100110, 
0b00110001,
0b11110110,
0b00110001,
0b10100010, 
0b01100101,
0b00000110,
0b01100101, 
0b11110110,
0b01100101, 
0b00000110,
0b01100101,
0b11110110, 
0b00110000,
0b00001101,
0b01100101, 
0b00000110, 
0b01100101,
0b11110110,
0b01100101,
0b00000110,
0b01100101,
0b11110110,
0b00110001, 
0b00110000,
0b01010110, 
0b00110001,
0b00110000,
0b01010110,
0b00110001,
0b00110000,
0b00110011, 
0b00001111,


124,34,
0b00110001,
0b00110000,
0b11110110,
0b00110001,
0b10100110,
0b00110001,
0b00110000,
0b00000110,
0b00110001,
0b10110101,
0b00110000,
0b00110001, 
0b00000110, 
0b00110001,
0b00000110, 
0b00010101,
0b10110101,
0b11110110,
0b00000110,
0b00110001,
0b11110110,
0b00110001,
0b00110000,
0b10100110,
0b00110001,
0b11110110,
0b00110001,
0b00000110,
0b00110000, 
0b00110001,
0b11110110,
0b00110001,
0b11110110,
0b00110001,
0b00000110,
0b00110001,
0b11110110,
0b00110001,
0b00000110,
0b00010101,
0b10110101, 
0b11110110,
0b11110111,
0b00110000,
0b00110001,
0b00110000,
0b00110001,
0b01010110,
0b00110001,
0b00110000,
0b00110011,
0b00001111,

97,25,
0b00110000,
0b11110110,
0b00110000,
0b10100110,
0b00110001,
0b11110110,
0b00110000,
0b00000110,
0b00110000, 
0b01010110,
0b00110000, 
0b10100110, 
0b00110001, 
0b00110000,
0b01010110, 
0b00110000,
0b00000110,
0b00110001,
0b00000110,
0b00110000,
0b01010110, 
0b00110000,
0b11110110, 
0b00110001,
0b10100110, 
0b00110001,
0b00000110, 
0b11110110,
0b00110000,
0b00001101, 
0b00110000,
0b00001101,
0b00110001,
0b01010110,
0b00110000,
0b10100110,
0b00110000,
0b00001101,
0b00110001, 
0b00110011, 
0b00001110,
};


const uint8_t  START_GAME_TBIKE [] PROGMEM= {
50,5,
0xFE,0x01,0x05,0x7D,0x05,0x01,0x75,0x01,0x7D,0x09,0x79,0x01,0x0D,0x71,0x0D,0x01,0x3E,0x7C,0x40,0x40,0x40,0x40,0x40,0x80,0x00,0x00,0x00,0x20,0x00,0x20,0x20,0x00,0x80,0xC0,0xE0,0xE0,0xE0,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x3E,0x40,0xDF,0xD5,0xCA,0xC0,0xDD,0xC0,0xDF,0xC6,0xD9,0xC0,0xDF,0xD5,0xD1,0xC0,0xBF,0x7F,0x08,0x09,0x01,0xC1,0xF0,0xF8,0xFF,0xFF,0xF9,0xF0,0x31,0x33,0x3B,0x1F,0x0F,0x03,0x06,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x12,0x00,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x00,0x00,0xFF,0xFF,0xFF,0x0F,0x0F,0x7F,0xFF,0x3F,0x2E,0x26,0xE0,0xF0,0xF2,0xFE,0x3C,0x38,0x10,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x10,0x00,0x11,0x10,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x01,0x01,0x01,0x78,0xFC,0xCE,0x87,0x07,0x0F,0x1F,0x9F,0xFC,0xF8,0x78,0x7C,0x0F,0x07,0x0F,0x1F,0x17,0xF7,0xFB,0x9F,0x1F,0x0F,0x07,0x8F,0xFE,0xFC,0x78,
0x00,0x00,0x00,0x01,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x01,0x03,0x03,0x03,0x03,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x03,0x03,0x03,0x03,0x01,0x00,0x00,
};

const uint8_t  START_RACE_TBIKE [] PROGMEM= {
50,2,
0xFF,0x01,0xFD,0xED,0x55,0x55,0xBD,0xFD,0xF5,0x05,0xF5,0xFD,0x0D,0xD5,0x0D,0xFD,0x05,0xD5,0x2D,0xFD,0xF5,0x05,0xF5,0xFD,0xFD,0xFD,0xFD,0xFD,0x05,0xB5,0x95,0x4D,0xFD,0xFD,0x0D,0xD5,0xD5,0x0D,0xFD,0x8D,0x75,0x75,0x75,0xFD,0x05,0x55,0x75,0xFD,0x01,0xFF,
0x07,0x04,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x04,0x07,
};

const uint8_t  NEXTRACE_TBIKE [] PROGMEM= {
50,2,
0xFF,0x01,0xFD,0x05,0xED,0xDD,0x05,0xFD,0xFD,0x05,0x55,0x75,0xFD,0x75,0xAD,0xDD,0xAD,0x75,0xFD,0xF5,0xF5,0x05,0xF5,0xF5,0xFD,0xFD,0xFD,0xFD,0x05,0xB5,0x95,0x4D,0xFD,0xFD,0x0D,0xD5,0xD5,0x0D,0xFD,0x8D,0x75,0x75,0x75,0xFD,0x05,0x55,0x75,0xFD,0x01,0xFF,
0x07,0x04,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x04,0x07,
};


const uint8_t  TOP_BACK_TBIKE [] PROGMEM= {//128,3
0x80,0x8C,0x81,0x8C,0x80,0xB0,0x84,0xB0,0x80,0x8C,0x81,0x8C,0x80,0xB0,0x84,0xB0,0x80,0x8C,0x81,0x8C,0x80,0xB0,0x84,0xB0,0x80,0x8C,0x81,0x8C,0x80,0xB0,0x84,0xB0,0x80,0x8C,0x81,0x8C,0x80,0xB0,0x84,0xB0,0x80,0x8C,0x81,0x8C,0x80,0xB0,0x84,0xB0,0x80,0x8C,
0x81,0x8C,0x80,0xB0,0x84,0xB0,0x80,0x8C,0x81,0x8C,0x80,0xB0,0x84,0xB0,0x80,0x8C,0x81,0x8C,0x80,0xB0,0x84,0xB0,0x80,0x8C,0x81,0x8C,0x80,0xB0,0x84,0xB0,0x80,0x8C,0x81,0x8C,0x80,0xB0,0x84,0xB0,0x80,0x8C,0x81,0x8C,0x80,0xB0,0x84,0xB0,0x80,0x8C,0x81,0x8C,
0x80,0xB0,0x84,0xB0,0x80,0x8C,0x81,0x8C,0x80,0xB0,0x84,0xB0,0x80,0x8C,0x81,0x8C,0x80,0xB0,0x84,0xB0,0x80,0x8C,0x81,0x8C,0x80,0xB0,0x84,0xB0,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,
0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,
0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x56,0xAE,
0x56,0xAA,0x56,0xAE,0x56,0xAA,0x05,0x02,0x09,0x02,0x05,0x02,0x05,0x02,0x05,0x02,0x09,0x02,0x05,0x02,0x05,0x02,0x05,0x02,0x09,0x02,0x05,0x02,0x05,0x02,0x05,0x02,0x09,0x02,0x05,0x02,0x05,0x02,0x05,0x02,0x09,0x02,0x05,0x02,0x05,0x02,0x05,0x02,0x09,0x02,
0x05,0x02,0x05,0x02,0x05,0x02,0x09,0x02,0x05,0x02,0x05,0x02,0x05,0x02,0x09,0x02,0x05,0x02,0x05,0x02,0x05,0x02,0x09,0x02,0x05,0x02,0x05,0x02,0x05,0x02,0x09,0x02,0x05,0x02,0x05,0x02,0x05,0x02,0x09,0x02,0x05,0x02,0x05,0x02,0x05,0x02,0x09,0x02,0x05,0x02,
0x05,0x02,0x05,0x02,0x09,0x02,0x05,0x02,0x05,0x02,0x05,0x02,0x09,0x02,0x05,0x02,0x05,0x02,0x05,0x02,0x09,0x02,0x05,0x02,0x05,0x02,0x05,0x02,0x09,0x02,0x05,0x02,0x05,0x02,
};

const uint8_t  FOUL_TBIKE [] PROGMEM= {0x80,0x8C,0x81,0x8C,0x80,0xB0,0x84,0xB0,};

const uint8_t  GRADIN_TBIKE [] PROGMEM= {0x56,0xAE,0x56,0xAA,0x56,0xAE,0x56,0xAA,0x05,0x02,0x09,0x02,0x05,0x02,0x05,0x02,};

const uint8_t  TIRE_TBIKE [] PROGMEM= {0x80,0x86,0x8D,0x8B,0x89,0x86,0x8B,0x89,0x86,0x80,0x80,0x80,0x80,0x80,0x80,};

const uint8_t  ROAD_TBIKE [] PROGMEM= {
0x00,0x20,0x00,0x20,0x00,0x00,0x20,0x00,0x20,0x00,
0x00,0x84,0x00,0x80,0x04,0x00,0x84,0x00,0x80,0x04,
0xB0,0x10,0x50,0x10,0x50,0x10,0x50,0x10,0xB0,0xF0,
};

const uint8_t  DISPLAY8_TBIKE [] PROGMEM= {
0xFF,0xC3,0x81,0x81,0x81,0xA1,0x99,0x95,0xA1,0x81,0x81,0x81,0x81,0xA1,0x99,0x95,0xA1,0x81,0x81,0x81,0x81,0xA1,0x99,0x95,0xA1,0x81,0x81,0x81,0xC3,0xFF,0xFF,0xC3,0x81,0x81,0x85,0xBD,0x85,0x81,0x81,0xA5,0x81,0x99,0xAD,0x95,0xA9,0x95,0xA9,0x95,0xA9,0x95,
0xA9,0x95,0xA9,0x95,0xA9,0x95,0xA9,0x95,0xA9,0x95,0xA9,0x95,0xA9,0x95,0xA9,0x95,0xA9,0x95,0xA9,0x95,0xA9,0x95,0xA9,0xB5,0x99,0x81,0xC3,0xFF,0xFF,0xC3,0x81,0x81,0xBD,0x95,0x89,0x81,0xA5,0x81,0x81,0xBD,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,
0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0x99,0xBD,0x81,0x81,0xC3,0xFF,};

const uint8_t  BigStepA_TBIKE [] PROGMEM= {
26,4,
0x00,0x00,0x00,0x00,0x80,0x40,0x20,0x10,0x08,0x04,0x42,0xFF,0xA5,0x73,0x29,0xFE,0x7C,0xF8,0xF0,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0xF8,0x04,0x42,0x01,0x10,0x00,0x84,0x00,0x21,0x00,0x08,0xFF,0x94,0xCE,0xA5,0xFF,0xEF,0xDE,0xBD,0x7B,0xF7,0xEF,0xDF,0xBE,
0x7C,0xF8,0xFF,0x00,0x08,0x00,0x42,0x00,0x10,0x00,0x84,0x40,0x21,0x1F,0x12,0x19,0x14,0x3F,0x7D,0xFB,0xF7,0xEF,0xDE,0xBD,0x7B,0xF7,0xEF,0xDE,0xFF,0x40,0x21,0x10,0x08,0x04,0x02,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0F,
0x1F,0x3E,0x7D,0xFB,
};

const uint8_t  BigStepB_TBIKE [] PROGMEM= {
26,4,
0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0xF0,0xF8,0xBC,0x00,0x5A,0x8C,0xD6,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xBC,0xFE,0xEF,0xFF,0x7B,0xFF,0xDE,0xFF,0xF7,0x00,0x6B,0x31,0x5A,0x00,0x10,0x21,0x42,0x84,0x08,0x10,0x20,0x40,
0x80,0x00,0x00,0xFF,0xF7,0xFF,0xBD,0xFF,0xEF,0xFF,0x7B,0xBF,0xDE,0xE0,0xED,0xE6,0xEB,0xC0,0x82,0x04,0x08,0x10,0x21,0x42,0x84,0x08,0x10,0x21,0x00,0xBF,0xDE,0xEF,0xF7,0xFB,0xFD,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFC,0xF8,0xF0,
0xE0,0xC1,0x82,0x04,
};

const uint8_t  MinijumpA_TBIKE [] PROGMEM= {
14,4,
0xE0,0x10,0x08,0x04,0x42,0xFF,0xA5,0x73,0x29,0xFE,0x7C,0xF8,0xF0,0xE0,0xFF,0x00,0x21,0x00,0x08,0xFF,0x94,
0xCE,0xA5,0xFF,0xEF,0xDE,0xBD,0x7B,0xFF,0x00,0x84,0x40,0x21,0x1F,0x12,0x19,0x14,0x3F,0x7D,0xFB,0xF7,0xEF,
0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,
};

const uint8_t  MinijumpB_TBIKE [] PROGMEM= {
14,4,
0x00,0xE0,0xF0,0xF8,0xBC,0x00,0x5A,0x8C,0xD6,0x00,0x80,0x00,0x00,0x00,0x00,0xFF,0xDE,0xFF,0xF7,0x00,0x6B,
0x31,0x5A,0x00,0x10,0x21,0x42,0x84,0x00,0xFF,0x7B,0xBF,0xDE,0xE0,0xED,0xE6,0xEB,0xC0,0x82,0x04,0x08,0x10,
0x00,0x02,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x02,0x00,
};

const uint8_t  huile_TBIKE [] PROGMEM= {15,1,0x00,0x00,0x04,0x0A,0x0C,0x0A,0x0C,0x0A,0x0C,0x0A,0x0C,0x0E,0x04,0x00,0x00,};

const uint8_t  Line_TBIKE [] PROGMEM= {6,3,0xFF,0x33,0x33,0xCC,0xCC,0xFF,0xFF,0x33,0x33,0xCC,0xCC,0xFF,0x0F,0x03,0x03,0x0C,0x0C,0x0F,};

const uint8_t  Start_TBIKE [] PROGMEM= {3,3,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0x0F,0x00,0x0F,};

const uint8_t  Speed_TBIKE [] PROGMEM= {
11,3,0x00,0x00,0x00,0x80,0xC0,0xE0,0xF0,0xF8,0x3C,0x1E,0xFF,0xFC,0x1E,0x8F,0xC7,0xE3,0xFF,0x7F,0xBF,0x5E,0xAF,0x57,0x1F,0x0F,0x17,0x0B,0x15,0x0A,0x15,0x0A,0x15,0x0A,0x15,
};

const uint8_t  plantage_TBIKE [] PROGMEM= {11,1,0x01,0x03,0x0E,0x0E,0x0C,0x08,0x09,0x0B,0x0E,0x0E,0x0C,};

const uint8_t  bike1_TBIKE [] PROGMEM= {
13,2,
0x00,0x00,0x80,0x80,0xDC,0xBE,0xF9,0xAB,0x86,0x00,0x00,0x00,0x00,0x00,0x03,0x05,0x04,0x03,0x00,0x01,0x0F,0x16,0x12,0x0C,0x00,0x00,
0x00,0x00,0x00,0xF0,0x7C,0xF2,0xD6,0x8C,0x80,0x80,0x00,0x00,0x00,0x00,0x0C,0x12,0x17,0x0C,0x0D,0x02,0x07,0x0F,0x16,0x12,0x0C,0x00, 
0x00,0x00,0x00,0xF8,0x3E,0xF9,0xB5,0xE3,0xE0,0xA0,0x80,0x00,0x00,0x00,0x0C,0x12,0x13,0x0E,0x06,0x00,0x01,0x03,0x05,0x04,0x03,0x00,
0x00,0x18,0xFE,0x39,0xF5,0xA3,0xE0,0x7C,0xB4,0x90,0x60,0x00,0x00,0x00,0x0C,0x13,0x12,0x0E,0x06,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
0x1E,0x39,0x75,0xB3,0x60,0xB4,0x18,0x2C,0x24,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x13,0x12,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x3C,0x72,0xF2,0xEC,0xC0,0x68,0x30,0x58,0x48,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x0E,0x13,0x12,0x0C,0x00,0x00,0x00,
0x00,0x00,0x00,0xE0,0xF8,0xE4,0xAC,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x12,0x1F,0x08,0x0B,0x05,0x0F,0x0F,0x1F,0x12,0x0C,0x00, 
0x00,0x00,0x00,0xE0,0x78,0xE4,0xCC,0x98,0xC0,0xA0,0x00,0x00,0x00,0x00,0x0C,0x12,0x17,0x0C,0x0D,0x02,0x03,0x05,0x04,0x03,0x00,0x00,
0x00,0x00,0x80,0xC0,0x70,0xD8,0x98,0xB0,0x00,0x00,0x00,0x00,0x00,0x06,0x09,0x0B,0x07,0x0C,0x0D,0x02,0x07,0x1F,0x25,0x18,0x00,0x00,
};

const uint8_t  New_Live_TBIKE [] PROGMEM= {11,1,0x34,0x4E,0x5E,0x36,0x32,0x08,0x19,0x3D,0x5E,0x48,0x30,};

const uint8_t  DIM_SPRITE_TBIKE [] PROGMEM= {26,32,14,26,15,4,6,20,5,20,11,21,11,4,11,7,};

