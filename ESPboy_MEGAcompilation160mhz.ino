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

//  This program is distributsed in the hope that it will be useful,
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

const uint16_t FIRMWARE_VERSION=25;

#include <ESP8266WiFi.h> // Copyright (c) 2011-2014 Arduino.  All right reserved. Modified by Ivan Grokhotkov, December 2014. (Refer to the "Library_License.txt" file.)
#include <ESP_EEPROM.h>

//#include <Wire.h>        // Copyright (c) 2006 Nicholas Zambetti.  All right reserved.                                        (Refer to the "Library_License.txt" file.)
//#include "SSD1306.h"     // Copyright (c) 2018 by ThingPulse, Daniel Eichhorn Copyright (c) 2018 by Fabrice Weinberg.         (Refer to the "Library_License.txt" file.)

#include "lib/ESPboyInit.h"
#include "lib/ESPboyInit.cpp"
#include "ESPboyRender.h"

ESPboyInit myESPboy;
ESPboyRender display(&myESPboy.tft);

#include "MENU_ESP.h"
#include "TESTMOD/JOY_TESTER_ESP.h"
#include "DATA/TINYMORPION/Tiny-Morpion-ESP.h"
#include "DATA/TINYMISSILE/Tiny-Missile-ESP.h"
#include "DATA/TINYDDUG/Tiny-DDug-ESP.h"
#include "DATA/TINYPLAQUE/Tiny-Plaque-ESP.h"
#include "DATA/TINYTRICK/tiny-trick-ESP.h"
#include "DATA/TINYBIKE/Tiny-Bike-ESP.h"
#include "DATA/TINYARKANOID/tiny-arkanoid-ESP.h"
#include "DATA/TINYBOMBER/tiny-bomber-ESP.h"
#include "DATA/TINYPACMAN/tiny-pacman-ESP.h"
#include "DATA/TINYGILBERT/tiny-gilbert-ESP.h"
#include "DATA/TINYPINBALL/tiny-Pinball-ESP.h"
#include "DATA/TINYINVADERS/Tiny_space_invaders-ESP.h"
#include "DATA/TINYBERT/Tiny-bert-ESP.h"
#include "DATA/TINYTRIS/tiny-tris-ESP.h"
#include "DATA/TINYLANDER/tiny-lander-ESP.h" //by Roger Buehler (c) 2020 GPLv3  https://github.com/tscha70/  Contact EMAIL: tscha70@gmail.com
#include "DATA/TINYPIPE/Tiny-Pipe-ESP.h"
#include "DATA/TINYSQUEST/Tiny-SQuest-ESP.h"
#include "DATA/ARDUMANIA/Ardumania-ESP.h" //Ardumania has been adapted from the official version on arduboy. The audio library has not been carried over, so the sounds are different from the original.
#include "DATA/NOHZDYVE/Nohzdyve-ESP.h" //Nohzdyve has been adapted from the official version on arduboy. The audio library has not been carried over, so the sounds are different from the original.
#include "DATA/GILBERTINTHEDOWNLAND/GilbertintheDownland-ESP.h" //Gilbert in the Downland has been adapted from the official version on arduboy.
#include "DATA/TINYDOC/TinyDoc-ESP.h"

#define FLUID (1.2) //1.3 80mhz
#define FLUID_SETUP (1.1) //1.3 80mhz
#define Frame_Rate 12 //30 80 mhz
#define Frame_Rate_FADE 40 //30 80 mhz
#define SHOW_COMMUNITY 1



//Public Var
uint8_t MAX_VIGNETTE=20;// 16 for 17 games
//VAR SLIDE
uint8_t 
FADE_ESP=8;//0 a 8 fix
uint8_t Slide_OFF=0;
uint8_t Slide1=1;
uint8_t Slide2=2;
uint8_t SLIDE_POS;
uint8_t Contrast;
//FIN VAR SLIDE

