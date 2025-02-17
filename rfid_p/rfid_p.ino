#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 5
#define RST_PIN 22

MFRC522 rfid(SS_PIN, RST_PIN); // Create MFRC522 instance

void setup() {
    Serial.begin(115200); // Initialize serial communication
    SPI.begin();          // Initialize SPI bus
    rfid.PCD_Init();     // Initialize MFRC522
    Serial.println("Place your card on the reader...");
}

void loop() {
    if (!rfid.PICC_IsNewCardPresent()) {
        return; // No new card present
    }

    if (!rfid.PICC_ReadCardSerial()) {
        return; // Read card serial number failed
    }

    Serial.print("Card UID: ");
    for (byte i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(rfid.uid.uidByte[i], HEX);
    }
    Serial.println();
    rfid.PICC_HaltA(); // Halt PICC
}

