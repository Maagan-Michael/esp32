//connects to a game
// game url: https://github.com/maaganm-hub/game_test

#include <Arduino.h>
#include <ezButton.h>
#include <search.h>
#include <connect_to_wifi.h>
#include <firebase.h>
#include <secrets.h>

const int vrx = 35;
const int vry = 32;
const int sw = 34;
ezButton button(sw);


unsigned long sendDataPrevMillis = 0;




void setup() {
  Serial.begin(115200);
 while (!Serial) { }
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
   
 initWiFi(ssid, password);
 firebase_config(API_KEY, DATABASE_URL, USER_EMAIL, USER_PASSWORD);

       Firebase.RTDB.setIntAsync(&fbdo, "/players/player1/x",0); 
       Firebase.RTDB.setIntAsync(&fbdo, "/players/player1/y", 0); 

}




void loop() {
  button.loop(); // MUST call the loop() function first

if (firebase_is_ready() && (millis() - sendDataPrevMillis > 50 || sendDataPrevMillis == 0))
  {
    sendDataPrevMillis = millis();

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




int x = analogRead(vrx); 
int y = analogRead(vry); 

move(x,y);



    Serial.println("ok");
  }




}









