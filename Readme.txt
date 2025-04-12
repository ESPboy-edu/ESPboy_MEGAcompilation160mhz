#ESPboy port of tinyjoypad mega compilation v025!
www.espboy.com
www.tinyjoypad.com


//    >>>>>  MEGA COMPILATION 0025 for ESP8266/ESP8285  GPL v3 <<<<
//                    >>>>>  MEGA Tinyjoypad  <<<<
//                   Programmer: Daniel C 2019-2025
//             Contact EMAIL: electro_l.i.b@tinyjoypad.com
//              official website: www.tinyjoypad.com
//       or  https://sites.google.com/view/arduino-collection
//    https://github.com/phoenixbozo/TinyJoypad/tree/main/TinyJoypad
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
//
//---------------------------------------------------------------------------------
//      This COMPILATION uses code created by Roger Buehler
// Tiny Lander under GPLv3 for ATTINY85  https://github.com/tscha70/ 
//                  Contact EMAIL: tscha70@gmail.com
//---------------------------------------------------------------------------------
// These Libraries used for Mega Tinyjoypad ESP82xx are NOT included in this source code.
//                  (Refer to the "Library_License.txt" file.)
//  1- ESP8266WiFi.h  // Copyright (c) 2011-2014 Arduino.  All right reserved.
//                       Modified by Ivan Grokhotkov, December 2014.
//  2- Wire.h         // Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

//  3- SSD1306.h      // Copyright (c) 2018 by ThingPulse, Daniel Eichhorn Copyright

//  4- Arduino.h      // Copyright (c) 2005-2013 Arduino Team.  All right reserved.

//  5- avr/pgmspace.h // Copyright (c) 2002-2007  Marek Michalkiewicz Copyright (c) 2006,
//                       Carlos Lamas Copyright (c) 2009-2010, Jan Waclawek All rights reserved.
//---------------------------------------------------------------------------------

// ACTUAL GAME LIST
//  1-Tiny Lander by (c)Roger Buehler 2020 GPLv3  https://github.com/tscha70/  Contact EMAIL: tscha70@gmail.com
//  2-Tiny Gilbert (Electro L.I.B)
//  3-Tiny Trick (Electro L.I.B)
//  4-Tiny Space Invaders (Electro L.I.B)
//  5-Tiny Pinball (Electro L.I.B)
//  6-Tiny Pacman (Electro L.I.B)
//  7-Tiny Bomber (Electro L.I.B)
//  8-Tiny Bike (Electro L.I.B)
//  9-Tiny Bert (Electro L.I.B)
//  10-Tiny Arkanoid (Electro L.I.B)
//  11-Tiny Tris (Electro L.I.B)
//  12-Tiny Plaque (Electro L.I.B)
//  13-Tiny DDug (Electro L.I.B)
//  14-Tiny Missile (Electro L.I.B)
//  15-Tiny Morpion (Electro L.I.B)
//  16-Tiny Pipe (Electro L.I.B)
//  17-Tiny SQuest (Electro L.I.B)
//  18-Ardumania (Electro L.I.B) v1.3
//  19-Nohzdyve (Electro L.I.B) 
//  20-Gilbert in the Downland (Electro L.I.B) -> NEW (2025)
//  21-Tiny-Doc (Electro L.I.B) -> NEW (2025)

// ACTUAL FONCTION
//----------------
//  1-SOUND On/Off    => Access by std MENU, key Down (if you write permanently your choice, push button for 3 sec)
//                     -> New feature for adjusting contrast: In the audio menu, press the up key and push the action button
//                        to adjust the desired contrast level. The contrast level is automatically saved in the audio settings at the same time.

//  2-clear EEPROM    => Access by std MENU, key Up (Clear EEPROM => key right and push the action button for 3 sec)
//                     -> New feature to delete the backup of a specific game: select the game, open the EEPROM menu with the up key,
//                       then press the right key and while holding down the right key, press the action button for 3 seconds to erase the backup.

//  3-CONTROL TESTER  => Access by Startup (power on, after 0.2 sec press button for 2 sec.

//  for ESP8266/ESP8285 at 160 Mhz
//  PROGRAM with "LOLIN (WEMOS) D1 mini lite"board for D1 mini lite ESP8266/ESP8285
//   or PROGRAM with "GENERIC ESP82xx MODULE" for generic board
//  Programmer = AVRISP mkii

