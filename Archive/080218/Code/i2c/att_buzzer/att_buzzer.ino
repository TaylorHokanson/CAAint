// Attiny85 buzzer
// Worked for me at 8mhz
// Attiny Pin 4 >> 220 Ohm resistor >> Piezo buzzer or 8 Ohm / 1 Watt speaker >> GND
// Largely copied from http://www.technoblogy.com/show?20MO

// Can be 1 or 4
const int Output = 4;   

// Cater for 16MHz, 8MHz, or 1MHz clock:
const int Clock = ((F_CPU/1000000UL) == 16) ? 4 : ((F_CPU/1000000UL) == 8) ? 3 : 0;
const uint8_t scale[] PROGMEM = {239,226,213,201,190,179,169,160,151,142,134,127};

void setup() {

}

void loop() {
  for (int n=0; n<=12; n++) {
    note(n, 4);
    if (n!=4 && n!=11) n++;
    delay(100);
  }
  note(0, 0);
  delay(100);
}

void note (int n, int octave) {
  int prescaler = 8 + Clock - (octave + n/12);
  if (prescaler<1 || prescaler>15 || octave==0) prescaler = 0;
  DDRB = (DDRB & ~(1<<Output)) | (prescaler != 0)<<Output;
  OCR1C = pgm_read_byte(&scale[n % 12]) - 1;
  GTCCR = (Output == 4)<<COM1B0;
  TCCR1 = 1<<CTC1 | (Output == 1)<<COM1A0 | prescaler<<CS10;
}
