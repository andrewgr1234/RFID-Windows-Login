import serial
import pyautogui
import time

pyautogui.FAILSAFE = False

ser = serial.Serial('COM3', 9600)

pin = 'YOUR_PIN'

print("Script running!")

while True:
    try:
        if ser.in_waiting > 0:
            message = ser.readline().decode('utf-8').strip()
            if message == "ACCESS_GRANTED":
                print("Access granted. Typing PIN...")

                pyautogui.press('space')
                time.sleep(1)

                pyautogui.write(pin)
                pyautogui.press('enter')
                print("PIN entered.")

    except Exception as e:
        print(f"Error in serial communication: {e}")

    time.sleep(1)
