#ifndef MAIN_ACTIVITY_H
#define MAIN_ACTIVITY_H


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#include <EasyButton.h>



#include "chemical.h"
#include "storage.h"
#include "lcd_display.h"
#include "coins.h"
#include "buttons.h"
#include "relays.h"


enum STATE {
  IDLE,
  CREDIT,
  PRICE,
  DISPENSE,
  PROG,
  PROG_MONEY,
  PROG_QTY_0,
  PROG_QTY_1,
  PROG_QTY_2,
  VIEW_SALES,
  TEST_SD
};


struct MAIN_ACTIVITY {
  int selectedChemical = -1;
  
  COINS gskCoins;

  unsigned int tymEqvToCredit=0;

  CHEMICAL gskChemicals[NUMBER_OF_CHEMICALS];
  STATE currentState = IDLE;
  unsigned long stateStartTime = millis();

  BUTTONS gskButtons;
  RELAYS gskRelays;


  


  
  STORAGE gskEEPROM;
  LCD_DISPLAY gskDisp;
  int tymOfLastDisp;



  void setup();
  void run ();
  void changeState(STATE);
  void stateDispense();
  void stateIdle();
  void stateProgMoney();
  void stateProgQty0();
  void stateProgQty1();
  void stateProgQty2();
  void stateProg();
  void stateCredit();
  void statePrice();
  void stateViewSales();
  void stateTestSD();
  unsigned long timeSinceStateChange();
  void resetStateStarttime();
  void correctEEPROMData();
  void updateEEPROMAtDispense(unsigned long, double);
};

void gskCoinInserted ();


#endif
