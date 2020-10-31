/*
ESPboy_render class to render ssd1306 to TFT
for www.ESPboy.com project by RomanS
https://hackaday.io/project/164830-espboy-games-iot-stem-for-education-fun
v1.0
*/

#ifndef ESPboy_render
#define ESPboy_render

#define LHSWAP(w) (uint16_t)((((uint16_t)w)>>8)|(((uint16_t)w)<<8))

#include <Arduino.h>
#include <TFT_eSPI.h>          //to draw at LCD TFT

class ESPboyRender{

private:
  TFT_eSPI *tft;
  uint16_t colors[19] = { 
            LHSWAP((uint16_t)TFT_BLACK), LHSWAP((uint16_t)TFT_NAVY), LHSWAP((uint16_t)TFT_DARKGREEN), LHSWAP((uint16_t)TFT_DARKCYAN), LHSWAP((uint16_t)TFT_MAROON),
            LHSWAP((uint16_t)TFT_PURPLE), LHSWAP((uint16_t)TFT_OLIVE), LHSWAP((uint16_t)TFT_LIGHTGREY), LHSWAP((uint16_t)TFT_DARKGREY), 
            LHSWAP((uint16_t)TFT_BLUE), LHSWAP((uint16_t)TFT_GREEN), LHSWAP((uint16_t)TFT_CYAN),
            LHSWAP((uint16_t)TFT_RED), LHSWAP((uint16_t)TFT_MAGENTA), LHSWAP((uint16_t)TFT_YELLOW), LHSWAP((uint16_t)TFT_WHITE), 
            LHSWAP((uint16_t)TFT_ORANGE), LHSWAP((uint16_t)TFT_GREENYELLOW), LHSWAP((uint16_t)TFT_PINK)};
   
   
public:
  uint8_t foregroundclr = 14;
  uint8_t backgroundclr = 0;
  uint8_t buffer[128*64/8];
  ESPboyRender(TFT_eSPI *tftparameter);
  void init();
  void flipScreenVertically();
  void setContrast(uint8_t no);
  void display();
};

#endif
