
#include <Arduino.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <secrets.h>
#include <connect_to_wifi.h>


const char *topic = "esp32/mqtt";
const char *client_id_prefix = "esp32-client-publisher-";


const int mqtt_port = 8883;


const int button = 32;  // the number of the pushbutton pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
int previousButtonState = 0;  // variable for reading the pushbutton status
int shouldTurnLedOn = false;


WiFiClientSecure espClient;
PubSubClient client(espClient);





void connect_to_mqtt_server() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
     String client_id = "esp32-client-publisher-";
     client_id += String(WiFi.macAddress());

    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void set_mqtt_client(){

 
espClient.setCACert(local_root_ca);
 
client.setClient(espClient);

client.setServer(mqtt_broker, mqtt_port);

}

void set_pins(){
  pinMode(button, INPUT);
}

void send_mqtt_message(const JsonDocument& _payload, const char *topic ){

  String payload_serialized;
  serializeJson(_payload , payload_serialized);

  // Publish the JSON string to the MQTT topic
  client.publish(topic, payload_serialized.c_str());


}

void send_mqtt_new_state(const bool state){
  StaticJsonDocument<200> doc;

  if(state){
     Serial.print("on");
    doc["message"] = "on";

  }else{
    Serial.print("off");
    doc["message"] = "off";
  }

  send_mqtt_message(doc,topic);

}


void setup() {
 Serial.begin(115200);
 while (!Serial) { }
  
set_pins();

initWiFi(ssid, password);

set_mqtt_client();
connect_to_mqtt_server();
 }




void loop() {

     if (!client.connected())  connect_to_mqtt_server();
  client.loop();

  
  previousButtonState = buttonState;
  buttonState = digitalRead(button);



if(previousButtonState == buttonState){
  delay(200);
  return;
}

if(buttonState == HIGH ){
  shouldTurnLedOn = !shouldTurnLedOn;

if(shouldTurnLedOn){
send_mqtt_new_state(true);

}else{
  send_mqtt_new_state(false);

 
}

delay(1000);

}


  
}

