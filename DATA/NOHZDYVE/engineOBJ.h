// >>> N-O-H-Z-D-Y-V-E for ESP8285/ESP8266 relicensed under GPLv3 <<<
//   (Based on Nohzdyve on ARDUBOY originally on (MIT) License)
//   If you are looking for the MIT version of the source code,
//   refer to my original source code for Arduboy.
//               https://www.tinyjoypad.com/arduboy

//                    Programmer: Daniel C 2024
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

#ifndef ENGINEOBJ_H
#define ENGINEOBJ_H

//prototype
void NOHZDYVE_Setup();
void NOHZDYVE_loop() ;
void ExitWindowND() ;
void PlayGameND() ;
void GamePlayAdj() ;
void SpriteSetCFGND() ;
void TimerConfigND() ;
void InitPan1ND(void) ;
void CalculatePanND(uint16_t Scores_) ;
void ScorePannelND(uint8_t x_, uint8_t y_) ;
void ResetStepSNND() ;
void PlayINGameND() ;
void PlaySongND() ;
void StartToneND() ;
void DeadToneND() ;
void GlobToneND() ;
void SplashScreenND() ;
void SelectND() ;
uint8_t RecupeFadePosND(uint8_t *scan_, uint8_t Frame_) ;
void Merge2PicND(const uint8_t *pic1_, const uint8_t *pic2_) ;
void ResetVarND(void) ;
void ChangePicND(uint8_t *Exit_) ;
void Explod_MainND(void) ;
void Explod_GlobND(void) ;
void AdjustScoreND() ;
void DrawOverLapND() ;
void DrawLivesND(void) ;
void DrawScoreND(void) ;
void CollisionCheckND(void) ;
void Main2SolidND() ;
void Main2GlobND() ;
uint8_t ColidCheckND(int8_t x, int8_t y, int8_t x2, int8_t y2, uint8_t MargingX, uint8_t MargingY) ;
void WallCollisionCheckMainND(void) ;
void RefreshMoveJAWND() ;
void LibarateSpriteND() ;
void LiberateLineND() ;
int8_t YLINENDSETND(void) ;
void LiberateJawND() ;
int8_t JAWNDSTARTPOSND() ;
void LiberateGlobND() ;
int8_t GLOBDSTARTPOSND() ;
void LiberateWallSpriteND() ;
int8_t XPLANTNDSETND() ;
int8_t YPLANTNDSETND(void) ;
int8_t XCLIMNDSETND() ;
int8_t YCLIMNDSETND(void) ;
void CleanOverScanND() ;
void ExplodLogisticND() ;
void SinWavRunND(void) ;
void UpDateMainND(void) ;
void JoyPadRefreshND(void) ;
void FrameRateND() ;
void FlipScreenND() ;
void DrawMainScreenND() ;
void StartPageND() ;
uint8_t FadeMainScreenND(uint8_t *FD_, uint8_t TR3_) ;
uint8_t SelectFrameND(uint8_t t_) ;
int8_t WavAnimND(uint8_t t) ;
int8_t WavXAnimND(uint8_t t) ;
void DrawSpritesND() ;
void EraseScreenND() ;
void DrawSideWallsND() ;
void ScrollDownND(uint8_t Spd_) ;
void MovingSpriteND() ;

enum {
  MAINND = 0,
  GLOBND = 1,
  JAWND = 2,
  CLIMND = 3,
  WINDOWND = 4,
  PLANTND = 5,
  SLIDEND = 6,
  EXPLODND = 7,
  LINEND = 8
};

typedef struct NUMND {
  uint8_t ND10000;
  uint8_t ND1000;
  uint8_t ND100;
  uint8_t ND10;
  uint8_t ND1;
  uint16_t Scores;
  uint16_t HIScores;
  uint16_t Lives;
} NUMND;

class TUNES {
private:
public:
  void tone(uint16_t Snd_,uint16_t Dur_) {
Sound_TTRICK(Snd_,Dur_);
}
};

class TIMERND {
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

class Sprite_ND {
private:
  uint8_t Actif;
  uint8_t Type;
  uint8_t Direction;
  int8_t X;
  int8_t Y;
  uint8_t W;
  uint8_t H;
  uint8_t AnimFrame;
  const uint8_t* PIC;
  const uint8_t* ANIM;
  void CheckPic(uint8_t Spk) {
    AnimFrame = 0;
    switch (Spk) {
      case (MAINND):
        PIC = &MainPND[0];
        ANIM = &AnimenemyND[0];
        break;
      case (GLOBND):
        PIC = &GlobND[0];
        ANIM = &AnimGlobND[0];
        break;
      case (JAWND):
        PIC = &enemyND[0];
        ANIM = &AnimJawND[0];
        break;
      case (CLIMND):
        PIC = (X > 64) ? &ClimRND[0] : &ClimLND[0];
        ANIM = &AnimClimND[0];
        break;

      case (WINDOWND):
        PIC = &WindowND[0];
        ANIM = &AnimFrame;
        break;
      case (PLANTND):
        PIC = (X > 64) ? &FlowerRND[0] : &FlowerLND[0];
        ANIM = &AnimFrame;
        break;
      case (SLIDEND):
        PIC = &SlideMainPND[0];
        ANIM = &AnimFrame;
        break;
      case (EXPLODND):
        PIC = &ExplodND[0];
        ANIM = &AnimFrame;
        break;
      case (LINEND):
        PIC = &LineND[2];
        ANIM = &AnimFrame;
        break;
      default: PIC = nullptr; break;
    }
  }

  void Update_move(void) {
    if (Direction) {
      X++;
    } else {
      X--;
    }
  }

public:

  void Init(void) {
    Type = 0;
    Actif = 0;
    X = 0;
    Y = 0;
    W = 0;
    H = 0;
    AnimFrame = 0;
    PIC = nullptr;
    ANIM = nullptr;
  }

  void ActivateSprite(int8_t x, int8_t y, uint8_t Type_) {
    X = x;
    Y = y;
    Actif = 1;
    Type = Type_;
    CheckPic(Type);
    Direction = rand() % 2;
  }

  const uint8_t* Get_PIC(void) {
    return PIC;
  }
  const uint8_t* Get_ANIM(void) {
    return ANIM;
  }
  uint8_t Get_AnimFrame(void) {
    return AnimFrame;
  }
  void Put_AnimFrame(uint8_t Fr_) {
    AnimFrame = Fr_;
  }
  uint8_t Get_A(void) {
    return Actif;
  }
  uint8_t Get_Type(void) {
    return Type;
  }
  int8_t Get_X(void) {
    return X;
  }
  int8_t Get_Y(void) {
    return Y;
  }
  uint8_t Get_D(void) {
    return Direction;
  }
  void Put_D(uint8_t D_) {
    Direction = D_;
  }
  void Put_Y(int8_t y_) {
    Y = y_;
  }
  void Put_X(int8_t x_) {
    X = x_;
  }
  void Desactive(void) {
    Init();
  }
  void Destroy(void) {
    AnimFrame = 0;
    Type = EXPLODND;
    X = X - 3;
    Y = Y + 1;
    PIC = &ExplodND[0];
    ANIM = &AnimFrame;
  }
  void SPY(void) {
    Y--;
  }
  void MoveXND(void) {
    if ((X > 10) && (X < 102)) {
      Update_move();
    } else {
      Direction = (Direction == 1) ? 0 : 1;
      Update_move();
    }
  }
};
#endif
