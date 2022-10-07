#include "gsk_lcd.h"

GSK_LCD::GSK_LCD(): LiquidCrystal_I2C( 0x27, LCD_COLS, LCD_ROWS) {
}


void GSK_LCD::setup() {
  Wire.begin(pins[0], pins[1]);
  init();
  backlight();
  showWelcome();
}

void GSK_LCD::showWelcome() {
  setCursor(4, 0);
  print("Bienvenidos");
}

void GSK_LCD::printNumber(int i) {
  clear();
  setCursor(4,0);
  print(i);
}