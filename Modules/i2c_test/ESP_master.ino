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
 
void setup()
{
 Wire.begin();            // join i2c bus (address optional for master)
 Serial.begin(9600);      // start serial for output
}
 
void loop()
{
 Wire.requestFrom(4, 1);  // request 1 byte from slave device address 4
 
while(Wire.available())   // slave may send less than requested
 {
 int i = Wire.read();     // receive a byte as character
 Serial.println(i);       // print the character
 }
 
delay(500);

// debug, should work even if the tiny is not sending
// Serial.println("testing...");

}
