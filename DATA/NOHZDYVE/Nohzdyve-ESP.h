// >>> N-O-H-Z-D-Y-V-E for ESP8285/ESP8266 relicensed under GPLv3 <<<
//   (Based on Nohzdyve on ARDUBOY originally on (MIT) License)
//   If you are looking for the MIT version of the source code,
//   refer to my original source code for Arduboy.
//               https://www.tinyjoypad.com/arduboy

//                    Programmer: Daniel C fStartPageND2024
//             Contact EMAIL: electro_l.i.b@tinyjoypad.com
//  https://github.com/phoenixbozo/TinyJoypad/tree/main/TinyJoypad
//                    https://WWW.TINYJOYPAD.COM
//          https://sites.google.com/view/arduino-collection

//  Nohzdyve is free software: you can redistribute it and/or modify
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
                      Nohzdyve (MEGA TinyJoypad)
               Email: electro_l.i.b@tinyjoypad.com
  https://github.com/phoenixbozo/TinyJoypad/tree/main/TinyJoypad
                    https://WWW.TINYJOYPAD.COM
          https://sites.google.com/view/arduino-collection
*/


#include "SpriteBank.h"  // Part of Nohzdyve.ino source code
#include "engineOBJ.h"   // Part of Nohzdyve.ino source code

#define MAJND 10
#define MINND 0
#define MAXSP 9     //max sprite
#define SINSTEP 37  //Number of step -1

TIMERND Tr1;   //STD anim
TIMERND Tr2;   //Explod anim
TIMERND Tr3;   //MainSinAnim and start game screen fade
TIMERND Tr4;   //JAWNDmove
TIMERND Tr5;   //JAWNDSP
TIMERND Tr6;   //GlobSinAnim
TIMERND Tr7;   //SNStepND
TIMERND Tr8;   //StartStepND
TIMERND Tr9;   //DeadStepND
TIMERND Tr10;  //GlobStepND

uint8_t FrmND = 0;
int8_t RLND = 0;
int8_t yScrollND = 0;
uint8_t SimAnim1ND = 0;  //JAWND
uint8_t SimAnim2ND = 0;  //GLOBND
uint8_t STEPSONGND = 0;
uint8_t STEPSTARTND = 0;
uint8_t STEPDEADND = 0;
uint8_t STEPGLOBND = 0;
uint8_t OneClicND = 2;
uint8_t Cnt = 0;

Sprite_ND SPND[MAXSP];
NUMND Pan1ND;

ESPCOMPATIBILITY MEGA82XXND;

TUNES tunes;


void NOHZDYVE_Setup() {
  MEGA82XXND.Init(&display);
  //ESP.wdtDisable();
  ESP.wdtFeed();
  MEGA82XXND.SetFPS(60);
}

void loop_NOHZDYVE() {
  NOHZDYVE_Setup();
  Pan1ND.HIScores = 0;
  //SplashScreenND();
Menu:;
  //srand(analogRead(A0));
  if (Pan1ND.Scores > Pan1ND.HIScores) { Pan1ND.HIScores = Pan1ND.Scores; }
  Pan1ND.Lives = 3;
  Pan1ND.Scores = 0;
  InitPan1ND();
  ResetVarND();
  SpriteSetCFGND();
  TimerConfigND();
  StartPageND();
NewLive:;
  ResetVarND();
  ExitWindowND();
  PlayGameND();
  if (Pan1ND.Lives > 0) {
    Pan1ND.Lives--;
    goto NewLive;
  } else {
    goto Menu;
  }
}



void ExitWindowND() {
  uint8_t Ex = 0;
  SPND[WINDOWND].ActivateSprite(8, 37, WINDOWND);
  tunes.tone(140, 40);
  OneClicND = 2;
  while (1) {
    //ESP.wdtDisable();
    ESP.wdtFeed();
    EraseScreenND();
    DrawLivesND();
    DrawScoreND();
    DrawSideWallsND();
    ChangePicND(&Ex);
    DrawSpritesND();
    FrameRateND();
    ScrollDownND(3);
    FlipScreenND();
    if (Ex == 1) { goto Start_game; }
    }
Start_game:;
  SPND[MAINND].ActivateSprite(SPND[SLIDEND].Get_X() + 5, SPND[SLIDEND].Get_Y(), MAINND);
  SPND[SLIDEND].Desactive();
  Tr3.Activate();
};




