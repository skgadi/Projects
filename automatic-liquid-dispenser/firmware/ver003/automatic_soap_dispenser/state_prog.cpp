#include "main_activity.h"
void MAIN_ACTIVITY::stateProg() {
  gskDisp.displayProg();

  int pressedBtn = gskButtons.getPressed();
  if (pressedBtn == 0) {
    selectedChemical = 0;
    changeState(PROG_MONEY);
  }
  if (pressedBtn == 1) {
    selectedChemical = 0;
    changeState(PROG_QTY_0);
  }



  if (gskButtons.isProgBtnPressed() || pressedBtn == 2) {
    changeState(IDLE);
  }

}
