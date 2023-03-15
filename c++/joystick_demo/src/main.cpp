#include <Arduino.h>
#include <ezButton.h>

const int vrx = 25;
const int vry = 26;
const int sw = 33;
ezButton button(sw);




void setup() {
  Serial.begin(115200);
 while (!Serial) { }
  button.setDebounceTime(50); // set debounce time to 50 milliseconds

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
Serial.println("_____________");


delay(100);


}














