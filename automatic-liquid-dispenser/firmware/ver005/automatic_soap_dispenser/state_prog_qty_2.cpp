#include "main_activity.h"
void MAIN_ACTIVITY::stateProgQty2() {
  gskRelays.on(selectedChemical);
  unsigned int tempTimeSince = timeSinceStateChange()/100;
  gskDisp.enable();
  gskDisp.displayProgQty1(selectedChemical+1, tempTimeSince, false);
  int pressedBtn = gskButtons.getPressed();
  if (pressedBtn>=0 && pressedBtn< NUMBER_OF_CHEMICALS) {
    gskRelays.stopAll();
    #ifdef ENABLE_SERIAL
    Serial.println(timeSinceStateChange());
    #endif
    gskChemicals[selectedChemical].timePerLiter = (timeSinceStateChange()/100);
    gskEEPROM.putAllChems(gskChemicals);
    gskEEPROM.getAllChems(gskChemicals);
#ifdef PROGRAM_SD
    if (SD.begin(CS_PIN_FOR_SD)) {
      File dataFile = SD.open(logFile, FILE_WRITE);
      if (dataFile) {
        dataFile.print(millis()/1000.0);
        dataFile.print(char(44));
        dataFile.print(gskDisp.textForDisplay[6]);
        dataFile.print(char(44));
        dataFile.print(selectedChemical+1);
        dataFile.print(char(44));
        dataFile.print(char(44));
        dataFile.println(gskChemicals[selectedChemical].timePerLiter/10.0);
        dataFile.close();
      }
    }
#endif
    changeState(PROG_QTY_0);
  }




  if (gskButtons.isProgBtnPressed()) {
    gskRelays.stopAll();
    changeState(IDLE);
  }


}
