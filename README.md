# CAAint
An open source badge project for noobs, artists, and the interdimensionally-curious

1. [Desired Features](#desired-features)
2. [Hardware BOM](#hardware-bom)
3. [Breadboard Setup](#breadboard-setup)
4. [Firmware Update](#firmware-update)
5. [NodeMCU Test](#nodemcu-test)
6. [OLED Test](#oled-test)
7. [Battery](#battery)
7. [PCB](#pcb)
8. [Notes](#notes)

## Desired Features
1. Arduino IDE programmable
2. Mesh networking capable
3. Hacker-friendly
4. Conference-centric function
5. Post-conference function
6. Battery power

### Hardware BOM
Part | US Cost | China Cost
--- | --- | ---
NodeMCU | [$9](https://www.amazon.com/gp/product/B010O1G1ES/ref=oh_aui_detailpage_o00_s01?ie=UTF8&psc=1) | $3 [Amica](https://www.aliexpress.com/item/1pcs-Wireless-module-NodeMcu-Lua-WIFI-Internet-of-Things-development-board-based-ESP8266-CP2102-with-pcb/32719524260.html?spm=2114.search0104.3.49.782Zwp&ws_ab_test=searchweb0_0,searchweb201602_4_10152_10065_10151_10130_10068_10344_10345_10342_10343_10340_10341_10307_10060_10155_10154_10056_10055_10054_10539_10538_5370015_10537_10059_10536_10535_10534_10533_100031_10099_10338_10103_10102_10052_10053_10107_10050_10142_10051_10324_10325_10084_10083_10080_10082_10081_10178_10110_5590015_10111_10112_10113_10114_5610015_10312_10313_10314_10317_10318_10078_10079_10073-normal#cfs,searchweb201603_1,ppcSwitch_5&btsid=2aed71c2-dffe-45d4-9c74-09e8aacf4ef1&algo_expid=34137b6c-91fb-44da-b06f-060b2c408eb9-6&algo_pvid=34137b6c-91fb-44da-b06f-060b2c408eb9), [Lolin](https://www.aliexpress.com/item/1PCS-Wireless-module-CH340-NodeMcu-V3-Lua-WIFI-Internet-of-Things-development-board-based-ESP8266/32802874451.html?spm=2114.search0104.3.169.782Zwp&ws_ab_test=searchweb0_0,searchweb201602_4_10152_10065_10151_10130_10068_10344_10345_10342_10343_10340_10341_10307_10060_10155_10154_10056_10055_10054_10539_10538_5370015_10537_10059_10536_10535_10534_10533_100031_10099_10338_10103_10102_10052_10053_10107_10050_10142_10051_10324_10325_10084_10083_10080_10082_10081_10178_10110_5590015_10111_10112_10113_10114_5610015_10312_10313_10314_10317_10318_10078_10079_10073,searchweb201603_1,ppcSwitch_5&btsid=2aed71c2-dffe-45d4-9c74-09e8aacf4ef1&algo_expid=34137b6c-91fb-44da-b06f-060b2c408eb9-21&algo_pvid=34137b6c-91fb-44da-b06f-060b2c408eb9)
OLED | [$8](https://www.amazon.com/gp/product/B072FJRNWV/ref=oh_aui_detailpage_o00_s01?ie=UTF8&psc=1) | [$3](https://www.aliexpress.com/store/product/10pcs-White-Blue-White-and-Blue-color-0-96-inch-128X64-OLED-Display-Module-For-arduino/1525680_32765278698.html?spm=2114.12010615.0.0.2253f604ZQG0c1)
Battery | TBA | [$3.50](https://www.aliexpress.com/item/5pcs-3-7V-1000mah-504050-Lithium-Polymer-LiPo-Rechargeable-Battery-For-Mp3-MP4-MP5-DVD-PAD/1097525459.html?spm=2114.10010108.100009.1.299e9514ZTnXiI&traffic_analysisId=recommend_2037_null_null_null&scm=1007.13482.91320.0&pvid=e6408c7e-7398-44d7-8bc4-ea6305ebcbbe&tpp=1)(verify specs/voltage)
Charger | TBA | [$0.25](https://www.aliexpress.com/item/10PCS-MINI-USB-1A-Lithium-Battery-Charging-Board-Charger-Module-With-Protection-TP4056/32805383965.html?ws_ab_test=searchweb0_0,searchweb201602_4_10152_10065_10151_10130_10068_10344_10345_10342_10343_10340_10341_10541_10540_10307_10060_10155_10154_10056_10055_10054_10539_10538_10537_10059_10536_10534_10533_100031_10099_10103_10102_5590020_10052_5640020_10053_10107_10050_10142_10051_10324_10325_10084_10083_5370020_10080_10082_10081_10178_10110_10111_10112_10113_10114_5630020_10312_10313_10314_10317_10318_10078_10079_10073-10318normal#cfs,searchweb201603_25,ppcSwitch_5&btsid=f94d43b7-f423-41f8-83ac-27b28ef9341d&algo_expid=7730b822-e17d-4589-93ef-2c0607a3ed26-7&algo_pvid=7730b822-e17d-4589-93ef-2c0607a3ed26)(verify specs/voltage)
PCB | TBA | [$5 for 10, $100 for 50](https://www.seeedstudio.com/fusion_pcb.html)
Shipping | ?? | ??

### Breadboard Setup
NodeMCU | OLED
--- | ---
3V3 | VCC
GND | GND
D1 | SCL
D2 | SDA

### Firmware Update
1. Request a vanilla Master build [here](https://nodemcu-build.com/index.php). This takes a little time.
2. Follow these instructions starting with [Install ESPTool](https://github.com/nodemcu/nodemcu-devkit/wiki/Getting-Started-on-OSX).

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

### Battery
1. I believe [this board](https://www.aliexpress.com/item/10PCS-MINI-USB-1A-Lithium-Battery-Charging-Board-Charger-Module-With-Protection-TP4056/32805383965.html?ws_ab_test=searchweb0_0,searchweb201602_4_10152_10065_10151_10130_10068_10344_10345_10342_10343_10340_10341_10541_10540_10307_10060_10155_10154_10056_10055_10054_10539_10538_10537_10059_10536_10534_10533_100031_10099_10103_10102_5590020_10052_5640020_10053_10107_10050_10142_10051_10324_10325_10084_10083_5370020_10080_10082_10081_10178_10110_10111_10112_10113_10114_5630020_10312_10313_10314_10317_10318_10078_10079_10073-10318normal#cfs,searchweb201603_25,ppcSwitch_5&btsid=f94d43b7-f423-41f8-83ac-27b28ef9341d&algo_expid=7730b822-e17d-4589-93ef-2c0607a3ed26-7&algo_pvid=7730b822-e17d-4589-93ef-2c0607a3ed26) is the one we need to add a rechargeable LiPo. How do we verify that?
2. Aliexpress ranges widely in terms of documentation. These links ([one](https://www.aliexpress.com/item/5-pcs-Micro-USB-5V-1A-18650-TP4056-Lithium-Battery-Charger-Module-Charging-Board-With-Protection/32728720869.html?ws_ab_test=searchweb0_0,searchweb201602_4_10152_10065_10151_10130_10068_10344_10345_10342_10343_10340_10341_10541_10540_10307_5640015_10060_10155_10154_10056_10055_10054_10539_10538_5370015_10537_10059_10536_10534_10533_100031_10099_10103_10102_10052_10053_10107_10050_10142_10051_10324_10325_10084_10083_10080_10082_10081_10178_10110_5590015_10111_10112_10113_10114_10312_10313_10314_10317_10318_10078_10079_10073_5630015,searchweb201603_25,ppcSwitch_5&btsid=3a938dc3-219f-4d86-93fb-d2da4a9aa73e&algo_expid=eaddbdc6-2ea0-40d2-a2cf-718034a3ffef-0&algo_pvid=eaddbdc6-2ea0-40d2-a2cf-718034a3ffef), [two](http://www.hotmcu.com/tp4056-micro-usb-5v-1a-lithium-battery-charger-with-protection-p-176.html)) are a good place to start.
3. More expensive circuits have a [load-sharing](http://blog.zakkemble.co.uk/a-lithium-battery-charger-with-load-sharing/) arrangement that allows simultaneous code uploading and battery charging. Perhaps we can get around that by [desoldering the 5 > 3.3 regulator](https://tinker.yeoman.com.au/2016/05/29/running-nodemcu-on-a-battery-esp8266-low-power-consumption-revisited/)?
4. More about [load sharing schematics](https://hackaday.io/project/5231-esp8266-esp-0712-dev-board)
5. OK! Looks like the board at #1 outputs 3.7 from battery alone and 4.2 while charging. 3.7 is just above the 3.6 spec, and anecdotal evidence suggests 4.2 would be OK.

### PCB
1. After reviewing many candidates, I settled on [Eagle](https://www.autodesk.com/education/free-software/eagle#), which has a permissive free license for educators/students.
2. Check out [this account](https://hackaday.io/project/18508-mr-robot-badge/log/64526-how-i-created-the-mr-robot-badge) of the design process for a complex DIY Badge for DEFCON
3. [Sparkfun Eagle how-to](https://learn.sparkfun.com/tutorials/using-eagle-schematic)
4. Collection of Eagle-compatible [part schematics](https://www.diymodules.org/)

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
1. Versioning conventions are [funky](https://frightanic.com/iot/comparison-of-esp8266-nodemcu-development-boards/).
2. V2/Amica preferred, though Amica is hard to find on Aliexpress, might be fake anyway.
3. NodeMCU [Reference](https://nodemcu.readthedocs.io/en/master/)
4. ESP2866 Arduino Core [Reference](http://arduino-esp8266.readthedocs.io/en/latest/)
5. DEFCON 25 ANDXOR [Kickstarter](https://www.kickstarter.com/projects/hyr0n/andxor-defcon-25-indie-badge)

