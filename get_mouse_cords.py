import pyautogui
import time

print("You have 5 seconds to move the mouse to the desired position...")

time.sleep(5)

x, y = pyautogui.position()

print(f"The current mouse position is: X={x}, Y={y}")
