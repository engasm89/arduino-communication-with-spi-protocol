# Arduino SPI — Circuit Schematic

- Course: Arduino Communication with SPI Protocol
- Author: Ashraf S A AlMadhoun
- Link: https://www.udemy.com/course/spi-arduino-communication-with-spi-protocol/?couponCode=JULYMAXDICOUNT

## Connections

- Arduino (Master) to SPI Slave: `MOSI`, `MISO`, `SCK`, `SS`. Common `GND`.
- Optionally connect `RESET` if required by the slave device.

## Diagram (ASCII)

```
 Arduino MOSI ---- MOSI Slave
 Arduino MISO ---- MISO Slave
 Arduino SCK  ---- SCK  Slave
 Arduino SS   ---- CS   Slave
 GND          ---- GND  Slave
 VCC          ---- VCC  Slave
```

## Notes

- Keep SCK within the slave’s maximum frequency; adjust SPI speed accordingly.
- Use short wires and proper shielding for high-speed signals.

