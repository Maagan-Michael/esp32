
#include <LiquidCrystal_I2C.h>
#include <lcd.h>

// // set the LCD number of columns and rows
// int lcdColumns = 16;
// int lcdRows = 2;

// // set LCD address, number of columns and rows
// // if you don't know your display address, run an I2C scanner sketch
// LiquidCrystal_I2C lcd(0x3F, lcdColumns, lcdRows);  

void setup(){
  lcd_setup();
}

void loop(){
  lcd_print("kami");
  // set cursor to first column, second row
 lcd_print("king", 1000);
 
}
