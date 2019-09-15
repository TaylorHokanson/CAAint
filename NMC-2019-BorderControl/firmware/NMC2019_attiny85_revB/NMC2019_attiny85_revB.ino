/*
Firmware for the Bontrager/Hokanson BadgeCulture project: New Media Caucus 2019 Symposium edition
http://bit.ly/badgeculture for more information and code/designs!
*/

int timeOn = 100;
int timeOff = 50;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  for (int x=0; x++; x<5){
    digitalWrite(x, LOW);// set all leds to LOW on boot
  }
}

void loop() {
  for (int x=0; x<5; x++){ //light the leds from left to right
    digitalWrite(x, HIGH);
    delay(timeOn);
    digitalWrite(x, LOW);
    delay(timeOff);
  }
  for (int x=4; x>=0; x--){ //light the leds from right to left
    digitalWrite(x, HIGH);
    delay(timeOn);
    digitalWrite(x, LOW);
    delay(timeOff);
  }
}
