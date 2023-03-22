#include <Arduino.h>

const int OUT_PIN = 32;
const int SAMPLE_TIME = 20;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;
int sampleBufferValue = 0;


void setup() {
Serial.begin(115200);
while (!Serial){}

pinMode(32,INPUT);


}

void loop() {

  millisCurrent = millis();
  millisElapsed = millisCurrent - millisLast;

  if (digitalRead(OUT_PIN) == LOW) {
    sampleBufferValue++;
  }

   if (millisElapsed > SAMPLE_TIME) {
     Serial.println(sampleBufferValue);
     sampleBufferValue = 0;
     millisLast = millisCurrent;
   }
 
 }