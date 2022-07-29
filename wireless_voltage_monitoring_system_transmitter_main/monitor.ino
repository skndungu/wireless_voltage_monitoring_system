#include <Arduino.h>
#include <Wire.h>
#include <INA226.h>

#define alert 10

INA226 ina(Wire);

void setupINA226()
{
    Serial.println("Initializing INA226");
    Serial.println("-----------------------------------------------");

    Wire.begin();

    // Default INA226 address is 0x40
    bool success = ina.begin();

    // Check if the connection was successful, stop if not
    if (!success)
    {
        Serial.println("Connection error");
        while (1)
            ;
    }

    // Configure INA226
    ina.configure(INA226_AVERAGES_1, INA226_BUS_CONV_TIME_1100US, INA226_SHUNT_CONV_TIME_1100US, INA226_MODE_SHUNT_BUS_CONT);

    // Calibrate INA226. Rshunt = 0.01 ohm, Max expected current = 4A
    // ina.calibrate(0.01, 4);

    // For our use, Rshunt = 2M Ohms
    // Calibrate INA226. Rshunt = 2000 ohm, Max expected current = 4A
    ina.calibrate(2000, 4);

    Serial.println("-----------------------------------------------");
}

float checkVoltage()
{
    float voltage = 0;
    voltage = ina.readBusVoltage();
    Serial.print("Bus voltage:  ");
    Serial.print(voltage, 1);
    Serial.println(" V");

    //   Serial.print("Bus power:     ");
    //   Serial.print(ina.readBusPower(), 5);
    //   Serial.println(" W");

    // Serial.print("Shunt voltage: ");
    // Serial.print(voltage, 1);
    // Serial.println(" V");

    //   Serial.print("Shunt current: ");
    //   Serial.print(ina.readShuntCurrent(), 5);
    //   Serial.println(" A");

    return voltage;
}