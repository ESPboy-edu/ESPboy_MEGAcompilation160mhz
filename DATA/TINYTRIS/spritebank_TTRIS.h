//     >>>>>  MEGA COMPILATION for ESP8266/ESP8285  GPL v3 <<<<
//                    >>>>>  MEGA Tiny Joypad  <<<<
//                      Programmer: Daniel C 2019
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

//public var
uint8_t Grid_TTRIS[12][3]={{0}};
const uint8_t  MEM_TTTRIS[16]= {0,2,0,4,3,7,6,9,9,12,11,15,14,17,17,19,};
uint8_t Level_TTRIS;
uint8_t Level_Speed_ADJ_TTRIS;
uint16_t Scores_TTRIS;
uint8_t Nb_of_line_TTRIS[3];
uint16_t Nb_of_line_F_TTRIS;
uint8_t RND_VAR_TTRIS;
uint8_t LONG_PRESS_X_TTRIS;
uint8_t DOWN_DESACTIVE_TTRIS;
uint8_t DROP_SPEED_TTRIS;
uint8_t SPEED_x_trig_TTRIS;
uint8_t DROP_TRIG_TTRIS;
int8_t xx_TTRIS,yy_TTRIS;
uint8_t Piece_Mat2_TTRIS[5][5];
uint8_t Ripple_filter_TTRIS;
uint8_t PIECEs_TTRIS;
uint8_t PIECEs_TTRIS_PREVIEW;
uint8_t PIECEs_rot_TTRIS;
uint8_t DROP_BREAK_TTRIS;
int8_t OU_SUIS_JE_X_TTRIS;
int8_t OU_SUIS_JE_Y_TTRIS;
uint8_t OU_SUIS_JE_X_ENGAGED_TTRIS;
uint8_t OU_SUIS_JE_Y_ENGAGED_TTRIS;
int8_t DEPLACEMENT_XX_TTRIS;
int8_t DEPLACEMENT_YY_TTRIS;

const uint8_t  H_Grid_TTTRIS[] PROGMEM= {
0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,
7,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12,  
};

const uint8_t Pieces_TTRIS[] PROGMEM= {
//0
0b00000000,
0b00100000,
0b01110000,
0b00000000,
0b00000000,
//1
0b00000000,
0b00000000,
0b00110000,
0b00110000,
0b00000000,
//2
0b00000000,
0b00000000,
0b00110000,
0b01100000,
0b00000000,
//3
0b00000000,
0b00010000,
0b00110000,
0b00100000,
0b00000000,
//4
0b00100000,
0b00100000,
0b00100000,
0b00100000,
0b00000000,
//5
0b00000000,
0b00100000,
0b00100000,
0b01100000,
0b00000000,
//6
0b00000000,
0b00100000,
0b00100000,
0b00110000,
0b00000000,
};

const uint8_t  tiny_PREVIEW_block_TTTRIS[] PROGMEM= {
2,1,
0b11000000,
0b11000000,
};

const uint8_t  tinyblock_TTTRIS[] PROGMEM= {
3,1,
0x07,0x05,0x07,
};

const uint8_t  tinyblock2_TTTRIS[] PROGMEM= {
3,1,
0b11100000,
0b11100000,
0b11100000,
};

const uint8_t  police_TTRIS [] PROGMEM= {
4,1,
0x1F,0x11,0x1F,0x00,
0x00,0x1F,0x00,0x00,
0x1D,0x15,0x17,0x00,
0x11,0x15,0x1F,0x00,
0x07,0x04,0x1F,0x00,
0x17,0x15,0x1D,0x00,
0x1F,0x15,0x1D,0x00,
0x01,0x1D,0x03,0x00,
0x1F,0x15,0x1F,0x00,
0x17,0x15,0x1F,0x00,
};

const uint8_t  start_button_1_TTRIS [] PROGMEM= {
30,1,
0xFE,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFE,
};

const uint8_t  start_button_2_TTRIS [] PROGMEM= {
30,1,
0x03,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x03,
};

