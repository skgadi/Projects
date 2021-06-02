#include "main_activity.h"
void MAIN_ACTIVITY::stateProgMoney() {
  if (selectedChemical<0) {
    selectedChemical=0;
  }
  gskDisp.displayProgPrice(selectedChemical+1, gskChemicals[selectedChemical].costPerLiter);

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
  if (pressedBtn == 2) {
    gskChemicals[selectedChemical].costPerLiter--;
    if (gskChemicals[selectedChemical].costPerLiter<1) {
      gskChemicals[selectedChemical].costPerLiter = MAX_MONEY_PER_LITER;
    }
    gskEEPROM.putAll(gskChemicals);
    gskEEPROM.getAll(gskChemicals);
  }
  if (pressedBtn == 3) {
    gskChemicals[selectedChemical].costPerLiter++;
    if (gskChemicals[selectedChemical].costPerLiter > MAX_MONEY_PER_LITER) {
      gskChemicals[selectedChemical].costPerLiter = 1;
    }
    gskEEPROM.putAll(gskChemicals);
    gskEEPROM.getAll(gskChemicals);
  }


  if (gskButtons.isProgBtnPressed()) {
    changeState(IDLE);
  }
  

}
