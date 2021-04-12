#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H


#include <LiquidCrystal_I2C.h>

struct LCD_DISPLAY {
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);
  bool enableDisplay = true;
  void init();
  void clearAll();
  void enable();
  void displayWelcome();
  void displayCredit(int);
  void displayPrice(int);
  void displayProg();
  void displayProgPrice(int, int);
  void displayProgQty(int, unsigned int);
  void displayProgQty1(int, unsigned int, bool);
  void displayProgPriceEdit();
  void displayProgQtyEdit();
  void displayDispensing(int, double, int);
};

void gskCoinInserted ();


#endif
