#include <FS.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>



const char* WEBHOOK_URL = "https://discord.com/api/webhooks/1084506187241898064/kN2iT14EP2iNaoTtjOrIz2XTQqkTjx-qAg9WSoIzNMZj_hOTDU3ZcTMkESleYx5nxKnh";




void send_message(char* message){
 // Create an instance of HTTPClient
  HTTPClient http;

  // Set the destination URL
  http.begin(WEBHOOK_URL);

  // Set the Content-Type header to indicate the format of the request body
  http.addHeader("Content-Type", "application/json");

  // Create a JSON object to hold the request body
  StaticJsonDocument<200> doc;
  doc["content"] = message;

  // Serialize the JSON object to a string
  String requestBody;
  serializeJson(doc, requestBody);

  // Send the POST request with the request body
  int httpResponseCode = http.POST(requestBody);

  // Check the response code
  if (httpResponseCode > 0) {
    Serial.printf("HTTP Response code: %d\n", httpResponseCode);
    String response = http.getString();
    Serial.println(response);
  } else {
    Serial.printf("Error code: %d\n", httpResponseCode);
  }

  // Close the connection
  http.end();

}