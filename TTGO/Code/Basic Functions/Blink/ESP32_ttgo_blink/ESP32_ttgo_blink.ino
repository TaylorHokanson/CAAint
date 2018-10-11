/**
   ESP32 TTGO Blink
   Date: 3 October 2018
   Author: Nick Bontrager <https://github.com/nabontra>
   Description: Demonstrate blink example
   
    * Board:   Wemos Wifi&Bluetooth Battery 
    * Flash:   80Mhz
    * Upload:  921600
    * Prog:    AVRISPmkII
    * 
    * Hold the Boot button on the TTGO i`f ESPtool.py is timing out during upload.
    * Required libraries: u8g2, Adafruit Neopixel
**/
#include <U8x8lib.h> 
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define RGBLEDPIN 17  //identify start of RGB leds
const int ledPin =  16;
// OLED
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 4, /* data=*/ 5, /* reset=*/U8X8_PIN_NONE );
Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, RGBLEDPIN, NEO_GRB + NEO_KHZ800);

int flashdelay = 250;
char currentcount[16];

void setup() {
  //Serial.begin(115200);
  strip.begin();  //init RGB leds
  strip.setBrightness(10);
  strip.show();
  pinMode(ledPin, OUTPUT);
  u8x8.begin();
  u8x8.setFont(u8x8_font_pxplusibmcga_r);
  u8x8.setFlipMode(1);        //remove if screen should be rotated 180 degrees

  //Serial.println("ESP32 Blink Example");
  u8x8.drawString(0, 0, "BLINK EXAMPLE");
  
}

void loop() {
  u8x8.drawString(0, 1, "LED:");
  digitalWrite(ledPin, LOW); //onboard TTGO blue led is active low
  u8x8.drawString(5, 1, "LOW ");
  delay(flashdelay*2);
  digitalWrite(ledPin, HIGH);//turn off TTGO onboard blue led
  u8x8.drawString(5, 1, "HIGH");
  delay(flashdelay*2);
  
  for(int i=0; i<strip.numPixels(); i++){
  u8x8.drawString(0, 1, "L  :");
  itoa(i,currentcount,10); //convert counting integer to const char* for display
  u8x8.drawString(1, 1, currentcount);
  strip.setPixelColor(i,100);
  strip.show();
  delay(flashdelay);
  strip.setPixelColor(i,0);
  strip.show();
  delay(flashdelay);
  }
}
