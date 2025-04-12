// >>> A-R-D-U-M-A-N-I-A for ESP8285/ESP8266 relicensed under GPLv3 <<<
//   (Based on Ardumania on ARDUBOY originally on (MIT) License)
//   If you are looking for the MIT version of the source code,
//   refer to my original source code for Arduboy.
//               https://www.tinyjoypad.com/arduboy

//                    Programmer: Daniel C 2024
//             Contact EMAIL: electro_l.i.b@tinyjoypad.com
//  https://github.com/phoenixbozo/TinyJoypad/tree/main/TinyJoypad
//                    https://WWW.TINYJOYPAD.COM
//          https://sites.google.com/view/arduino-collection

//  Ardumania is free software: you can redistribute it and/or modify
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
/*
      Check out my website for other interesting projects!
                      Ardumania (MEGA TinyJoypad)
               Email: electro_l.i.b@tinyjoypad.com
  https://github.com/phoenixbozo/TinyJoypad/tree/main/TinyJoypad
                    https://WWW.TINYJOYPAD.COM
          https://sites.google.com/view/arduino-collection
*/


#ifndef ENGINEAMANIA_H
#define ENGINEAMANIA_H

#include "SpriteAMania.h"  //Part of Ardumania source code
#include "../MEGA_LIB/ESPKIT.h"        //Compatibility library for MEGATinyjoypad (Electro L.I.B)

extern ALVL Level;

//#define TINYJOYPAD_LEFT  (digitalRead(PIN_LEFT_BUTTON))
//#define TINYJOYPAD_RIGHT (digitalRead(PIN_RIGHT_BUTTON))
//#define TINYJOYPAD_DOWN (digitalRead(PIN_DOWN_BUTTON))
//#define TINYJOYPAD_UP  (digitalRead(PIN_UP_BUTTON))

//#define BUTTON_DOWN (digitalRead(PIN_START_BUTTON)==0)
//#define BUTTON_UP (digitalRead(PIN_START_BUTTON)==1)

//PROTOTYPE
void InitCamGrid(void) ;
void loop_ARDUMANIA() ;
uint16_t ArduMap(float x, float in_min, float in_max, float out_min, float out_max) ;
void InitFirstBoot(void) ;
void InitFrameRepeat(void);
void InitNewGame(void);
void InitResetPos(void) ;
void InitHSVar(void) ;
void InitGamePlay(uint8_t Lvl_) ;
void FILLSCREENSHADE(void) ;
void GreenOn(void) ;
void GreenOff(void) ;
void RedOn(void) ;
void RedOff(void) ;
void LEDOFF(void) ;
void Snd_Drive(void) ;
void Delay_SND(uint16_t Tm_) ;
void FakeLoad(void) ;
void BootIntro(void) ;
void Fail(void) ;
void DrawBar(uint8_t Scr) ;
void DrawArduMania(uint8_t Scr) ;
void Menu(void) ;
void ForcedSaveEEPROM(void) ;
void CheckNewHighScore(void) ;
void ClassementHighScore() ;
uint8_t READEEPROM(uint8_t Adress_);
uint8_t CheckMarqueurEEPROM(void) ;
void SaveMarqueurEEPROM(void) ;
void LoadSlotEEPROM(uint8_t Slot_) ;
void SaveSlotEEPROM(uint8_t Slot_, uint8_t Avatar_, uint16_t Valeur) ;
void LoadHighScoreData(void) ;
void RestHighScore(void) ;
void ScoreMenu(void) ;
void AnimLvlChange(void) ;
void ScorePannel(uint8_t x_, uint8_t y_) ;
void Pannel(void) ;
void CalculateNum(void) ;
void CheckGob(uint8_t a, uint8_t b) ;
void ActivateHighSpeed(void) ;
void ProgramExitMode(uint8_t EXITMODE, uint8_t FADE_INOUT) ;
uint8_t ExitTime(void) ;
void FrameRedundancy(void) ;
void Fade_SCR(void) ;
void GobFruit(void) ;
void ONEUP(void) ;
void UpdateFruitDelivery(void) ;
void LiberateFruit(void) ;
void Snd(uint8_t f_,uint8_t D_);
void SoundSystem(uint8_t Val_) ;
void deadSound(void) ;
void GhostJumpCalculate(void) ;
uint8_t AnimateDeadMania(void) ;
void RCupDeadAnim(void) ;
void RefreshMovingArdu(void) ;
void CheckPadFunction(void) ;
uint8_t MaskUse(void) ;
void LoopScreen(int8_t* x_) ;
uint8_t GhostTime(uint8_t t_) ;
void RefreshTimers(void) ;
void RemoveDot(void) ;
void SwitchModeGhost(uint8_t Tested_, uint8_t Set_) ;
void GhostUturn(uint8_t t) ;
uint8_t collision(void) ;
void GhostRespawn(uint8_t val_) ;
void GhostDirectionChoser(void) ;
uint8_t RNDGhost(uint8_t t_) ;
uint8_t TrackObjectifX(uint8_t Val_) ;
uint8_t TrackObjectifY(uint8_t Val_) ;
uint8_t GateExit(uint8_t Val_) ;
void GhostRight(uint8_t t) ;
void GhostLeft(uint8_t t) ;
void GhostUp(uint8_t t);
void GhostDown(uint8_t t) ;
void RefreshMovingGhost(void) ;
uint8_t RandVar(void) ;
uint8_t FruitActif(int8_t x_, int8_t y_) ;
void InitLevelBuffer(void) ;
uint16_t Total_Dot_Count_test(void) ;
void BigDotAssign(void) ;
void Initialize2Bits(int8_t x_, int8_t y_) ;
uint8_t Read2Bits(int8_t x_, int8_t y_) ;
void Define2Bits(int8_t x_, int8_t y_, uint8_t initValue) ;
void CopyLevelToMem_test(void) ;
void Reset_SpritesPos(void) ;
void RemoveDotNotUse(void) ;
void Load_Selected_Level(uint8_t level_to_Load) ;
void DeleteSerialDot(void) ;
void SetGhost(void) ;
void Center_Screen(void) ;
uint8_t RCupAnimMask(uint8_t d_) ;
int8_t RCupAnim(uint8_t d_) ;
uint8_t InvertBlock(uint8_t Lvl_) ;
void Out_Check(uint8_t* val, int8_t y) ;
uint8_t ExploreMapChose(int8_t x_, int8_t y_, uint8_t SriteType_) ;
uint8_t ExploreMap(int8_t x_, int8_t y_) ;
uint8_t Select_Byte(uint8_t y_) ;
uint8_t Select_Byte_2Bits(uint8_t y_) ;

