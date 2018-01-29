/* Required libraries:
 * u8g2
 * Adafruit Neopixel
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define LEDPIN 27

#include <U8x8lib.h>

const int btn_up = 34;
const int btn_dn = 14;
const int btn_rt = 12;
const int btn_lt = 13;
const int btn_enter = 35;

// the OLED used
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);

Adafruit_NeoPixel strip = Adafruit_NeoPixel(3, LEDPIN, NEO_GRB + NEO_KHZ800);


void setup() {
  // put your setup code here, to run once:
strip.begin();
strip.setBrightness(10);
  strip.show();

  pinMode(btn_up, INPUT);
  pinMode(btn_dn, INPUT_PULLUP);
  pinMode(btn_lt, INPUT_PULLUP);
  pinMode(btn_rt, INPUT_PULLUP);
  pinMode(btn_enter, INPUT);

  u8x8.begin();
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.setFlipMode(1);
}


void loop() {
  // put your main code here, to run repeatedly:
//rainbowCycle(20);
// if (digitalRead(btn_dn) == LOW)
 // { // Check if button has been pressed
  // u8x8.drawString(0, 1, "Down Button");
 // }
  if (digitalRead(btn_lt) == LOW)
  { // Check if button has been pressed
    u8x8.drawString(0, 1, "Left Button");
  }
  else if (digitalRead(btn_rt) == LOW)
  { // Check if button has been pressed
    u8x8.drawString(0, 1, "Right Button");
  }
//  else if (digitalRead(btn_enter) == LOW)
//  { // Check if button has been pressed
//    u8x8.drawString(0, 1, "Enter Button");
//  }
  else {
    u8x8.drawString(0,1,"no buttons");
  }
u8x8.drawString(0, 0, "Button Checker");
}

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
