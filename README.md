# ArduinoHelpers
Utility and auxilliary sketches for Arduino.


## I2C_scanner
The sketch initates transmition at each of 7 bit addresses. If some device answers at particular address, it is considered as present and active.

- The sketch lists found addresses in hexadecimal and decimal format.
- Results are displayed in serial monitor at 9600 baud.


## DS18B20_scanner
The sketch detects all devices on the one wire bus.

- Printed features:
    - **MODEL**: Family name of sensors
    - **RES**: Temperature sensing resolution in bits
    - **POWER**: Mode of power supply
    - **ID**: Identifier as a CRC8 value from address (last address byte)
    - **ADDRESS**: Address in hexadecimal format
- Results are displayed in serial monitor at 9600 baud.
