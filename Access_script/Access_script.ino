#include <SPI.h>
#include <MFRC522.h>
#include "USB.h"
#include "USBHIDMouse.h"
#include "USBHIDKeyboard.h"
USBHIDMouse Mouse;
USBHIDKeyboard Keyboard;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

String authorizedUID = "Tag_UID_here";
String password = "Your_password_here"

void setup() {
  Serial.begin(115200);
  SPI.begin();
  rfid.PCD_Init();
  Mouse.begin();
  Keyboard.begin();
  USB.begin();
}

void loop() {
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    String uid = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      uid += String(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
      uid += String(rfid.uid.uidByte[i], HEX);
    }
    if (uid == authorizedUID) {
      Serial.println("ACCESS_GRANTED, Sending Password");
      Mouse.click(MOUSE_LEFT);
      delay(100);
      Keyboard.print(password);
      delay(100);
      Keyboard.write('\n');
    } else {
      Serial.println("ACCESS_DENIED");
    }

    rfid.PICC_HaltA();
  }
}
