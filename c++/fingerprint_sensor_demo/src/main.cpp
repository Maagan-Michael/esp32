
#include <Adafruit_Fingerprint.h>
#include <finger/finger_enroll.h>
#include <finger/finger_setup.h>
#include <finger/finger_read.h>






void setup()
{
  Serial.begin(115200);
  while (!Serial); 
  delay(5000);
  setup_finger();
  print_finger_sensor_data();



finger.getTemplateCount();

  if (finger.templateCount == 0) {
    Serial.print("Sensor doesn't contain any fingerprint data. Please run the 'enroll' example.");
  }
  else {
    Serial.println("Waiting for valid finger...");
      Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  }

}







void loop()                     // run over and over again
{

    // getFingerprintID(finger);
  delay(50); 
  Serial.println("Ready to enroll a fingerprint!");
  Serial.println("Please type in the ID # (from 1 to 127) you want to save this finger as...");
  id = readnumber();
  if (id == 0) {// ID #0 not allowed, try again!
     return;
  }
  Serial.print("Enrolling ID #");
  Serial.println(id);

  while (!  getFingerprintEnroll(finger, id) );
}
