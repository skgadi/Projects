#include "main_activity.h"
void MAIN_ACTIVITY::stateCredit() {

  if (gskCoins.creditChange) {
    gskDisp.enable();
    resetStateStarttime();
    gskCoins.ackChange();
  }
  //Display the balance on the Display
  gskDisp.displayCredit(gskCoins.credit);

  // Change to idle state if it is more than 10 minutes after paying money
  if (
    ((timeSinceStateChange()/1000)>(REMOVE_CREDIT_AFTER_x_SECONDS)) ||
    (gskCoins.credit<=0)
    ) {
    gskCoins.resetCredit();
    changeState(IDLE);
  }

  //Goto dispense if a button is pressed
  //If any button is pressed show its price
  selectedChemical = gskButtons.getPressed();
  if (selectedChemical>=0 && selectedChemical< NUMBER_OF_CHEMICALS) {
    tymEqvToCredit = (gskChemicals[selectedChemical].timePerLiter * gskCoins.credit)/(gskChemicals[selectedChemical].costPerLiter);
    #ifdef ENABLE_SERIAL
    Serial.print("Equivalent time of credit: ");
    Serial.println(tymEqvToCredit);
    #endif
    changeState(DISPENSE);
  }


}
