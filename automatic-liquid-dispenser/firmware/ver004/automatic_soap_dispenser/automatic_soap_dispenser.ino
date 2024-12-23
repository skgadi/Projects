/*
*/
#include <SPI.h>
#include <SD.h>


//#include <EasyButton.h>
#include "main_activity.h"

MAIN_ACTIVITY gskMainActivity;
//EasyButton GLOBAL_gskCoinEntry(COINS_PIN);

void setup() {
  gskMainActivity.setup();
  SD.begin(10);
  //GLOBAL_gskCoinEntry.onPressed(GLOBAL_gskCoinInserted);
  attachInterrupt(digitalPinToInterrupt(COINS_PIN), GLOBAL_gskCoinInserted, FALLING);
}

void loop() {
  gskMainActivity.run();
  //GLOBAL_gskCoinEntry.read();
}


void GLOBAL_gskCoinInserted () {
  gskMainActivity.gskCoins.increaseCredit();
}