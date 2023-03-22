#include <Arduino.h>
#include <lazer.h>
#include <Wire.h>

#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x3F, lcdColumns, lcdRows);  



void lcd_print(uint8_t distance){
    lcd.clear(); 

  // set cursor to first column, first row
  lcd.setCursor(0, 0);
 lcd.print(distance);
   lcd.print(" milimiters");
  // clears the display to print new message
  // set cursor to first column, second row
 
}

int lightbulb = 25;


void setup() {
  Serial.begin(115200);

  // wait for serial port to open on native usb devices
  while (!Serial) {}
  
  pinMode(lightbulb, OUTPUT);

  set_laser_sensor();

  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
 
}

void loop() {
  
 uint8_t distance =  read_distance_milimeters();
 Serial.println(distance);


 if(distance< 105 && distance >95){
    digitalWrite(lightbulb,HIGH);

 }else{

      digitalWrite(lightbulb,LOW);

 }

 lcd_print(distance);
 
  delay(500);
}