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
    ((timeSinceStateChange()/1000.0)>(REMOVE_CREDIT_AFTER_x_SECONDS*1.0)) ||
    (gskCoins.credit<=0)
    ) {
    gskEEPROM.addToToal(gskCoins.credit);
#ifdef PROGRAM_SD
    SdFat sd;
    File myFile;
    if (sd.begin(CS_PIN_FOR_SD)){
      myFile = sd.open(logFile, FILE_WRITE);
      myFile.seekEnd();
      myFile.println(millis()/1000.0 
      + gskDisp.textForDisplay[20] + gskDisp.textForDisplay[3]
      + gskDisp.textForDisplay[20]
      + gskDisp.textForDisplay[20] + (gskCoins.credit)
      + gskDisp.textForDisplay[20]
      );
      myFile.close();
    }
#endif
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
