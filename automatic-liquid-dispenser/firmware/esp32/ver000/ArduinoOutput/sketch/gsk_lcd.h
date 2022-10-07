#line 1 "c:\\Suresh\\git\\Projects\\automatic-liquid-dispenser\\firmware\\esp32\\ver000\\uc\\gsk_lcd.h"
#ifndef GSK_LCD_H
#define GSK_LCD_H

#include "gsk_global.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ROWS 4
#define LCD_COLS 20

class GSK_LCD : LiquidCrystal_I2C {
private:
  int pins[2]={PIN_SDA_uC, PIN_SCL_uC};
public:
  GSK_LCD();
  void setup();
  void showWelcome();
  void printNumber(int i);
};

#endif