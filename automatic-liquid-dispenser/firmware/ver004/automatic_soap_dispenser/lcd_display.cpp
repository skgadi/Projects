#include "lcd_display.h"
#include "global_variables.h"
#include "Arduino.h"

void LCD_DISPLAY::init () {
  byte splChars[8][8] = {{
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
    0b01000,
    0b01000,
    0b10010,
    0b11110,
    0b00000,
    0b00000
    },{
    0b00100,
    0b01000,
    0b01000,
    0b10000,
    0b11110,
    0b00010,
    0b00100,
    0b01000
    },{
    0b10001,
    0b10010,
    0b10010,
    0b10100,
    0b10100,
    0b11000,
    0b11001,
    0b10110
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
    lcd.setCursor(4,1);
    lcd.print(textForDisplay[2]);
    printLogo(3, 17);
    enableDisplay = false;
  }
}

void LCD_DISPLAY::displayCredit (int credit) {
  if (enableDisplay) {
    lcd.setCursor(5, 1);
    lcd.print(textForDisplay[3]+textForDisplay[1]);    
    lcd.setCursor(12, 1);
    lcd.print(credit);
    printLogo(3, 17);
    enableDisplay = false;
  }
}

void LCD_DISPLAY::displayPrice(int price) {
  if (enableDisplay) {
    lcd.setCursor(4,1);
    lcd.print(textForDisplay[4]+textForDisplay[1]);
    lcd.setCursor(12,1);
    lcd.print(price);
    printLogo(3, 17);
    enableDisplay = false;
  }
}

void LCD_DISPLAY::displayProg(unsigned int total) {
  if (enableDisplay) {
    for (int i=0; i<3; ){
      lcd.setCursor(0,i++);
      lcd.print(i);
    }
    lcd.setCursor(2,0);
    lcd.print(textForDisplay[4]);
    lcd.setCursor(2,1);
    lcd.print(textForDisplay[6]);
    lcd.setCursor(2,2);
    lcd.print(textForDisplay[7]);
    if (PROGRAM_SUMMARY || PROGRAM_SD){
      drawVerticalLine(8);
      lcd.setCursor(9,0);
      lcd.print(textForDisplay[0]);
      lcd.setCursor(10,0);
      lcd.print(commaForInt(total, 10, 0));
      lcd.setCursor(9,1);
      lcd.print(4);
      lcd.setCursor(11,1);
      lcd.print(textForDisplay[8]);
    }
    if (PROGRAM_SD){
      lcd.setCursor(9,2);
      lcd.print(5);
      lcd.setCursor(11,2);
      lcd.print(textForDisplay[9]);
    }
    printLogo(3,3);
    lcd.setCursor(9,3);
    lcd.print("SKGadi.com");

    enableDisplay = false;

  }
}


void LCD_DISPLAY::displayProgPrice(int chemNo, int cpl) {
  if (enableDisplay) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(textForDisplay[5]);
    lcd.setCursor(12,0);
    lcd.print(textForDisplay[4]);
    for (int i=0; i<4;) {
      lcd.setCursor(6*i, 1);
      lcd.print(char(i%2));
      lcd.setCursor(6*i, 2);
      lcd.print(++i);
    }
    lcd.setCursor(3,1);
    lcd.print(chemNo);
    lcd.setCursor(14,1);
    lcd.print(cpl);
    lcd.setCursor(0,3);
    lcd.print(5);
    lcd.setCursor(2,3);
    lcd.print(textForDisplay[7]);
    printLogo(3, 17);
    enableDisplay = false;
  }  
}

void LCD_DISPLAY::displayProgQty(int chemNo, unsigned int tpl) {
  if (enableDisplay) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(textForDisplay[5]);
    lcd.setCursor(12,0);
    lcd.print(textForDisplay[6]);
    for (int i=0; i<2;) {
      lcd.setCursor(6*i, 1);
      lcd.print(char(i%2));
      lcd.setCursor(6*i, 2);
      lcd.print(++i);
    }
    lcd.setCursor(3,1);
    lcd.print(chemNo);
    lcd.setCursor(13,1);
    double tpld = tpl/10.0;
    lcd.print(tpld);
    lcd.setCursor(11,2);
    lcd.print("3 CAMBIAR");
    lcd.setCursor(0,3);
    lcd.print(4);
    lcd.setCursor(2,3);
    lcd.print(textForDisplay[7]);
    printLogo(3, 17);
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
      //lcd.print("");
    }
    enableDisplay = false;
  }  
}

void LCD_DISPLAY::displayDispensing(int price, double liters, int rCredit) {
  if (enableDisplay) {
    lcd.setCursor(0,0);
    //lcd.print("PRECIO POR LITRO");
    lcd.setCursor(0,1);
    //lcd.print("DESPACHADO");
    lcd.setCursor(18,1);
    //lcd.print("LT");
    lcd.setCursor(0,2);
    //lcd.print("CREDITOS");
    lcd.setCursor(15,2);
    //lcd.print("PESOS");
    lcd.setCursor(1,3);
    //lcd.print("PULSE PARA CAMBIAR");
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

void LCD_DISPLAY::displayViewSales(int chemNo, unsigned long sales, unsigned long cons) {
  if (enableDisplay) {
    lcd.setCursor(0,0);
    //lcd.print("PRODUCTO: 1<      >2");
    lcd.setCursor(0,1);
    //lcd.print("VENTAS:");
    lcd.setCursor(9,1);
    lcd.print(commaForInt(sales, 7, 0));
    lcd.setCursor(17,1);
    //lcd.print("MXN");
    lcd.setCursor(0,2);
    //lcd.print("CONSUMO:");
    lcd.setCursor(14,0);
    lcd.print(chemNo);
    lcd.setCursor(9,2);
    lcd.print(commaForInt(cons, 9, 2));
    lcd.setCursor(18,2);
    lcd.print("LT");
    lcd.setCursor(0,3);
    //lcd.print("3. AL MENU ANTERIOR");
    enableDisplay = false;
  }  
}

void LCD_DISPLAY::displayTestSD(bool isCardAvail, bool isValidFormat, bool writtenTest){
  if (enableDisplay) {    
    lcd.setCursor(0,0);
    //lcd.print("[ ] SD DISPONIBLE");
    lcd.setCursor(0,1);
    //lcd.print("[ ] FORMATEADO BIEN");
    lcd.setCursor(0,2);
    lcd.print("[ ] PRUEBA DE ESCRB.");
    lcd.setCursor(0,3);
    lcd.print("1.PRUEBALO  2.SALIR ");
    lcd.setCursor(1,0);
    lcd.print(isCardAvail?char(3):char(2));
    lcd.setCursor(1,1);
    lcd.print(isValidFormat?char(3):char(2));
    lcd.setCursor(1,2);
    lcd.print(writtenTest?char(3):char(2));

    enableDisplay = false;
  }
}




String LCD_DISPLAY::commaForInt(unsigned long inp, int size, int dec){
  size++;
  char out[size--];
  out[size--] = '\0';
  int idx =0;
  while (size>=0) {
    out[size--] = 0x30 + inp%10;
    inp = inp/10;
    if (dec) {
      if (!(--dec)) {
      out[size--] = '.';        
      }
    } else if ((++idx)%3 == 0) {
      out[size--] = ',';
    }
  }
  return out;  
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