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

#ifndef ENGINEOBJ_GITD_H
#define ENGINEOBJ_GITD_H

#include "../MEGA_LIB/ESPKIT.h"  
#include "SpriteBank_GITD.h"
#define x_offset 7
#define y_offset 0

extern ESPCOMPATIBILITY MEGA82XX;
uint8_t JumpCycle = 0;
uint8_t JumpCycleMem = 0;
uint8_t RopeMode = 0;
uint8_t UPDOWN = 2;
uint8_t DDead = 0;
uint8_t RoomChange = 0;
uint8_t Frm = 0;

uint8_t VisibleKeyAndDoors[22];  //Total of 21 keys -  First Byte= 1!
uint8_t VisibleSprite[30];

void DrawRecBW(uint8_t x, uint8_t y, uint8_t x2, uint8_t y2, uint8_t Col_) ;
void InvertPix(uint8_t Flip_, uint8_t x, uint8_t y, uint8_t x2, uint8_t y2) ;
void SplashScreen(void) ;
void loop_GILBERTINTHEDOWNLAND() ;
void InitPan(void) ;
void InitnextRoom(void) ;
void ResetPickupSprite(void) ;
void InitAllItems(void) ;
void ResetVarForNewGame(void) ;
void DrawMainScreen(void) ;
void SubLive(void) ;
void DrawLives(int8_t x_, int8_t y_) ;
void DrawCH(int8_t x_, int8_t y_) ;
void DisplayNum(void) ;
void DrawTime(uint8_t xx_, uint8_t yy_) ;
void DrawScore(uint8_t xx_, uint8_t yy_, uint16_t Val_) ;
void NumCalculate(uint16_t Nub_) ;
void DrawAllSprites(void) ;
void DrawRoomInProgress(void) ;
void TransitReDraw(void) ;
void RoomTransition(void) ;
void CheckIfBallExist(const int8_t *SPK_) ;
void Sprite_Colid(void) ;
uint8_t colid_univ(int8_t x1_, int8_t w1_, int8_t y1_, int8_t h1_, int8_t x2_, int8_t w2_, int8_t y2_, int8_t h2_) ;
void update_Ballon(void) ;
void Draw_Ballon(void) ;
void ReleaseNewDrop(void) ;
void CalculateAcidDrop(void) ;
void DrawAcidDrop(void) ;
uint8_t ColAcidDrop(int8_t x_, int8_t y_, uint8_t t_) ;
bool checkMainColision(int8_t T_, int8_t bx, int8_t by) ;
uint8_t PickupSprites(int8_t T_, int8_t X_, int8_t Y_, int8_t I_) ;
void GotoNexRoom(int8_t DoorNumber_) ;
void DrawSprites(const int8_t *SPK_) ;
void MovingMode(void) ;
void RopeProcess(void) ;
void RopeModeGITD(void) ;
void WalkingModeGITD(void) ;
uint8_t RopeDetectionGITD(int8_t x_, int8_t y_, const int8_t *Rope_) ;
int STDHcollisionGITD(int8_t x1, int8_t y1, int8_t L_, int8_t x2, int8_t y2) ;
int STDVcollisionGITD(int8_t x1, int8_t y1, int8_t L_, int8_t x2, int8_t y2) ;
void FrmCall(void) ;
void Draw_Gilbert_ITD(void) ;
void DrawVector(int8_t x_, int8_t y_, const int8_t *VectorSelect) ;
void SetVectorStartPos(int8_t x_, int8_t y_) ;
void DrawWalls(int8_t y0, int8_t y1, int8_t x_) ;
void DrawStalagtite(int8_t x0, int8_t x1, int8_t y_) ;
void drawRopeVector(int8_t x_, int8_t y_, const int8_t *VectorSelect) ;
void drawRope(int8_t x0, int8_t y0, int8_t x1, int8_t y1) ;
void drawLine(int8_t x0, int8_t y0, int8_t x1, int8_t y1) ;
uint8_t ColWall(int8_t CX_, int8_t CY_) ;
void Sound_GITD(uint8_t freq_, uint8_t dur);
void SoundSystem_GITD(uint8_t Snd_);

