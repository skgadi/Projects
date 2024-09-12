#include "main_activity.h"
void MAIN_ACTIVITY::stateProg() {
  gskDisp.displayProg(gskSummaryData.total);

  int pressedBtn = gskButtons.getPressed();
  if (pressedBtn == 0) {
    selectedChemical = 0;
    changeState(PROG_MONEY);
  }
  if (pressedBtn == 1) {
    selectedChemical = 0;
    changeState(PROG_QTY_0);
  }

  #if defined (PROGRAM_SUMMARY) || defined (PROGRAM_SD)
  if (pressedBtn == 3) {
    selectedChemical = 0;
    changeState(VIEW_SALES);
  }
  #endif
  #ifdef PROGRAM_SD
  if (pressedBtn == 4) {
    selectedChemical = 0;
    testSD = true;
    changeState(TEST_SD);
  }
  #endif
  



  if (gskButtons.isProgBtnPressed() || pressedBtn == 2) {
    changeState(IDLE);
  }

}
