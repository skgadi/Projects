#include "main_activity.h"
void MAIN_ACTIVITY::stateViewSales() {
  if (selectedChemical<-1) {
    selectedChemical=-1;
  }
  if (selectedChemical< 0) {
    gskDisp.displayViewSales(0, gskSummaryData.subTotal, 0, true);
  } else {
    gskDisp.displayViewSales(selectedChemical+1, 0, gskChemicals[selectedChemical].cons, false);
  }

  int pressedBtn = gskButtons.getPressed();
  if (pressedBtn>=0 && pressedBtn< 4) {
    gskDisp.enable();
  }
  if (pressedBtn == 2) {
    selectedChemical = 0;
    changeState(PROG);
  }
  if ((selectedChemical<0) && (pressedBtn == 3)) {
    gskSummaryData.subTotal=0.0;
    gskEEPROM.putTheSummary(gskSummaryData);
    gskEEPROM.getTheSummary(gskSummaryData);
  }
  if (pressedBtn == 0) {
    selectedChemical--;
    if (selectedChemical < -1) {
      selectedChemical = NUMBER_OF_CHEMICALS - 1;
    }
  }
  if (pressedBtn == 1) {
    selectedChemical++;
    if (selectedChemical >= NUMBER_OF_CHEMICALS) {
      selectedChemical = -1;
    }
  }

  if (gskButtons.isProgBtnPressed()) {
    changeState(IDLE);
  }
  

}
