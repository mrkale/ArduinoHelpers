# ArduinoHelpers
Utility and auxiliary sketches for Arduino.


## I2C_scanner
The sketch initiates transmission at each of 7 bit addresses. If some device answers at particular address, it is considered as present and active.

- The sketch lists found addresses in hexadecimal and decimal format.
- Results are displayed in serial monitor at 9600 baud.


## DS18B20_scanner
The sketch detects all Dallas Semiconductor temperature sensors on the one-wire bus.

- Printed features:
    - **MODEL**: Family name of sensors
    - **RESOLUTION**: Temperature sensing resolution in bits and centigrade
    - **POWER**: Mode of power supply
    - **ID**: Identifier as a CRC8 value from address (last address byte)
    - **ADDRESS**: Address in hexadecimal format
- Results are displayed in serial monitor at 9600 baud.
