#include "main_activity.h"
void MAIN_ACTIVITY::stateTestSD() {
  if (selectedChemical<0) {
    selectedChemical=0;
  }

  #ifdef PROGRAM_SD
  if (testSD) {
    gskDisp.lcd.clear();
    gskDisp.lcd.setCursor(0,0);
    gskDisp.lcd.print(gskDisp.textForDisplay[18] + gskDisp.textForDisplay[11] + gskDisp.textForDisplay[17] + gskDisp.textForDisplay[11] + gskDisp.textForDisplay[19]);
    gskDisp.lcd.setCursor(0,1);
    gskDisp.lcd.print(1 + gskDisp.textForDisplay[11] + gskDisp.textForDisplay[19]);
    gskDisp.lcd.setCursor(12,1);
    gskDisp.lcd.print(2 + gskDisp.textForDisplay[11] + gskDisp.textForDisplay[7]);
    gskDisp.lcd.setCursor(17,3);
    gskDisp.lcd.print(char(4));
    gskDisp.lcd.print(char(5));
    gskDisp.lcd.print(char(6));


    testSD = false;
    SdFat sd;
    File myFile;
    bool fileWritten = false;
    if (sd.begin(CS_PIN_FOR_SD)){
      myFile = sd.open(logFile, FILE_WRITE);
      myFile.seekEnd();
      myFile.println(millis()/1000.0 
      + gskDisp.textForDisplay[20] + gskDisp.textForDisplay[19] + gskDisp.textForDisplay[11] + gskDisp.textForDisplay[17]
      + gskDisp.textForDisplay[20]
      + gskDisp.textForDisplay[20]
      + gskDisp.textForDisplay[20]
      );
      if (myFile.close()) {
        gskDisp.lcd.setCursor(1,0);
        gskDisp.lcd.print(char(3));
      } else {
        gskDisp.lcd.setCursor(1,0);
        gskDisp.lcd.print(char(2));
      }
    } else {
      gskDisp.lcd.setCursor(1,0);
      gskDisp.lcd.print(char(2));
    }
    //gskDisp.displayTestSD(isSDPresent, fileWritten);
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