void PlayGameND() {
  TIMERND DELAY_RST;
  DELAY_RST.Init(255);
  Tr8.Activate();
  ResetStepSNND();
  OneClicND = 2;
  while (1) {
    //ESP.wdtDisable();
    ESP.wdtFeed();
    EraseScreenND();
    JoyPadRefreshND();
    UpDateMainND();
    GamePlayAdj();
    DrawSideWallsND();
    FrameRateND();
    CollisionCheckND();
    DrawSpritesND();
    if (SPND[MAINND].Get_A()) { ScrollDownND(1); }

    if (SPND[MAINND].Get_A() == 0) {

      if (Pan1ND.Lives == 0) { MEGA82XXND.drawSelfMasked(42, 42, &GameOverND[0], 0); }
      if ((BUTTON_DOWN) && (OneClicND == 0) && (!Tr9.Get_A())) {
        OneClicND = 2;

        goto Reset_;
      }
      if ((BUTTON_UP) && (OneClicND == 2)) { OneClicND = 0; }
    }
  
    DrawScoreND();
    DrawLivesND();
    FlipScreenND();
    PlaySongND();
  }
Reset_:;
};

void GamePlayAdj() {
  LibarateSpriteND();
  ExplodLogisticND();
  CleanOverScanND();
  RefreshMoveJAWND();
}

void SpriteSetCFGND() {
  for (uint8_t t = 0; t < MAXSP; t++) { SPND[t].Init(); }
}

void TimerConfigND() {
  Tr1.Init(3);
  Tr1.Activate();
  Tr2.Init(4);
  Tr2.Activate();
  Tr3.Init(2);
  Tr3.Activate();
  Tr4.Init(1);
  Tr4.Activate();
  Tr5.Init(2);
  Tr5.Activate();
  Tr6.Init(2);
  Tr6.Activate();
  Tr7.Init(7);
  Tr8.Init(1);
  Tr9.Init(1);
  Tr10.Init(1);
}

void InitPan1ND(void) {  //new game
  Pan1ND.ND10000 = 0;
  Pan1ND.ND1000 = 0;
  Pan1ND.ND100 = 0;
  Pan1ND.ND10 = 0;
  Pan1ND.ND1 = 0;
}

void CalculatePanND(uint16_t Scores_) {
  Pan1ND.ND10000 = (Scores_ / 10000);
  Pan1ND.ND1000 = (((Scores_) - (Pan1ND.ND10000 * 10000)) / 1000);
  Pan1ND.ND100 = (((Scores_) - (Pan1ND.ND1000 * 1000) - (Pan1ND.ND10000 * 10000)) / 100);
  Pan1ND.ND10 = (((Scores_) - (Pan1ND.ND100 * 100) - (Pan1ND.ND1000 * 1000) - (Pan1ND.ND10000 * 10000)) / 10);
  Pan1ND.ND1 = ((Scores_) - (Pan1ND.ND10 * 10) - (Pan1ND.ND100 * 100) - (Pan1ND.ND1000 * 1000) - (Pan1ND.ND10000 * 10000));
}

void ScorePannelND(uint8_t x_, uint8_t y_) {
#define INVERT 0
  MEGA82XXND.drawInvertPixel(22 + x_, y_, &NUMERICND[0], Pan1ND.ND1);
  MEGA82XXND.drawInvertPixel(18 + x_, y_, &NUMERICND[0], Pan1ND.ND10);
  MEGA82XXND.drawInvertPixel(14 + x_, y_, &NUMERICND[0], Pan1ND.ND100);
  MEGA82XXND.drawInvertPixel(10 + x_, y_, &NUMERICND[0], Pan1ND.ND1000);
  MEGA82XXND.drawInvertPixel(6 + x_, y_, &NUMERICND[0], Pan1ND.ND10000);
}