typedef struct NUMGITD {
  uint8_t M10000;
  uint8_t M1000;
  uint8_t M100;
  uint8_t M10;
  uint8_t M1;
  uint16_t Scores;
  uint16_t HIScores;
  uint8_t Lives;
} NUMGITD;

class TIMERGITD {
private:
  uint8_t Activ;
  uint8_t startTime;
  uint8_t interval;
public:
  void Init(uint8_t Interval_) {
    startTime = 0;
    interval = Interval_;
    Activ = 0;
  }

  uint8_t Get_A(void) {
    return Activ;
  }

  void Activate(void) {
    Activ = 1;
  }

  void DeActivate(void) {
    Activ = 0;
  }

  uint8_t Trigger(void) {
    if (Activ == 0) return 0;
    if (startTime < interval) {
      startTime++;
      return 0;
    } else {
      startTime = 0;
      return 1;
    }
  }
};

class StaticSprite_GITD {
private:
  uint8_t Actif;
  int8_t X;
  int8_t Y;
public:

  void StaticInit(void) {
    Actif = 0;
    X = 0;
    Y = 0;
  }

  uint8_t Get_A(void) {
    return Actif;
  }
  int8_t Get_X(void) {
    return X;
  }
  int8_t Get_Y(void) {
    return Y;
  }

  void Put_A(uint8_t A_) {
    Actif = A_;
  }

  void Put_X(int8_t X_) {
    X = X_;
  }

  void Put_Y(int8_t Y_) {
    Y = Y_;
  }
};

class AcidDrop_GITD : public StaticSprite_GITD {
private:
  uint8_t Delays;

public:

  uint8_t Get_Dl(void) {
    return Delays;
  }

  void InitAcidDrop(void) {
    Put_A(0);
  }

  void SetAcidDrop(int8_t x_, int8_t y_) {
    Put_A(1);
    Put_X(x_ + x_offset);
    Put_Y(y_ + y_offset);
    Delays = 35;
  }

  void UpdateAcideDrop(void) {
    if (Delays > 0) {
      Delays--;
    } else {
      Put_Y(Get_Y() + 1);
    }
  }
};

class Sprite_GITD : public StaticSprite_GITD {
private:

  uint8_t Type;
  uint8_t Direction;

  uint8_t AnimFrame;
  uint8_t DeadFrameStep;
  int8_t StretchADD;
  uint8_t TrigSpeedRestriction;
  uint8_t SpeedRestriction;

  const float GravityQ = .2;
  float GravitySpeed;
  uint8_t FloorStat;
  uint8_t OneClick;
  uint8_t OneClick2;
  int8_t Stretch;

  void InitDeadAnim(void) {
    if (DDead == 4) {
      SubLive();
      DeadFrameStep = 110;
      Put_X(Get_X() + StretchADD);
      StretchADD = 0;
      Stretch = 0;
      DDead = 0;
    }
  }

  void ForcedJumpTrig(void) {
    GravitySpeed = -1.2;
    FloorStat = 0;
    OneClick = 0;
  }

  void SpriteStretchSelect(void) {
    switch (Stretch) {
      case -29 ... 29:
        RopeJump();
        StretchADD = 0;
        break;
      case -50 ... - 30: StretchADD = -2; break;
      case 30 ... 50: StretchADD = 2; break;
      case -68 ... - 51:
        {
          Put_X(Get_X() - 4);
          StretchADD = 0;
          Stretch = 0;
        }
        break;
      case 51 ... 68:
        {
          Put_X(Get_X() + 4);
          StretchADD = 0;
          Stretch = 0;
        }
        break;
      default: break;
    }
  }

  uint8_t ColWallP(void) {
    return ColWall(Get_X(), Get_Y());
  }

  uint8_t MainAnimSelect(void) {
    return ((GET_FLS()) ? Get_ANIMFRM() : (Get_Direction() == 6) ? Get_ANIMFRM():1)+ Get_Direction();
  }
public:

