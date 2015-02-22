# ArduinoHelpers
Utility and auxilliary sketches for Arduino.

## I2C_scanner
The sketch detects active I2C addresses by initiating transmition at each of 7 bit addresses (parametrized). If some device answers at particular address, it is considered as present and active one.
  - Addresses are displayed in hexadecimal and decimal format in serial monitor at 9600 baud.
  - The sketch has been inspired by Nick Gammon, 20th April 2011.
