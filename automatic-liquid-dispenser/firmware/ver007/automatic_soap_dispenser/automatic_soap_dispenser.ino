/*
*/
//#include <SPI.h>

#include "global_variables.h"


#include "main_activity.h"





MAIN_ACTIVITY gskMainActivity;
#ifdef USE_EASY_BUTTON_FOR_COIN
EasyButton GLOBAL_gskCoinEntry(COINS_PIN);
#endif

void setup() {
  gskMainActivity.setup();
#ifdef PROGRAM_SD
  //SD.begin(CS_PIN_FOR_SD);
#endif
#ifdef USE_EASY_BUTTON_FOR_COIN
  GLOBAL_gskCoinEntry.onPressed(GLOBAL_gskCoinInserted);
#else
  //attachInterrupt(digitalPinToInterrupt(COINS_PIN), GLOBAL_gskCoinInserted, FALLING);
#endif
}

void loop() {
  gskMainActivity.run();
#ifdef USE_EASY_BUTTON_FOR_COIN
  GLOBAL_gskCoinEntry.read();
#else
  //if (gskMainActivity.currentState != DISPENSE) {
    gskMainActivity.gskCoins.checkCoinPulse();
  //}
#endif
}


void GLOBAL_gskCoinInserted () {
#ifdef USE_EASY_BUTTON_FOR_COIN
  if (gskMainActivity.currentState != DISPENSE) {
#endif
    gskMainActivity.gskCoins.increaseCredit();
#ifdef USE_EASY_BUTTON_FOR_COIN
  }
#endif
}
