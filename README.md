# CAAint
An open source badge project for noobs, artists, and the interdimensionally-curious

## Desired Features
1. Arduino IDE programmable
2. Mesh networking capable
3. Hacker-friendly
4. Conference-centric function
5. Post-conference function
6. Battery power

## NodeMCU
1. Versioning conventions are [funky](https://frightanic.com/iot/comparison-of-esp8266-nodemcu-development-boards/).
2. V2/Amica preferred, though Amica is hard to find on Aliexpress, might be fake anyway.
3. NodeMCU [Reference](https://nodemcu.readthedocs.io/en/master/)
4. ESP2866 Arduino Core [Reference](http://arduino-esp8266.readthedocs.io/en/latest/)

### Hardware BOM
Part | US Cost | China Cost
--- | --- | ---
NodeMCU | [$9](https://www.amazon.com/gp/product/B010O1G1ES/ref=oh_aui_detailpage_o00_s01?ie=UTF8&psc=1) | $3 [Amica](https://www.aliexpress.com/item/1pcs-Wireless-module-NodeMcu-Lua-WIFI-Internet-of-Things-development-board-based-ESP8266-CP2102-with-pcb/32719524260.html?spm=2114.search0104.3.49.782Zwp&ws_ab_test=searchweb0_0,searchweb201602_4_10152_10065_10151_10130_10068_10344_10345_10342_10343_10340_10341_10307_10060_10155_10154_10056_10055_10054_10539_10538_5370015_10537_10059_10536_10535_10534_10533_100031_10099_10338_10103_10102_10052_10053_10107_10050_10142_10051_10324_10325_10084_10083_10080_10082_10081_10178_10110_5590015_10111_10112_10113_10114_5610015_10312_10313_10314_10317_10318_10078_10079_10073-normal#cfs,searchweb201603_1,ppcSwitch_5&btsid=2aed71c2-dffe-45d4-9c74-09e8aacf4ef1&algo_expid=34137b6c-91fb-44da-b06f-060b2c408eb9-6&algo_pvid=34137b6c-91fb-44da-b06f-060b2c408eb9), [Lolin](https://www.aliexpress.com/item/1PCS-Wireless-module-CH340-NodeMcu-V3-Lua-WIFI-Internet-of-Things-development-board-based-ESP8266/32802874451.html?spm=2114.search0104.3.169.782Zwp&ws_ab_test=searchweb0_0,searchweb201602_4_10152_10065_10151_10130_10068_10344_10345_10342_10343_10340_10341_10307_10060_10155_10154_10056_10055_10054_10539_10538_5370015_10537_10059_10536_10535_10534_10533_100031_10099_10338_10103_10102_10052_10053_10107_10050_10142_10051_10324_10325_10084_10083_10080_10082_10081_10178_10110_5590015_10111_10112_10113_10114_5610015_10312_10313_10314_10317_10318_10078_10079_10073,searchweb201603_1,ppcSwitch_5&btsid=2aed71c2-dffe-45d4-9c74-09e8aacf4ef1&algo_expid=34137b6c-91fb-44da-b06f-060b2c408eb9-21&algo_pvid=34137b6c-91fb-44da-b06f-060b2c408eb9)
OLED | [$8](https://www.amazon.com/gp/product/B072FJRNWV/ref=oh_aui_detailpage_o00_s01?ie=UTF8&psc=1) | [$3](https://www.aliexpress.com/store/product/10pcs-White-Blue-White-and-Blue-color-0-96-inch-128X64-OLED-Display-Module-For-arduino/1525680_32765278698.html?spm=2114.12010615.0.0.2253f604ZQG0c1)
Shipping | 0$ | 0$ - $50

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
7. List of [reset causes](http://www.esp8266.com/viewtopic.php?p=2096#p2112).
8. Boots in SoftAP (limited connections), then switches to station
9. See [this link](http://arduino-esp8266.readthedocs.io/en/latest/libraries.html#esp-specific-apis) for info on battery saving with deep sleep
10. See [this link](http://arduino-esp8266.readthedocs.io/en/latest/libraries.html#other-libraries-not-included-with-the-ide) for additional libraries. Ticker looks promising.
11. [Epic argument](https://forum.arduino.cc/index.php?topic=220385.0) regarding multidimensional arrays and trolling.

## Links
1. https://www.jameco.com/jameco/workshop/jamecobuilds/arduinocircuit.html
2. https://arduinodiy-wordpress-com.cdn.ampproject.org/c/s/arduinodiy.wordpress.com/2016/09/30/adding-an-rtc-and-oled-to-esp8266-01/amp/
3. https://www.digikey.com/en/maker/blogs/01f5c0fa4b6445f3b71866447f400d8d


