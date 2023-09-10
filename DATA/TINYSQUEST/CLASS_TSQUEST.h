//   >>>>>  T-I-N-Y  S-Q-U-E-S-T for ESP8285/ESP8266  GPL v3 <<<<<
//                    Programmer: Daniel C 2023
//             Contact EMAIL: electro_l.i.b@tinyjoypad.com
//  https://github.com/phoenixbozo/TinyJoypad/tree/main/TinyJoypad
//                    https://WWW.TINYJOYPAD.COM
//          https://sites.google.com/view/arduino-collection

//  tiny-Squest is free software: you can redistribute it and/or modify
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

//include 
#include "spritebank_TSQUEST.h"
//Structure

typedef struct GamePlay_TSQUEST {
  uint8_t RETURN_START;
  uint8_t Level;
  uint8_t OX;
  uint16_t Scores;
  uint8_t Diver;
  uint8_t Speed;
  uint8_t Main_SPK_Bank;
  uint8_t Amount_Sprite;
  uint8_t Lib_Sprite_Timer;
  uint8_t LIBTRIG;
  uint8_t Speed_Balistic;
  uint8_t Frame;
  uint8_t Frame_Main;
  uint8_t Main_Live;
  uint8_t Frame_Cycle_STEP2;
  int8_t SUBSOLO_X;
  uint8_t DIVER_OSD_STATE;
  uint8_t OX_OSD_STATE;
  uint8_t Refresh_OSD;
  uint8_t FlipFlop;
  uint8_t Flipflop_Counter;
  uint8_t FlipFlop2_OX;
  uint8_t FlipFlop2_OX_Counter_;
  uint8_t Limit_move_Other_Sprite;
  uint8_t Limit_Refresh;
  uint8_t latch_0_FIRSTFULLING;
  uint8_t latch_1_REFILL;
  uint8_t latch_2_AFTERDEAD;
  uint8_t NO_JOY;
  uint8_t NEXTLEVEL;
  uint8_t Sin_Anim;
  uint8_t sa, eb;
  uint8_t RND3Pos;
  uint8_t RND2Pos;
} GamePlay_TSQUEST;

