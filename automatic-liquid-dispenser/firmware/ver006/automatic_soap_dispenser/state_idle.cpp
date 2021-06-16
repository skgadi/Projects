#include "main_activity.h"

void MAIN_ACTIVITY::stateIdle() {
  gskDisp.displayWelcome();
  if (gskCoins.credit) {
    changeState(CREDIT);
  }

  //If any button is pressed show its price
  selectedChemical = gskButtons.getPressed();
  if (selectedChemical>=0 && selectedChemical< NUMBER_OF_CHEMICALS) {
    changeState(PRICE);
  }

  //if program button is pressed 
  if (gskButtons.isProgBtnPressed()) {
    changeState(PROG);
  }
  //if waited for long enough
  if (((millis() - prevTimeLCDClear)/1000.0/60.0)>=(RESET_LCD_AFTER_x_MINUTES*1.0)) {
    //gskDisp.displaywaitMessage();
    prevTimeLCDClear = millis();
    gskDisp.init();
    changeState(IDLE);
  }

  if (( millis() /1000.0/60.0)>=(RESET_SYSTEM_AFTER_x_MINUTES*1.0)) {
#ifdef PROGRAM_SD
    SdFat sd;
    File myFile;
    if (sd.begin(CS_PIN_FOR_SD)){
      myFile = sd.open(logFile, FILE_WRITE);
      myFile.seekEnd();
      myFile.println(millis()/1000.0 
      + gskDisp.textForDisplay[20] + gskDisp.textForDisplay[7]
      + gskDisp.textForDisplay[20]
      + gskDisp.textForDisplay[20]
      + gskDisp.textForDisplay[20]
      );
      myFile.close();
    }
#endif
    resetTheSystem();
  }
}