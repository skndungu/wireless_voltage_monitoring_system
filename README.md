#A wireless Battery Voltage Monitoring System

The repo contains firmware codes for both the transmitter and receiver that monitors the battery voltage levels of the specified batteries.Everything on how to program and what the codes does is documented sequentially in this repo. The data from the transmitters to the receiver is transferred wirelessly via LoRa where it's then logged to a display.

## Transmitter 
The transmitter consists of an ESP32 as the main MCU unit, INA226 as the voltage measuring device & the LoRa module as the wireless data transmitter to the receiver. 

#Programming
---
- The IDE to be used for this development is [Arduino IDE](https://www.arduino.cc/en/software).  
- The PCB has Micro USB interface as the programming interface, if you don't have familiarity with the software you can pick up on this :link:[tutorial](https://www.youtube.com/watch?v=nL34zDTPkcs&t=3s)

- Download all the files on the `Code`:arrow_down_small: on the platform, In your downloads you will get the a folder :file_folder:  `wireless_voltage_monitoring_system
-master` this will have all the codes and related libraries.
- On library installation unzip the folder :file_folder: `libs` copy and paste all the folders to your directory `documents/arduino/library` folder :file_folder:
- Open the `.ino` file for wireless_voltage_monitoring_system
 with the downloaded and ide, compile and uplaod to the hardware `(procedure on how to use the ide is on the tutorial link)`:link:    [tutorial](https://www.youtube.com/watch?v=nL34zDTPkcs&t=3s)







