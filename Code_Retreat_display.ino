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
int multi = 0;
// Print small arrays as asterisks
void draw_asterisk(int x, int y){
  tft.setCursor(3+x*10, 3+y*10); tft.printf(cell_map[x][y].current_state ? "*" : " ");
}

// Print medium arrays as quad pixel
void draw_quad(int x, int y){
  if(cell_map[x][y].current_state){
    tft.drawPixel(2*x, 2*y, YELLOW);
    tft.drawPixel(2*x+1, 2*y, YELLOW);

    tft.drawPixel(2*x, 2*y+1, YELLOW);
    tft.drawPixel(2*x+1, 2*y+1, YELLOW);
  }
}

// Print large arrays as nona pixel (3x3)
void draw_nona(int x, int y){
  if(cell_map[x][y].current_state){
    tft.drawPixel(3*x, 3*y, YELLOW);
    tft.drawPixel(3*x+1, 3*y, YELLOW);
    tft.drawPixel(3*x+2, 3*y, YELLOW);

    tft.drawPixel(3*x, 3*y+1, YELLOW);
    tft.drawPixel(3*x+1, 3*y+1, YELLOW);
    tft.drawPixel(3*x+2, 3*y+1, YELLOW);

    tft.drawPixel(3*x, 3*y+2, YELLOW);
    tft.drawPixel(3*x+1, 3*y+2, YELLOW);
    tft.drawPixel(3*x+2, 3*y+2, YELLOW);
  }
}

void draw(){
  tft.fillScreen(BLACK);
  for(int y = 0; y < ARRAY_SIZE; ++y){
    for(int x = 0; x < ARRAY_SIZE; ++x){
      //printf("[%d][%d]=%d\n",x,y,cell_map[x][y].current_state);
#ifdef DRAW_ASTERISK
      draw_asterisk(x,y);
#endif
#ifdef DRAW_QUAD
      //draw_quad(x,y);
#endif
#ifdef DRAW_NONA
      draw_nona(x,y);
#endif
    }
  }
  //tft.fillRect(0, ARRAY_SIZE*2, 300, 300, WHITE);
  tft.drawFastHLine(0,ARRAY_SIZE*multi,300, YELLOW);
  tft.drawFastVLine(ARRAY_SIZE*multi,0,300, YELLOW);
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

#ifdef DRAW_ASTERISK
  multi = 1;
#endif
#ifdef DRAW_QUAD
  multi = 2;
#endif
#ifdef DRAW_NONA
  multi = 3;
#endif
}
