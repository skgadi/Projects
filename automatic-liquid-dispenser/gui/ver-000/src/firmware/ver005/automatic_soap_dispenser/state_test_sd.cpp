#include "main_activity.h"
void MAIN_ACTIVITY::stateTestSD() {
  if (selectedChemical<0) {
    selectedChemical=0;
  }

  #ifdef PROGRAM_SD
  if (testSD) {
    testSD = false;
    bool isSDPresent = SD.begin(CS_PIN_FOR_SD);
    bool fileWritten = false;

    if (isSDPresent) {
      File dataFile = SD.open(logFile, FILE_WRITE);
      if (dataFile) {
        dataFile.print(millis()/1000.0);
        dataFile.print(char(44));
        dataFile.print(gskDisp.textForDisplay[19]);
        dataFile.print(char(32));
        dataFile.println(gskDisp.textForDisplay[17]);
        dataFile.close();
        fileWritten = true;
      }
    }
   gskDisp.displayTestSD(isSDPresent, fileWritten);
  }
  #endif


  int pressedBtn = gskButtons.getPressed();

  if (pressedBtn == 1) {
    selectedChemical = 0;
    changeState(PROG);
  }
  if (pressedBtn == 0) {
    testSD = true;
    gskDisp.enableDisplay = true;
  }

  if (gskButtons.isProgBtnPressed()) {
    changeState(IDLE);
  }
  

}
