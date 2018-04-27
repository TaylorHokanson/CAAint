# CAAint
An open source badge project for noobs, artists, and the interdimensionally-curious

### Notes

To flash the original TTGO firmware:

Using esptool.py, use the following command to flash TTGO_esp-wroom-32_oled18650_factory.bin to the device:

`python esptool.py -p COM16 -b 460800 write_flash  0x0 TTGO_esp-wroom-32_oled18650_factory.bin`
