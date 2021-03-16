# ESP8266
[Espressif Systems](https://www.espressif.com/) is the company created the popular ESP8266, ESP32, ESP32-S and ESP32-C series of chips, modules and development boards and this is a getting started guide for the ESP8266 module.

## How to flash ESP8266 NonOS AT Bin V1.7.4 firmware
1. Download the firmware from https://www.espressif.com/sites/default/files/ap/ESP8266_NonOS_AT_Bin_V1.7.4.zip
2. Download the flashing tool from https://www.espressif.com/sites/default/files/tools/flash_download_tool_v3.8.5.zip
3. Open the flash_download_tool_3.8.5.exe tool and select all binaries with addresses based on your module flash size 
https://www.espressif.com/sites/default/files/documentation/4a-esp8266_at_instruction_set_en.pdf.
4. After selecting CrystalFreq, SPI SPEED, SPI MODE and FLASH SIZE click on the START button to flash the firmware to your module.

![FLASH DOWNLOAD TOOLS](https://github.com/chovanj/Microcontrollers/blob/master/Architecture/ESP/32-bit/ESP8266/ESP8266DownloadTool.png)

5. After successful flashing you can check a new version from the Arduino IDE in the Serial Monitor.
