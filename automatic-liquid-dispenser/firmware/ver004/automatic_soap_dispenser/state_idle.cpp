#include "main_activity.h"

void MAIN_ACTIVITY::stateIdle() {
  gskDisp.displayWelcome();
  if (gskCoins.credit) {
    changeState(CREDIT);
  }

  //If any button is pressed show its price
  selectedChemical = gskButtons.getPressed();
  if (selectedChemical >= 0) {
    changeState(PRICE);
  }

  //if program button is pressed 
  if (gskButtons.isProgBtnPressed()) {
    changeState(PROG);
  }
}