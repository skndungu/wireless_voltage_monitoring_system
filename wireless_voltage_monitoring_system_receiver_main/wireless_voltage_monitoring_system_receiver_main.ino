#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include "display.h"

// LoRa
#define ss 15
#define rst 18
#define dio0 9
#define dio1 10

byte sender;
String incoming;

// Lora packet wait period
unsigned long timeNow = 0;
bool loraReceived = false;

byte localAddress = 0x02; // address of this device

void setup()
{
  // initialize Serial Monitor
  Serial.begin(115200);

  // setup LoRa
  Serial.println("Initializing LoRa Receiver");
  LoRa.setPins(ss, rst, dio0);

  // replace the LoRa.begin(---E-) argument with your location's frequency
  // 433E6 for Asia
  // 866E6 for Europe
  // 915E6 for North America
  while (!LoRa.begin(866E6))
  {
    Serial.print(".");
    delay(500);
  }
  // Change sync word (0xF3) to match the receiver
  // The sync word assures you don't get LoRa messages from other LoRa transceivers
  // ranges from 0-0xFF
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");

  // setup OLED
  setupRGBOLED();
}

void onReceive(int packetSize)
{
  if (packetSize == 0)
    return; // if there's no packet, return

  // read packet header bytes:
  int recipient = LoRa.read();       // recipient address
  sender = LoRa.read();              // sender address
  byte incomingMsgId = LoRa.read();  // incoming msg ID
  byte incomingLength = LoRa.read(); // incoming msg length

  incoming = "";

  while (LoRa.available())
  {
    incoming += (char)LoRa.read();
  }

  if (incomingLength != incoming.length())
  { // check length for error
    Serial.println("error: message length does not match length");
    return; // skip rest of function
  }

  // if the recipient isn't this device or broadcast,
  if (recipient != localAddress && recipient != 0xFF)
  {
    Serial.println("This message is not for me.");
    return; // skip rest of function
  }

  Serial.println("Received from: 0x" + String(sender, HEX));
  Serial.println("Sent to: 0x" + String(recipient, HEX));
  Serial.println("Message ID: " + String(incomingMsgId));
  Serial.println("Message length: " + String(incomingLength));
  Serial.println("Message: " + incoming);
  Serial.println("RSSI: " + String(LoRa.packetRssi()));
  Serial.println("Snr: " + String(LoRa.packetSnr()));
  Serial.println();
  loraReceived = true;
}

void loop()
{
  onReceive(LoRa.parsePacket());

  String sender_ = "0x" + String(sender, HEX);

  // display data
  displayData(sender_, incoming);
}