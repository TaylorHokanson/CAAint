/* 
 * OLED, nav button, neopixels
 * 
 * For ESP32-WROOM board (OLED, battery, full pin breakout) and custom PCB
 * Don't forget to turn the device on, or it won't show up in the port list
 * If UART disappears from port list, change board to UNO and attach an UNO
 * 
 * Board:   Wemos Wifi&Bluetooth Battery 
 * Flash:   80Mhz
 * Upload:  921600
 * Port:    cu.SLAB_USBtoUART
 * Prog:    AVRISPmkII
 * 
 * ESP pins to watch out for:
 * 4,5          OLED
 * 0,2,5,12,15  Strapping pins (boot-related)
 * 34,35        Input-only
 * 
 */

//this is inside the required library U8g2
#include <U8x8lib.h>  
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// OLED
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 4, /* data=*/ 5, /* reset=*/U8X8_PIN_NONE );

// Neopixels
#define PIN       17
#define NUMPIXELS 10
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//int delayval = 500; 

const int led = 16;
//int navBtn = 0;

// Nav button
const int buttonPin1 = 18;   // right 
const int buttonPin2 = 16;   // select      
const int buttonPin3 = 23;   // up
const int buttonPin4 = 19;   // down 
const int buttonPin5 = 14;   // left

// https://github.com/Serpent999/ESP32_Touch_LED/blob/master/Touch_LED/Touch_LED.ino
int buff(int pin){
  int out = (25 - touchRead(pin));             //  adjust touch sensitivity here
  if (out > 0 ){
    return (out + 2);
  }else{
    return 0;                                        
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  u8x8.begin();
  u8x8.setFont(u8x8_font_pxplusibmcga_r);
  //u8x8.setFlipMode(1);        //remove if screen is flipped

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);

  strip.begin();              // This initializes the NeoPixel library
  strip.show();               // Begin with all LEDs turned off 
  strip.setBrightness(5);     // These goddamn things are bright
 

}

void loop(){
     
  pollMenu();
    
/*
  digitalWrite(led,LOW);  //onboard LED is on when pulled LOW
  delay(100);
  digitalWrite(led,HIGH);
*/

  //delay(3000);
  
}

void pollMenu(){
   
  // LOW is button pressed
  u8x8.setFont(u8x8_font_victoriamedium8_u);   
  
  // Center button
  if(digitalRead(buttonPin2) == 0){
    u8x8.drawString(0,0,"X BUTTON");
    chase(strip.Color(0, 255, 0));
  }else{
    u8x8.drawString(0,0,"  BUTTON");
  } 
  
  // Upper right
  if(digitalRead(buttonPin1) == 0){
    u8x8.drawString(0,1,"X RIGHT");
    chase(strip.Color(255, 0, 0));
  }else{
    u8x8.drawString(0,1,"  RIGHT");
  } 
  
  // Upper left
  if(digitalRead(buttonPin3) == 0){
    u8x8.drawString(0,2,"X UP");
    chase(strip.Color(0, 0, 255));
  }else{
    u8x8.drawString(0,2,"  UP");
  } 
  
  // Lower right
  if(digitalRead(buttonPin4) == 0){
    u8x8.drawString(0,3,"X DOWN");
    chase(strip.Color(255, 0, 255));
  }else{
    u8x8.drawString(0,3,"  DOWN");
  }       
  
  // Lower left
  if(digitalRead(buttonPin5) == 0){
    u8x8.drawString(0,4,"X LEFT");
    chase(strip.Color(255, 255, 255));
  }else{
    u8x8.drawString(0,4,"  LEFT");
  }
  //String touchData = String(buff(T9));
  //Serial.println(touchData);
  u8x8.setCursor(0, 5);
  u8x8.print("  TOUCH " + String(buff(T9)));         
}

static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
      strip.show();
      delay(25);
  }
}

