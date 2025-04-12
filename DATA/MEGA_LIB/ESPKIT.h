//       >>> E-S-P-K-I-T for ESP8285/ESP8266 under GPLv3 <<<
//                    Programmer: Daniel C 2025
//             Contact EMAIL: electro_l.i.b@tinyjoypad.com
//  https://github.com/phoenixbozo/TinyJoypad/tree/main/TinyJoypad
//                    https://WWW.TINYJOYPAD.COM
//          https://sites.google.com/view/arduino-collection

//  ESPKIT is free software: you can redistribute it and/or modify
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
               Email: electro_l.i.b@tinyjoypad.com
  https://github.com/phoenixbozo/TinyJoypad/tree/main/TinyJoypad
                    https://WWW.TINYJOYPAD.COM
          https://sites.google.com/view/arduino-collection
*/
/*
// ESPKIT.h is a mini library to ensure compatibility with certain specific
// functions used by some of my games for Arduboy on Mega Tinyjoypad.
*/

#ifndef ESPKIT_H
#define ESPKIT_H

class ESPCOMPATIBILITY {
private:
  //var
  uint8_t T;
  ESPboyRender *Disp_1;
  uint8_t FPS_Break;
  unsigned long MemMil = 0;
  //var end

  //private Methode
  int8_t ESP_RecupeLineY(int8_t Valeur) {
    return (Valeur >> 3);
  }

  int8_t ESP_RecupeDecalageY(uint8_t Valeur) {
    return (Valeur - ((Valeur >> 3) << 3));
  }
  
  uint8_t ESP_SplitSpriteDecalageY(uint8_t decalage, uint8_t Input, uint8_t UPorDOWN) {
    if (UPorDOWN) { return Input << decalage; }
    return Input >> (8 - decalage);
  }

  uint8_t ESP_blitzSprite(int8_t xPos, int8_t yPos, int8_t HSPRITE_, uint8_t xPASS, uint8_t yPASS, uint8_t FRAME, const uint8_t *SPRITES) {
    uint8_t OUTBYTE;
    uint8_t WSPRITE = (pgm_read_byte(&SPRITES[0]));
    int8_t HSPRITE = HSPRITE_;
    int16_t Wmax = ((HSPRITE * WSPRITE) + 1);
    int16_t PICBYTE = FRAME * (Wmax - 1);
    int8_t RECUPELINEY = ESP_RecupeLineY(yPos);
    if (
      (xPASS > (xPos + (WSPRITE - 1))) || (xPASS < xPos) || (RECUPELINEY > yPASS) || ((RECUPELINEY + (HSPRITE)) < yPASS)) { return 0x00; }
    int8_t SPRITEyLINE = (yPASS - (RECUPELINEY));
    int8_t SPRITEyDECALAGE = (ESP_RecupeDecalageY(yPos));
    int16_t ScanA = (((xPASS - xPos) + (SPRITEyLINE * WSPRITE)) + 2);
    int16_t ScanB = (((xPASS - xPos) + ((SPRITEyLINE - 1) * WSPRITE)) + 2);
    if (ScanA > Wmax) {
      OUTBYTE = 0x00;
    } else {
      OUTBYTE = ESP_SplitSpriteDecalageY(SPRITEyDECALAGE, pgm_read_byte(&SPRITES[ScanA + (PICBYTE)]), 1);
    }
    if (SPRITEyLINE > 0) {
      uint8_t OUTBYTE2 = ESP_SplitSpriteDecalageY(SPRITEyDECALAGE, pgm_read_byte(&SPRITES[ScanB + (PICBYTE)]), 0);
      if (ScanB > Wmax) {
        return OUTBYTE;
      } else {
        return OUTBYTE | OUTBYTE2;
      }
    } else {
      return OUTBYTE;
    }
  }

  //private methode end

public:

void drawPixel(int16_t x_, int16_t y_,uint8_t Col_){
if (Col_) {Disp_1->setPixel(x_,y_);} else{Disp_1->clearPixel(x_,y_);}

}

uint8_t getPixel(int16_t x_, int16_t y_) {
  if (x_ >= 0 && x_ < Disp_1->width() && y_ >= 0 && y_ < Disp_1->height()) {
    uint8_t bit = Disp_1->buffer[x_ + (y_ / 8) * Disp_1->width()] & (1 << (y_ & 7));
    return bit ? WHITE : BLACK;
  }
  return BLACK;
}

uint8_t *getBuffer(void)
{
  return Disp_1->buffer;
}

  uint8_t RBuffer(uint16_t pos_) {
    return Disp_1->buffer[pos_];
  }

