/*
  NAME:
  DS18B20_scanner.ino - Detect DS18B20 sensors on 1-wire bus

  DESCRIPTION:
  - The sketch detects all devices on the one wire bus.
  - For detected device the address is printed in hexadecimal and decimal
    format as an 8 items arrays.
  - Printed features:
    MODEL: Family name of a sensors
    RES: Temperature sensing resolution in bits
    POWER: Mode of power supply
  - Results are displayed in serial monitor at 9600 baud.

  LICENSE:
  This program is free software; you can redistribute it and/or modify
  it under the terms of the MIT License (MIT).
  
  CREDENTIALS:
  Author: Libor Gabaj
  Version: 1.0.0
  Created: 25.03.2015
  Updated: 25.03.2015
 */
#include <OneWire.h>
#include <DS18B20.h>

const byte pinDS18B20 = 4;

DS18B20 ds(pinDS18B20);

void setup()
{
  Serial.begin(9600);
  Serial.println("DS18B20 scanner");
    
  // Print header
  Serial.println(F("#\tMODEL\tRES\tPOWER\t\tADDRESS"));

  // Devices scanning
  byte count = 0;
  while(ds.selectNext())
  {
    // Print order number
    count++;
    Serial.print(count);
    Serial.print(F(".\t"));

    // Print family name
    switch(ds.getFamilyCode())
    {
      case MODEL_DS18S20:
        Serial.print(F("DS18S20"));
        break;
      case MODEL_DS1820:
        Serial.print(F("DS1820"));
        break;
      case MODEL_DS18B20:
        Serial.print(F("DS18B20"));
        break;
      default:
        Serial.print(F("UNKNOWN"));
        break;
    }
    
    // Print resolution
    Serial.print(F("\t"));
    Serial.print(ds.getResolution());
    
    // Print power mode
    Serial.print(F("\t"));
    if(ds.getPowerMode())
    {
      Serial.print(F("External"));
    }
    else
    {
      Serial.print(F("Parasite"));
    }
    
    // Print address
    uint8_t address[8];    
    ds.getAddress(address);    
    Serial.print(F("\t"));    
    for (byte i = 0; i < 8; i++)
    {
      Serial.print(F("0x"));
      if (address[i] < 0x10) Serial.print("0");
      Serial.print(address[i], HEX);
      if (i < 7) Serial.print(F(", "));
    }
    Serial.print(F("\t\t"));    
    for (byte i = 0; i < 8; i++)
    {
      if (address[i] < 100) Serial.print("0");
      if (address[i] < 10) Serial.print("0");
      Serial.print(address[i], DEC);
      if (i < 7) Serial.print(F(", "));
    }
    Serial.println();
  }
  // Scan results
  if (count == 0) Serial.println("N/A");
  Serial.print(F("*** Found "));
  Serial.print(count);
  Serial.println(F(" device(s) ***\n"));
}
 
 void loop(){}
