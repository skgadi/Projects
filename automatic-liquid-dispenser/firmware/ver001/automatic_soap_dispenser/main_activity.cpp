#include "main_activity.h"




void MAIN_ACTIVITY::setup(){

  gskButtons.configure();
  gskRelays.configure();





  gskEEPROM.getAll(gskChemicals);
  correctEEPROMData();
  gskDisp.init();
  pinMode(COINS_PIN, INPUT_PULLUP);
  #ifdef ENABLE_SERIAL
  Serial.begin(115200);
  #endif
}


void MAIN_ACTIVITY::run () {
  switch (currentState) {
  case IDLE:
    stateIdle();
    break;
  case CREDIT:
    stateCredit();
    break;
  case PRICE:
    statePrice();
    break;
  case DISPENSE:
    stateDispense();
    break;
  case PROG:
    stateProg();
    break;
  case PROG_MONEY:
    stateProgMoney();
    break;
  case PROG_QTY_0:
    stateProgQty0();
    break;
  case PROG_QTY_1:
    stateProgQty1();
    break;
  case PROG_QTY_2:
    stateProgQty2();
    break;
  default:
    break;
  }


/*Temp code 
  delay(200);
  gskCoins.increaseCredit();
  gskDisp.enable();
  */
}


void MAIN_ACTIVITY::correctEEPROMData() {
  for (int i = 0; i < NUMBER_OF_CHEMICALS; i++) {
    if (gskChemicals[i].costPerLiter<1 || gskChemicals[i].costPerLiter>MAX_MONEY_PER_LITER) {
      gskChemicals[i].costPerLiter = MAX_MONEY_PER_LITER;
      gskEEPROM.putAll(gskChemicals);
      gskEEPROM.getAll(gskChemicals);
    }
    if (gskChemicals[i].timePerLiter < MIN_CENTI_SEC_PER_LITER || gskChemicals[i].timePerLiter > MAX_CENTI_SEC_PER_LITER) {
      gskChemicals[i].timePerLiter = MIN_CENTI_SEC_PER_LITER;
      gskEEPROM.putAll(gskChemicals);
      gskEEPROM.getAll(gskChemicals);
    }
  }
}
