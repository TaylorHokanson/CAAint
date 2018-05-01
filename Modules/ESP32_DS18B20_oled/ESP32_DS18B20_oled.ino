/* 
 * For ESP32-WROOM board (OLED, battery, full pin breakout) 
 * 
 * Board:   Wemos Wifi&Bluetooth Battery 
 * Flash:   80Mhz
 * Upload:  921600
 * Port:    cu.SLAB_USBtoUART
 * Prog:    AVRISPmkII
 * 
 * 
 * ESP 22   >>  Temperature sensor signal
 * ESP VCC  >>  Temp vcc
 * ESP GND  >>  temp GND
 * 
 */
#include <U8x8lib.h>  //this is inside the required library U8g2
#include <OneWire.h>
// OneWire DS18S20, DS18B20, DS1822 Temperature Example

// the OLED used
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 4, /* data=*/ 5, /* reset=*/U8X8_PIN_NONE );

OneWire  ds(22);  // on pin 3 (a 4.7K pullup resistor is necessary)

void setup() {
  Serial.begin(9600);
  u8x8.begin();
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.setFlipMode(1);    //remove if screen is flipped
}

void loop(){
  
  byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  float celsius, fahrenheit;
  
  if ( !ds.search(addr)) {
    Serial.println("No more addresses.");
    Serial.println();
    ds.reset_search();
    delay(250);
    return;
  }
  
  Serial.print("ROM =");
  for( i = 0; i < 8; i++) {
    Serial.write(' ');
    Serial.print(addr[i], HEX);
  }

  if (OneWire::crc8(addr, 7) != addr[7]) {
      Serial.println("CRC is not valid!");
      return;
  }
  Serial.println();

  u8x8.drawString(0, 0, "Chip: ");
 
  // the first ROM byte indicates which chip
  switch (addr[0]) {
    case 0x10:
      Serial.println("  Chip = DS18S20");  // or old DS1820
      u8x8.drawString(6, 0, "DS18S20");
      type_s = 1;
      break;
    case 0x28:
      Serial.println("  Chip = DS18B20");
      u8x8.drawString(6, 0, "DS18B20");
      type_s = 0;
      break;
    case 0x22:
      Serial.println("  Chip = DS1822");
      u8x8.drawString(6, 0, "DS1822");
      type_s = 0;
      break;
    default:
      Serial.println("Device is not a DS18x20 family device.");
      u8x8.drawString(6, 0, "not a DS18x20!");
      return;
  } 

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);        // start conversion, with parasite power on at the end
  
  delay(1000);     // maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.
  
  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);         // Read Scratchpad

  Serial.print("  Data = ");
  Serial.print(present, HEX);
  Serial.print(" ");
  for ( i = 0; i < 9; i++) {           // we need 9 bytes
    data[i] = ds.read();
    Serial.print(data[i], HEX);
    Serial.print(" ");
  }
  Serial.print(" CRC=");
  Serial.print(OneWire::crc8(data, 8), HEX);
  Serial.println();

  // Convert the data to actual temperature
  // because the result is a 16 bit signed integer, it should
  // be stored to an "int16_t" type, which is always 16 bits
  // even when compiled on a 32 bit processor.
  int16_t raw = (data[1] << 8) | data[0];
  if (type_s) {
    raw = raw << 3; // 9 bit resolution default
    if (data[7] == 0x10) {
      // "count remain" gives full 12 bit resolution
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    // at lower res, the low bits are undefined, so let's zero them
    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
    //// default is 12 bit resolution, 750 ms conversion time
  }
  celsius = (float)raw / 16.0;
  fahrenheit = celsius * 1.8 + 32.0;
  Serial.print("  Temperature = ");
  Serial.print(celsius);
  Serial.print(" Celsius, ");
  Serial.print(fahrenheit);
  Serial.println(" Fahrenheit");
 
  u8x8.drawString(0, 1, "Celsius: ");
  u8x8.setCursor(11, 1);
  u8x8.print(celsius);
  u8x8.drawString(0, 2, "Fahrenheit: ");
  u8x8.setCursor(11, 2);
  u8x8.print(fahrenheit);

delay(5000);
}

