/*
  NAME:
  I2C_scanner.ino - Detect active I2C addresses for 7-bit addressing

  DESCRIPTION:
  The sketch initates transmition at each of 7 bit addresses. If some
  device answers at particular address, it is considered as present
  and active.
  - The sketch lists found addresses in hexadecimal and decimal format.
  - Results are displayed in serial monitor at 9600 baud.

  LICENSE:
  This program is free software; you can redistribute it and/or modify
  it under the terms of the MIT License (MIT).
  
  CREDENTIALS:
  Author: Libor Gabaj
   
  CREDITS:
  Nick Gammon, 20th April 2011 - Inspiration taken for thish sketch.
*/
#include <Wire.h>

#define SKETCH "I2C_scanner 1.1.3"
#define TWOWIRE_VERSION "TwoWire 2006-2012"

// Range of scanned addresses
const byte minAddress = 0x00;
const byte maxAddress = 0x7F;

void setup() {
  Serial.begin(9600);
  Serial.println(F(SKETCH));
  Serial.println(F("Libraries:"));
  Serial.println(F(TWOWIRE_VERSION));
  Serial.println(F("---"));
  
  // Print header
  Serial.println(F("I2C scanner found address(es) within the range"));
  
  // Buffer for formatted text
  char text[50];

  sprintf(text, "0x%02X - 0x%02X (%u - %u):",
    minAddress, maxAddress,
    minAddress, maxAddress
  );
  Serial.println(text);
  
  // Active devices counter
  byte count = 0;
 
  // Address scanning
  Wire.begin();
  for (byte i = minAddress; i <= maxAddress; i++)
  {
    Wire.beginTransmission(i);
    if (Wire.endTransmission() == 0)
    {
      sprintf(text, "%1u. 0x%02X (%u)", ++count, i, i);
      Serial.println(text);
    }
  }
  // Scanning results
  if (count == 0)
  {
    Serial.println("N/A");
  }
  sprintf(text, "*** Found %u device(s) ***", count);
  Serial.println(text);
}

void loop() {}
