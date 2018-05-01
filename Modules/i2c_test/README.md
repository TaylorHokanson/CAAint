1. Install ESP32 harware def [here](https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/mac.md).
2. Replace some files as detailed [here](https://desire.giesecke.tk/index.php/2018/04/20/how-to-use-stickbreakers-i2c-improved-code/).
3. Upload master code to ESP32 dev board.
4. Upload slave code to Attiny85.
5. Open a serial port and you should see incrementing numbers.

6. If using the OLED example, make sure to install the required Arduino U8g2 library before uploading.