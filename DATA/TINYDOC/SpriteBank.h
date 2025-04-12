//      >>>>>  Tiny-Doc for ESP8285/ESP8266  GPL v3 <<<<<
//                    Programmer: Daniel C 2025
//             Contact EMAIL: electro_l.i.b@tinyjoypad.com
//  https://github.com/phoenixbozo/TinyJoypad/tree/main/TinyJoypad
//                    https://WWW.TINYJOYPAD.COM
//          https://sites.google.com/view/arduino-collection

//  Tiny-Doc is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// Reference in file "COPYING.txt".
// -__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-


//For Mega Tinyjoypad ESP8285/ESP8266

#ifndef _SPRITEBANK_TD_H
#define _SPRITEBANK_TD_H

#include <avr/pgmspace.h>

#define HORIZONTAL_TD 0
#define VERTICAL_TD 1

const uint8_t  LevelCleared_TD [] PROGMEM= {
29,2,
0xFF,0x01,0x01,0x01,0x01,0x01,0x01,0x7D,0x41,0x01,0x7D,0x55,0x01,0x7D,0x41,0x3D,0x01,0x7D,0x55,0x01,
0x7D,0x41,0x01,0x01,0x01,0x01,0x01,0x01,0xFF,0xFF,0x80,0x80,0xBE,0xA2,0x80,0xBE,0xA0,0x80,0xBE,0xAA,
0x80,0xBE,0x8A,0xBC,0x80,0xBE,0x8A,0xB4,0x80,0xBE,0xAA,0x80,0xBE,0xA2,0xBC,0x80,0x80,0xFF,
};

const uint8_t SpriteOrder_TD[] PROGMEM={
1,2,3,
2,3,1,
3,1,2,
};

const uint8_t  RBBRVV [] PROGMEM= {
0,2,2,0,1,1
};

const uint8_t  police_TD [] PROGMEM= {
3,1,
0x1F,0x11,0x1F,
0x00,0x00,0x1F,
0x1D,0x15,0x17,
0x11,0x15,0x1F,
0x07,0x04,0x1F,
0x17,0x15,0x1D,
0x1F,0x15,0x1D,
0x01,0x1D,0x03,
0x1F,0x15,0x1F,
0x17,0x15,0x1F,
};

const uint8_t Anim_TD[] PROGMEM = {
    97, 18,  // (point de départ)
    93, 14,
    90, 11,
    86, 8,
    82, 6,
    79, 5,
    75, 5,
    72, 5,
    68, 6,
    65, 8,
    61, 10
};

const uint8_t  VirusLoupe_TD [] PROGMEM= {
7,1,
0x08,0x0E,0x11,0x11,0x11,0x0E,0x08,0x00,0x0E,0x11,0x11,0x11,0x0E,0x00,0x02,0x0E,0x11,0x11,0x11,0x0E,
0x02,0x08,0x0E,0x15,0x1B,0x15,0x0E,0x08,0x00,0x0E,0x15,0x1B,0x15,0x0E,0x00,0x02,0x0E,0x15,0x1B,0x15,
0x0E,0x02,0x08,0x0E,0x1F,0x1F,0x1F,0x0E,0x08,0x00,0x0E,0x1F,0x1F,0x1F,0x0E,0x00,0x02,0x0E,0x1F,0x1F,
0x1F,0x0E,0x02,
};

const uint8_t  SHADOW_TD [] PROGMEM= {
11,1,
0x1E,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x1E,
};

const uint8_t  virus_TD [] PROGMEM= {
4,1,//3
0x08,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x01,
};

