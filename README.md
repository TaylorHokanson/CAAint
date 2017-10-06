# CAAint
An open source badge project for noobs, artists, and the interdimensionally-curious

### Functions
1. Must be Arduino IDE programmable?
2. Must include ESP mesh networking?
3. Could store interests, then respond when near participants with similar interests.

### Links
1. https://www.jameco.com/jameco/workshop/jamecobuilds/arduinocircuit.html
2. https://arduinodiy-wordpress-com.cdn.ampproject.org/c/s/arduinodiy.wordpress.com/2016/09/30/adding-an-rtc-and-oled-to-esp8266-01/amp/
3. https://www.digikey.com/en/maker/blogs/01f5c0fa4b6445f3b71866447f400d8d

### NodeMCU
1. Cheap! ([AliExpess](https://www.aliexpress.com/store/product/NodeMcu-Lua-WIFI-development-board-based-on-the-ESP8266-Internet-of-things/110055_32339203041.html), [eBay](https://www.ebay.com/i/192164536182?chn=ps&dispItem=1), [Amazon](https://www.amazon.com/HiLetgo-Internet-Development-Wireless-Micropython/dp/B010O1G1ES/ref=sr_1_6_sspa?s=electronics&ie=UTF8&qid=1506962067&sr=1-6-spons&keywords=nodemcu+1.0&psc=10))
3. Battery power may be an issue, but it sounds like all wifi modules are power hungry.
4. Seems like cheaper boards are version 0.9, which has a less friendly layout compared to 1.0.
2. Arduino IDE programmable
  1. Update IDE (I used 1.8.4).
  2. Arduino > Preferences > Additional Board Manager URLs
  3. Add http://arduino.esp8266.com/stable/package_esp8266com_index.json
  4. Tools > Board > Board Manager
  5. Search for ESP, install
  6. Install [this driver](https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver). While it works for the NodeMCU, I'm still having trouble connecting to my Sparkfun RedBoard in OSX Sierra.
  7. You have to use the USB ports on the right side of the keyboard? I did...
  7. Select NODEMCU 1.0 as your board and pick the corresponding port.
  8. Now you should have a ton of ESP examples in the IDE. Try Examples > ESP8266WebServer > SimpleAuthentication.
  9. Enter the login credentials of a wifi network within range and upload the sketch to the board.

