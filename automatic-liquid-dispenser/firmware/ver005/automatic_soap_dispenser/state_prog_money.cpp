#include "main_activity.h"
void MAIN_ACTIVITY::stateProgMoney() {
  if (selectedChemical<0) {
    selectedChemical=0;
  }
  gskDisp.displayProgPrice(selectedChemical+1, gskChemicals[selectedChemical].costPerLiter);

  int pressedBtn = gskButtons.getPressed();
  if (pressedBtn>=0 && pressedBtn< 4) {
    gskDisp.enable();
  }
  if (pressedBtn == 0) {
    if (configChangeNoted) {
      configChangeNoted = false;
#ifdef PROGRAM_SD
      if (SD.begin(CS_PIN_FOR_SD)) {
        File dataFile = SD.open(logFile, FILE_WRITE);
        if (dataFile) {
          dataFile.print(millis()/1000.0);
          dataFile.print(char(44));
          dataFile.print(gskDisp.textForDisplay[4]);
          dataFile.print(char(44));
          dataFile.print(selectedChemical+1);
          dataFile.print(char(44));
          dataFile.println(gskChemicals[selectedChemical].costPerLiter);
          dataFile.close();
        }
      }
#endif
    }
    selectedChemical--;
    if (selectedChemical < 0) {
      selectedChemical = NUMBER_OF_CHEMICALS - 1;
    }
  }
  if (pressedBtn == 1) {
    if (configChangeNoted) {
      configChangeNoted = false;
#ifdef PROGRAM_SD
      if (SD.begin(CS_PIN_FOR_SD)) {
        File dataFile = SD.open(logFile, FILE_WRITE);
        if (dataFile) {
          dataFile.print(millis()/1000.0);
          dataFile.print(char(44));
          dataFile.print(gskDisp.textForDisplay[4]);
          dataFile.print(char(44));
          dataFile.print(selectedChemical+1);
          dataFile.print(char(44));
          dataFile.println(gskChemicals[selectedChemical].costPerLiter);
          dataFile.close();
        }
      }
#endif
    }
    selectedChemical++;
    if (selectedChemical >= NUMBER_OF_CHEMICALS) {
      selectedChemical = 0;
    }
  }
  if (pressedBtn == 2) {
    configChangeNoted = true;
    gskChemicals[selectedChemical].costPerLiter--;
    if (gskChemicals[selectedChemical].costPerLiter<1) {
      gskChemicals[selectedChemical].costPerLiter = MAX_MONEY_PER_LITER;
    }
    gskEEPROM.putAllChems(gskChemicals);
    gskEEPROM.getAllChems(gskChemicals);
  }
  if (pressedBtn == 3) {
    configChangeNoted = true;
    gskChemicals[selectedChemical].costPerLiter++;
    if (gskChemicals[selectedChemical].costPerLiter > MAX_MONEY_PER_LITER) {
      gskChemicals[selectedChemical].costPerLiter = 1;
    }
    gskEEPROM.putAllChems(gskChemicals);
    gskEEPROM.getAllChems(gskChemicals);
  }


  if (gskButtons.isProgBtnPressed()) {
    if (configChangeNoted) {
      configChangeNoted = false;
#ifdef PROGRAM_SD
      if (SD.begin(CS_PIN_FOR_SD)) {
        File dataFile = SD.open(logFile, FILE_WRITE);
        if (dataFile) {
          dataFile.print(millis()/1000.0);
          dataFile.print(char(44));
          dataFile.print(gskDisp.textForDisplay[4]);
          dataFile.print(char(44));
          dataFile.print(selectedChemical+1);
          dataFile.print(char(44));
          dataFile.println(gskChemicals[selectedChemical].costPerLiter);
          dataFile.close();
        }
      }
#endif
    }
    changeState(IDLE);
  }
  
  if (pressedBtn == 4) {
    if (configChangeNoted) {
      configChangeNoted = false;
#ifdef PROGRAM_SD
      if (SD.begin(CS_PIN_FOR_SD)) {
        File dataFile = SD.open(logFile, FILE_WRITE);
        if (dataFile) {
          dataFile.print(millis()/1000.0);
          dataFile.print(char(44));
          dataFile.print(gskDisp.textForDisplay[4]);
          dataFile.print(char(44));
          dataFile.print(selectedChemical+1);
          dataFile.print(char(44));
          dataFile.println(gskChemicals[selectedChemical].costPerLiter);
          dataFile.close();
        }
      }
#endif
    }
    selectedChemical = 0;
    changeState(PROG);
  }

}
