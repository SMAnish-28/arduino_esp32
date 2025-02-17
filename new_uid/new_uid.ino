#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN  21
#define RST_PIN 22
MFRC522 mfrc522(SS_PIN, RST_PIN);

byte newUID[4] = {0x12, 0x34, 0x56, 0x78};  // Set your new UID

void setup() {
    Serial.begin(115200);
    SPI.begin();
    mfrc522.PCD_Init();

    Serial.println("Place your Magic Card...");
}

void loop() {
    if (!mfrc522.PICC_IsNewCardPresent()) return;
    if (!mfrc522.PICC_ReadCardSerial()) return;

    Serial.print("Old UID: ");
    for (byte i = 0; i < mfrc522.uid.size; i++) {
        Serial.print(mfrc522.uid.uidByte[i], HEX);
        Serial.print(" ");
    }
    Serial.println();

    if (writeNewUID(newUID)) {
        Serial.println("UID successfully changed!");
    } else {
        Serial.println("UID change failed!");
    }
    
    delay(2000);
}

bool writeNewUID(byte *newUID) {
    MFRC522::StatusCode status;

    mfrc522.PICC_DumpDetailsToSerial(&(mfrc522.uid));

    // Authenticate to sector 0 (must be a Magic Card)
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 0, &mfrc522.MIFARE_Key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) return false;

    // Write the new UID to sector 0
    status = mfrc522.MIFARE_Write(0, newUID, 4);
    if (status != MFRC522::STATUS_OK) return false;

    return true;
}
