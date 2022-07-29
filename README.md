#A wireless Battery Voltage Monitoring System

The repo contains firmware codes for both the transmitter and receiver that monitors the battery voltage levels of the specified batteries.Everything on how to program and what the codes does is documented sequentially in this repo. The data from the transmitters to the receiver is transferred wirelessly via LoRa where it's then logged to a display.

## Transmitter 
The transmitter consists of an ESP32 as the main MCU unit, INA226 as the voltage measuring device & the LoRa module as the wireless data transmitter to the receiver. 


## Receiver 
The transmitter consists of an ESP32 as the main MCU unit, INA226 as the voltage measuring device, the LoRa module as the wireless data receiver from  the transmitter & and OLED display to visualize the data. 



#Programming
## Programming & Ide 
Download the ide from this 🔗 [link](https://www.arduino.cc/en/software)
## Programmer
To communicate with the device and program it as well you will need a usb-ttl adapter this type [link](https://www.amazon.com/Adapter-Serial-Converter-Development-Projects/dp/B075N82CDL) 
[To instal the drivers](https://www.prolific.com.tw/US/ShowProduct.aspx?p_id=223&pcid=126) use this 

## Connections 
Please make the connections to the mcu and the pc/mac as shown below 
<br/>
<br/>
<img src="https://github.com/skndungu/compressor_controller/blob/main/assets/img/USB-TTL-Connection.jpeg" height="200">
## Installing ESP32 Add-on the ide
1. In your Arduino IDE, go to `File> Preferences` <hr/>


![Screenshot 2022-01-31 at 12 49 40](https://user-images.githubusercontent.com/20322653/151772329-1345b087-cf35-4a58-bcf8-39fea4dd4812.png)

2. Enter `https://dl.espressif.com/dl/package_esp32_index.json` into the “Additional Board Manager URLs” field as shown in the figure below. Then, click the “OK” button: <hr/>


![Screenshot 2022-01-31 at 12 57 04](https://user-images.githubusercontent.com/20322653/151773399-d6762ec4-a9ed-410a-a410-8ef1611f5fda.png)

3. Open the Boards Manager. Go to `Tools > Board > Boards Manager`<hr/>

![Screenshot 2022-01-31 at 12 59 45](https://user-images.githubusercontent.com/20322653/151773627-4791c26a-21c5-4ae0-9564-5fcec6f476c7.png)

4. Search for `ESP32` and press install button for the `ESP32 by Espressif Systems`<hr/>

![Screenshot 2022-01-31 at 13 02 24](https://user-images.githubusercontent.com/20322653/151774112-fa0cb56c-a05e-42d9-ad90-913617b0e670.png)

5. That’s it. It should be installed after a few seconds.
 
 ## Dowload the files 
- Download all the files on the `Code`:arrow_down_small: on the platform, In your downloads you will get the a folder :file_folder:  `wireless_voltage_monitoring_system-master` this will have all the codes and related libraries.
- On library installation unzip the folder :file_folder: `libs` copy and paste all the folders to your directory `documents/arduino/library` folder :file_folder:
- Open the `.ino` file for `wireless_voltage_monitoring_system-master` with the downloaded and ide, compile and uplaod to the hardware `(procedure on how to use the ide is on the tutorial link)`:link:    [tutorial](https://www.youtube.com/watch?v=nL34zDTPkcs&t=3s)