uint16_t NoteND[6] = { 1, 21, 41, 61, 91, 121 };


void ResetStepSNND() {
  STEPSONGND = 0;
  STEPSTARTND = 0;
  STEPDEADND = 0;
  STEPGLOBND = 0;
}

void PlayINGameND() {
  if (Tr7.Trigger()) {
    tunes.tone(NoteND[pgm_read_byte(&StepListND[STEPSONGND])], 20);
    STEPSONGND = (STEPSONGND < 31) ? STEPSONGND + 1 : 0;
  }
}

void PlaySongND() {
  StartToneND();
  DeadToneND();
  GlobToneND();
  PlayINGameND();
}

uint16_t StartTone[18] = {
  100, 100, 100, 100, 100, 100,
  1, 1, 1, 1, 1, 1,0
};

void StartToneND() {
  if (Tr8.Trigger()) {
    tunes.tone(StartTone[STEPSTARTND], 10);
    if (STEPSTARTND < 12) {
      STEPSTARTND++;
    } else {
      Tr8.DeActivate();
      Tr7.Activate();
    }
  }
}

void DeadToneND() {
  if (Tr9.Get_A()) {
    if (STEPDEADND % 2) {
      tunes.tone(210 - (STEPDEADND * 5), 10);
    } else {
    }
    if (STEPDEADND < 40) {
      STEPDEADND++;
    } else {
      Tr9.DeActivate();
    }
  }
}

void GlobToneND() {
  if (Tr10.Get_A()) {
    if (STEPGLOBND % 2) {
      tunes.tone(1, 1);
    } else {
      tunes.tone((STEPGLOBND * 10), 1);
    }
    if (STEPGLOBND < 14) {
      STEPGLOBND++;
    } else {
      Tr10.DeActivate();
    }
  }
}

void SplashScreenND() {
  EraseScreenND();
  MEGA82XXND.drawSelfMasked(0, 0, &TinyJoypadND[0], 0);
  MEGA82XXND.display();
  myDelay(2000);
  Merge2PicND(&TinyJoypadND[0], &Loading1ND[0]);
  for (uint16_t t = 0; t < 30; t++) {
    EraseScreenND();
    MEGA82XXND.drawSelfMasked(0, 0, &Loading1ND[0], 0);
    MEGA82XXND.display();
    tunes.tone(200, 20);
    EraseScreenND();
    MEGA82XXND.drawSelfMasked(0, 0, &Loading2ND[0], 0);
    MEGA82XXND.display();
    tunes.tone(220, 20);
  }
  Merge2PicND(&Loading2ND[0], &Pic2ND[0]);
  myDelay(1000);
  Merge2PicND(&Pic2ND[0], &PaxND[0]);
  myDelay(1000);
  Merge2PicND(&PaxND[0], &selectND[0]);
  SelectND();
}

void SelectND() {
  uint8_t Chose_ = 2;
  myDelay(500);
  for (uint8_t t = 0; t < 65; t++) {
    //ESP.wdtDisable();
    ESP.wdtFeed();
    MEGA82XXND.sBuffer(((5 * 128) + t), MEGA82XXND.RBuffer(((5 * 128) + t)) & 0x00);
    MEGA82XXND.sBuffer(((5 * 128) + (128 - t)), MEGA82XXND.RBuffer(((5 * 128) + (128 - t))) & 0x00);
    if (Chose_ == 2) {
      if (TINYJOYPAD_LEFT == 0) {
        Chose_ = 0;
        MEGA82XXND.drawSelfMasked(8, 56, &choselineND[0], 0);
      }
      if (TINYJOYPAD_RIGHT == 0) {
        Chose_ = 1;
        MEGA82XXND.drawSelfMasked(78, 56, &choselineND[0], 0);
      }
    }
    myDelay(10);
    MEGA82XXND.display();
  }
  myDelay(600);
  if (Chose_ != 2) {
    MEGA82XXND.fillScreen(0xff);
    MEGA82XXND.drawOverwrite(32, 0, &VideoCodeND[0], 0);
    MEGA82XXND.display();
    myDelay(2000);
  }
}

