#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN D2
#define RST_PIN D4

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance

void setup() {
  Serial.begin(115200);   // Initiate a serial communication
  SPI.begin();  // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Put your card to the reader...");
  Serial.println();
}

void loop() {
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Show UID on serial monitor
  
  String content= "";
 
  for (byte i = 0; i < mfrc522.uid.size; i++) {
     
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  
  Serial.print("Message : ");
  content.toUpperCase();
     //change here the UID of the card/cards that you want to give access
  if (content.substring(1) == "51 DC D0 26") {
 
    Serial.println("tag");
    Serial.println();
    delay(1000);
  }else if (content.substring(1) == "40 EC 71 1A") {
 
    Serial.println("kart");
    Serial.println();
    delay(1000);
  }



  /*RFID 522 VCC to Wemos D1 Mini 3.3V
RFID 522 GND to Wemos D1 Mini GND
RFID 522 RST to Wemos D1 Mini D4
RFID 522 SS to Wemos D1 Mini D2
RFID 522 MOSI to Wemos D1 Mini D7
RFID 522 MISO to Wemos D1 Mini D6
RFID 522 SCKto Wemos D1 Mini D5*/

} 
