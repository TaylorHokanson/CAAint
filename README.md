# CAAint
An open source badge project for noobs, artists, and the interdimensionally-curious

1. [Project Goals](#project-goals)
2. [BOM](#bom)
2. [Design](#design)
3. [Team](#team)
4. [Thanks](#thanks)

## Project Goals
We are artists following in the footsteps of the DEFCON [Badgelife](https://hackaday.com/tag/badgelife/) scene. Badgelifers create custom electronic devices to replace the ho-hum badges that display your name and affiliation at conferences. These badges feature playable video games, animated LED displays, wifi connectivity, and more! But what would happen if we released a simple badge template that non-engineers could program and expand upon themselves? Let's find out.

## BOM
After [much experimentation](/Archive), we've settled on [this board](https://www.aliexpress.com/item/TTGO-ESP8266-ESP32-0-96-0-96-inch-OLED-Display-WiFi-Bluetooth-18650-Lithium-Battery-Shield/32839517061.html?spm=a2g0s.9042311.0.0.qXU7bh). It includes the following features in one tidy package:

1. Wifi/bluetooth (via ESP32, the recent update to the ESP8266)
2. LIPO battery clip/recharging circuit
3. Arduino IDE compatibility
4. OLED screen

## Design
After flirting with building a project from scratch, we've brought the process back down to earth. Right now the plan is to focus on a cool little breakout for an existing ESP PCB (see [BOM](#bom)) that will allow for the addition of sensors etc. in the form of pluggable modules. The form-factor could even take the shape of a robot or action figure! Once we release the platform specs, other developers could develop their own modules to extend the project's ecosystem. Ideas include:

1. [Co-planar PCB connectors](https://www.gradconn.com/Products/BoardToBoard/CoPlanarConnectors) ([image](/Media/right_angle_to_right_angle.jpg))
2. [Hemaphroditic connectors](https://octopart.com/10120045-400lf-fci-29441219) ([image](/Media/10120045-400LF.jpg))
3. [5-way tac switch](https://www.aliexpress.com/wholesale?catId=0&initiative_id=AS_20180403080800&SearchText=5+way+tactile+switch)

## Team
Nick Bontrager, Texas Christian University  
Taylor Hokanson, Columbia College Chicago

...and you? Please get in touch!

## Thanks
Supported in part by a generous [Faculty Development Grant](https://about.colum.edu/faculty-development/awards-grants/full-time-development-grants.html) from Columbia College Chicago
