#include "main_activity.h"
void MAIN_ACTIVITY::stateProgQty2() {
  gskRelays.on(selectedChemical);
  double tempTimeSince = timeSinceStateChange();
  gskDisp.enable();
  gskDisp.displayProgQty1(selectedChemical+1, tempTimeSince, false);
  int pressedBtn = gskButtons.getPressed();
  if (pressedBtn>=0 && pressedBtn< NUMBER_OF_CHEMICALS) {
    gskRelays.stopAll();
    #ifdef ENABLE_SERIAL
    Serial.println(timeSinceStateChange());
    #endif
    gskChemicals[selectedChemical].timePerLiter = timeSinceStateChange();
    gskEEPROM.putAllChems(gskChemicals);
    gskEEPROM.getAllChems(gskChemicals);
#ifdef PROGRAM_SD
    SdFat sd;
    File myFile;
    if (sd.begin(CS_PIN_FOR_SD)){
      myFile = sd.open(logFile, FILE_WRITE);
      myFile.seekEnd();
      myFile.println(millis()/1000.0 
      + gskDisp.textForDisplay[20] + gskDisp.textForDisplay[6]
      + gskDisp.textForDisplay[20] + (selectedChemical+1)
      + gskDisp.textForDisplay[20]
      + gskDisp.textForDisplay[20] + (gskChemicals[selectedChemical].timePerLiter)
      );
      myFile.close();
    }
#endif
    changeState(PROG_QTY_0);
  }




  if (gskButtons.isProgBtnPressed()) {
    gskRelays.stopAll();
    changeState(IDLE);
  }


}
