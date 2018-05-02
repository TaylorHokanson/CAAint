// Tested on UNO

// Based on Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

#include <Wire.h>

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  Wire.requestFrom(10, 2);    // request x bytes from slave device #y

  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
  }
  Serial.println("");         
  delay(1000);
}
