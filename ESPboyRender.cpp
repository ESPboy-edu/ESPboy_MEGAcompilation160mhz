/*
ESPboy_render class to render ssd1306 to TFT
for www.ESPboy.com project by RomanS
https://hackaday.io/project/164830-espboy-games-iot-stem-for-education-fun
v1.0
*/

#include "ESPboyRender.h"

ESPboyRender::ESPboyRender(TFT_eSPI *tftparameter){
  tft=tftparameter;
};

void ESPboyRender::init(){
  tft->fillScreen(TFT_BLACK);
};


void ESPboyRender::display(){
  static uint16_t oBuffer[128*16];
  static uint8_t currentDataByte;
  static uint16_t foregroundColor, backgroundColor, xPos, yPos, kPos, kkPos, addr;

  //foregroundColor = LHSWAP((uint16_t)TFT_YELLOW);
  //backgroundColor = LHSWAP((uint16_t)TFT_BLACK);
  
  foregroundColor = colors[foregroundclr];
  backgroundColor = colors[backgroundclr];
  
  for(kPos = 0; kPos<4; kPos++){  //if exclude this 4 parts screen devision and process all the big oBuffer, EPS8266 resets (
    kkPos = kPos<<1;
    for (xPos = 0; xPos < 128; xPos++) {
      for (yPos = 0; yPos < 16; yPos++) {		
		    if (!(yPos % 8)) currentDataByte = buffer[xPos + ((yPos>>3)+kkPos) * 128];
		    addr = 	yPos*128+xPos;
            if (currentDataByte & 0x01) oBuffer[addr] = foregroundColor;
            else oBuffer[addr] = backgroundColor;
			currentDataByte = currentDataByte >> 1;
	  }
    }
    tft->pushImage(0, 20+kPos*16, 128, 16, oBuffer);
  }
};


void ESPboyRender::flipScreenVertically(){};

void ESPboyRender::setContrast(uint8_t no){};