const uint8_t  pills_TD [] PROGMEM= {
4,1,
0x06,0x09,0x09,0x06,//O
0x06,0x0B,0x0D,0x06,//0
0x06,0x0F,0x0F,0x06,//*

0x0F,0x09,0x09,0x06,//> O
0x06,0x09,0x09,0x0F,//<
0x07,0x09,0x09,0x07,//v
0x0E,0x09,0x09,0x0E,//^

0x0F,0x0B,0x0D,0x06,//> 0
0x06,0x0B,0x0D,0x0F,//<
0x07,0x0D,0x0B,0x07,//v
0x0E,0x0D,0x0B,0x0E,//^

0x0F,0x0F,0x0F,0x06,//> *
0x06,0x0F,0x0F,0x0F,//<
0x07,0x0F,0x0F,0x07,//v
0x0E,0x0F,0x0F,0x0E,//^

0x05,0x08,0x01,0x0A,
0x0A,0x01,0x08,0x05,
0x00,0x00,0x00,0x00,
};

const uint8_t  background_TD [] PROGMEM= {
0xFF,0x33,0xFD,0x0D,0x07,0x07,0x05,0x45,0xA7,0xA7,0x25,0x05,0xCF,0x2B,0x2B,0x2B,0x0B,0xCB,0x2B,0x2B,
0x2B,0xCB,0x0B,0xEB,0xAB,0xAB,0xCF,0x05,0xE7,0xA7,0x25,0x25,0x07,0x07,0x05,0x0D,0xFB,0x03,0xCD,0xCD,
0x33,0x33,0xCD,0xCD,0x33,0x33,0xCD,0xCD,0x33,0x33,0xDF,0xF0,0x60,0xC7,0x88,0x90,0x10,0x10,0xE0,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x10,0x10,0x90,0x88,0xC7,0xE0,0xF0,
0x3F,0x33,0xCD,0xCD,0x33,0x33,0xCD,0xCD,0x33,0x33,0xCD,0xCD,0x33,0x33,0xCD,0xCD,0x33,0x33,0xCD,0xCD,
0x33,0x33,0xCD,0xCD,0x33,0x33,0xCD,0xCD,0x33,0x33,0xCD,0xCD,0x33,0x33,0xCD,0xCD,0x33,0x33,0xCD,0xCD,
0x33,0x33,0xCD,0xCD,0x33,0x33,0xCD,0xFF,0xFF,0x33,0xFF,0x00,0x00,0x00,0x00,0x02,0x02,0x02,0x01,0x00,
0x01,0x02,0x02,0x02,0x00,0x01,0x02,0x02,0x02,0x01,0x00,0x03,0x00,0x01,0x02,0x00,0x03,0x02,0x02,0x02,
0x00,0x00,0x00,0x00,0xFF,0x00,0xCC,0xCC,0x33,0xFF,0x06,0x03,0xF1,0x09,0x09,0x09,0x09,0x09,0x09,0x09,
0x09,0x09,0x09,0x08,0x04,0x04,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x03,0x04,0x04,0x08,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0xF1,0x03,0x07,0xFF,0xCC,0xCC,
0x33,0x33,0xEC,0x3C,0x13,0x13,0x1C,0x1C,0x13,0x13,0x1C,0x1C,0x13,0x13,0x1C,0x1C,0x13,0x13,0x9C,0x9C,
0x93,0x93,0x9C,0x1C,0x13,0x13,0x1C,0x1C,0x33,0xE3,0x0C,0xCC,0x33,0x33,0xCC,0xFF,0xFF,0x33,0xCF,0xD8,
0x10,0x10,0xD0,0xD0,0x10,0x10,0xD0,0xD0,0x10,0x10,0xD0,0xD0,0x10,0x10,0xD0,0xD0,0x10,0x10,0xD0,0xD0,
0x10,0x10,0xD0,0xD0,0x10,0x10,0xD0,0xD0,0x10,0x10,0xD0,0xC8,0x2F,0x20,0xCC,0xCC,0x33,0xFF,0x00,0x00,
0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0xFF,0x00,0x00,0xFF,0xCC,0xCC,0x33,0x33,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x80,0x02,0x87,0x3F,0x46,0x84,0x15,0x04,0x04,0x04,0x85,0x8D,0x4A,0x3C,0x18,0x00,0xFF,0x00,0xCC,
0x33,0x33,0xCC,0xFF,0xFF,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0xB3,0xF3,0x4C,0x4C,
0x33,0x33,0x2C,0x2C,0x33,0x33,0x2C,0x2C,0x73,0x73,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,
0x33,0x33,0xCC,0xCC,0x33,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0xFF,0xCC,0xCC,0x33,0x33,0x7F,0xC0,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x81,0x81,0x81,0x80,0x91,0xBF,0xB7,0xBF,0xBF,0xAF,
0x80,0x80,0x80,0x80,0xC0,0x7F,0x00,0xCC,0x33,0x33,0xCC,0xFF,0xFF,0x33,0xCC,0xCC,0x33,0x33,0xCC,0x7C,
0x1B,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x01,0x03,0x06,0x0C,0x33,0xF3,0x4C,0xCC,0x33,0x33,0xCC,0xCC,0x33,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,
0x00,0xFF,0xCC,0xCC,0x33,0x33,0xF4,0x0C,0x0A,0x0A,0x0C,0x0C,0x0A,0x0A,0x0C,0x1C,0x16,0x16,0x14,0x14,
0x16,0x16,0x14,0x14,0x16,0x1E,0x0C,0x0C,0x0A,0x0A,0x0C,0x0C,0x0A,0xF2,0x05,0xCC,0x33,0x33,0xCC,0xFF,
0xFF,0x33,0xCC,0xCC,0x33,0x7F,0xC1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC1,0x3E,0x80,0x33,0x33,0xCC,0xCC,
0x33,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0xFF,0xCC,0xCC,0x33,0x33,0xFF,0x00,0x00,0x00,0x00,0x00,
0x3E,0x20,0x20,0x00,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0x00,0xCC,0x33,0x33,0xCC,0xFF,0xFF,0x33,0xCC,0x4C,0x33,0x93,0x4C,0x17,0x24,0x48,0x90,0x60,
0x40,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x40,0x40,0x20,0x10,0xC8,0xC4,
0x33,0x31,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0xFF,0xCC,0xCC,
0x33,0x33,0xFF,0x00,0x00,0x00,0x00,0x00,0x3C,0x40,0x3C,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0xCC,0x33,0x33,0xCC,0xFF,0xFF,0xA7,0xC8,0xD2,
0x95,0x90,0xC8,0xC4,0xB2,0xB1,0xCC,0xCC,0xB2,0xB2,0xCC,0xCC,0xB1,0xB1,0xCD,0xCD,0xB1,0xB1,0xCD,0xCD,
0xB0,0xB2,0xCC,0xCC,0xB3,0xB3,0xCC,0xCC,0xB3,0xB3,0xCC,0xCC,0xB3,0xB3,0xCC,0xCC,0xB3,0xFF,0x80,0x00,
0x7F,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x7F,0x00,0x80,0xFF,0xCC,0xCC,0xB3,0xB3,0xC3,0xC4,0xB4,0xB4,0xC4,0xC4,0xB4,0xB4,0xC4,0xC4,
0xB4,0xB4,0xC4,0xC4,0xB4,0xB4,0xC4,0xC4,0xB4,0xB4,0xC4,0xC4,0xB4,0xB4,0xC4,0xC4,0xB4,0xB3,0xC8,0xCC,
0xB3,0xB3,0xCC,0xFF,
};