  void Init(void) {
    Direction = 0;
    StaticInit();
    Type = 0;
    Put_A(0);
    TrigSpeedRestriction = 0;
    SpeedRestriction = 4;
    AnimFrame = 0;
    GravitySpeed = 0;
    FloorStat = 1;
    OneClick = 1;
    OneClick2 = 1;
    Stretch = 0;
    StretchADD = 0;
    DeadFrameStep = 0;
    DDead = 0;
  }

  int8_t Get_Stretch(void) {
    return StretchADD;
  }

  uint8_t DeadAnim(void) {
    DeadFrameStep = (DeadFrameStep > 0) ? DeadFrameStep - 1 : DeadFrameStep;
    if (DeadFrameStep > 106) {
      return 9;
    } else {
      if ((DeadFrameStep > 98)) { Sound_GITD(1, 4); }
      if (DeadFrameStep == 0) DDead = 3;
      return 10;
    }
  }

  uint8_t NoiseMain(void) {
    if (DeadFrameStep != 0) {
      DeadFrameStep--;
    } else {
      DeadFrameStep = 3;
    }
    return 11 + DeadFrameStep;
  }

  uint8_t GetMainFrame(void) {
    switch (DDead) {
      case 0: return MainAnimSelect();
      case 1:
        if (GravitySpeed < 0) { GravitySpeed = 0; }
        return MainAnimSelect();
      case 2: return DeadAnim();
      case 3:
      case 4: return NoiseMain();
      default: return 0; break;
    }
  }

  void Put_1Click2(void) {
    OneClick2 = 0;
    OneClick = 0;
  }

  void Put_Direction(uint8_t D_) {
    Direction = D_;
  }

  uint8_t GET_FLS(void) {
    return FloorStat;
  }

  int8_t Get_AddStretch(void) {
    return StretchADD;
  }

  void JumpTrig(void) {
    if (DDead) return;
    if ((FloorStat) && (OneClick)) {
      GravitySpeed = -1.2;
      FloorStat = 0;
      OneClick = 0;
    }
  }

  int8_t Get_GS(void) {
    return GravitySpeed;
  }
  uint8_t Get_1Click(void) {
    return OneClick;
  }

  void GravityReset(void) {
    GravitySpeed = 0;
  }

  void GravityUpdate(void) {
    if ((GravitySpeed + GravityQ) < 3) {
      GravitySpeed = GravitySpeed + GravityQ;
    } else {
      DDead = 1;
    }
    Put_Y(Get_Y() + GravitySpeed);
  }

  void FloorDirectCheck(void) {
    if (ColWall(Get_X(), Get_Y() + 1)) { DDead = 2; }
  }

  void Gravitycalcule(void) {
    if (DDead == 1) {
      FloorDirectCheck();
    }
    if ((GravitySpeed) >= 0) {
Recheck:;
      if (ColWall(Get_X(), Get_Y())) {
        GravityReset();
        Stretch = 0;
        FloorStat = 1;
        if (BUTTON_UP) OneClick = 1;
        Put_Y(Get_Y() - 1);
        if (DDead == 1) { DDead = 2; }
        goto Recheck;
      }
    } else {
Recheck2:;
      if (ColWall(Get_X(), Get_Y())) {
        GravityReset();
        Put_Y(Get_Y() + 1);
        JumpCycleMem = 2;
        goto Recheck2;
      }
    }

    if (GravitySpeed > 1) {
      FloorStat = 0;
      OneClick = 0;
      OneClick2 = 0;
    }
  }

  void SetSpritePos(int8_t x_, int8_t y_) {
    Put_X(x_offset + x_);
    Put_Y(y_offset + y_);
  }

  int8_t Get_Direction(void) {
    return Direction;
  }

  void Neutral(void) {
    TrigSpeedRestriction = SpeedRestriction;
    AnimFrame = 1;
  }

  int8_t Get_ANIMFRM(void) {
    return AnimFrame;
  }