uint8_t RecupeFadePosND(uint8_t *scan_, uint8_t Frame_) {
  uint8_t Ret_ = pgm_read_byte(&fadeND[*scan_ + (8 * Frame_)]);
  *scan_ = (*scan_ < 8) ? *scan_ + 1 : 0;
  return Ret_;
}

void Merge2PicND(const uint8_t *pic1_, const uint8_t *pic2_) {
  EraseScreenND();
  uint8_t SCAN_ = 0;
  uint8_t Mem1_ = 0;
  for (uint8_t f_ = 0; f_ < 10; f_++) {
    for (uint8_t y = 0; y < 8; y++) {
      for (uint8_t x = 0; x < 128; x++) {
        //ESP.wdtDisable();
        ESP.wdtFeed();
        uint16_t ByTe = (x + (128 * y));
        Mem1_ = RecupeFadePosND(&SCAN_, f_);
        MEGA82XXND.sBuffer(ByTe, (pgm_read_byte(&pic1_[ByTe + 2]) & (0xff - Mem1_)) | (pgm_read_byte(&pic2_[ByTe + 2]) & Mem1_));
      }
    }
    MEGA82XXND.display();
    myDelay(60);
  }
}

void ResetVarND(void) {
  yScrollND = 0;
  FrmND = 0;
  RLND = 0;
  SimAnim1ND = 0;
  SimAnim2ND = 0;
  for (uint8_t t_ = 0; t_ < MAXSP; t_++) {
    //ESP.wdtDisable();
    ESP.wdtFeed();
    SPND[t_].Desactive();
  }
  SPND[CLIMND].ActivateSprite(107, 41, CLIMND);
}

void ChangePicND(uint8_t *Exit_) {
  if (SPND[WINDOWND].Get_Y() < 30) {
    SPND[WINDOWND].Put_AnimFrame(2);
  } else if (SPND[WINDOWND].Get_Y() < 36) {
    SPND[WINDOWND].Put_AnimFrame(1);
  } else {
    SPND[WINDOWND].Put_AnimFrame(0);
  }
  if (SPND[WINDOWND].Get_Y() == 30) { SPND[SLIDEND].ActivateSprite(12, 30, SLIDEND); }
  if (SPND[SLIDEND].Get_A()) {
    if (SPND[SLIDEND].Get_X() < 64) {
      SPND[SLIDEND].Put_X(SPND[SLIDEND].Get_X() + 1);
    } else {
      *Exit_ = 1;
      goto End_;
    }
  }
  if (SPND[SLIDEND].Get_X() > 20) {
    MEGA82XXND.drawSelfMasked(SPND[SLIDEND].Get_X() - 18, SPND[SLIDEND].Get_Y(), &SlideMainPND[0], 1);
  }
End_:;
}

void Explod_MainND(void) {
  if (SPND[0].Get_Type() != 7) {
    Tr7.DeActivate();
    Tr3.DeActivate();
    Tr9.Activate();
    SPND[0].Destroy();
  }
}

void Explod_GlobND(void) {
  if (SPND[1].Get_Type() != 7) {
    AdjustScoreND();
    Tr6.DeActivate();
    STEPGLOBND = 0;
    Tr10.Activate();
    SPND[1].Destroy();
  }
}

void AdjustScoreND() {
  Pan1ND.Scores += 10;
}

void DrawLivesND(void) {
  for (uint8_t t = 0; t < Pan1ND.Lives; t++) {
    //ESP.wdtDisable();
    ESP.wdtFeed();
    MEGA82XXND.drawInvertPixel(12 + (t * 4), 1, &HARTND[0], 0);
  }
}

