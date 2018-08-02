// Attiny Hello World
// Will blink an LED attached to pin 0
// Don't forget to burn bootloader first

int ledPin = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);   
  delay(1000);              
  digitalWrite(ledPin, LOW); 
  delay(1000);              
}
