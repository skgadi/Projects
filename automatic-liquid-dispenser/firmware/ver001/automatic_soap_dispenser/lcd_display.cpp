#include "lcd_display.h"

void LCD_DISPLAY::init () {
  lcd.init();
  lcd.backlight();
}

void LCD_DISPLAY::enable() {
  enableDisplay = true;
}

void LCD_DISPLAY::clearAll () {
  lcd.clear();
}

void LCD_DISPLAY::displayWelcome () {
  if (enableDisplay){
    lcd.setCursor(5,0);
    lcd.print("BIENVENIDOS");
    lcd.setCursor(2,1);
    lcd.print("INSERTAR MONEDAS");
    lcd.setCursor(9,2);
    lcd.print("Y");
    lcd.setCursor(1,3);
    lcd.print("SELECIONAR PRODUCTO");
    enableDisplay = false;
  }
}

void LCD_DISPLAY::displayCredit (int credit) {
  if (enableDisplay) {
    lcd.setCursor(4,0);
    lcd.print("SU SALDO ES");    
    lcd.setCursor(7,2);
    lcd.print("PESOS"); 
    lcd.setCursor(1,3);
    lcd.print("SELECIONAR PRODUCTO");
    lcd.setCursor(9,1);
    lcd.print(credit);
    enableDisplay = false;
  }
}

void LCD_DISPLAY::displayPrice(int price) {
  if (enableDisplay) {
    lcd.setCursor(4,0);
    lcd.print("EL PRECIO ES");
    lcd.setCursor(9,1);
    lcd.print(price);
    lcd.setCursor(2,2);
    lcd.print("PESOS POR LITRO");
    lcd.setCursor(0,3);
    lcd.print("INSERTAR LAS MONEDAS");
    enableDisplay = false;
  }
}

void LCD_DISPLAY::displayProg() {
  if (enableDisplay) {
    lcd.setCursor(3,0);
    lcd.print("CONFIGURACION");
    lcd.setCursor(0,1);
    lcd.print("1. PRECIO POR LITRO");
    lcd.setCursor(0,2);
    lcd.print("2. CANTIDAD (TIEMPO)");
    lcd.setCursor(0,3);
    lcd.print("3. SALIR DEL MENU");
    enableDisplay = false;
  }
}


void LCD_DISPLAY::displayProgPrice(int chemNo, int cpl) {
  if (enableDisplay) {
    lcd.setCursor(1,0);
    lcd.print("PRODUCTO   PRECIO");
    lcd.setCursor(2,1);
    lcd.print("<    >    -    +");
    lcd.setCursor(4,1);
    lcd.print(chemNo);
    lcd.setCursor(14,1);
    lcd.print(cpl);
    lcd.setCursor(1,2);
    lcd.setCursor(2,2);
    lcd.print("1    2    3    4");
    lcd.setCursor(0,3);
    lcd.print("5. AL MENU ANTERIOR");
    enableDisplay = false;
  }  
}

void LCD_DISPLAY::displayProgQty(int chemNo, unsigned int tpl) {
  if (enableDisplay) {
    lcd.setCursor(1,0);
    lcd.print("PRODUCTO   TIEMPO");
    lcd.setCursor(2,1);
    lcd.print("<    >");
    lcd.setCursor(4,1);
    lcd.print(chemNo);
    lcd.setCursor(14,1);
    double tpld = tpl/10.0;
    lcd.print(tpld);
    lcd.setCursor(1,2);
    lcd.setCursor(2,2);
    lcd.print("1    2   3.CAMBIAR");
    lcd.setCursor(0,3);
    lcd.print("4. AL MENU ANTERIOR");
    enableDisplay = false;
  }  
}

void LCD_DISPLAY::displayProgQty1(int chemNo, unsigned int tpl, bool start) {
  if (enableDisplay) {
    lcd.setCursor(1,0);
    lcd.print("PRODUCTO   TIEMPO");
    lcd.setCursor(4,1);
    lcd.print(chemNo);
    lcd.setCursor(14,1);
    double tpld = tpl/10.0;
    lcd.print(tpld);
    lcd.setCursor(1,2);
    lcd.setCursor(0,2);
    lcd.print("SELECCIONE CUALQUIER");
    lcd.setCursor(1,3);
    if (start) {
      lcd.print("BOTON PARA INICIAR");
    } else {
      lcd.print("BOTON PARA DETENER");
    }
    enableDisplay = false;
  }  
}

void LCD_DISPLAY::displayDispensing(int price, double liters, int rCredit) {
  if (enableDisplay) {
    lcd.setCursor(0,0);
    lcd.print("PRECIO POR LITRO");
    lcd.setCursor(0,1);
    lcd.print("DESPACHADO");
    lcd.setCursor(18,1);
    lcd.print("LT");
    lcd.setCursor(0,2);
    lcd.print("CREDITOS");
    lcd.setCursor(15,2);
    lcd.print("PESOS");
    lcd.setCursor(1,3);
    lcd.print("PULSE PARA CAMBIAR");
    enableDisplay = false;
    lcd.setCursor(17,0);
    lcd.print(price);
    lcd.setCursor(11,1);
    lcd.print(liters);
    lcd.setCursor(10,2);
    lcd.print(rCredit);
    if (rCredit<1000){
      lcd.setCursor(13,2);
      lcd.print(" ");
    }
    if (rCredit<100){
      lcd.setCursor(12,2);
      lcd.print(" ");
    }
    if (rCredit<10){
      lcd.setCursor(11,2);
      lcd.print(" ");
    }
  }  
}