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

#ifndef CHAMBER0_H
#define CHAMBER0_H


#define POS 0
#define ROOF 1
#define WALL 2
#define FLOOR 3
#define VEC 3
#define ILOT 4
#define BIG_ILOT 5
#define BALLONSPK 6
#define EXIT -1

#define HORIZONTAL 0
#define VERTICAL 1

#define GOLD 0
#define GOLD2 1
#define KEY 2
#define DOOR 3

const int8_t RopeVec0[] PROGMEM = {
VERTICAL,9,37,18,

VERTICAL,21,53,3,
VERTICAL,49,53,3,
VERTICAL,77,53,3,

VERTICAL,35,35,9,
VERTICAL,63,35,9,

VERTICAL,84,20,18,

VERTICAL,9,4,16,

VERTICAL,56,4,2,

EXIT};


const int8_t Vec0[] PROGMEM = {
ILOT,18,44,
ILOT,46,44,
ILOT,74,44,

POS,0,5,
VEC,2,3,
ROOF,93,3,
VEC,96,6,
FLOOR,96,13,
VEC,16,13,
VEC,18,16,
VEC,24,19,
ROOF,87,19,
VEC,96,23,
WALL,96,63,
FLOOR,0,63,

POS,0,37,
WALL,0,64,
POS,0,37,
VEC,5,33,
VEC,8,35,
VEC,16,31,
VEC,17,29,
FLOOR,1,29,

POS,0,5,
WALL,0,29,

POS,73,29,
FLOOR,25,29,
POS,25,29,
VEC,27,32,
VEC,34,34,
ROOF,64,34,
VEC,70,31,
VEC,72,30,

EXIT
};

const int8_t Small_Ilot[] PROGMEM = {
POS,0,0,
FLOOR,6,0,
WALL,6,6,
POS,0,0,
WALL,0,6,
VEC,3,8,
VEC,6,6,
EXIT};

const int8_t SPK0[] PROGMEM = {
GOLD,60,46,0,
GOLD2,32,46,1,
GOLD,18,32,2,

KEY,72,32,1,
KEY,14,16,2,

DOOR,98,6,2,

BALLONSPK,81,32,0,
EXIT
};

const int8_t AcidDrop0[] PROGMEM = {
26,
6,3,
12,3,
16,3,
22,3,
42,3,
53,2,
59,2,
90,3,
87,18,
81,18,
52,19,
37,20,
25,20,
6,36,
12,35,
32,35,
38,34,
52,36,
60,34,
66,35,
80,52,
74,52,
52,52,
46,52,
24,52,
18,52,
};

#endif
