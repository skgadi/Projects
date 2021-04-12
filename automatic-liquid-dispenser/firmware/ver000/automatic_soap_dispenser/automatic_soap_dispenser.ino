#include <EasyButton.h>



#include "main_activity.h"


//COINS gskCoins;

MAIN_ACTIVITY gskMainActivity;
//EasyButton gskAnyButton(COINS_PIN);
EasyButton gskCoinEntry(COINS_PIN);


void setup() {
  gskMainActivity.setup();

  gskCoinEntry.onPressed(gskCoinInserted);
  //gskAnyButton.onPressed(gskCoinInserted);
  //attachInterrupt(digitalPinToInterrupt(COINS_PIN), gskCoinInserted, FALLING);
}

int i=0;
void loop() {
  gskMainActivity.run();
  gskCoinEntry.read();
  //gskAnyButton.read();
}


void gskCoinInserted () {
  if (gskMainActivity.currentState != DISPENSE) {
    gskMainActivity.gskCoins.increaseCredit();
  }
}