void setup() {
//Serial.begin(115200);
WiFi.mode( WIFI_OFF );
WiFi.forceSleepBegin();
//delay( 1 );

myESPboy.begin("www.tinyjoypad.com");


//Check OTA2
//if (myESPboy.getKeys()&PAD_ACT || myESPboy.getKeys()&PAD_ESC) { 
//     terminalGUIobj = new ESPboyTerminalGUI(&myESPboy.tft, &myESPboy.mcp);
//     OTA2obj = new ESPboyOTA2(terminalGUIobj);
//}


ESP.wdtDisable();
ESP.wdtFeed();
disableWatchdog(); // Désactiver les deux WDT (soft et hard)

/*
delay( 1 );
pinMode(PIN_,OUTPUT);
pinMode(PIN_START_BUTTON,INPUT_PULLUP);
pinMode(PIN_RIGHT_BUTTON,INPUT_PULLUP);
pinMode(PIN_DOWN_BUTTON,INPUT_PULLUP);
pinMode(PIN_LEFT_BUTTON,INPUT_PULLUP);
pinMode(PIN_UP_BUTTON,INPUT_PULLUP);
*/

 display.init();
 display.flipScreenVertically();
 display.setContrast(Contrast);

 EEPROM.begin(512);
 /*
 EEPROM using Location

 -> tiny-tris (0-10)
 
 -> ARDUMANIA  (11-21)

 -> Audio Setting (9)

 -> Contrast Setting (22)

 */
}

void loop() {
ESP.wdtDisable();
ESP.wdtFeed();
//Serial.println("Mega Compilation");
//Serial.println("  Start MENU");
LOAD_Config_EEPROM();
//SPLASH
{
My_delay_ms(1000);
if (!SHOW_COMMUNITY) {MAX_VIGNETTE--;}
if (BUTTON_DOWN) {if (loop_JOYTESTER()) {if (!SHOW_COMMUNITY) {MAX_VIGNETTE++;}}}//JOY_TESTER
currentMillis=millis();
for(uint8_t t=0;t<9;t++){
ESP_SPLASH((t));
while((currentMillis-MemMillis)<Frame_Rate_FADE){
currentMillis=millis();}
MemMillis=currentMillis;}
My_delay_ms(1000);}
for(uint8_t t=0;t<9;t++){
ESP_SPLASH((8-t));}
currentMillis=millis();
for(uint8_t t=0;t<9;t++){
FADEIN_MENU(t);
while((currentMillis-MemMillis)<Frame_Rate_FADE){
currentMillis=millis();
}
MemMillis=currentMillis;
}
randomSeed(MemMillis);
MENU:;
FADE_ESP=8;
while(1){
ESP.wdtDisable();
ESP.wdtFeed();

if(myESPboy.getKeys()&PAD_RGT) {
  display.foregroundclr++;
  if(display.foregroundclr > 19) display.foregroundclr = 0;
  while(myESPboy.getKeys()) delay(10);
  delay(100);}
if(myESPboy.getKeys()&PAD_LFT) {
  display.backgroundclr++;
  if(display.backgroundclr > 19) display.backgroundclr = 0;
  while(myESPboy.getKeys()) delay(10);
  delay(100);}


if (TINYJOYPAD_RIGHT==0) {Sound_TTRICK(30,10);SLIDE_SHOW(0);SLIDE_DIRECTION(1);}
if (TINYJOYPAD_LEFT==0) {Sound_TTRICK(30,10);SLIDE_DIRECTION(0);SLIDE_SHOW(1);}
if (TINYJOYPAD_DOWN==0) {Sound_TTRICK(60,10);CONFIG_SLIDE();}
if ((TINYJOYPAD_UP==0)&&(Check_EEPROM_Slide(Slide1))) {Sound_TTRICK(60,10);EEPROM_SLIDE();}
ESP_MENU();
if (BUTTON_DOWN) {
for(uint8_t t=0;t<40;t++){
My_delay_ms(1);
if (BUTTON_UP) {goto CANCEL;} 
}

randomSeed(MemMillis);
SLIDE_SELECT();
switch(Slide1){

case (0):loop_TLANDER();break;
case (1):loop_TGILBERT();break;
case (2):loop_TTRICK();break;
case (3):loop_TINVADERS();break;
case (4):loop_TPINBALL();break;
case (5):loop_TPACMAN();break;
case (6):loop_TBOMBER();break;
case (7):loop_TBIKE();break;
case (8):loop_TBERT();break;
case (9):loop_TARKANOID();break;
case (10):loop_TTRIS();break;
case (11):loop_TPLAQUE();break;
case (12):loop_TDDUG();break;
case (13):loop_TMISSILE();break;
case (14):loop_TMORPION();break;
case (15):loop_TPIPE();break;
case (16):loop_TSQUEST();break;
case (17):loop_ARDUMANIA();break;
case (18):loop_NOHZDYVE();break;
case (19):loop_GILBERTINTHEDOWNLAND();break;
case (20):loop_TDOC();break;
default:goto CANCEL;break;
}
CANCEL:;
}}
goto MENU;
}

