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
    if (SD.begin(CS_PIN_FOR_SD)) {
      File dataFile = SD.open(logFile, FILE_WRITE);
      if (dataFile) {
        dataFile.print(millis()/1000.0);
        dataFile.print(char(44));
        dataFile.print(gskDisp.textForDisplay[10]);
        dataFile.print(char(44));
        dataFile.print(selectedChemical+1);
        dataFile.print(char(44));
        dataFile.print(consumedCredit);
        dataFile.print(char(44));
        dataFile.println(dispensed);
        dataFile.close();
      }
    }
#endif
    if (gskCoins.credit<0) {
      gskCoins.resetCredit();
      changeState(IDLE);
    }
    changeState(CREDIT);
  }
  if (remainingTime<0) {
    gskRelays.stopAll();
    updateEEPROMAtDispense(gskCoins.credit, dispensed);
#ifdef PROGRAM_SD
    if (SD.begin(CS_PIN_FOR_SD)) {
      File dataFile = SD.open(logFile, FILE_WRITE);
      if (dataFile) {
        dataFile.print(millis()/1000.0);
        dataFile.print(char(44));
        dataFile.print(gskDisp.textForDisplay[10]);
        dataFile.print(char(44));
        dataFile.print(selectedChemical+1);
        dataFile.print(char(44));
        dataFile.print(gskCoins.credit);
        dataFile.print(char(44));
        dataFile.println(dispensed);
        dataFile.close();
      }
    }
#endif
    gskCoins.resetCredit();
    changeState(IDLE);
  }
}


