
#include <Adafruit_Fingerprint.h>
#include <finger/finger_enroll.h>
#include <finger/finger_setup.h>
#include <finger/finger_read.h>
#include <id_to_names.h>
#include <connect_to_wifi.h>
#include <secrets.h>
#include <discord.h>
#include <lcd.h>
#include <ota.h>

bool enroll_mode = false;




void setup()
{
  Serial.begin(115200);
  while (!Serial); 

  lcd_setup();
  initWiFi(ssid, password);
  delay(5000);
  setup_finger();
  print_finger_sensor_data();
  setup_ota();

}







void loop()                     // run over and over again
{
if(enroll_mode){

    lcd_print("Ready to enroll a fingerprint!");
  Serial.println("Please type in the ID # (from 1 to 127) you want to save this finger as...");
  id = readnumber();
  if (id == 0) {// ID #0 not allowed, try again!
     return;
  }
  Serial.print("Enrolling ID #");
  Serial.println(id);

  while (!  getFingerprintEnroll(finger, id) );

}else{
   
  const int person_id = getFingerprintID(finger);

  const char* x =id_to_name(person_id);

  if(x != ""){

  std::string lcd_text = std::string("Welcome ") + x + "!";

    lcd_print(lcd_text.c_str());


      std::string discord_text = std::string("Yoo ") + x + " just started working in the Bunker. \nCome Join!";

    send_message(discord_text.c_str(), channel_webhook_url);
  }
  Serial.print(x);
}
     delay(50); 

}