void disableWatchdog() {
  ESP.wdtDisable();           // Désactive le WDT logiciel
  *((volatile uint32_t*)0x60000900) &= ~(1); // Désactive le WDT matériel (registre spécifique ESP8266/ESP8285)
}

uint8_t Check_EEPROM_Slide(uint8_t Val_){
  switch(Val_){
   case 10:
   case 17:return 1;break;
   default:return 0;break;
  }
}

void FADEIN_MENU(uint8_t FRm){
uint8_t y=0;
uint8_t x=0; 
uint8_t RETURN_BYTE_MENU;
for (y = 0; y < 8; y++){   
for (x = 0; x < 128; x++){
if ((x%2)==0) {
RETURN_BYTE_MENU=pgm_read_byte(&MENU_FADE[(FRm*2)]);}else{
RETURN_BYTE_MENU=pgm_read_byte(&MENU_FADE[(FRm*2)+1]);}
display.buffer[(x+(y*128))]=blitzSprite(0,0,x,y,Slide1,MENU_VIGNETTE)&RETURN_BYTE_MENU;
}}
display.display();   
}

void ESP_SPLASH(uint8_t FRm){
uint8_t y=0;
uint8_t x=0; 
uint8_t RETURN_BYTE_MENU;
for (y = 0; y < 8; y++){   
for (x = 0; x < 128; x++){
if ((x%2)==0) {
RETURN_BYTE_MENU=pgm_read_byte(&MENU_FADE[(FRm*2)]);}else{
RETURN_BYTE_MENU=pgm_read_byte(&MENU_FADE[(FRm*2)+1]);}
display.buffer[(x+(y*128))] =(blitzSprite(0,0,x,y,0,INTRO_MENU)|recupe_VERSION_MEGA(x,y))&(RETURN_BYTE_MENU);
}}
display.display();  
}


void SLIDE_SELECT (void){
while(1) {
ESP_MENU();
while((currentMillis-MemMillis)<Frame_Rate_FADE){
currentMillis=millis();
}
MemMillis=currentMillis;
if (FADE_ESP==0) {FADE_ESP=8;goto ENDING;}
FADE_ESP=(FADE_ESP>0)?FADE_ESP-1:0; 
}
ENDING:;
My_delay_ms(1000);
}

void ESP_CONFIG_FLIP(uint8_t FRm){
uint8_t y=0;
uint8_t x=0; 
for (y = 0; y < 8; y++){   
for (x = 0; x < 128; x++){
display.buffer[(x+(y*128))] =( (blitzSprite(0,FRm,x,y,0,SETUP))|((blitzSprite(0,0,x,y,Slide1,MENU_VIGNETTE))&(0xff-blitzSprite(0,FRm,x,y,1,SETUP))));
}}
display.display();  
}

void ESP_CONFIG_SET(uint8_t FRm){
uint8_t y=0;
uint8_t x=0; 
for (y = 0; y < 8; y++){   
for (x = 0; x < 128; x++){
display.buffer[(x+(y*128))] =((blitzSprite(0,0,x,y,0,SETUP))&(0xff-blitzSprite(FRm,7,x,y,0,Trackbar)));
}}
display.display();  
}

