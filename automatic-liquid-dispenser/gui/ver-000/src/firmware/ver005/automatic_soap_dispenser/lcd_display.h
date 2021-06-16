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
  void displayProg(unsigned int);
  void displayProgPrice(int, int);
  void displayProgQty(int, unsigned int);
  void displayProgQty1(int, unsigned int, bool);
  void displayProgPriceEdit();
  void displayProgQtyEdit();
  void displayDispensing(int, double, int);
  void displayViewSales(int, unsigned long, unsigned long);
  void displayTestSD(bool, bool);
  String commaForInt(unsigned long, int, int);
  void drawVerticalLine(int);
  void printLogo(int, int);
  void displayTest(int);
  String textForDisplay[20] = {
    "$",
    ":",
    "BIENVENIDOS",
    "SALDO",
    "PRECIO",
    "PRODUCTO",
    "TIEMPO",
    "SALIR",
    "INFO",
    "SD",
    "DESPACHADO",
    " ",
    "BOTON PARA",
    "INICIAR",
    "PARAR",
    "VENTAS",
    "CONSUMO",
    "SD",
    "[ ]",
    "PRUEBA"
  };
};

void gskCoinInserted ();


#endif
