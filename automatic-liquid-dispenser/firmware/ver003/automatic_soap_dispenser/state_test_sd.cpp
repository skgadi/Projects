#include "main_activity.h"
void MAIN_ACTIVITY::stateTestSD() {
  if (selectedChemical<0) {
    selectedChemical=0;
  }
  gskDisp.displayTestSD(true, true, false);

  int pressedBtn = gskButtons.getPressed();
  if (pressedBtn>=0 && pressedBtn< 4) {
    gskDisp.enable();
  }
  if (pressedBtn == 4) {
    selectedChemical = 0;
    changeState(PROG);
  }
  if (pressedBtn == 0) {
    selectedChemical--;
    if (selectedChemical < 0) {
      selectedChemical = NUMBER_OF_CHEMICALS - 1;
    }
  }
  if (pressedBtn == 1) {
    selectedChemical++;
    if (selectedChemical >= NUMBER_OF_CHEMICALS) {
      selectedChemical = 0;
    }
  }

  if (gskButtons.isProgBtnPressed()) {
    changeState(IDLE);
  }
  

}
