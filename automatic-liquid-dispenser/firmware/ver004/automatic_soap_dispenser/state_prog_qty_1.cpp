#include "main_activity.h"
void MAIN_ACTIVITY::stateProgQty1() {
  if (selectedChemical<0) {
    selectedChemical=0;
  }
  gskDisp.displayProgQty1(selectedChemical+1, gskChemicals[selectedChemical].timePerLiter, true);

  if (gskButtons.isProgBtnPressed()) {
    changeState(IDLE);
  }

  int pressedBtn = gskButtons.getPressed();
  if (pressedBtn>=0 && pressedBtn< NUMBER_OF_CHEMICALS) {
    changeState(PROG_QTY_2);
  }

}
