//   >>>>>  Gilbert in the Downland for ESP8285/ESP8266  GPL v3 <<<<<
//                    Programmer: Daniel C 2025
//             Contact EMAIL: electro_l.i.b@tinyjoypad.com
//  https://github.com/phoenixbozo/TinyJoypad/tree/main/TinyJoypad
//                    https://WWW.TINYJOYPAD.COM
//          https://sites.google.com/view/arduino-collection

//  Gilbert in the Downland is free software: you can redistribute it and/or modify
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

#ifndef CHAMBER7_H
#define CHAMBER7_H

#include "Chamber6.h"

const int8_t RopeVec7[] PROGMEM = {
VERTICAL,79,3,52,
VERTICAL,16,3,52,
EXIT};

const int8_t Vec7[] PROGMEM = {
POS,0,5,
VEC,2,3,
ROOF,44,3,
VEC,47,5,
VEC,48,6,
VEC,51,9,
VEC,54,6,
VEC,56,3,
ROOF,93,3,
VEC,96,5,

WALL,96,23,
VEC,96,29,

FLOOR,90,29,
VEC,91,30,
VEC,92,32,
VEC,96,35,
WALL,96,63,

FLOOR,48,63,
WALL,48,50,
VEC,54,47,
VEC,55,45,
WALL,55,39,
VEC,61,36,
VEC,61,35,
VEC,65,32,
VEC,67,31,
WALL,67,19,
FLOOR,60,19,
VEC,60,24,
FLOOR,54,24,
VEC,54,29,

FLOOR,41,29,
VEC,41,24,
FLOOR,35,24,
VEC,35,19,
FLOOR,28,19,
WALL,28,32,
VEC,45,45,
VEC,43,46,
VEC,40,48,
VEC,39,50,
WALL,39,63,
FLOOR,0,63,

WALL,0,27,
VEC,5,24,
VEC,6,22,
FLOOR,0,22,
VEC,0,21,
WALL,0,5,
EXIT
};

const int8_t SPK7[] PROGMEM = {
DOOR,-7,56,15,
DOOR,98,22,4,

KEY,3,12,15,
KEY,52,50,16,

GOLD,87,16,23,
GOLD,30,50,21,
GOLD,45,11,22,

EXIT
};

const int8_t AcidDrop7[] PROGMEM = {
17,
6,3,
13,4,
19,4,
28,3,
35,2,
41,2,
47,7,
54,8,
60,3,
67,4,
76,3,
82,3,
90,3,
28,34,
34,39,
61,38,
66,34,
};

#endif
