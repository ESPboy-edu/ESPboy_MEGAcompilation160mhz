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

#ifndef _ELECTROLIB_H
#define _ELECTROLIB_H

uint8_t blitzSprite(int8_t xPos, int8_t yPos, uint8_t xPASS, uint8_t yPASS, uint8_t FRAME, const uint8_t *SPRITES) ;
uint8_t SPEED_BLITZ(int8_t xPos, int8_t yPos, uint8_t xPASS, uint8_t yPASS, uint8_t FRAME, const uint8_t *SPRITES) ;
uint8_t SplitSpriteDecalageY(uint8_t decalage, uint8_t Input, uint8_t UPorDOWN) ;
int8_t RecupeLineY(int8_t Valeur) ;
uint8_t RecupeDecalageY(uint8_t Valeur) ;
uint8_t Mymap(uint8_t x, uint8_t in_min, uint8_t in_max, uint8_t out_min, uint8_t out_max) ;
uint8_t Trace_LINE(uint8_t DESACTIVE_, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t xPASS, uint8_t yPASS) ;
uint8_t DIRECTION_LINE(uint8_t DESACTIVE_, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t xPASS, uint8_t yPASS) ;
uint8_t Return_Full_Byte(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t xPASS, uint8_t yPASS) ;
void Universal_Swap(uint8_t *A_, uint8_t *B_) ;
uint8_t RECONSTRUCT_BYTE(uint8_t Min_, uint8_t Max_) ;
void FADE(const uint8_t *PIC, uint8_t FADE) ;
void PLAY_MUSIC(const uint8_t *Music_) ;
void Sound(uint8_t freq_, uint8_t dur) ;
void TINYJOYPAD_INIT(void) ;

#endif