//PROTOTYPE
void loop_TSQUEST(void);
int8_t RecupeLineY_TSQUEST(int8_t Valeur);
uint8_t blitzSprite(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES);
uint8_t SPEED_BLITZ(int8_t xPos,int8_t yPos,uint8_t xPASS,uint8_t yPASS,uint8_t FRAME,const uint8_t *SPRITES);
uint8_t SplitSpriteDecalageY(uint8_t decalage,uint8_t Input,uint8_t UPorDOWN);
void RESET_VAR_TSQUEST(void);
void REST_LEVEL_TSQUEST(void);
void Init_TSQUEST(void);
uint8_t Amount_Sprite_SET_TSQUEST(uint8_t Level_);
void Level_Adjust_TSQUEST(uint8_t Level_);
uint8_t Blink_Start_TSQUEST(uint8_t X_, uint8_t Y_, uint8_t BL_);
void RENDER_DISPLAY_TSQUEST(uint8_t BL_);
void Intro_TSQUEST(void);
void CheckCollisionSolo_TSQUEST(void);
void NEW_LEVEL_TSQUEST(void);
void Respond_TSQUEST(void);
void Game_Over_TSQUEST(void);
void Kiling_Main_TSQUEST(void);
void Refresh_Anim_TSQUEST(void);
void Refresh_Main_Anim_TSQUEST(void);
void Sound_1_TSQUEST(void);
void Start_Proccess_Destroy_Main_TSQUEST(void);
void Start_Proccess_Destroy_Main_Step3_TSQUEST(void);
void Start_Proccess_Destroy_Main_Step4_TSQUEST(void);
void Step2_counter_TSQUEST(uint8_t Skip_);
void Step3_counter_TSQUEST(void);
void JoyPad_Refresh_TSQUEST(void);
void OX_REDUCE_TSQUEST(void);
void REMOVE_DIVER_TSQUEST(void);
void Refill_TSQUEST(uint8_t Y_);
void NEXT_LEVEL_TRIGGER_TSQUEST(void);
void NEXT_LEVEL_TSQUEST(void);
void UPDATE_GAMEPLAY_TSQUEST(void);
int8_t P_TSQUEST(uint8_t Direction_, uint8_t position_);
uint8_t LINE_TSQUEST(uint8_t position_);
void Check_Endingline_TSQUEST(uint8_t Line_);
void LIBERATE_LINE_TSQUEST(uint8_t Line_);
void MAKE_LINE_TSQUEST(uint8_t *A_, uint8_t *B_, uint8_t *C_);
void FLIPFLOP2_TSQUEST(void);
void FLIPFLOP_TSQUEST(void);
void OSD_Diver_TSQUEST(uint8_t STATE_);
void OSD_OX_TSQUEST(uint8_t STATE_);
void OSD_MANAGER_SQUEST(void);
void RND3X_tsquest(void);
uint8_t RECUP_RND3_tsquest(void);
void RND2X_tsquest(void);
uint8_t RECUP_RND2_tsquest(void);
int8_t Recup_sin_Add_TSQUEST(uint8_t Activ_);
void Sin_Move_TSQUEST(void);
void CHECK_COLLISION_BALLISTIC_TSQUEST(void);
void CHECK_OTHER_COLLISION_BALLISTIC_TSQUEST(void);
void Check_Collision_Main2Other_TSQUEST(void);
void SCORE_ADD_TSQUEST(void);
int8_t COLLISION_TSQUEST(int8_t x, int8_t y, int8_t w, int8_t h, int8_t x2, int8_t y2, int8_t w2, int8_t h2);
uint8_t Balistic_Line_TSQUEST(uint8_t Sprite_, uint8_t State_);
uint8_t Check_if_Deployed_TSQUEST(uint8_t T_);
void UPDATE_BALLISTIC_TSQUEST(void);
uint8_t Recupe_SPRBANK_TSQUEST(void);
uint8_t RECUPE_MAIN_TSQUEST(uint8_t xPASS, uint8_t yPASS);
uint8_t RECUPE_BALLISTIC_MAIN_TSQUEST(uint8_t xPASS, uint8_t yPASS);
uint8_t RECUPE_BALLISTIC_OTHER_TSQUEST(uint8_t xPASS, uint8_t yPASS);
void RECUP_RANGE_TSQUEST(uint8_t yPASS);
uint8_t RECUPE_OTHER_TSQUEST(uint8_t xPASS, uint8_t yPASS);
uint8_t RecupeRanged_TSQUEST(uint8_t xPASS, uint8_t yPASS);
uint8_t Recupe_SUBsolo_TSQUEST(uint8_t xPASS, uint8_t yPASS);
void RENDER_TSQUEST(void);
void RENDER_DISPLAY_TSQUEST(uint8_t FlipFlop1_, uint8_t FlipFlop2_);
uint8_t Recupe_OX_TSQUEST(uint8_t Flip_, uint8_t xPASS);
void Config_Display_Diver_TSQUEST(uint8_t *A_, uint8_t *B_);
uint8_t Recupe_Diver_TSQUEST(uint8_t xPASS);
uint8_t Recupe_LIVE_TSQUEST(uint8_t xPASS);
uint8_t FullDisplayRefresh_TSQUEST(uint8_t FlipFlop1_, uint8_t FlipFlop2_, uint8_t xPASS, uint8_t yPASS);
void COMPIL_SCO_TSQUEST(void);
uint8_t recupe_SCORES_TSQUEST(uint8_t xPASS, uint8_t yPASS);

class PASIVE_SPRITE_TSQUEST {
private:
  int8_t x;
  int8_t y;
  uint8_t Direction;
  uint8_t killed;
  uint8_t active;
  uint8_t width;
  uint8_t height;

public:
  void INIT(uint8_t Active_, int8_t X_, int8_t Y_) {
    x = X_;
    y = Y_;
    Direction = 0;
    active = Active_;
    killed = 0;
    width = 7;
    height = 7;
  }

  uint8_t GET_D(void) {
    return Direction;
  }

  void PUT_D(uint8_t D_) {
    Direction = D_;
  }

  uint8_t GET_K(void) {
    return killed;
  }

  void PUT_K(uint8_t K_) {
    killed = K_;
  }

  int8_t GET_X(void) {
    return x;
  }

  int8_t GET_Y(void) {
    return y;
  }

  uint8_t GET_W(void) {
    return width;
  }

  uint8_t GET_H(void) {
    return height;
  }

  void PUT_A(uint8_t F_) {
    active = F_;
  }

