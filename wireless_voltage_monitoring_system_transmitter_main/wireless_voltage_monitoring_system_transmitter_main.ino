#include <Arduino.h>
#include "lora_transmit.h"
#include "monitor.h"
#include "oled_display.h"

long lastSendTime = 0; // last send time
int interval = 1000;

void setup()
{
  // initialize Serial Monitor
  Serial.begin(115200);

  // setup OLED
  setupOLED();

  // setup the INA226 battery monitor
  setupINA226();

  // setup Lora
  setupLora();
}

void loop()
{
  if (millis() - lastSendTime > interval)
  {
    // get voltage value
    float voltage = checkVoltage();

    // send voltage value
    sendData(voltage);

    // show voltage value
    displayData(voltage);
    lastSendTime = millis();
    interval = random(2000) + 1000; // 2-3 seconds
  }
}