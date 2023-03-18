#include <Arduino.h>
#include <ezButton.h>
#include <ESP32Servo.h>

const int vrx = 32;
const int vry = 35;
const int sw = 34;
ezButton button(sw);

Servo servo;
const int servo_pin = 18;



void setup() {
  Serial.begin(115200);
 while (!Serial) { }
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
  servo.attach(servo_pin);
  servo.write(0);

}

void loop() {
  button.loop(); // MUST call the loop() function first

  if (button.isPressed()) {
    Serial.println("The button is pressed");
    // TODO do something here
  }

  if (button.isReleased()) {
    Serial.println("The button is released");
  }
    // TODO do something here
Serial.println(analogRead(vrx));
Serial.println(analogRead(vry));

servo.write((analogRead(vrx)+1)/20);
Serial.println("_____________");


delay(100);


}














