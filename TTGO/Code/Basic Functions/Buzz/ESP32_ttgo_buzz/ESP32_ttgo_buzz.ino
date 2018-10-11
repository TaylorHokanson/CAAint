/**
   ESP32 TTGO Buzzer
   Date: 9 October 2018
   Author: Nick Bontrager <https://github.com/nabontra>
   Description: Demonstrate buzzer example
   
    * Board:   Wemos Wifi&Bluetooth Battery 
    * Flash:   80Mhz
    * Upload:  921600
    * Prog:    AVRISPmkII
    * 
    * Hold the Boot button on the TTGO if ESPtool.py is timing out during upload.
    * Required libraries: u8g2
**/
#include <U8x8lib.h> 
#ifdef __AVR__
  #include <avr/power.h>
#endif

const int ledPin =  16; //onboard LED
// OLED
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 4, /* data=*/ 5, /* reset=*/U8X8_PIN_NONE );

int freq = 2000;
int channel = 0;
int resolution = 8;
char tonedisplay[16];

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); //turn off onboard LED
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(15, channel);
  u8x8.begin();
  u8x8.setFont(u8x8_font_pxplusibmcga_r);
  u8x8.setFlipMode(1);        //remove if screen should be rotated 180 degrees
  u8x8.drawString(0, 0, "BUZZ EXAMPLE");
}

void loop() {
  u8x8.draw2x2String(0, 2, "BUZZ!");
  ledcWriteTone(channel, 50); //use low 50hz tone for dutyCycle test
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle=dutyCycle+10){
    itoa(dutyCycle,tonedisplay,10); //convert dutyCycle integer to const char* for display
    u8x8.drawString(0, 5, "DUTY:       ");
    u8x8.drawString(5, 5, tonedisplay);
    ledcWrite(channel, dutyCycle);
    delay(1000);
  }
 
  ledcWrite(channel, 50); //lower duty cycle before frequency test
  
  for (int freq = 255; freq < 10000; freq = freq + 250){
     itoa(freq,tonedisplay,10); //convert dutyCycle integer to const char* for display
     u8x8.drawString(0, 5, "FREQ:       ");
    u8x8.drawString(5, 5, tonedisplay);
     ledcWriteTone(channel, freq);
     delay(1000);
  }
}