void DrawScoreND(void) {
  MEGA82XXND.drawInvertPixel(25, 0, &SCOREND[0], 0);
  CalculatePanND(Pan1ND.Scores);
  ScorePannelND(41, 0);
  MEGA82XXND.drawInvertPixel(75, 0, &SCOREND[0], 1);
  CalculatePanND(Pan1ND.HIScores);
  ScorePannelND(91, 0);
}

void CollisionCheckND(void) {
  WallCollisionCheckMainND();
  Main2SolidND();
  Main2GlobND();
}

void Main2SolidND() {
  if (SPND[MAINND].Get_A() == 0) return;
  if (SPND[MAINND].Get_Type() == 7) return;
  if (ColidCheckND(SPND[MAINND].Get_X(), SPND[MAINND].Get_Y() + pgm_read_byte(&SinWavND[SimAnim1ND]), SPND[JAWND].Get_X(), SPND[JAWND].Get_Y(), 12, 14)) {
    if (SPND[JAWND].Get_A()) Explod_MainND();
  }
  if (ColidCheckND(SPND[MAINND].Get_X(), SPND[MAINND].Get_Y() + pgm_read_byte(&SinWavND[SimAnim1ND]), SPND[PLANTND].Get_X(), SPND[PLANTND].Get_Y(), 7, 14)) {
    if (SPND[PLANTND].Get_A()) Explod_MainND();
  }
  if (ColidCheckND(SPND[MAINND].Get_X(), SPND[MAINND].Get_Y() + pgm_read_byte(&SinWavND[SimAnim1ND]), SPND[CLIMND].Get_X(), SPND[CLIMND].Get_Y(), 8, 14)) {
    if (SPND[CLIMND].Get_A()) Explod_MainND();
  }
}

void Main2GlobND() {
  if (SPND[MAINND].Get_A() == 0) return;
  if (SPND[MAINND].Get_Type() == 7) return;
  if (ColidCheckND(SPND[MAINND].Get_X(), SPND[MAINND].Get_Y() + pgm_read_byte(&SinWavND[SimAnim1ND]), SPND[GLOBND].Get_X() + pgm_read_byte(&SinWavND[SimAnim2ND]), SPND[GLOBND].Get_Y(), 8, 14)) { Explod_GlobND(); }
}

uint8_t ColidCheckND(int8_t x, int8_t y, int8_t x2, int8_t y2, uint8_t MargingX, uint8_t MargingY) {
  if (x > (x2 + (MargingX))) return 0;
  if (y > (y2 + (MargingY))) return 0;
  if ((x + 7) < x2) return 0;
  if ((y + 13) < y2) return 0;
  return 1;
}

void WallCollisionCheckMainND(void) {
  int8_t XM = SPND[MAINND].Get_X();
  if (XM < 8) Explod_MainND();
  if (XM > 110) Explod_MainND();
}

void RefreshMoveJAWND() {
  if (Tr4.Trigger()) { SPND[JAWND].MoveXND(); }
  if (Tr5.Trigger()) { SPND[JAWND].SPY(); }
}

void LibarateSpriteND() {
  LiberateWallSpriteND();
  if (SPND[MAINND].Get_A()) {
    LiberateJawND();
    LiberateGlobND();
  }
  LiberateLineND();
}

void LiberateLineND() {
  if (SPND[LINEND].Get_A()) return;
  if (((rand() % 100) > 75) && (yScrollND == -63)) {
    SPND[LINEND].ActivateSprite(12, YLINENDSETND(), LINEND);
    SPND[LINEND].Put_AnimFrame(rand() % 4);
  }
}

int8_t YLINENDSETND(void) {
  return yScrollND + 127;
}

void LiberateJawND() {
  if (SPND[JAWND].Get_A()) return;
  SPND[JAWND].ActivateSprite(JAWNDSTARTPOSND(), 106, JAWND);
}

int8_t JAWNDSTARTPOSND() {
  return (rand() % 92) + 10;
}

