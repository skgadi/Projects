#include "main_activity.h"
void MAIN_ACTIVITY::stateProg() {
  gskDisp.displayProg(gskEEPROM.getTotal());

  int pressedBtn = gskButtons.getPressed();
  if (pressedBtn == 0) {
    selectedChemical = 0;
    changeState(PROG_MONEY);
  }
  if (pressedBtn == 1) {
    selectedChemical = 0;
    changeState(PROG_QTY_0);
  }
  if (PROGRAM_SUMMARY || PROGRAM_SD) {
    if (pressedBtn == 3) {
      selectedChemical = 0;
      changeState(VIEW_SALES);
    }
  }
  if (PROGRAM_SD) {
    if (pressedBtn == 4) {
      selectedChemical = 0;
      changeState(TEST_SD);
    }
  }



  if (gskButtons.isProgBtnPressed() || pressedBtn == 2) {
    changeState(IDLE);
  }

}
