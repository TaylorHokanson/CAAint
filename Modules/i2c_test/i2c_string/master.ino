/* Tested on the Arduion UNO
 * Connect SDA/SDL/3.3V/GND to Attiny85 running slave code
 * Open Serial port to see results
 * Don't forget to match up your slave device ID below
 *
 * based on Wire Master Reader
 * by Nicholas Zambetti <http://www.zambetti.com>
*/

#include <Wire.h>

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  Wire.requestFrom(10, 32);    // request 32 bytes from slave device #10

  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
  }
  Serial.println("");         
  delay(1000);
}