  uint8_t GET_A(void) {
    return active;
  }

  void PUT_W(uint8_t Width_) {
    width = Width_;
  }

  void PUT_H(uint8_t height_) {
    height = height_;
  }

  void PUT_X(int8_t X_) {
    x = X_;
  }

  void PUT_Y(int8_t Y_) {
    y = Y_;
  }

};

class ACTIVE_SPRITE_TSQUEST : public PASIVE_SPRITE_TSQUEST {
private:
  uint8_t Speed;
  uint8_t SpeedAdd;
  uint8_t Ballistic;
  int8_t BallisticPositionX;
  int8_t BallisticPositionY;
  int8_t BallisticSpeed;
public:

  void ACTIVE_SPRITE_INIT(uint8_t Active_, int8_t X_, int8_t Y_, int8_t Speed_) {
    INIT(Active_, X_, Y_);
    if ((X_ < 63) && (X_ > -100)) {
      PUT_D(3);
    } else {
      PUT_D(0);
    }
    Speed = Speed_;
    Ballistic = 0;
    BallisticPositionX = 0;
    BallisticPositionY = 0;
    BallisticSpeed = 0;
  }

#define MAX_LEFT 2
#define MAX_RIGHT 125
#define MAX_DOWN 51
#define MAX_UP 6

  void PUT_SPEED(uint8_t Speed_) {
    Speed = Speed_;
  }

  uint8_t GET_SPEED(void) {
    return Speed;
  }

  uint8_t GET_Ballistic(void) {
    return Ballistic;
  }

  void DESTROY_Ballistic(void) {
    Ballistic = 0;
  }

  int8_t GET_BallisticX(void) {
    return BallisticPositionX;
  }

  int8_t GET_BallisticY(void) {
    return BallisticPositionY;
  }

  void MOVE_X_R(uint8_t Width_) {
    if ((Width_ + GET_X()) < MAX_RIGHT) {
      PUT_X(GET_X() + Speed);
      PUT_D(3);
    }
  }

  void MOVE_X_L(void) {
    if ((GET_X()) > MAX_LEFT) {
      PUT_X(GET_X() - Speed);
      PUT_D(0);
    }
  }

  void MOVE_Y_D(uint8_t Width_) {
    if ((Width_ + GET_Y()) < MAX_DOWN) { PUT_Y(GET_Y() + Speed); }
  }
  void MOVE_Y_U(void) {
    if ((GET_Y()) > MAX_UP) { PUT_Y(GET_Y() - Speed); }
  }

  void SPEEDCALC_POS(uint8_t Speed_Frame) {
    uint8_t Speed_ = (Speed == 0) ? 1 : Speed;
    if ((Speed == 0) && (Speed_Frame == 0)) { return; }
    if ((GET_X() + Speed_) <= 127) {
      PUT_X(GET_X() + Speed_);
    } else {
      PUT_A(0);
    }
  }

  void SPEEDCALC_NEG(uint8_t Width_, uint8_t Speed_Frame) {
    uint8_t Speed_ = (Speed == 0) ? 1 : Speed;
    if ((Speed == 0) && (Speed_Frame == 0)) { return; }
    if ((GET_X() + Width_) > 0) {
      PUT_X(GET_X() - Speed_);
    } else {
      if ((GET_X()) < -100) {
        PUT_X(GET_X() - Speed_);
      } else {
        PUT_A(0);
      }
    }
  }

  void AUTOMOVE(uint8_t Width_, uint8_t Speed_Frame) {
    if (GET_A() == 0) return;
    if (GET_D() > 0) {
      SPEEDCALC_POS(Speed_Frame);
    } else {
      SPEEDCALC_NEG(Width_, Speed_Frame);
    }
  }

  void BallisticDeploy(uint8_t Width_, uint8_t Speed_Balistic_) {
    if (Ballistic == 0) {
      Ballistic = 1;
      BallisticPositionX = GET_X() + uint8_t(Width_ >> 1);
      BallisticPositionY = GET_Y() + 3;
      BallisticSpeed = (GET_D() == 0) ? -Speed_Balistic_ : Speed_Balistic_;
    }
  }

  void BallisticUpdate(void) {
    if (Ballistic != 0) {
      BallisticPositionX = BallisticPositionX + BallisticSpeed;
      if (BallisticPositionX < -6) { Ballistic = 0; }
    }
  }
};
