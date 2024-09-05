# RFID with windows login

This project involves automating the login process using an RFID reader and Arduino. The setup includes three main scripts: Arduino scripts for reading the RFID tag and sending access status, and a Python script for interacting with the Windows login screen.

## Components

- **Arduino Nano ESP32(or any board compatible with the Keyboard Library)**
- **MFRC522 RFID Reader (with RFID tag)**

## Wiring Diagram

### RFID Reader to Arduino Uno

| RFID Reader Pin | Arduino Pin |
| --------------- | ----------- |
| 3.3V            | 3.3V        |
| IRQ             | No need     |
| GND             | GND         |
| SDA             | D10         |
| SCK             | D13         |
| MOSI            | D11         |
| MISO            | D12         |
| RST             | RST         |

## Instructions

1. Connect the RFID reader with the board
2. Go into the Get_Tag_UID and get your nfc tag's UID
3. Change the "authorizedUID" and "password"
4. Upload the code onto your board and thats it!
