#include "main_activity.h"
void MAIN_ACTIVITY::stateDispense() {
  gskRelays.on(selectedChemical);
  int timeOfDispense = timeSinceStateChange()/100;
  int remainingTime = tymEqvToCredit - timeOfDispense;
  int consumedCredit = 1+ timeOfDispense*(gskChemicals[selectedChemical].costPerLiter*(1.0/(gskChemicals[selectedChemical].timePerLiter*1.0)));
  //Serial.print("Consumed credit: ");
  //Serial.println(consumedCredit);
  int remainingCredits = gskCoins.credit - consumedCredit;
  double dispensed = timeOfDispense/(gskChemicals[selectedChemical].timePerLiter*1.0);
  if (tymOfLastDisp != timeOfDispense) {
    gskDisp.enable();
    tymOfLastDisp = timeOfDispense;
  }
  gskDisp.displayDispensing(gskChemicals[selectedChemical].costPerLiter, dispensed, remainingCredits);
  int pressedBtn = gskButtons.getPressed();
  if (pressedBtn>=0 && pressedBtn< NUMBER_OF_CHEMICALS) {
    gskCoins.credit -= consumedCredit;
    gskRelays.stopAll();
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
  if (remainingTime<=0) {
    gskRelays.stopAll();
    updateEEPROMAtDispense(gskCoins.credit, dispensed);
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


