#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 5
#define RST_PIN 22
MFRC522 mfrc522(SS_PIN, RST_PIN); // create an instance

void setup(){
  Serial.begin(115200); // initiating serial communication
  SPI.begin(); // initiating spi bus
  mfrc522.PCD_Init(); // initiating MFRC522
  Serial.println("Approximate your card to the reader: ");
  Serial.println();
}

void loop(){
  // looking for new cards
  if(!mfrc522.PICC_IsNewCardPresent()) return;
  // select one of the cards
  if(!mfrc522.PICC_ReadCardSerial()) return;
  // show UID on serial monitor
  Serial.print("UID Tag: ");
  String content = "";
  byte letter;
  for(byte i = 0; i < mfrc522.uid.size; i++){
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  // Access Authorization
  if(content.substring(1) == "D5 99 2A 02") // change for access uid
  {
    Serial.println("Authorized Access :)");
    Serial.println();
    delay(2000);
  }
  else{
    Serial.println("Access Denied ):");
    delay(2000);
  }
}