/* 
 * For ESP32-WROOM board (OLED, battery, full pin breakout) 
 * Don't forget to turn the device on, or it won't show up in the port list
 * 
 * Board:   Wemos Wifi&Bluetooth Battery 
 * Flash:   80Mhz
 * Upload:  921600
 * Port:    cu.SLAB_USBtoUART
 * Prog:    AVRISPmkII
 * 
 */

//this is inside the required library U8g2
#include <U8x8lib.h>  

// the OLED used
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 4, /* data=*/ 5, /* reset=*/U8X8_PIN_NONE );

const int led = 16;
int navBtn = 0;

const int buttonPin1 = 0;    // the number of the pushbutton pin
const int buttonPin2 = 2;    // the number of the pushbutton pin
const int buttonPin3 = 15;    // the number of the pushbutton pin
const int buttonPin4 = 18;    // the number of the pushbutton pin
const int buttonPin5 = 19;    // the number of the pushbutton pin

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers



void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  u8x8.begin();
  u8x8.setFont(u8x8_font_pxplusibmcga_r);
  u8x8.setFlipMode(1);    //remove if screen is flipped

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);

}

void loop(){
     
  pollNavBtn();
  sampleMenu();
    
/*
  digitalWrite(led,LOW);  //onboard LED is on when pulled LOW
  delay(100);
  digitalWrite(led,HIGH);
*/

  delay(3000);
  
}

void sampleMenu(){
  
  
  u8x8.setFont(u8x8_font_victoriabold8_u);
  u8x8.drawString(0,0,"MENU"); 
  u8x8.setFont(u8x8_font_victoriamedium8_u);   
  if(navBtn == 0){
    u8x8.drawString(0,2,">OPTION 1");  
    u8x8.drawString(0,3," OPTION 2");  
    u8x8.drawString(0,4," OPTION 3");  
  }else if(navBtn == 1){
    u8x8.drawString(0,2," OPTION 1");  
    u8x8.drawString(0,3,">OPTION 2");  
    u8x8.drawString(0,4," OPTION 3");  
  }else{
    u8x8.drawString(0,2," OPTION 1");    
    u8x8.drawString(0,3," OPTION 2");    
    u8x8.drawString(0,4,">OPTION 3");    
  } 
/*
  if(navBtn < 3){
    navBtn++;
  }else{
    navBtn = 0;
  }
*/
}

void pollNavBtn(){
    // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin1);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        navBtn++;
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}