  void sBuffer(uint16_t pos_, uint8_t Val_) {
    Disp_1->buffer[pos_] = Val_;
  }

  void SetFPS(uint8_t Val_) {
    FPS_Break = (1000 / Val_);
  }

  void FPS_Temper(void) {
    while ((millis() - MemMil) < FPS_Break) { delay(1); }
    MemMil = millis();
  }

  void Init(ESPboyRender *disp_) {
    Disp_1 = disp_;
  }
  
  void clear(void) {
    Disp_1->clear();
}

  void Begin(void) {
     Disp_1 = NULL;
}

  void display(void) {
    Disp_1->display();
  }

  void fillScreen(uint8_t t) {
    Disp_1->fillScreen(t);
  }

  void ClearBuffer(void) {
    Disp_1->clear();
  }

  uint8_t nextFrame(void) {
    return 0;
  }
  
  uint8_t pressed(uint8_t) {
    return 1;
  }

  void drawSelfMasked(int8_t x_, int8_t y_, uint8_t const *PRGM_, uint8_t F_) {

    if ((y_ > 63) || (x_ < -16) || (y_ < -16)) return;

    uint8_t WSPRITE_ = pgm_read_byte(&PRGM_[0]);
    int8_t HSPRITE_ = ESP_RecupeLineY(pgm_read_byte(&PRGM_[1]));
    int8_t STARTY = ESP_RecupeLineY(y_);
    int8_t BL_STARTY = STARTY;

    if (STARTY < 0) STARTY = 0;

    if ((pgm_read_byte(&PRGM_[1]) - (HSPRITE_ << 3)) != 0) {
      HSPRITE_++;
    }

    uint8_t endY = BL_STARTY + HSPRITE_ + 1;

    for (int16_t y = STARTY; y < endY; y++) {

      if (y > 63) break;

      for (int16_t x = x_; x < (WSPRITE_ + x_); x++) {

        if (x > 127) break;
        uint16_t addr = x + (y << 7);
        if (addr < 128*64/8)
          Disp_1->buffer[addr] |= ESP_blitzSprite(x_, y_, HSPRITE_, x, y, F_, PRGM_);
      }
    }
  }


  void drawSelfMasked_OverScan(int8_t x_, int8_t y_, uint8_t const *PRGM_, uint8_t F_) {

    if ((y_ > 63) || (x_ < 0) || (y_ < -64)) return;


    uint8_t WSPRITE_ = pgm_read_byte(&PRGM_[0]);
    int8_t HSPRITE_ = ESP_RecupeLineY(pgm_read_byte(&PRGM_[1]));
    int8_t STARTY = ESP_RecupeLineY(y_);
    int8_t BL_STARTY = STARTY;

    if (STARTY < 0) STARTY = 0;

    if ((pgm_read_byte(&PRGM_[1]) - (HSPRITE_ << 3)) != 0) {
      HSPRITE_++;
    }

    uint8_t endY = BL_STARTY + HSPRITE_ + 1;

    for (int16_t y = STARTY; y < endY; y++) {

      if (y > 63) break;


      for (int16_t x = x_; x < (WSPRITE_ + x_); x++) {

        if (x > 127) break;
        uint16_t addr = x + (y << 7);
        if (addr < 128*64/8)
          Disp_1->buffer[addr] |= ESP_blitzSprite(x_, y_, HSPRITE_, x, y, F_, PRGM_);
      }
    }
  }

  void drawErase(int8_t x_, int8_t y_, uint8_t const *PRGM_, uint8_t F_) {

    if ((y_ > 63) || (x_ < -16) || (y_ < -16)) return;


    uint8_t WSPRITE_ = pgm_read_byte(&PRGM_[0]);
    int8_t HSPRITE_ = ESP_RecupeLineY(pgm_read_byte(&PRGM_[1]));
    int8_t STARTY = ESP_RecupeLineY(y_);
    int8_t BL_STARTY = STARTY;

    if (STARTY < 0) STARTY = 0;


    if ((pgm_read_byte(&PRGM_[1]) - (HSPRITE_ << 3)) != 0) {
      HSPRITE_++;
    }


    uint8_t endY = BL_STARTY + HSPRITE_ + 1;

    for (int16_t y = STARTY; y < endY; y++) {

      if (y > 63) break;


      for (int16_t x = x_; x < (WSPRITE_ + x_); x++) {

        if (x > 127) break;

        uint16_t addr = x + (y << 7);
        if (addr < 128*64/8)
          Disp_1->buffer[addr] &= ~(ESP_blitzSprite(x_, y_, HSPRITE_, x, y, F_, PRGM_));
      }
    }
  }

