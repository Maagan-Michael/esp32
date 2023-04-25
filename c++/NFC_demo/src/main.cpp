// connected to:
//SDA => 5
//SCK => 18
//MOSI=> 23
//MISO => 19
//IRQ => ---
//GND => GND
//RST => 27
//VCC => 3.3v

#include <SPI.h>
#include <MFRC522.h>
#include <rfid.h>





void setup() {
  Serial.begin(115200);

  rfid_setup();
  // SPI.begin(); // init SPI bus
  // mfrc522.PCD_Init(); // init MFRC522
  // Serial.println("Tap an RFID/NFC tag on the RFID-RC522 reader");
}



void loop() {
  if (mfrc522.PICC_IsNewCardPresent()) { // new tag is available
    if (mfrc522.PICC_ReadCardSerial()) { // NUID has been readed
readingData();
  // mfrc522.PICC_DumpToSerial(&(mfrc522.uid));  //call menu function and retrieve the desired option
  // int op = menu();

  // if(op == 0) 
  //   readingData();
  // else if(op == 1) 
  //   writingData();
  // else {
  //   Serial.println(F("Incorrect Option!"));
  //   return;
  // }

//instructs the PICC when in the ACTIVE state to go to a "STOP" state
  mfrc522.PICC_HaltA(); 
  // "stop" the encryption of the PCD, it must be called after communication with authentication, otherwise new communications can not be initiated
  mfrc522.PCD_StopCrypto1();  
    }
  }
}
