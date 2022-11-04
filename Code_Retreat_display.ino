#define TFT_DC     13
#define TFT_CS     11
#define TFT_MOSI    9
#define TFT_CLK    15
#define TFT_MISO    8
#define TFT_BL      6
#define TFT_RST    16

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

// Color definitions
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

SPIClass TFT_SPI = SPIClass(HSPI);
Adafruit_ILI9341 tft = Adafruit_ILI9341(&TFT_SPI, TFT_DC, TFT_CS, TFT_RST);

void draw(){
  tft.fillScreen(BLACK);
  for(int y = 0; y < ARRAY_SIZE; ++y){
    for(int x = 0; x < ARRAY_SIZE; ++x){
      //printf("[%d][%d]=%d\n",x,y,cell_map[x][y].current_state);

      // Print small arrays as asterisks
      //tft.setCursor(3+x*10, 3+y*10); tft.printf(cell_map[x][y].current_state ? "*" : " ");

      // Print large arrays as quad pixel
      if(cell_map[x][y].current_state){
        tft.drawPixel(2*x, 2*y, YELLOW);
        tft.drawPixel(2*x+1, 2*y, YELLOW);
        tft.drawPixel(2*x, 2*y+1, YELLOW);
        tft.drawPixel(2*x+1, 2*y+1, YELLOW);
      }
    }
  }
}


void display_setup() {
  TFT_SPI.begin(TFT_CLK, TFT_MISO, TFT_MOSI, -1);
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, LOW);
  tft.begin();
  tft.setRotation(2);
  tft.setTextColor(YELLOW);
  tft.setFont(NULL);
  tft.setTextSize(1);
}