  void drawInvertPixel(int8_t x_, int8_t y_, uint8_t const *PRGM_, uint8_t F_) {

    if ((y_ > 63) || (x_ < -16) || (y_ < -16)) return;


    uint8_t WSPRITE_ = pgm_read_byte(&PRGM_[0]);
    int8_t HSPRITE_ = ESP_RecupeLineY(pgm_read_byte(&PRGM_[1]));
    int8_t STARTY = ESP_RecupeLineY(y_);
    int8_t BL_STARTY = STARTY;

    if (STARTY < 0) STARTY = 0;


    if ((pgm_read_byte(&PRGM_[1]) - (HSPRITE_ << 3)) != 0) {
      HSPRITE_++;
    }


    uint8_t endY = BL_STARTY + HSPRITE_ + 1;

    for (int16_t y = STARTY; y < endY; y++) {

      if (y > 63) break;


      for (int16_t x = x_; x < (WSPRITE_ + x_); x++) {

        if (x > 127) break;

        uint16_t addr = x + (y << 7);
        if (addr < 128*64/8)
          Disp_1->buffer[addr] ^= ESP_blitzSprite(x_, y_, HSPRITE_, x, y, F_, PRGM_);
      }
    }
  }

  void drawOverwrite(int8_t x_, int8_t y_, uint8_t const *PRGM_, uint8_t F_) {

    if ((y_ > 63) || (x_ < -16) || (y_ < -16)) return;


    uint8_t WSPRITE_ = pgm_read_byte(&PRGM_[0]);
    int8_t HSPRITE_ = ESP_RecupeLineY(pgm_read_byte(&PRGM_[1]));
    int8_t STARTY = ESP_RecupeLineY(y_);
    int8_t BL_STARTY = STARTY;

    if (STARTY < 0) STARTY = 0;


    if ((pgm_read_byte(&PRGM_[1]) - (HSPRITE_ << 3)) != 0) {
      HSPRITE_++;
    }


    int16_t endY = BL_STARTY + HSPRITE_ + 1;

    for (int16_t y = STARTY; y < endY; y++) {

      if (y > 63) break;


      for (int16_t x = x_; x < (WSPRITE_ + x_); x++) {

        if (x > 127) break;

        uint16_t addr = x + (y << 7);
        if (addr < 128*64/8){
          Disp_1->buffer[addr] &= BlackSquare(y_, y, PRGM_);
          Disp_1->buffer[addr] |= ESP_blitzSprite(x_, y_, HSPRITE_, x, y, F_, PRGM_);
        }
      }
    }
  }

  uint8_t BlackSquare(int8_t y, uint8_t yPASS, const uint8_t *PRGM_) {
    uint8_t Result = 0xff;

    uint8_t Line = ESP_RecupeLineY(y);
    uint8_t Dec = ESP_RecupeDecalageY(y);

    uint8_t MH = pgm_read_byte(&PRGM_[1]);
    uint8_t MH_Line = ESP_RecupeLineY(MH + y);
    uint8_t DecH = ESP_RecupeDecalageY(MH + y);

    if (((yPASS * 8) > y) && (((yPASS * 8) + 7) < (MH + y))) {
      return 0x00;
    }

    if (Line == yPASS) {
      Result >>= (8 - Dec);
    }

    if (MH_Line == yPASS) {
      Result <<= DecH;
    }

    return Result;
  }
};

void MEGA_Sound(uint8_t freq_, uint8_t dur) {
  ESP.wdtFeed();
  if (freq_ == 0) {
    My_delay_ms(dur);
    goto END;
  }
  for (uint8_t t = 0; t < dur; t++) {
    if (freq_ != 0) {
      digitalWrite(PIN_, SOUND_ON_OFF);
    }
    for (uint8_t t = 0; t < (255 - freq_); t++) {
      My_delay_us(1);
    }
    digitalWrite(PIN_, LOW);
    for (uint8_t t = 0; t < (255 - freq_); t++) {
      My_delay_us(1);
    }
  }
END:;
  digitalWrite(PIN_, LOW);
}


void MEGA_PLAY_MUSIC(const uint8_t *Music_) {
  uint8_t t, to_ = pgm_read_byte(&Music_[0]);
  for (t = 1; t < to_; t = t + 2) {
    MEGA_Sound(pgm_read_byte(&Music_[t]), pgm_read_byte(&Music_[t + 1]));
  }
}

#endif
