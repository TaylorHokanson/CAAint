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

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  u8x8.begin();
  u8x8.setFont(u8x8_font_pxplusibmcga_r);
  u8x8.setFlipMode(1);    //remove if screen is flipped
}

void loop(){
     
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

  if(navBtn < 3){
    navBtn++;
  }else{
    navBtn = 0;
  }
}

