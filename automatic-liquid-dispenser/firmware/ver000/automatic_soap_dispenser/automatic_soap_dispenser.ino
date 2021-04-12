#include <EasyButton.h>



#include "main_activity.h"


//COINS gskCoins;

MAIN_ACTIVITY gskMainActivity;
EasyButton gskAnyButton(COINS_PIN);


void setup() {
  gskMainActivity.setup();

  gskAnyButton.onPressed(gskCoinInserted);
}

int i=0;
void loop() {
  gskMainActivity.run();
  gskAnyButton.read();
}


void gskCoinInserted () {
  gskMainActivity.gskCoins.increaseCredit();
  gskMainActivity.gskDisp.enable();
  gskMainActivity.resetStateStarttime();
}