void CONFIG_SLIDE(void){
uint8_t Switch=1;
uint8_t Pos_TrackBar=85;
uint8_t Speed_0=64;
uint8_t LOOP=64;
if (SOUND_ON_OFF==HIGH) {Pos_TrackBar=50;}
while(1){
ESP_CONFIG_FLIP(Speed_0); 
if (Speed_0>0) {Speed_0=Speed_0/FLUID_SETUP;}else{break;}
}
My_delay_ms(33);
do {ESP.wdtDisable();
ESP.wdtFeed();}while(TINYJOYPAD_DOWN==0);
My_delay_ms(33);
do {ESP.wdtDisable();
ESP.wdtFeed();}while(TINYJOYPAD_DOWN==0);
while(1){
ESP.wdtDisable();
ESP.wdtFeed();
if (TINYJOYPAD_DOWN==0) {if (Switch==1) {SOUND_ON_OFF=(Pos_TrackBar==50)?HIGH:LOW;goto END;}}
if (TINYJOYPAD_RIGHT==0) {Switch=2;}
if (TINYJOYPAD_LEFT==0)  {Switch=0;}
if (TINYJOYPAD_UP==0) {
while((TINYJOYPAD_UP==0)||(BUTTON_DOWN)){
ESP.wdtDisable();
ESP.wdtFeed();
ESP_CONFIG_CONTRAST_FLIP();

My_delay_ms(11);
if (BUTTON_DOWN) {
  if (Contrast<255) {Contrast++;if ((Contrast==255)||(Contrast==1)){My_delay_ms(300);}}else{Contrast=0;}
  display.setContrast(Contrast);
  }}}
if (BUTTON_DOWN) {
if (Switch==1) {
for (LOOP=0;LOOP<50;LOOP++) {
if (BUTTON_UP) {goto CONT;}
My_delay_ms(33);
}
SOUND_ON_OFF=(Pos_TrackBar==50)?HIGH:LOW;
save_Config_EEPROM();
SAVE_FLIP(Pos_TrackBar);
My_delay_ms(1000);
goto END;
}}
CONT:;
switch(Switch){
case 0:if (Pos_TrackBar>50) {Pos_TrackBar--;}else{Switch=1;};break;
case 1:break;
case 2:if (Pos_TrackBar<85) {Pos_TrackBar++;}else{Switch=1;};break;
}
ESP_CONFIG_SET(Pos_TrackBar);
while((currentMillis-MemMillis)<(Frame_Rate/4)){
currentMillis=millis();}
MemMillis=currentMillis;
}  
END:;
Speed_0=64;
while(1){
ESP.wdtDisable();
ESP.wdtFeed();
ESP_CONFIG_FLIP(64-Speed_0); 
if (Speed_0>0) {Speed_0=Speed_0/FLUID_SETUP;}else {break;}
}
while(TINYJOYPAD_DOWN==0){ESP.wdtDisable();
ESP.wdtFeed();}
}

uint8_t RecupContrast(uint8_t x,uint8_t y){
  //14-114
uint8_t ContVal=map(Contrast,0,255,14,114);
if (y==2) {
if ((x>13)&&(x<ContVal)) return 0b11000011;
}
return 0xff;
}

void ESP_CONFIG_CONTRAST_FLIP(void){
uint8_t y=0;
uint8_t x=0; 
for (y = 0; y < 8; y++){   
for (x = 0; x < 128; x++){
display.buffer[(x+(y*128))] =((blitzSprite(0,0,x,y,0,Contrast_Pic))&(RecupContrast(x,y)));
}}
display.display();  
}

void SAVE_FLIP(uint8_t FRm){
uint8_t y;
uint8_t x,LooP;
uint8_t BYTE_=0; 
for (LooP = 0; LooP < 20; LooP++){  
for (y = 0; y < 8; y++){   
for (x = 0; x < 128; x++){
display.buffer[(x+(y*128))] = blitzSprite(0,0,x,y,0,SETUP);
BYTE_=blitzSprite(FRm,7,x,y,0,Trackbar);
if ((LooP%2)!=0) {BYTE_|=blitzSprite(64,32,x,y,0,Saved);}
display.buffer[(x+(y*128))] &=(0xff-(BYTE_));
}}
display.display();  
My_delay_ms(15);
}
}

void ESP_EEPROM_FLIP(uint8_t FRm){
uint8_t y=0;
uint8_t x=0; 
for (y = 0; y < 8; y++){   
for (x = 0; x < 128; x++){
display.buffer[(x+(y*128))] =( (blitzSprite(0,FRm,x,y,0,CLEAR_EEPROM))|((blitzSprite(0,0,x,y,Slide1,MENU_VIGNETTE))&(0xff-blitzSprite(0,FRm,x,y,1,CLEAR_EEPROM))));
}}
display.display();  
}

void ESP_EEPROM_SET(uint8_t FRm){
uint8_t y=0;
uint8_t x=0; 
for (y = 0; y < 8; y++){   
for (x = 0; x < 128; x++){
display.buffer[(x+(y*128))] = blitzSprite(0,0,x,y,0,CLEAR_EEPROM);
if (FRm==1) display.buffer[(x+(y*128))] &= (0xff-blitzSprite(61,11,x,y,0,LONG_PRESS));
}}
display.display();  
}

