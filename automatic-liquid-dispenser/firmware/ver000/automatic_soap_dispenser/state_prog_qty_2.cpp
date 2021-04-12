#include "main_activity.h"
void MAIN_ACTIVITY::stateProgQty2() {
  gskRelays.on(selectedChemical);
  unsigned int tempTimeSince = timeSinceStateChange()/100;
  gskDisp.displayProgQty1(selectedChemical+1, tempTimeSince, false);
  int pressedBtn = gskButtons.getPressed();
  if (pressedBtn>=0 && pressedBtn< NUMBER_OF_CHEMICALS) {
    gskRelays.stopAll();
    #ifdef ENABLE_SERIAL
    Serial.println(timeSinceStateChange());
    #endif
    gskChemicals[selectedChemical].timePerLiter = (timeSinceStateChange()/100);
    gskEEPROM.putAll(gskChemicals);
    gskEEPROM.getAll(gskChemicals);
    changeState(PROG_QTY_0);
  }




  if (gskButtons.isProgBtnPressed()) {
    gskRelays.stopAll();
    changeState(IDLE);
  }


}