const uint8_t  Introgame_TD [] PROGMEM= {
0xFF,0x01,0xFD,0xCD,0x35,0x35,0x0D,0x0D,0x35,0x35,0xCD,0xCD,0x35,0x35,0xCD,0xCD,0x35,0x35,0xCD,0xCD,
0x35,0x35,0xCD,0xCD,0x35,0x35,0x4D,0x4D,0x35,0x35,0x4D,0x4D,0x35,0x35,0x4D,0x4D,0x35,0x35,0x4D,0x4D,
0x35,0x35,0x4D,0x4D,0x35,0x35,0x4D,0x4D,0x35,0x35,0x4D,0x4D,0x35,0x35,0x4D,0x4D,0x35,0x35,0x4D,0x4D,
0x35,0x35,0x4D,0x4D,0x35,0x35,0x4D,0x4D,0x75,0x75,0x4D,0x4D,0x75,0x75,0x4D,0x4D,0x75,0x75,0x4D,0x4D,
0x75,0x75,0x4D,0x4D,0x75,0x75,0x4D,0x4D,0x75,0x75,0x4D,0x4D,0x75,0x75,0x4D,0x4D,0x75,0x75,0xCD,0xCD,
0x35,0x35,0xCD,0xCD,0x35,0x35,0xCD,0xCD,0x35,0x35,0xCD,0xCD,0x35,0x35,0xCD,0xCD,0x35,0x35,0x0D,0x0D,
0x35,0x35,0xCD,0xCD,0x35,0xFD,0x01,0xFF,0xFF,0x00,0xFF,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,
0x33,0x33,0xCC,0xCC,0x33,0x13,0xCC,0xE4,0xF3,0xF9,0xFC,0xFE,0xFE,0xFF,0xFF,0xFB,0xFB,0xFB,0xFB,0xFB,
0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,
0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFB,0xFF,0xFF,0xFE,0xF0,0x00,0x00,0x04,0x04,0x04,0x04,0x04,
0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
0x04,0x04,0x04,0x04,0x04,0x00,0x08,0x08,0x11,0x31,0x62,0xC4,0x87,0x0B,0x3C,0x4C,0xB3,0x33,0xCC,0xCC,
0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xCC,
0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0x00,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xF7,0xF3,0xF3,0x13,0x03,0xE3,0xF3,0xF3,0xF3,0xFB,0xFF,0xFF,0x4F,0x0F,0x89,0xE9,0xFF,0xFF,0xFF,0x07,
0x0F,0xCF,0xEF,0xEF,0x0F,0x1F,0xFF,0xFF,0xEF,0x0F,0x0F,0xEF,0xFF,0x7F,0x0F,0x8F,0xEF,0xEF,0xFF,0xFF,
0xFF,0x00,0x00,0x00,0x00,0x00,0x80,0xE4,0x7C,0x0C,0x04,0x04,0x0C,0xFC,0xF8,0x00,0xC0,0xE0,0x20,0x30,
0x30,0x30,0xF0,0xC0,0x00,0x80,0xE0,0x60,0x30,0x10,0x10,0x30,0x70,0x20,0x00,0x00,0x00,0x00,0x00,0x00,
0x01,0x06,0x18,0x00,0x01,0x03,0xFC,0x04,0x13,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,
0x33,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xC0,
0x1F,0x7F,0xBF,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFB,0xF8,0xF8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF9,0xF9,
0xF8,0xF8,0xFB,0xF9,0xFF,0xFF,0xFB,0xF8,0xF8,0xFF,0xFF,0xFB,0xF8,0xF8,0xFF,0xEF,0xEF,0xE0,0xE0,0xF8,
0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x04,0x07,0x07,0x04,0x04,0x06,0x02,
0x03,0x01,0x00,0x00,0x03,0x07,0x06,0x06,0x06,0x03,0x03,0x00,0x00,0x01,0x07,0x06,0x04,0x04,0x04,0x06,
0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0x30,0x0C,0x00,0xC0,0x60,0x1F,0x00,0x00,0x33,0xCC,0xCC,
0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xCC,0x33,0x33,0xCC,0xCC,
0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x30,0xC9,0xC3,0x26,0x0D,0xDA,0x95,0x2B,0x55,0x6B,0x57,
0xAB,0xD7,0xAF,0xD7,0xAF,0xDF,0xAF,0xDF,0xAF,0xDF,0xAF,0xDF,0xAF,0xDF,0xAF,0xDF,0xAF,0xDF,0xAF,0xDF,
0xAF,0xDF,0xAF,0xDF,0xAF,0xDF,0xAF,0xDF,0xAF,0xDF,0xAF,0xDF,0xAF,0xDF,0xAF,0xDF,0x03,0x00,0x40,0x00,
0x20,0x00,0x40,0x00,0x20,0x00,0x40,0x00,0x20,0x00,0x40,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x40,0x00,
0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x88,0x88,0x44,0x46,0x23,0x11,0x10,0x08,0x86,0xC1,
0x20,0x30,0xC8,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0xFF,0x00,0xFF,
0xFF,0x00,0xFF,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,
0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x32,0x32,0xC8,0xC8,0x31,0x31,0xC9,0xC9,0x31,0x31,0xC9,0xC9,
0x31,0x31,0xC9,0xC9,0x31,0x31,0xC9,0xC9,0x31,0x31,0xC9,0xC9,0x31,0x31,0xC9,0xC9,0x31,0x31,0xC9,0xC9,
0x31,0x31,0xC9,0xC8,0x31,0x31,0xC9,0xC9,0x31,0x31,0xC9,0xC9,0x31,0x31,0xC9,0xC9,0x31,0x31,0xC9,0xC9,
0x31,0x31,0x49,0x49,0x31,0x31,0xC9,0xC9,0x31,0x11,0x49,0x41,0xE1,0xE1,0xC1,0x91,0xB1,0x91,0x90,0x90,
0xA0,0xA0,0x4C,0x8C,0x32,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,
0x33,0x33,0xCC,0xCC,0x33,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xCC,0x33,0x33,0x0C,0x0C,0x33,0x33,0xCC,0xCC,
0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,
0x33,0x33,0xCC,0xCC,0x33,0x33,0xCC,0xCC,0x03,0x00,0x00,0x00,0x00,0xB8,0xA8,0xE8,0x00,0x08,0xF8,0x08,
0x00,0xF8,0x28,0xF8,0x00,0xF8,0x28,0xD8,0x00,0x08,0xF8,0x08,0x00,0x00,0x00,0x00,0x70,0x88,0xA8,0xE8,
0x00,0xF8,0x28,0xF8,0x00,0xF8,0x10,0xF8,0x00,0xF8,0xA8,0x88,0x00,0x00,0x00,0x00,0x03,0x33,0xCC,0xCC,
0x30,0x27,0x88,0x30,0xE2,0xE0,0xE0,0xE0,0xF0,0x11,0x09,0x07,0x03,0x20,0xC8,0xCC,0x33,0x33,0xCC,0xCC,
0x33,0x33,0xCC,0xCC,0x33,0x33,0x0C,0x0C,0x33,0x33,0xCC,0xCC,0x33,0xFF,0x00,0xFF,0xFF,0x80,0xBF,0xAC,
0xB3,0xB3,0xAC,0xAC,0xB3,0xB3,0xAC,0xAC,0xB3,0xB3,0xAC,0xAC,0xB3,0xB3,0xAC,0xAC,0xB3,0xB3,0xAC,0xAC,
0xB3,0xB3,0xAC,0xAC,0xB3,0xB3,0xAC,0xAC,0xB3,0xB3,0xAC,0xAC,0xB3,0xB3,0xAC,0xAC,0xB3,0xB0,0xA8,0xA8,
0xB0,0xB0,0xA8,0xA8,0xB0,0xB0,0xA8,0xA8,0xB0,0xB0,0xA8,0xA8,0xB0,0xB0,0xA8,0xA8,0xB0,0xB0,0xA8,0xA8,
0xB0,0xB0,0xA8,0xA8,0xB0,0xB0,0xA8,0xA8,0xB0,0xB0,0xA8,0xA8,0xB0,0xB0,0xA8,0xA8,0xB0,0xB0,0xA8,0xA8,
0xB0,0xB0,0xA8,0xAC,0xB3,0xB3,0xAC,0xAC,0xB3,0xB1,0xA8,0xA2,0xB7,0xA6,0xA7,0xA7,0xA5,0xA0,0xA0,0xA0,
0xB3,0xB3,0xAC,0xAC,0xB3,0xB3,0xAC,0xAC,0xB3,0xB3,0xAC,0xAC,0xB3,0xB3,0xAC,0xAC,0xB3,0xB3,0xAC,0xAC,
0xB3,0xBF,0x80,0xFF,
};
const uint8_t shad_TD [] PROGMEM= {
46,2,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,
0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,
0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,
};



#endif