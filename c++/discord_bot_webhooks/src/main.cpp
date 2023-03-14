#include <connect_to_wifi.h>
#include <secrets.h>
#include <discord.h>

const int button = 32;  // the number of the pushbutton pin


void set_pins(){
  pinMode(button, INPUT);
}


void setup() {
  // Start the Serial communication
  Serial.begin(115200);

 
  while (!Serial) {}

  set_pins();


 initWiFi(ssid, password);
 
}

void loop() {

  if(digitalRead(button) == HIGH){
    send_message("this was sent from an esp32 button!");
    Serial.print("test");
    delay(100000);
  }
  // Empty
}
