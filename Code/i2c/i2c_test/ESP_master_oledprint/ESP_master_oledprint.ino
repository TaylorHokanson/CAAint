/* 
 * For ESP32-WROOM board (OLED, battery, full pin breakout) 
 * 
 * Board:   Wemos Wifi&Bluetooth Battery 
 * Flash:   80Mhz
 * Upload:  921600
 * Port:    cu.SLAB_USBtoUART
 * Prog:    AVRISPmkII
 * 
 * ESP 21   >>  Attiny SDA
 * ESP 22   >>  Attiny SCL
 * ESP VCC  >>  Attiny VCC
 * ESP GND  >>  Attiny GND
 * 
 */

#include <Wire.h>
#include <U8x8lib.h>  //this is inside the required library U8g2

// the OLED used
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 4, /* data=*/ 5, /* reset=*/U8X8_PIN_NONE );
 
void setup()
{
 Wire.begin();            // join i2c bus (address optional for master)
 Serial.begin(9600);      // start serial for output
  u8x8.begin();
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.setFlipMode(1);    //remove if screen is flipped
}
 
void loop()
{
 Wire.requestFrom(4, 1);  // request 1 byte from slave device address 4
 
while(Wire.available())   // slave may send less than requested
 {
 int i = Wire.read();     // receive a byte as character
 Serial.println(i);       // print the character
 u8x8.drawString(0, 0, "Counter: ");
 u8x8.setCursor(0, 1); //set position for incoming counter digits
 u8x8.print(i);
 }
 
delay(500);

// debug, should work even if the tiny is not sending
// Serial.println("testing...");

}