const uint8_t  chateau_TTRIS [] PROGMEM= {
0xD5,0xF8,0xF4,0xEA,0x54,0x7A,0x55,0x68,0x74,0x7A,0x54,0x6A,0x55,0x78,0x74,0x6A,0x54,0x7A,0x55,0x68,
0x74,0x7A,0x54,0x6A,0x55,0x78,0x74,0x6A,0x54,0x7A,0x55,0x68,0xF4,0xFA,0xD4,0xEA,0xFF,0x01,0x00,0x02,
0x02,0x82,0xFE,0x82,0x02,0x02,0x88,0xFA,0x80,0x00,0xF8,0x10,0x08,0x08,0xF0,0x00,0x18,0x60,0xC0,0x38,
0x88,0xA0,0xA8,0xA8,0x28,0x28,0x28,0x08,0x08,0x08,0x01,0xFF,0xFF,0x00,0x04,0x04,0x04,0x14,0x14,0x14,
0x54,0x54,0x50,0x50,0x44,0x04,0x04,0xFC,0x04,0x04,0x04,0xF0,0x22,0x12,0x01,0x10,0xF4,0x00,0x00,0x20,
0x50,0x50,0x90,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x80,0x40,0x40,0x00,0x40,0x40,0xC0,
0x40,0x40,0x01,0x81,0x41,0x40,0x80,0x01,0x00,0xC0,0x40,0x41,0x81,0x01,0x40,0x41,0xC1,0x41,0x40,0x00,
0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x01,0x12,0x12,0x0C,0x00,0x00,0x1F,0x00,0x00,0x00,0x1F,
0x02,0x02,0x1F,0x00,0x00,0x1F,0x06,0x0A,0x11,0x00,0x00,0x00,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,
0xFF,0x00,0x00,0x00,0xF0,0xB0,0x50,0x88,0x88,0xC8,0x50,0x50,0x20,0x20,0x60,0x60,0xB0,0x90,0x10,0x18,
0x08,0x98,0x98,0xA4,0xE4,0x46,0xE4,0xE4,0xE8,0xF8,0xF0,0xF0,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,
0x03,0x06,0x0D,0x1A,0x3F,0x6B,0xD6,0xAA,0x54,0xF8,0xFC,0xFC,0xFE,0xFE,0xAB,0x7F,0x7F,0x3F,0x3F,0x1F,
0x0F,0x0D,0x07,0x07,0x03,0x03,0x01,0x01,0x00,0x00,0x00,0xFF,0x1F,0x3C,0x38,0x38,0x30,0x30,0x30,0x30,
0x30,0x30,0x30,0x31,0x33,0x37,0x33,0x31,0x31,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
0x30,0x30,0x30,0x30,0x38,0x38,0x3C,0x1F,
};

