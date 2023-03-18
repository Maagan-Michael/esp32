/**
 * Created by K. Suwatchai (Mobizt)
 *
 * Email: k_suwatchai@hotmail.com
 *
 * Github: https://github.com/mobizt/Firebase-ESP-Client
 *
 * Copyright (c) 2023 mobizt
 *
 */

// This example shows how to send data fast and continuously.

#include <Arduino.h>
#if defined(ESP32) || defined(ARDUINO_RASPBERRY_PI_PICO_W)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

#include <Firebase_ESP_Client.h>

// Provide the token generation process info.
#include <addons/TokenHelper.h>

// Provide the RTDB payload printing info and other helper functions.
#include <addons/RTDBHelper.h>


// For the following credentials, see examples/Authentications/SignInAsUser/EmailPassword/EmailPassword.ino

// Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;



void firebase_config(const char* api_key, const char* database_url, const char* email, const char* passwrod){

  /* Assign the api key (required) */
  config.api_key = api_key;

  /* Assign the user sign in credentials */
  auth.user.email = email;
  auth.user.password = passwrod;

  /* Assign the RTDB URL (required) */
  config.database_url = database_url;

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h

  // Or use legacy authenticate method
  // config.database_url = DATABASE_URL;
  // config.signer.tokens.legacy_token = "<database secret>";

  // To connect without auth in Test Mode, see Authentications/TestMode/TestMode.ino

  Firebase.begin(&config, &auth);

  Firebase.reconnectWiFi(true);
}

void move(int x_to_add, int y_to_add){

int x = 0;
int y = 0;

       if (Firebase.RTDB.getInt(&fbdo, "/players/player1/x")) {
        x =  fbdo.intData();
      }


       if (Firebase.RTDB.getInt(&fbdo, "/players/player1/y")) {
         y =  fbdo.intData();
      }


      Serial.println(x_to_add);
      Serial.println(y_to_add);


       int new_x =  x + x_to_add - 2048;
       int new_y =  y + y_to_add - 2048;


       if(new_x > 100000){
        new_x = 100000;
       }
       if(new_x < -100000){
        new_x = -100000;
       }
       if(new_y > 75000){
        new_y = 75000;
       }
       if(new_y < -75000){
        new_y = -75000;
       }



       Firebase.RTDB.setIntAsync(&fbdo, "/players/player1/x",new_x); 
       Firebase.RTDB.setIntAsync(&fbdo, "/players/player1/y", new_y); 


        //setIntAsync(&fbdo, "/test/int", i);

}

bool firebase_is_ready(){
    return Firebase.ready();
}


