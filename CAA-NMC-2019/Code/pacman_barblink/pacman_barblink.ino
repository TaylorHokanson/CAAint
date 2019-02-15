/*
 * This is a modified version of the "strandtest" sketch from the Adafruit 
 * Neopixel library, for use in the BADGECULTURE project. To run this demo 
 * as intended, you need:
 *  Arduino IDE (with neopixel library installed: https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-installation)
 *  Mini USB cable
 *  USBTinyISP programmer
 *  Reflowed BADGECULTURE board
 * 
 * IDE settings:
 *  Board:      ATTiny 25/45/85
 *  Processor:  Attiny85
 *  Clock:      8mhz
 *  Programmer: USBTinyISP
 *  
 * Make sure the USBTinyISP is set to power the target device.
 * Before you can upload code, you must first burn the bootloader.
 * Finally, with all programming settings the same, upload the code.
 * 
 * See bit.ly/BADGECULTURE for more info.
 */
// 

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define NUMPIX 2    // verfiy the number of pixels on your board
#define PIN 4       // verfiy the Attiny control pin
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIX, PIN, NEO_GRB + NEO_KHZ800);

// I left the following in, though we haven't found the huge cap necessary with few pixels (so far)

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  strip.begin();
  strip.setBrightness(50);    // To save batteries and eyeballs
  strip.show();               // Initialize all pixels to 'off'
}

void loop() {
  for(int x=0;x<20;x++){
    rainbow(1);
  
  rainbowCycle(10);
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
