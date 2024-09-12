#include "main_activity.h"
void MAIN_ACTIVITY::stateDispense() {
  gskRelays.on(selectedChemical);
  double timeOfDispense = timeSinceStateChange();
  //double remainingTime = tymEqvToCredit - timeOfDispense;
  double consumedCredit = timeOfDispense*((1.0*gskChemicals[selectedChemical].costPerLiter)*(1.0/(gskChemicals[selectedChemical].timePerLiter*1.0)));
  //Serial.print("Consumed credit: ");
  //Serial.println(consumedCredit);
  double remainingCredits = gskCoins.credit - consumedCredit;
  double dispensed = timeOfDispense/gskChemicals[selectedChemical].timePerLiter;
  if ((tymOfLastDisp + REFRESH_DISPLAY_DURING_DISPENSE_EVERY_x_SECONDS) <= timeOfDispense) {
    gskDisp.enable();
    tymOfLastDisp = timeOfDispense;
  }
  gskDisp.displayDispensing(gskChemicals[selectedChemical].costPerLiter, dispensed, remainingCredits);
  int pressedBtn = gskButtons.getPressed();
  if (pressedBtn>=0 && pressedBtn< NUMBER_OF_CHEMICALS) {
    gskRelays.stopAll();
    gskCoins.credit -= consumedCredit;
    updateEEPROMAtDispense(consumedCredit, dispensed);
#ifdef PROGRAM_SD
    SdFat sd;
    File myFile;
    if (sd.begin(CS_PIN_FOR_SD)){
      myFile = sd.open(logFile, FILE_WRITE);
      myFile.seekEnd();
      myFile.println(millis()/1000.0 
      + gskDisp.textForDisplay[20] + gskDisp.textForDisplay[10]
      + gskDisp.textForDisplay[20] + (selectedChemical+1)
      + gskDisp.textForDisplay[20] + (consumedCredit)
      + gskDisp.textForDisplay[20] + (dispensed)
      );
      myFile.close();
    }
#endif
    if (gskCoins.credit<0) {
      gskCoins.resetCredit();
      changeState(IDLE);
    }
    changeState(CREDIT);
  }
  if (remainingCredits<=0) {
    gskRelays.stopAll();
    //delay(20000);
    updateEEPROMAtDispense((gskCoins.credit)*1.0, dispensed);
#ifdef PROGRAM_SD
    SdFat sd;
    File myFile;
    if (sd.begin(CS_PIN_FOR_SD)){
      myFile = sd.open(logFile, FILE_WRITE);
      myFile.seekEnd();
      myFile.println(millis()/1000.0 
      + gskDisp.textForDisplay[20] + gskDisp.textForDisplay[10]
      + gskDisp.textForDisplay[20] + (selectedChemical+1)
      + gskDisp.textForDisplay[20] + (gskCoins.credit)
      + gskDisp.textForDisplay[20] + (dispensed)
      );
      myFile.close();
    }
#endif
    gskCoins.resetCredit();
    changeState(IDLE);
  }
}


