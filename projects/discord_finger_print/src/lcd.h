#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x3F, lcdColumns, lcdRows);  


void lcd_setup(){
    // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}


void lcd_print(const char* text, int duration = 2000){

    // clears the display to print new message
  lcd.clear();
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print(text);
  delay(duration);
  lcd.clear();
}