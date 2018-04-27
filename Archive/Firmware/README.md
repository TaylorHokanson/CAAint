# CAAint
An open source badge project for noobs, artists, and the interdimensionally-curious

### Notes

To flash the original TTGO firmware:

Using esptool.py, use the following command to flash TTGO_esp-wroom-32_oled18650_factory.bin to the device where PORT is your device port /dev/tty0 or COM3, etc:

`$ python esptool.py -p PORT -b 460800 write_flash  0x0 TTGO_esp-wroom-32_oled18650_factory.bin`

Conversely, use the following command to read and archive the code running on the device:

`$ python esptool.py -p PORT -b 460800 read_flash 0 0x400000 yourfilename.bin`