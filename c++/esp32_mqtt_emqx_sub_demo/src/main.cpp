
#include <Arduino.h>
#include <WiFiClientSecure.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <secrets.h>
#include <connect_to_wifi.h>



// MQTT Broker
const char *topic = "esp32/mqtt";
const char *client_id_prefix = "esp32-client-publisher-";
const int mqtt_port = 8883;

WiFiClientSecure espClient;
PubSubClient client(espClient);




const int led = 32;  // the number of the pushbutton pin


void on_message_recieved_callback(char *topic, byte *payload, unsigned int length) {
 Serial.print("Message arrived in topic: ");
 Serial.println(topic);
 Serial.print("Message:");
Serial.write(payload, length);

   StaticJsonDocument<200> doc;
  deserializeJson(doc, payload, length);
  JsonObject obj = doc.as<JsonObject>();

  if(obj["message"] == "on"){
    digitalWrite(led, HIGH);

  } else if(obj["message"] == "off") {
    digitalWrite(led, LOW);


  }

 Serial.println();
 Serial.println("-----------------------");


}


void connect_to_mqtt_server() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
     String client_id = client_id_prefix;
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

client.setCallback(on_message_recieved_callback);
 
espClient.setCACert(local_root_ca);
 
client.setClient(espClient);

client.setServer(mqtt_broker, mqtt_port);
}

void set_pins(){
  pinMode(led, OUTPUT);
}

void setup() {
  Serial.begin(115200);
  while (!Serial) { }
  
  initWiFi(ssid, password);
 

 set_pins();
  set_mqtt_client();
 connect_to_mqtt_server();
 

 client.subscribe(topic);
}



void loop() {
   if (!client.connected())  connect_to_mqtt_server();
  client.loop();

   }