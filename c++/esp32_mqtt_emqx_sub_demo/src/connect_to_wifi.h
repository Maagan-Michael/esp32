#include <WiFi.h>



 void initWiFi(const char* ssid, const char* password) {
  Serial.print("Connecting to WiFi ...");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    WiFi.begin(ssid, password);

    delay(1000);
  }
  Serial.println(WiFi.localIP());
}
