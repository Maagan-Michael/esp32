
// #include <Arduino.h>
// #include <rfid.h>




// void set_pins (){


// }

// void setup() 
// {
//   Serial.begin(115200);
//   while (!Serial){}
  
//   set_pins();
//  rfid_setup();




// }

//   void loop() {

//    // Aguarda a aproximacao do cartao
//    //waiting the card approach
//   if ( ! mfrc522.PICC_IsNewCardPresent()) 
//   {
//     return;
//   }
//   // Select a card
//   if ( ! mfrc522.PICC_ReadCardSerial()) 
//   {
//     return;
// connected to:
//SDA => 5
//SCK => 18
//MOSI=> 23
//MISO => 19
//IRQ => ---
//GND => GND
//RST => 27
//VCC => 3.3v

/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-rfid-nfc
 */

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
