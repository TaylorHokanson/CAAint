# CAAint
An open source badge project for noobs, artists, and the interdimensionally-curious

## Functions
1. Must be Arduino IDE programmable?
2. Must include ESP mesh networking?
3. Could store interests, then respond when near participants with similar interests.

## Links
1. https://www.jameco.com/jameco/workshop/jamecobuilds/arduinocircuit.html
2. https://arduinodiy-wordpress-com.cdn.ampproject.org/c/s/arduinodiy.wordpress.com/2016/09/30/adding-an-rtc-and-oled-to-esp8266-01/amp/
3. https://www.digikey.com/en/maker/blogs/01f5c0fa4b6445f3b71866447f400d8d

## NodeMCU

### Hardware BOM
Part | Cost
--- | ---
[NodeMCU](https://www.amazon.com/gp/product/B010O1G1ES/ref=oh_aui_detailpage_o00_s01?ie=UTF8&psc=1) | $9*
[OLED](https://www.amazon.com/gp/product/B072FJRNWV/ref=oh_aui_detailpage_o00_s01?ie=UTF8&psc=1) | $8*
*way cheaper on AliExpress | $?

### Breadboard Setup
NodeMCU | OLED
--- | ---
3V3 | VCC
GND | GND
D1 | SCL
D2 | SDA

### NodeMCU test
2. Arduino > Preferences > Additional Board Manager URLs
3. Add ```http://arduino.esp8266.com/stable/package_esp8266com_index.json``` to the list
4. Tools > Board > Board Manager
5. Search for ESP, install "esp2866 by ESP2866 Community"
6. Install [this driver](https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver).
7. Plug the board into the USB ports on the right side of your computer. I don't know why, but I had to do this to get things working.
7. Back in the IDE, Select NODEMCU 1.0 as your board and pick the corresponding port.
8. Examples > ESP8266WebServer > SimpleAuthentication
1. The [default upload speed](http://www.esp8266.com/viewtopic.php?f=32&t=2626&sid=0d51751c466764477328d679d83d98ba&start=4) (115200) is slow. I got 230420 to work, YMMV.
9. Enter the login credentials of a wifi network within range and upload the sketch to the board.

### OLED test
1. Download the sketch, follow instructions in comments

### NodeMCU Firmware Update
1. Request a vanilla Master build [here](https://nodemcu-build.com/index.php). This takes a little time.
2. Follow these instructions starting with [Install ESPTool](https://github.com/nodemcu/nodemcu-devkit/wiki/Getting-Started-on-OSX).

### Notes
1. Tested on a 2017 MacBook Pro, running Sierra 10.12.6 and Arduino 1.8.4 
3. Battery power may be an issue, but it sounds like all wifi modules are power hungry.
4. There are three versions: V1/.9, V2/1.0, V3. V1 is not breadboard friendly. V3 is unofficial AFAIK. We'll use V2/1.0.
5. [ESP8266](http://arduino-esp8266.readthedocs.io/en/latest/index.html) (the wifi chip on the NodeMCU) is able to operate both in
"station" and "soft access point" mode. This dual function allows for [mesh networks](http://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/readme.html#who-is-who).
6. Sometimes my code leads the NodeMCU to reset over and over. I'll go
through [these](https://stackoverflow.com/questions/31083757/esp8266-constantly-restarting) 
troubleshooting steps eventually. Now that I've flashed the
firmware, I think it's an issue with the watchdog tripping when strings
take too long to send.

