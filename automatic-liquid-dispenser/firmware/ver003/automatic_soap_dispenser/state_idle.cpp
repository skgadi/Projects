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
  //if waited for long enough
  if ((timeSinceStateChange()/1000.0/60.0)>(RESET_LCD_AFTER_x_MINUTES*1.0)) {
    //gskDisp.displaywaitMessage();
    gskDisp.init();
    changeState(IDLE);
  }
}