void EEPROM_SLIDE(void){
uint8_t TRIG_=0;
uint8_t Speed_0=64;
uint8_t LOOP=0;
while(1){
ESP_EEPROM_FLIP((64-Speed_0)-64); 
if (Speed_0>0) {Speed_0=Speed_0/FLUID_SETUP;}else{break;}
}
My_delay_ms(33);
do {ESP.wdtDisable();
ESP.wdtFeed();}while(TINYJOYPAD_UP==0);
while(1){
ESP.wdtDisable();
ESP.wdtFeed();
if (TINYJOYPAD_UP==0) {goto END;}
if (TINYJOYPAD_RIGHT==0) {TRIG_=1;}else{TRIG_=0;}
if (BUTTON_DOWN) {
if (TRIG_==1) {
for (LOOP=0;LOOP<90;LOOP++) {
if (BUTTON_UP) {goto ByPass;}
My_delay_ms(33);
}
EEPROM_CLEAR_FLIP();
WRITE_CLEAR_EEPROM();
My_delay_ms(1000);
goto END;
}
ByPass:;
}
ESP_EEPROM_SET(TRIG_);
}  
END:;
Speed_0=64;
while(1){
  ESP.wdtDisable();
ESP.wdtFeed();
ESP_EEPROM_FLIP(Speed_0-64); 
if (Speed_0>0) {Speed_0=Speed_0/FLUID_SETUP;}else {break;}
}
while(TINYJOYPAD_UP==0){ESP.wdtDisable();
ESP.wdtFeed();}
}

void EEPROM_CLEAR_FLIP(void){
uint8_t y=0;
uint8_t x=0; 
uint8_t LooP=0; 
uint8_t BYTE_=0;
for (LooP = 0; LooP < 20; LooP++){  
for (y = 0; y < 8; y++){   
for (x = 0; x < 128; x++){
if ((LooP%2)!=0) {BYTE_=blitzSprite(61,11,x,y,0,LONG_PRESS);}else{BYTE_=0x00;}
display.buffer[(x+(y*128))] =( (blitzSprite(0,0,x,y,0,CLEAR_EEPROM)) & (0xff-BYTE_) );
}}
My_delay_ms(15);
display.display(); 
}}

void WRITE_CLEAR_EEPROM(void){
uint8_t t;
switch(Slide1){
//tiny-tris (0-10)
case 9:for (t=0;t<11;t++){EEPROM.write(t,0);}break;

//ARDUMANIA  (11-21)
case 16:for (t=11;t<22;t++){EEPROM.write(t,0);}break;
default:break;
}
//Reset Audio Setting (9) (0=OFF/1=ON)
//EEPROM.write(9,1);
//SOUND_ON_OFF=HIGH;
EEPROM.commit();
}

void LOAD_Config_EEPROM(void){
uint8_t TMP;
TMP=EEPROM.read(9);
Contrast=EEPROM.read(22);
display.setContrast(Contrast);
if (TMP>0) {SOUND_ON_OFF=HIGH;}else{SOUND_ON_OFF=LOW;}
}

void save_Config_EEPROM(void){
EEPROM.write(9,SOUND_ON_OFF);
EEPROM.write(22,Contrast);
EEPROM.commit();
}

void SLIDE_SHOW(uint8_t Direct){
if (Direct==0) {SLIDE_POS=127;}else{SLIDE_POS=0;}
float Speed_0=128;
while(1){
  ESP.wdtDisable();
ESP.wdtFeed();
Slide_OFF=1;
if (Direct==1) {if (SLIDE_POS<127) {SLIDE_POS=(128-Speed_0); }else {SLIDE_POS=128;goto STOP;}}else{if ((SLIDE_POS)>0) {SLIDE_POS=Speed_0;} else {SLIDE_POS=0;goto STOP;}}
Speed_0=Speed_0/FLUID;
while((currentMillis-MemMillis)<Frame_Rate){
currentMillis=millis();
}
MemMillis=currentMillis;
ESP_MENU();  
}
STOP:;
Slide_OFF=0;
}

void SLIDE_DIRECTION(uint8_t Direct){
if (Direct==0) {
  Slide1=(Slide1>0)?Slide1-1:MAX_VIGNETTE;
  Slide2=(Slide2>0)?Slide2-1:MAX_VIGNETTE;
}else{
Slide1=(Slide1<MAX_VIGNETTE)?Slide1+1:0; 
Slide2=(Slide2<MAX_VIGNETTE)?Slide2+1:0; 
}}