  void Go2Left(void) {
    uint8_t Trig_ = 0;
    if ((DDead == 1) || (DDead == 2) || (DDead == 3)) return;
    InitDeadAnim();
    if (TrigSpeedRestriction < SpeedRestriction) {
      TrigSpeedRestriction++;
    } else {
      if (Get_X() > 0) {
        Put_X(Get_X() - 1);
        if ((FloorStat) && (AnimFrame == 2)) Trig_ = 1;
      }
      if (ColWallP()) {
        Trig_ = 0;
        Put_X(Get_X() + 1);
        if (GravitySpeed < 0) GravitySpeed = 0;
      } else {
        TrigSpeedRestriction = 0;
        AnimFrame = (AnimFrame < 2) ? AnimFrame + 1 : 0;
        Direction = 0;
        if (Trig_) SoundSystem_GITD(1);
      }
    }
  }

  void Go2Right(void) {
    uint8_t Trig_ = 0;
    if ((DDead == 1) || (DDead == 2) || (DDead == 3)) return;
    InitDeadAnim();
    if (TrigSpeedRestriction < SpeedRestriction) {
      TrigSpeedRestriction++;
    } else {
      if (Get_X() < 127) {
        Put_X(Get_X() + 1);
        if ((FloorStat) && (AnimFrame == 2)) Trig_ = 1;
      }
      if (ColWallP()) {
        Put_X(Get_X() - 1);
        if (GravitySpeed < 0) GravitySpeed = 0;
      } else {
        TrigSpeedRestriction = 0;
        AnimFrame = (AnimFrame < 2) ? AnimFrame + 1 : 0;
        Direction = 3;
        if (Trig_) SoundSystem_GITD(1);
      }
    }
  }

  void GoClimb(void) {
    uint8_t Trig_ = 0;
    if (DDead) return;
    if (TrigSpeedRestriction < SpeedRestriction) {
      TrigSpeedRestriction++;
    } else {
      Put_Y(Get_Y() - 1);
      Trig_ = 1;
      if (ColWallP()) {
        AnimFrame = (AnimFrame > 0) ? AnimFrame - 1 : AnimFrame;
        Put_Y(Get_Y() + 1);
        Trig_ = 0;
      }

      GravitySpeed = 0;
      TrigSpeedRestriction = 0;
      AnimFrame = (AnimFrame < 2) ? AnimFrame + 1 : 0;
      if (Trig_) SoundSystem_GITD(3);
    }
  }

  void GoFall(void) {
    if (DDead) return;
    if (TrigSpeedRestriction < SpeedRestriction) {
      TrigSpeedRestriction++;
    } else {
      Put_Y(Get_Y() + 1);
      GravitySpeed = 2;
      TrigSpeedRestriction = 0;
      AnimFrame = (AnimFrame > 0) ? AnimFrame - 1 : 2;
      SoundSystem_GITD(4);
    }
  }

  void RopeJump(void) {
    if (DDead) return;
    if (BUTTON_UP) { OneClick2 = 1; }
    if ((BUTTON_DOWN) && (OneClick2)) {
      UPDOWN = 2;
      RopeMode = 0;
      if (TINYJOYPAD_LEFT==0) {
        JumpCycle = 0;
        JumpCycle = 0;
        JumpCycleMem = 0;
        ForcedJumpTrig();
      } else if (TINYJOYPAD_RIGHT==0) {
        JumpCycle = 1;
        JumpCycle = 1;
        JumpCycleMem = 1;
        ForcedJumpTrig();
      }
    }
  }

  void leftstretch(void) {
    if (DDead) return;
    if (Stretch > -127) Stretch--;
    SpriteStretchSelect();
    if (!StretchADD) {
    } else {
      Direction = 0;
    }
  }

  void rightstretch(void) {
    if (DDead) return;
    if (Stretch < 127) Stretch++;
    SpriteStretchSelect();

    if (!StretchADD) {
    } else {
      Direction = 3;
    }
  }

  void NeutralStretch(void) {
    if ((Stretch > 29) || (Stretch < -29)) return;
    Stretch = 0;
    SpriteStretchSelect();
  }
};

