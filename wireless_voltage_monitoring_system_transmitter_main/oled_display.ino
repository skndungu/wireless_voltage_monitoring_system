#include "SSD1306.h"
#define SDA_PIN 21 // GPIO21 -> SDA
#define SCL_PIN 22 // GPIO22 -> SCL
#define SSD_ADDRESS 0x3c

SSD1306 display(SSD_ADDRESS, SDA_PIN, SCL_PIN);

void setupOLED()
{
    Serial.println("");
    Serial.println("Setting up OLED Display");
    Serial.println("");

    display.init();
    // display.flipScreenVertically();
    // display.setTextAlignment(TEXT_ALIGN_LEFT);
}

void displayData(float voltage)
{
    display.clear(); // clear the display

    display.drawString(0, 0, "BAT | ");
    display.drawString(40, 0, String(voltage));
    display.drawString(70, 0, "V");
    // display.drawString(0, 32, "%  ");
    // display.drawString(40, 32, String(1));
    // display.drawString(70, 32, "%");

    display.display(); // write the buffer to the display
    delay(10);
}