void UP_SET(void);
void DOWN_SET(void) ;
void RIGHT_SET(void) ;
void LEFT_SET(void);
uint8_t ExploreMapChose(int8_t x_, int8_t y_, uint8_t SriteType_);
uint8_t Select_Byte(uint8_t y_);


class TIMER{
private:
uint8_t Activ;
uint8_t startTime;
uint8_t interval;
public:
void Init(uint8_t Interval_){
startTime = 0;
interval=Interval_;
Activ=0;
}
uint8_t Get_A(void){
return Activ;
}

void Activate(void){
Activ=1;
}

void DeActivate(void){
Activ=0;
}

uint8_t Trigger(void){
if (Activ==0) return 1;
if (startTime<interval) {startTime++;return 0;}else{startTime=0; return 1;}
}
};

class SpriteAmania{
private:
uint8_t SpriteType;
  int8_t SpriteDirection;
  uint8_t DirectionX;
  uint8_t DirectionY;
  int8_t GridX;
  int8_t GridY;
  int8_t DecX;
  int8_t DecY;
  uint8_t Priority;
  uint8_t PadX;
  uint8_t PadY;

  uint8_t JmpPos;
  uint8_t JmpTrig;
  uint8_t JmpSeq;
  uint8_t SpriteMode;
public:

void Init(int8_t x_,int8_t y_,uint8_t SpriteType_){
SpriteType=SpriteType_;
SpriteDirection=0;
DirectionX=2;
DirectionY=2;
GridX=x_;
GridY=y_;
DecX=0;
DecY=0;
Priority=1;
PadX=2;
PadY=2;
SpriteMode=0;
JmpPos=0;
JmpTrig=0;
JmpSeq=0;
}

void Put_SpriteMode(uint8_t Val_){SpriteMode=Val_;}
void Put_JmpPos(uint8_t Val_){JmpPos=Val_;}
void Put_JmpTrig(uint8_t Val_){JmpTrig=Val_;}
void Put_JmpSeq(uint8_t Val_){JmpSeq=Val_;}
void Put_Priority(uint8_t Val_){Priority=Val_;}
void Put_DirectionX(uint8_t val_){DirectionX=val_;}
void Put_DirectionY(uint8_t val_){DirectionY=val_;}
void Put_GridX(int8_t val_){GridX=val_;}
void Put_GridY(int8_t val_){GridY=val_;}
void Put_DecX(int8_t val_){DecX=val_;}
void Put_DecY(int8_t val_){DecY=val_;}
void Put_PadX(int8_t val_){PadX=val_;}
void Put_PadY(int8_t val_){PadY=val_;}

uint8_t Get_SpriteMode(void){return SpriteMode;}
uint8_t Get_JmpPos(void){return JmpPos;}
uint8_t Get_JmpTrig(void){return JmpTrig;}
uint8_t Get_JmpSeq(void){return JmpSeq;}
uint8_t Get_SpriteDirection(void){return SpriteDirection;}
uint8_t Get_DirectionX(void){return DirectionX;}
uint8_t Get_DirectionY(void){return DirectionY;}
int8_t Get_GridX(void){return GridX;}
int8_t Get_GridY(void){return GridY;}
int8_t Get_DecX(void){return DecX;}
int8_t Get_DecY(void){return DecY;}

void AdjustControl(void){
if (DirectionX==1) {if (PadX==0) DirectionX=0;}
if (DirectionX==0) {if (PadX==1) DirectionX=1;}
if (DirectionY==1) {if (PadY==0) DirectionY=0;}
if (DirectionY==0) {if (PadY==1) DirectionY=1;}
if ((DecX==0) && (DecY==0)) {
if (PadX!=2) DirectionX=PadX;
if (PadY!=2) DirectionY=PadY;
switch(Priority){
  case 0:if (CheckPriorityX()) CheckPriorityY();break;
  case 1:if (CheckPriorityY()) CheckPriorityX();break;
  default:break;
}}
PadX=2;
PadY=2;
}

uint8_t CheckPriorityX(void){
if (DirectionX==0) {if (ExploreMapChose(GridX-1, GridY,SpriteType)) {DirectionX=2;return 1;}else{DirectionY=2;return 0;}}
if (DirectionX==1) {if (ExploreMapChose(GridX+1, GridY,SpriteType)) {DirectionX=2;return 1;}else{DirectionY=2;return 0;}}
return 0;
}
uint8_t CheckPriorityY(void){
if (DirectionY==0) {if (ExploreMapChose(GridX, GridY-1,SpriteType)) {DirectionY=2;return 1;}else{DirectionX=2;return 0;}}
if (DirectionY==1) {if (ExploreMapChose(GridX, GridY+1,SpriteType)) {DirectionY=2;return 1;}else{DirectionX=2;return 0;}}
return 0;
}

void RefreshJump(void){
if (JmpTrig==1) {JmpPos=pgm_read_byte(&Saut[JmpSeq]);if (JmpSeq<39){JmpSeq++;}else{JmpSeq=0;JmpTrig=2;}}
}

void RefreshMove(void){
if (JmpTrig==1) {JmpPos=pgm_read_byte(&Saut[JmpSeq]);if (JmpSeq<39){JmpSeq++;}else{JmpSeq=0;JmpTrig=2;}}
switch (DirectionX) {
  case 0:GoLeft();Priority=1;return;break;
  case 1:GoRight();Priority=1;return;break;
  case 2:break;
  default:break;
}
switch (DirectionY) {
  case 0:GoUp();Priority=0;return;break;
  case 1:GoDown();Priority=0;return;break;
  case 2:break;
  default:break;
}
}

void GoUp(void){
  if ((DecX==0)&&(DecY==0)) {if (ExploreMapChose(GridX, GridY-1,SpriteType)) {DirectionY=2;return;}}
      if (DecY>((-YSTEP)+1)) {
      DecY--;}else{
      DecY=0;
      GridY--;
      }
    DecX=-(DecY>>1);
    DirectionX=2;  
     SpriteDirection=9;
}

void GoDown(void){
    if ((DecX==0)&&(DecY==0)) {if (ExploreMapChose(GridX, GridY+1,SpriteType)) {DirectionY=2;return;}}
 if (DecY<0) {
       DecY++;}else{
      DecY=(-YSTEP)+1;
      GridY++;
      }
      DecX=-(DecY>>1);
      DirectionX=2;   
      SpriteDirection=6;
}

void GoRight(void){
    if ((DecX==0)&&(DecY==0)) {if (ExploreMapChose(GridX+1, GridY,SpriteType)) {DirectionX=2;return;}}
      if (DecX<0) {
       DecX++;}else{
      DecX=(-XSTEP)+1;
      if (GridX==(Level.W-1)) {GridX=0;}else{GridX++;}
      }
      DirectionY=2;   
      SpriteDirection=0;
}

void GoLeft(void){
      if ((DecX==0)&&(DecY==0)) {if (ExploreMapChose(GridX-1, GridY,SpriteType)) {DirectionX=2;return;}}
         if (DecX>((-XSTEP)+1)) {
       DecX--;}else{
      DecX=0;
      if (GridX==(0)) {GridX=Level.W-1;}else{GridX--;}
      }
      DirectionY=2; 
        SpriteDirection=3;
      }
};

#endif
