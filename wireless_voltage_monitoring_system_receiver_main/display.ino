#include <Arduino.h>
#include "OLED_Driver.h"
#include "GUI_Paint.h"
#include "DEV_Config.h"
#include "Debug.h"

void setupRGBOLED()
{
    Serial.println("Initializing OLED");

    System_Init();
    // if(USE_IIC) {
    //   Serial.print("Only USE_SPI_4W, Please revise DEV_config.h !!!");
    //   return 0;
    // }
    OLED_1in5_rgb_Init();
    Driver_Delay_ms(500);
    OLED_1in5_rgb_Clear();
}

void displayData(String sender, String voltage)
{
    OLED_1in5_rgb_Clear();
    Paint_DrawString_EN(10, 0, sender.c_str(), &Font16, BLACK, BLUE);
    Paint_DrawString_EN(10, 20, "BAT  |", &Font16, BLACK, BLUE);
    Paint_DrawNum(10, 40, voltage.c_str(), &Font16, 2, RED, BLACK);
    Paint_DrawNum(10, 70, "V", &Font16, 2, RED, BLACK);
    // Driver_Delay_ms(100);
}