void LiberateGlobND() {
  if (SPND[GLOBND].Get_A()) return;
  SPND[GLOBND].ActivateSprite(GLOBDSTARTPOSND(), 74, GLOBND);
  Tr6.Activate();
}

int8_t GLOBDSTARTPOSND() {
  return (rand() % 70) + 25;
}

void LiberateWallSpriteND() {
  if (SPND[CLIMND].Get_A()) return;
  if (SPND[PLANTND].Get_A()) return;
  if (rand() % 2) {
    SPND[CLIMND].ActivateSprite(XCLIMNDSETND(), YCLIMNDSETND(), CLIMND);
  } else {
    SPND[PLANTND].ActivateSprite(XPLANTNDSETND(), YPLANTNDSETND(), PLANTND);
  }
}

int8_t XPLANTNDSETND() {
  if (rand() % 2) {
    return 11;
  } else {
    return 110;
  }
}

int8_t YPLANTNDSETND(void) {
  return 108 + yScrollND;
}

int8_t XCLIMNDSETND() {
  if (rand() % 2) {
    return 8;
  } else {
    return 107;
  }
}

int8_t YCLIMNDSETND(void) {
  return 105 + yScrollND;
}

void CleanOverScanND() {
  for (uint8_t t_ = 0; t_ < MAXSP; t_++) {
    if (SPND[t_].Get_A()) {
      if (SPND[t_].Get_Y() < -24) SPND[t_].Desactive();
    }
  }
}

void ExplodLogisticND() {
  uint8_t Add_ = 0;
  if (Tr2.Trigger()) {
    for (uint8_t t_ = 0; t_ < MAXSP; t_++) {
      //ESP.wdtDisable();
      ESP.wdtFeed();
      if ((SPND[t_].Get_A() == 1) && (SPND[t_].Get_Type() == EXPLODND)) {
        Add_ = SPND[t_].Get_AnimFrame();
        if (Add_ < 3) {
          Add_++;
          SPND[t_].Put_AnimFrame(Add_);
        } else {
          SPND[t_].Desactive();
        }
      }
    }
  }
}

void SinWavRunND(void) {
  if (Tr3.Trigger()) { SimAnim1ND = (SimAnim1ND < (SINSTEP)) ? SimAnim1ND + 1 : 0; }
  if (Tr6.Trigger()) { SimAnim2ND = (SimAnim2ND < (SINSTEP)) ? SimAnim2ND + 1 : 0; }
}

void UpDateMainND(void) {
  SinWavRunND();
  if (RLND == 0) return;
  if (SPND[MAINND].Get_Type() == EXPLODND) return;
  if (SPND[MAINND].Get_A() == 0) return;
  switch (RLND) {
    case (-2): SPND[MAINND].Put_X(SPND[MAINND].Get_X() - 2); break;
    case (-1): SPND[MAINND].Put_X(SPND[MAINND].Get_X() - 1); break;
    case (1): SPND[MAINND].Put_X(SPND[MAINND].Get_X() + 1); break;
    case (2): SPND[MAINND].Put_X(SPND[MAINND].Get_X() + 2); break;
    default: break;
  }
}

void JoyPadRefreshND(void) {
  if (TINYJOYPAD_RIGHT == 0) {
    RLND = 2;
  } else if (TINYJOYPAD_LEFT == 0) {
    RLND = -2;
  } else {
    if (RLND == 2) { RLND = 1; }
    if (RLND == -2) { RLND = -1; }
  }
}

void FrameRateND() {
  MEGA82XXND.FPS_Temper();
  if ((FrmND++) >60) FrmND=0;
}

void FlipScreenND() {
  MEGA82XXND.display();
  if (Tr1.Trigger()) { Cnt = (Cnt < 3) ? Cnt + 1 : 0; }
}

void DrawMainScreenND() {
  MEGA82XXND.drawSelfMasked(18, 2, nohzdyve_IntroND, 0);
}

