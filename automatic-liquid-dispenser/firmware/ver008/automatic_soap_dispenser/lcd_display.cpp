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

void LCD_DISPLAY::displayCredit (double credit) {
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

void LCD_DISPLAY::displayProg(double total) {
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
    #if defined (PROGRAM_SUMMARY) || defined (PROGRAM_SD)
      drawVerticalLine(8);
      lcd.setCursor(9,0);
      lcd.print(textForDisplay[0] + total);
      lcd.setCursor(9,1);
      lcd.print(4 + textForDisplay[11] + textForDisplay[8]);
    #endif
    #ifdef PROGRAM_SD
      lcd.setCursor(9,2);
      lcd.print(5 + textForDisplay[11] + textForDisplay[17]);
    #endif
    printLogo(3,3);
    lcd.setCursor(9,3);
    lcd.print("SKGadi.com");

    enableDisplay = false;

  }
}


void LCD_DISPLAY::displayProgPrice(int chemNo, int cpl) {
  if (enableDisplay) {
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
    lcd.print(textForDisplay[11]);
    lcd.setCursor(14,1);
    lcd.print(cpl);
    int tempFactor = 1;
    while(cpl*tempFactor < MAX_MONEY_PER_LITER) {
      lcd.print(textForDisplay[11]);
      tempFactor *= 10;
    }
    lcd.setCursor(0,3);
    lcd.print(5);
    lcd.setCursor(2,3);
    lcd.print(textForDisplay[7]);
    printLogo(3, 17);
    enableDisplay = false;
  }  
}

void LCD_DISPLAY::displayProgQty(int chemNo, double tpld) {
  if (enableDisplay) {
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
    lcd.print(textForDisplay[11]);
    lcd.setCursor(13,1);
    lcd.print(tpld);
    lcd.print(textForDisplay[11]+textForDisplay[11]);
    lcd.setCursor(11,2);
    lcd.print(3 + textForDisplay[11] + "CAMBIAR");
    lcd.setCursor(0,3);
    lcd.print(4);
    lcd.setCursor(2,3);
    lcd.print(textForDisplay[7]);
    printLogo(3, 17);
    enableDisplay = false;
  }  
}

void LCD_DISPLAY::displayProgQty1(int chemNo, double tpld, bool start) {
  if (enableDisplay) {
    lcd.setCursor(0,0);
    lcd.print(textForDisplay[5]);
    lcd.setCursor(12,0);
    lcd.print(textForDisplay[6]);
    lcd.setCursor(3,1);
    lcd.print(chemNo);
    lcd.setCursor(13,1);
    lcd.print(tpld);
    lcd.setCursor(0,2);
    lcd.print(textForDisplay[12]+textForDisplay[11]);
    if (start) {
      lcd.print(textForDisplay[13]);
    } else {
      lcd.print(textForDisplay[14]);
    }
    printLogo(3, 17);
    enableDisplay = false;
  }  
}

void LCD_DISPLAY::displayDispensing(int price, double liters, double rCredit) {
  if (enableDisplay) {
    lcd.setCursor(0,0);
    lcd.print(textForDisplay[4] + textForDisplay[1] + textForDisplay[11]);
    lcd.print(price);
    lcd.setCursor(0,1);
    lcd.print(textForDisplay[10] + textForDisplay[1] + textForDisplay[11]);    
    lcd.print(liters);
    lcd.print(textForDisplay[11]);
    lcd.setCursor(0,2);
    lcd.print(textForDisplay[3] + textForDisplay[1] + textForDisplay[11] + textForDisplay[0]);
    lcd.print(rCredit);
    lcd.print(textForDisplay[11]);
    printLogo(3, 17);
    enableDisplay = false;
  }  
}

void LCD_DISPLAY::displayViewSales(int chemNo, double sales, double cons, bool isSpl) {
  if (enableDisplay) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(textForDisplay[5] + textForDisplay[1] + textForDisplay[11] + 1 + char(0) +  textForDisplay[11] + chemNo +  textForDisplay[11] + char(1) + 2 +  textForDisplay[11]);
    lcd.setCursor(0,1);
    if (isSpl) {
      lcd.print(textForDisplay[15] + textForDisplay[1] + textForDisplay[11] + textForDisplay[0] + sales);
    } else {
      lcd.print(textForDisplay[16] + textForDisplay[1] + textForDisplay[11] + cons);
    }
    lcd.setCursor(0,2);
      lcd.print(3+textForDisplay[1]+ textForDisplay[11] + textForDisplay[7]);
    if (isSpl) {
      lcd.setCursor(0,3);
      lcd.print(4 + textForDisplay[1] + textForDisplay[11] + textForDisplay[0] + 0);
    }
    printLogo(3, 17);
    enableDisplay = false;
  }  
}
/*
void LCD_DISPLAY::displayTestSD(bool isCardAvail, bool writtenTest){
  if (enableDisplay) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(textForDisplay[18] + textForDisplay[11] + textForDisplay[17]);
    lcd.setCursor(0,1);
    lcd.print(textForDisplay[18] + textForDisplay[11] + textForDisplay[19]);
    lcd.setCursor(0,2);
    lcd.print(1 + textForDisplay[11] + textForDisplay[19]);
    lcd.setCursor(0,3);
    lcd.print(2 + textForDisplay[11] + textForDisplay[7]);

    lcd.setCursor(1,0);
    lcd.print(isCardAvail?char(3):char(2));
    lcd.setCursor(1,1);
    lcd.print(writtenTest?char(3):char(2));

    printLogo(3, 17);
    enableDisplay = false;
  }
}
*/



String LCD_DISPLAY::commaForInt(long inp, int size, int dec){
  size++;
  char out[size--];
  out[size--] = '\0';
  int idx =0;
  while (size>=0) {
    out[size--] = 0x30 + inp%10;
    inp = inp/10;
    if (dec) {
      if (!(--dec)) {
      out[size--] = 46; // for dot        
      }
    } else if ((++idx)%3 == 0) {
      out[size--] = 44; // for comma
    }
  }
  return out;  
}


void LCD_DISPLAY::drawVerticalLine(int pos) {
  for (int i = 0; i < 4; i++) {
      lcd.setCursor(pos,i);
    lcd.print(char(124)); // for pipe
  }
}

void LCD_DISPLAY::printLogo(int row, int col){
  for (int i = 4; i < 7; i++) {
    lcd.setCursor(col++, row);
    lcd.print(char(i));    
  }
}

void LCD_DISPLAY::displayTest(int test) {
    if (enableDisplay) {
    lcd.clear();
    lcd.setCursor(10,1);
    lcd.print(test);
    enableDisplay = false;
  }
}