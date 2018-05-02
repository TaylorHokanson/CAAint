
/*  Based on the slave_sender example in the TinyWire library
 *  https://github.com/lucullusTheOnly/TinyWire
 *  
 *  Photoresistor leg 1 >> 3.3V
 *  Photoresistor leg 2 >> 10k resistor >> GND
 *  Photoresistor leg 2 >> Attiny A3
 *  
 *  Connect Attiny SDA and SCL to UNO SDA and SCL
 *  Supply 3.3V and GND to Attiny from UNO
 *  
 *  Attiny85 pinout:     
 *  
 *       RST -|*  |- 3.3/5V
 *      A3/3 -|   |- A1/2   <-- SCL
 *      A2/4 -|   |- PWM/1
 *       GND -|   |- 0/PWM  <-- SDA
 */

#include <TinyWire.h>

byte own_address = 10;
// can't use A1 with ic2?
int analogInPin = A3;

void setup() {
	// config TinyWire library for I2C slave functionality
	TinyWire.begin( own_address );
	// register a handler function in case of a request from a master
	TinyWire.onRequest( onI2CRequest );
   pinMode(analogInPin, INPUT);
}

void loop() {

}

// Request Event handler function
//  --> Keep in mind, that this is executed in an interrupt service routine. It shouldn't take long to execute
void onI2CRequest() {
  
  // take sensor reading and add descriptive text
  int analogReading = analogRead(analogInPin);  
  String contextText = "Sensor: ";
  String sensorReading = contextText + analogReading;
  
  // ascertain the string length and convert to char array
  char charBuf[sensorReading.length()+1];
  sensorReading.toCharArray(charBuf, sensorReading.length()+1); 
  
  // send the character array to master
  for (int i = 0; i < sizeof(charBuf) - 1; i++){
    TinyWire.send(charBuf[i]);
  }

  // fill the rest of the 32 byte request with neutral chars and send
  int bytesLeft = 32 - sizeof(charBuf);
  for (int i = 0; i < bytesLeft; i++){
    TinyWire.send('.');
  }

  sensorReading = "";
  
}