void StartPageND() {
  uint8_t FDT = 0;
  Tr3.Activate();
  uint8_t SG = 0;
  SPND[CLIMND].ActivateSprite(107, 41, CLIMND);
  while (1) {
    //ESP.wdtDisable();
    ESP.wdtFeed();
    rand();
    EraseScreenND();
    DrawMainScreenND();
    if (SG) {
      if (FadeMainScreenND(&FDT, Tr3.Trigger()) == 1) { return; }
    } else {
      if (Cnt > 1) { MEGA82XXND.drawSelfMasked(42, 42, &StartGameND[0], 0); }
    }
    DrawSideWallsND();
    DrawSpritesND();
    FrameRateND();
    FlipScreenND();
    if ((BUTTON_DOWN) && (OneClicND == 0)) { SG = 1; }
    if (BUTTON_UP) { OneClicND = 0; }
  }
}

uint8_t FadeMainScreenND(uint8_t *FD_, uint8_t TR3_) {
  for (uint8_t y = 0; y < 4; y++) {
    for (uint8_t x = 0; x < 12; x++) {
      //ESP.wdtDisable();
      ESP.wdtFeed();
      MEGA82XXND.drawErase(18 + (x * 8), 2 + (y * 8), &fadeND[0], *FD_);
    }
  }
  if (TR3_) {
    if (*FD_ < 8) {
      (*FD_)++;
    } else {
      return 1;
    }
  }
  return 0;
}

uint8_t SelectFrameND(uint8_t t_) {
  uint8_t B_ = (SPND[t_].Get_Type() == EXPLODND) ? 7 : t_;
  switch (B_) {
    case 0 ... 3: return SPND[t_].Get_ANIM()[Cnt]; break;
    default: return SPND[t_].Get_AnimFrame(); break;
  }
}

int8_t WavAnimND(uint8_t t) {
  switch (t) {
    case (0): return pgm_read_byte(&SinWavND[SimAnim1ND]); break;
    default: return 0; break;
  }
}

int8_t WavXAnimND(uint8_t t) {
  switch (t) {
    case (1): return pgm_read_byte(&SinWavBND[SimAnim2ND]); break;
    default: return 0; break;
  }
}

void DrawSpritesND() {

  for (uint8_t t = 0; t < MAXSP; t++) {
    //ESP.wdtDisable();
    ESP.wdtFeed();
    if (SPND[t].Get_A() == 1) {
      switch (t) {
        case (LINEND): MEGA82XXND.drawInvertPixel(SPND[t].Get_X() + WavXAnimND(t), SPND[t].Get_Y() + WavAnimND(t), SPND[t].Get_PIC(), SPND[t].Get_AnimFrame()); break;
        default: MEGA82XXND.drawSelfMasked(SPND[t].Get_X() + WavXAnimND(t), SPND[t].Get_Y() + WavAnimND(t), SPND[t].Get_PIC(), SelectFrameND(t)); break;
      }
    }
  }
}

void EraseScreenND() {
  MEGA82XXND.ClearBuffer();
}

void DrawSideWallsND() {
  MEGA82XXND.drawSelfMasked_OverScan(118, yScrollND, &DroiteND[0], 0);
  MEGA82XXND.drawSelfMasked_OverScan(118, yScrollND + 64, &DroiteND[0], 0);
  MEGA82XXND.drawSelfMasked_OverScan(0, yScrollND, &GaucheND[0], 0);
  MEGA82XXND.drawSelfMasked_OverScan(0, yScrollND + 64, &GaucheND[0], 0);
}

void ScrollDownND(uint8_t Spd_) {
  if ((FrmND % Spd_) == 0) {
    if (yScrollND > -63) {
      yScrollND--;
    } else {
      yScrollND = 0;
    }
    MovingSpriteND();
  }
}

void MovingSpriteND() {
  for (uint8_t t = 1; t < MAXSP; t++) {
    if (SPND[t].Get_A() == 1) { SPND[t].Put_Y(SPND[t].Get_Y() - 1); }
  }
}
