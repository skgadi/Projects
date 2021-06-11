#include "lcd_display.h"

void LCD_DISPLAY::init () {
  byte splChars[9][8] = {{
    0b00010,
    0b00110,
    0b01110,
    0b11110,
    0b01110,
    0b00110,
    0b00010,
    0b00000
    },{
    0b01000,
    0b01100,
    0b01110,
    0b01111,
    0b01110,
    0b01100,
    0b01000,
    0b00000
    },{
    0x0,0x1b,0xe,0x4,0xe,0x1b,0x0
    },{
    0x0,0x1,0x3,0x16,0x1c,0x8,0x0
    },{
    0b00010,
    0b00100,
    0b00100,
    0b01000,
    0b01000,
    0b10010,
    0b11110,
    0b00000
    },{
    0b00010,
    0b00100,
    0b01000,
    0b01110,
    0b00010,
    0b00100,
    0b01000,
    0b00000
    },{
    0b10010,
    0b10010,
    0b10100,
    0b10100,
    0b11000,
    0b11001,
    0b10110,
    0b00000
    },{
    0b11111,
    0b10001,
    0b01010,
    0b00100,
    0b01010,
    0b10001,
    0b11111,
    0b00000
    },{
    0x4,0xe,0xe,0xe,0x1f,0x0,0x4
  }};

  lcd.init();
  for (int i = 0; i < 8; i++) {
    lcd.createChar(i, splChars[i]);
  }
  
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
#ifdef CLIENT_COMPANY_NAME
    lcd.setCursor(3,0);
    lcd.print("BIENVENIDOS A");
    lcd.setCursor(0,1);
    lcd.print(CLIENT_COMPANY_NAME);
    
#else
    lcd.setCursor(4,1);
    lcd.print("BIENVENIDOS");
#endif
    printLogo(3, 17);
    enableDisplay = false;
  }
}

void LCD_DISPLAY::displayCredit (int credit) {
  if (enableDisplay) {
    lcd.setCursor(0, 1);
    lcd.print("SU SALDO ES $");
    lcd.print(credit);
    printLogo(3, 17);
    enableDisplay = false;
  }
}

void LCD_DISPLAY::displayPrice(int price) {
  if (enableDisplay) {
    lcd.setCursor(2, 1);
    lcd.print("PRECIO ES $");
    lcd.print(price);
    printLogo(3, 17);
    enableDisplay = false;
  }
}

void LCD_DISPLAY::displayProg() {
  if (enableDisplay) {
    lcd.setCursor(3,0);
    lcd.print("CONFIG");
    lcd.setCursor(0,1);
    lcd.print("1.PRECIO");
    lcd.setCursor(0,2);
    lcd.print("2.TIEMPO");
    lcd.setCursor(0,3);
    lcd.print("3.SALIR");
    drawVerticalLine(9);
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

void LCD_DISPLAY::displaywaitMessage(){
  clearAll();
  lcd.setCursor(3,1);
  lcd.print("Espere ... ");
  lcd.print(char(7));
  printLogo(3,17);
}

void LCD_DISPLAY::drawVerticalLine(int pos) {
  for (int i = 0; i < 4; i++) {
      lcd.setCursor(pos,i);
    lcd.print("|");
  }
}

void LCD_DISPLAY::printLogo(int row, int col){
  for (int i = 4; i < 7; i++) {
    lcd.setCursor(col++, row);
    lcd.print(char(i));    
  }
}