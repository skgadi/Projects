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
      SdFat sd;
      File myFile;
      if (sd.begin(CS_PIN_FOR_SD)){
        myFile = sd.open(logFile, FILE_WRITE);
        myFile.seekEnd();
        myFile.println(millis()/1000.0 
          + gskDisp.textForDisplay[20] + gskDisp.textForDisplay[4]
          + gskDisp.textForDisplay[20] + (selectedChemical+1)
          + gskDisp.textForDisplay[20] + gskChemicals[selectedChemical].costPerLiter
          + gskDisp.textForDisplay[20]
        );
        myFile.close();
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
      SdFat sd;
      File myFile;
      if (sd.begin(CS_PIN_FOR_SD)){
        myFile = sd.open(logFile, FILE_WRITE);
        myFile.seekEnd();
        myFile.println(millis()/1000.0 
          + gskDisp.textForDisplay[20] + gskDisp.textForDisplay[4]
          + gskDisp.textForDisplay[20] + (selectedChemical+1)
          + gskDisp.textForDisplay[20] + gskChemicals[selectedChemical].costPerLiter
          + gskDisp.textForDisplay[20]
        );
        myFile.close();
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
      SdFat sd;
      File myFile;
      if (sd.begin(CS_PIN_FOR_SD)){
        myFile = sd.open(logFile, FILE_WRITE);
        myFile.seekEnd();
        myFile.println(millis()/1000.0 
          + gskDisp.textForDisplay[20] + gskDisp.textForDisplay[4]
          + gskDisp.textForDisplay[20] + (selectedChemical+1)
          + gskDisp.textForDisplay[20] + gskChemicals[selectedChemical].costPerLiter
          + gskDisp.textForDisplay[20]
        );
        myFile.close();
      }
#endif
    }
    changeState(IDLE);
  }
  
  if (pressedBtn == 4) {
    if (configChangeNoted) {
      configChangeNoted = false;
#ifdef PROGRAM_SD
      SdFat sd;
      File myFile;
      if (sd.begin(CS_PIN_FOR_SD)){
        myFile = sd.open(logFile, FILE_WRITE);
        myFile.seekEnd();
        myFile.println(millis()/1000.0 
          + gskDisp.textForDisplay[20] + gskDisp.textForDisplay[4]
          + gskDisp.textForDisplay[20] + (selectedChemical+1)
          + gskDisp.textForDisplay[20] + gskChemicals[selectedChemical].costPerLiter
          + gskDisp.textForDisplay[20]
        );
        myFile.close();
      }
#endif
    }
    selectedChemical = 0;
    changeState(PROG);
  }

}
