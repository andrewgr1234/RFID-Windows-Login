# RFID with windows login

This project involves automating the login process using an RFID reader and Arduino. The setup includes three main scripts: Arduino scripts for reading the RFID tag and sending access status, and a Python script for interacting with the Windows login screen.

## Components

- **Arduino Uno**
- **MFRC522 RFID Reader (with RFID tag)**
- **Python 3.x**
- **Libraries**: `pyautogui` and `pyserial`

## Wiring Diagram

### RFID Reader to Arduino Uno

| RFID Reader Pin | Arduino Pin |
| --------------- | ----------- |
| 3.3V            | 3.3V        |
| IRQ             | No need     |
| GND             | GND         |
| SDA             | 10          |
| SCK             | 13          |
| MOSI            | 11          |
| MISO            | 12          |
| RST             | 9           |

## Scripts

### Get_Tag_UID:

This script is for the Arduino to get the rfid tag's uid.

### Access_script:

This script is for checking the RFID UID of the tag your are using and giving you a "Access Granted" or "Access Denied" message based on the tag you are using.
Note: change the "authorizedUID" variable to the UID you got form the first script.

### script.py:

This is the main scrip that listens to the arduino's "access_granted" message for it to start the script which is for going to the login input box, writing the password and pressing enter to log on.
Note: change the "pin" variable to your user pin.

## Instructions

1. Install Required Python Libraries:

   ```bash
   pip install pyautogui pyserial
   ```

2. Run the Scripts:
   - Make sure to change all the nessacrry variables to the right value.
   - Upload Arduino Scripts: Use both aruino script to get the tag UID and to check for the right tag.
   - Run Python Script: Run the python script and then lock the computer (use Win + L) and then put the tag to the reader.

## Troubleshooting

- Ensure that the COM port specified in the Python script matches the port where your Arduino is connected.
- Verify that the pin variable in the Python script is set to your actual PIN.
- Verify that the UID for the tag is set for the tag you are using.
