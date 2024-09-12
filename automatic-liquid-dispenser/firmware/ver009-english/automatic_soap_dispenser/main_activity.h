#ifndef MAIN_ACTIVITY_H
#define MAIN_ACTIVITY_H


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "global_variables.h"

#ifdef USE_EASY_BUTTON_FOR_COIN
#include <EasyButton.h>
#endif

#ifdef PROGRAM_SD
//#include <SD.h>
#include <SdFat.h>
#endif



#include "chemical.h"
#include "summary_data.h"
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

  double tymEqvToCredit=0;

  CHEMICAL gskChemicals[NUMBER_OF_CHEMICALS];
  SUMMARY_DATA gskSummaryData;
  STATE currentState = IDLE;
  unsigned long stateStartTime = millis();

  BUTTONS gskButtons;
  RELAYS gskRelays;


  


  
  STORAGE gskEEPROM;
  LCD_DISPLAY gskDisp;
  double tymOfLastDisp;

  bool testSD = false;
  
  char logFile[8] = "log.csv";

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
  double timeSinceStateChange();
  void resetStateStarttime();
  void correctEEPROMData();
  void updateEEPROMAtDispense(double, double);
  /*bool testSDExist();
  bool writeToSD(String,String,String,String);*/
  void(* resetTheSystem) (void) = 0;
  bool configChangeNoted = false;
  double prevTimeLCDClear = 0;
};

void gskCoinInserted ();


#endif
