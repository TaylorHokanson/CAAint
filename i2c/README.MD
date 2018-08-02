1. Populate breakout board with components (Attiny, LEDs, resistors, capacitor, headers)
2. Attach [AVR programmer](https://www.sparkfun.com/products/9825) to breakout (taking careful note of polarity, see breakout silkscreen)
3. Select "power device" on programmer via switch
4. Connect programmer to computer via USB
5. Download and install [board definitions](https://github.com/damellis/attiny) for Attiny
6. Set the following in the Arduino IDE Tools menu:

   - Board: Attiny 25/45/85
   Processor: Attiny85
- Clock: 1Mhz
- Port: Leave this alone
- Programmer: USBTinyISP