void ESP_MENU(void){
uint8_t y=0;
uint8_t x=0; 
for (y = 0; y < 8; y++){   
for (x = 0; x < 128; x++){
display.buffer[(x+(y*128))]=Recupe(x,y);
}}
display.display();  
}

uint8_t blitzSprite(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES){
uint8_t OUTBYTE;
uint8_t WSPRITE=(pgm_read_byte(&SPRITES[0]));
uint8_t HSPRITE=(pgm_read_byte(&SPRITES[1]));
uint16_t Wmax=((HSPRITE*WSPRITE)+1);
uint16_t PICBYTE=FRAME*(Wmax-1);
int8_t RECUPELINEY=RecupeLineY_TDDUG(yPos);
if ((xPASS>((xPos+(WSPRITE-1))))||(xPASS<xPos)||((RECUPELINEY>yPASS)||((RECUPELINEY+(HSPRITE))<yPASS))) {return 0x00;}
int8_t SPRITEyLINE=(yPASS-(RECUPELINEY));
uint8_t SPRITEyDECALAGE=(RecupeDecalageY_TDDUG(yPos));
uint16_t ScanA=(((xPASS-xPos)+(SPRITEyLINE*WSPRITE))+2);
uint16_t ScanB=(((xPASS-xPos)+((SPRITEyLINE-1)*WSPRITE))+2);
if (ScanA>Wmax) {OUTBYTE=0x00;}else{OUTBYTE=SplitSpriteDecalageY_TDDUG(SPRITEyDECALAGE,pgm_read_byte(&SPRITES[ScanA+(PICBYTE)]),1);}
if ((SPRITEyLINE>0)) {
uint8_t OUTBYTE2=SplitSpriteDecalageY_TDDUG(SPRITEyDECALAGE,pgm_read_byte(&SPRITES[ScanB+(PICBYTE)]),0);
if (ScanB>Wmax) {return OUTBYTE;}else{return OUTBYTE|OUTBYTE2;}
}else{return OUTBYTE;}
}

uint8_t Recupe(uint8_t xPASS,uint8_t yPASS){
uint8_t BYTE_0;
uint8_t SHADE;
uint8_t Y_POSSITION=map(SLIDE_POS,0,128,0,64);
if ((xPASS%2)==0) {SHADE=pgm_read_byte(&MENU_FADE[FADE_ESP*2]);}else{SHADE=pgm_read_byte(&MENU_FADE[(FADE_ESP*2)+1]);}
if (Slide_OFF==0) {
BYTE_0=0x00;
Y_POSSITION=64;
SLIDE_POS=128;
}else{
BYTE_0=blitzSprite(SLIDE_POS,Y_POSSITION,xPASS,yPASS,Slide2,MENU_VIGNETTE);
}
return  SHADE&(((blitzSprite(SLIDE_POS-128,64-Y_POSSITION,xPASS,yPASS,Slide1,MENU_VIGNETTE))|(BYTE_0)));
}

uint8_t recupe_VERSION_MEGA(uint8_t xPASS,uint8_t yPASS){
  if (xPASS<8) {return 0;}
if (xPASS>23){return 0;}
if (yPASS<7) {return 0;}
uint8_t M10000_MEGA=(FIRMWARE_VERSION/1000);
uint8_t M1000_MEGA=(((FIRMWARE_VERSION)-(M10000_MEGA*1000))/100);
uint8_t M100_MEGA=(((FIRMWARE_VERSION)-(M1000_MEGA*100)-(M10000_MEGA*1000))/10);
uint8_t M10_MEGA=(((FIRMWARE_VERSION)-(M100_MEGA*10)-(M1000_MEGA*100)-(M10000_MEGA*1000)));
return 
(
 SPEED_BLITZ_TDDUG(8,7,xPASS,yPASS,M10000_MEGA,police_MEGA)|
 SPEED_BLITZ_TDDUG(12,7,xPASS,yPASS,M1000_MEGA,police_MEGA)|
 SPEED_BLITZ_TDDUG(16,7,xPASS,yPASS,M100_MEGA,police_MEGA)|
 SPEED_BLITZ_TDDUG(20,7,xPASS,yPASS,M10_MEGA,police_MEGA));
}
