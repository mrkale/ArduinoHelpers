/*
  NAME:
  Scanning 1-wire bus and detecting all DS18x20 sensors on it

  DESCRIPTION:
  - The sketch detects all devices on the one wire bus.
  - Printed features:
    MODEL: Family name of a sensors
    RES: Temperature sensing resolution in bits
    POWER: Mode of power supply
    ID: Identifier as a hash value from address
    ADDRESS: Address in hexadecimal format
  - Results are displayed in serial monitor at 9600 baud.

  LICENSE:
  This program is free software; you can redistribute it and/or modify
  it under the terms of the MIT License (MIT).
  
  CREDENTIALS:
  Author: Libor Gabaj
 */
#include "OneWire.h"
#include "DS18B20.h"

#define SKETCH "DS18B20_scanner 1.3.0"
#define ONEWIRE_VERSION "OneWire 2.3.2"

// Hardware configuration
const byte PIN_DS18B20 = 4;

// Measurement
DS18B20 ds(PIN_DS18B20);

void setup()
{
  Serial.begin(9600);
  Serial.println(F(SKETCH));
  Serial.println(F("Libraries:"));
  Serial.println(F(DS18B20_VERSION));
  Serial.println(F(ONEWIRE_VERSION));
  // Print header
  Serial.println(F("---"));
  Serial.println(F("#\tMODEL\tRES\tPOWER\t\tID\tADDRESS"));

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
      case DS18B20_MODEL_DS18S20:
        Serial.print(F("DS18S20"));
        break;
      case DS18B20_MODEL_DS1820:
        Serial.print(F("DS1820"));
        break;
      case DS18B20_MODEL_DS18B20:
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
    
    // Print identifier
    char addressId[DS18B20_PRINT_ID_LEN];    
    ds.printAddressId(addressId);    
    Serial.print(F("\t"));    
    Serial.print(addressId);

    // Print address
    char address[DS18B20_PRINT_ADDRESS_LEN];    
    ds.printAddress(address);    
    Serial.print(F("\t"));    
    Serial.println(address);
  }
  // Scannig results
  if (count == 0) Serial.println("N/A");
  Serial.print(F("*** Found "));
  Serial.print(count);
  Serial.print(F(" device"));
  if (count > 1) Serial.print(F("s"));
  Serial.println(F(" ***"));
}
 
 void loop(){}



