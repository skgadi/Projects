#include "main_activity.h"
void MAIN_ACTIVITY::stateProgQty0() {
  if (selectedChemical<0) {
    selectedChemical=0;
  }
  gskDisp.displayProgQty(selectedChemical+1, gskChemicals[selectedChemical].timePerLiter);

  int pressedBtn = gskButtons.getPressed();
  if (pressedBtn>=0 && pressedBtn< 3) {
    gskDisp.enable();
  }
  if (pressedBtn == 3) {
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
  if (pressedBtn == 2) {
    changeState(PROG_QTY_1);
  }

  if (gskButtons.isProgBtnPressed()) {
    changeState(IDLE);
  }


}
