#include "main_activity.h"
void MAIN_ACTIVITY::statePrice() {
  gskDisp.displayPrice(gskChemicals[selectedChemical].costPerLiter);
  // Change to idle state if it is more than 10 minutes after paying money
  if ((timeSinceStateChange()/1000)>(HIDE_PRICE_AFTER_x_SECONDS)) {
    changeState(IDLE);
  }
  //If any button is pressed show its price
  selectedChemical = gskButtons.getPressed();
  if (selectedChemical >= 0) {
    changeState(PRICE);
  }

  // Change to credit view 
  if (gskCoins.credit) {
    changeState(CREDIT);
  }

  //if program button is pressed 
  if (gskButtons.isProgBtnPressed()) {
    changeState(PROG);
  }

}