class Ballon_GITD : public StaticSprite_GITD {
private:
  float Step;
  uint8_t Anim;
  int8_t XMEM;
  int8_t YMEM;
  uint8_t collXBallon(void) {
    if (MEGA82XX.getPixel(Get_X() + 1, Get_Y() + 5) || MEGA82XX.getPixel(Get_X() + 2, Get_Y() + 5)) {
      return 1;
    } else {
      return 0;
    }
  }

  uint8_t collYBallon(void) {
    if ((MEGA82XX.getPixel(Get_X() + 2, Get_Y() + 6)) || (MEGA82XX.getPixel(Get_X() + 2, Get_Y() + 7))) {
      return 1;
    } else {
      return 0;
    }
  }

  void UpdateGravity(void) {
    if (Step < 2) Step += .2;
    Put_Y(Get_Y() + Step);
    Anim = 0;
Recheck3:;
    if (collYBallon()) {
      Anim = 1;
      Step = -.8;
      Put_Y(Get_Y() - 1);
      goto Recheck3;
    }
  }

  void leftmove(void) {
    if (!collXBallon()) {
      Put_X(Get_X() - 1);
    } else {
      Put_A(0);
      Step = 0;
      Rset_Ballon();
    }
  }

public:

  void Init_Ballon(void) {
    Put_A(0);
    Put_X(0);
    Put_Y(0);
  }

  void Set_Ballon(int8_t x_, int8_t y_) {
    Put_A(1);
    Put_X(x_);
    Put_Y(y_);
    Step = 0;
    Anim = 0;
    XMEM = x_;
    YMEM = y_;
  }

  void Rset_Ballon(void) {
    Put_A(1);
    Put_X(XMEM);
    Put_Y(YMEM);
  }

  uint8_t Get_Anim(void) {
    return Anim;
  }

  void Update_Ballon(void) {
    if (!Get_A()) return;
    leftmove();
    UpdateGravity();
  }
};

class TIMEOUT {

private:
  uint16_t Time;
  uint8_t Flip;
  uint8_t Actif;
  int8_t x;
  int8_t y;
  uint8_t UD;
  uint8_t RL;

  uint8_t FlipFrm(void) {
    Flip = (Flip < 10) ? Flip + 1 : 0;
    if (Flip < 6) {
      return 0;
    } else {
      return 1;
    }
  }

public:

  uint16_t Get_Time(void) {
    return Time;
  }

  void Set_Time(void) {
    Time = 4000;
  }

  void ResetTime(void) {
    if ((Actif) && (Time == 0)) { Time = 2048; }
  }

  void deactivate(void) {
    Actif = 0;
    Flip = 0;
  }

  void Activate(void) {
    if (Actif) return;
    Actif = 1;
    x = 0;
    y = 0;
    RL = 1;
    UD = 1;
  }

  void TimeOutFunction(int8_t x_, int8_t y_) {
    if (DDead > 2) return;
    if (Time > 0) {
      Time--;
    } else {
      Activate();
    }
    if (!Actif) return;
    if (colid_univ(x_ + 1, 4, y_ + 2, 5, x, 5, y, 3)) {
      if (!DDead) DDead = 1;
    }
    if (UD) {
      Go2Down();
    } else {
      Go2UP();
    }
    if (RL) {
      Go2Right();
    } else {
      Go2Left();
    }
    MEGA82XX.drawSelfMasked(x, y, TimeOut_GITD, FlipFrm());
  }

  void Go2Right(void) {
    if (x < (x_offset + 96)) {
      x++;
    } else {
      RL = 0;
    }
  }

  void Go2Left(void) {
    if (x > (x_offset)) {
      x--;
    } else {
      RL = 1;
    }
  }

  void Go2UP(void) {
    if (y < (y_offset + 60)) {
      y++;
    } else {
      UD = 1;
    }
  }

  void Go2Down(void) {
    if (y > (y_offset)) {
      y--;
    } else {
      UD = 0;
    }
  }
};

#endif