const uint8_t  BACKGROUND_TTRIS [] PROGMEM= {
0xFC,0x02,0xF9,0xF5,0x1D,0x0D,0x0D,0x0D,0x0D,0x0B,0x07,0x1F,0x3F,0x20,0x2F,0x2F,0x3F,0x22,0x3F,0x20,
0x39,0x33,0x20,0x3F,0x20,0x2A,0x2E,0x3F,0x2D,0x2A,0x2A,0x36,0x1F,0x07,0x0B,0x0D,0x0D,0x0D,0x0D,0x1D,
0xF5,0xF9,0x02,0xFC,0xF8,0x00,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,
0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,
0x00,0x40,0x00,0xF8,0xFC,0x02,0xF9,0xF5,0x1D,0x0D,0x0D,0x0B,0x07,0x1F,0x3F,0x2D,0x2A,0x2A,0x36,0x3F,
0x31,0x2E,0x2E,0x3F,0x31,0x2E,0x2E,0x31,0x3F,0x20,0x3A,0x32,0x2D,0x3F,0x20,0x2A,0x2E,0x3F,0x1F,0x07,
0x0B,0x0D,0x0D,0x1D,0xF5,0xF9,0x02,0xFC,0xFF,0x00,0x7F,0xBF,0xE0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,
0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,
0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xE0,0xBF,0x7F,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x7F,0xBF,0xE0,0xC0,0xC0,0xC0,
0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,
0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xE0,0xBF,0x7F,0x00,0xFF,0x00,0x01,0xFA,0x5A,
0x7A,0x5A,0xDA,0x5A,0x7A,0x5A,0xDA,0x5A,0x7A,0x5A,0xDA,0xDA,0x7A,0x5A,0xDA,0x5A,0x7A,0x5A,0xDA,0x5A,
0x7A,0x5A,0xDA,0x5A,0x7A,0x5A,0xDA,0x5A,0x7A,0x5A,0xDA,0x5A,0x7A,0x5A,0xDA,0x5A,0x7A,0xFA,0x01,0x00,
0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,
0x00,0x01,0xFA,0xFA,0x5A,0x5A,0x5A,0x7A,0x5A,0x5A,0x5A,0x7A,0x5A,0x5A,0x5A,0x7A,0x5A,0x5A,0x5A,0x7A,
0x5A,0x5A,0x5A,0x7A,0xDA,0xDA,0x5A,0x7A,0x5A,0xDA,0x5A,0x7A,0x5A,0xDA,0x5A,0x7A,0x5A,0xDA,0x5A,0x7A,
0x5A,0xFA,0x01,0x00,0x00,0x00,0xFF,0x55,0x77,0x55,0xDD,0x55,0x77,0x55,0xDD,0xF5,0xFF,0x3F,0x07,0xE0,
0xFC,0xBC,0xE0,0x81,0x07,0x1D,0x7D,0xD5,0x77,0x55,0xDD,0x55,0x77,0x55,0xDD,0x55,0x77,0x55,0xDD,0x55,
0x77,0x55,0xDD,0x55,0x77,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0xFE,0xFD,0x07,0x03,0x03,0x03,0x03,0x03,
0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x07,0xFD,0xFE,0x00,0x01,0xFF,0xF7,0xD5,0xDD,0xD5,0xF7,
0xD5,0xDD,0xD5,0xF7,0xD5,0xDD,0xD5,0x77,0x55,0xFF,0x00,0x00,0x00,0x00,0xFF,0x55,0x77,0x55,0xDD,0xF5,
0x7F,0x3F,0x8F,0xC3,0xF0,0xDC,0xBF,0xF7,0xEF,0xFD,0xEA,0xD7,0xBC,0xF0,0x40,0x81,0x07,0x1D,0x75,0x3F,
0x87,0xF1,0x81,0x03,0x0F,0x35,0xDD,0x55,0x77,0x55,0xDD,0x55,0x77,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,
0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x7E,0xC2,0x5E,0x7E,
0x42,0x52,0x5A,0x7E,0x62,0x5E,0x62,0x7E,0x42,0x52,0x5A,0x7E,0xC2,0x5E,0xFC,0x01,0x03,0xFF,0x00,0x00,
0x00,0x00,0xFF,0x55,0x77,0x55,0xDF,0x57,0x7C,0xF8,0xE1,0x04,0x2A,0xEE,0xDA,0x4E,0x0A,0x0A,0x0E,0x1A,
0xAE,0x0A,0x05,0x01,0xC0,0x60,0x78,0x6F,0x5F,0x7E,0x75,0x6F,0x58,0x60,0xC0,0x03,0x0F,0x75,0xDD,0x55,
0x77,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0xFF,0x00,0x00,0xFF,0x78,0x73,0xE5,0x67,0x66,0x66,0xE6,0x66,0x66,0x6E,0xFE,0xFE,0x0E,
0x06,0xC6,0x00,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x80,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x0F,0x15,0x17,0x95,0x1D,0x15,0x97,0x1F,0x9F,0x00,
0x09,0xBF,0x3A,0x95,0x20,0x00,0x91,0x00,0xAA,0x00,0x00,0x80,0x02,0x85,0x37,0x2D,0x95,0x07,0x85,0x0D,
0x37,0x85,0x02,0x80,0x18,0x1C,0x9F,0x15,0x17,0x0F,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x0F,0x17,0x15,0x9D,0x15,0x17,
0x95,0x1D,0x95,0x17,0x15,0x7F,0x3F,0x80,0x00,0x1D,0x94,0x19,0x9A,0x13,0x13,0x93,0x13,0x93,0x13,0x17,
0x7F,0x3F,0x87,0x03,0x13,0x93,0x13,0x93,0x13,0x12,0x91,0x10,0x18,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,
0x06,0x0F,0x0D,0x1F,0x1D,0x16,0x1F,0x1D,0x1F,0x1D,0x36,0x3F,0x3D,0x7F,0x7D,0x76,0xFF,0xFD,0xFF,0xFD,
0x76,0x7F,0x7D,0x3F,0x3D,0x36,0x1F,0x1D,0x1F,0x1D,0x16,0x1F,0x1D,0x0F,0x0D,0x06,0x00,0x00,0x00,0x00,
0xFF,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xFF,
0x00,0x00,0x00,0x00,0x06,0x0F,0x0D,0x1F,0x1D,0x16,0x1F,0x1D,0x1F,0x1D,0x36,0x3F,0x3D,0x7F,0x7D,0x76,
0xFF,0xFD,0xFF,0xFD,0x76,0x7F,0x7D,0x3F,0x3D,0x36,0x1F,0x1D,0x1F,0x1D,0x16,0x1F,0x1D,0x0F,0x0D,0x06,
0x00,0x00,0x00,0x00,
};


