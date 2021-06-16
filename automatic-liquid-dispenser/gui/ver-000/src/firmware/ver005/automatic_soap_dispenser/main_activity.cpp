#include "main_activity.h"




void MAIN_ACTIVITY::setup(){

  gskButtons.configure();
  gskRelays.configure();





  gskEEPROM.getAllChems(gskChemicals);
  correctEEPROMData();
  gskDisp.init();
  pinMode(COINS_PIN, INPUT_PULLUP);
  #ifdef ENABLE_SERIAL
  Serial.begin(115200);
  #endif

#ifdef PROGRAM_SD
  if (SD.begin(CS_PIN_FOR_SD)) {
    File dataFile = SD.open(logFile, FILE_WRITE);
    if (dataFile) {
      dataFile.print(millis()/1000.0);
      dataFile.print(char(44));
      dataFile.println(gskDisp.textForDisplay[2]);
      dataFile.close();
    }
  }
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
  case VIEW_SALES:
    stateViewSales();
    break;
  case TEST_SD:
    stateTestSD();
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
  bool changed = false;
  if (gskEEPROM.getTotal()> (MAX_TOTAL_SALES_FACTOR * MAX_SALES_AMOUNT)) {
    gskEEPROM.resetTotal();
  }
  for (int i = 0; i < NUMBER_OF_CHEMICALS; i++) {
    if (gskChemicals[i].costPerLiter<1 || gskChemicals[i].costPerLiter>MAX_MONEY_PER_LITER) {
      gskChemicals[i].costPerLiter = MAX_MONEY_PER_LITER;
      changed = true;
    }
    if (gskChemicals[i].timePerLiter < MIN_CENTI_SEC_PER_LITER || gskChemicals[i].timePerLiter > MAX_CENTI_SEC_PER_LITER) {
      gskChemicals[i].timePerLiter = MIN_CENTI_SEC_PER_LITER;
      changed = true;
    }
    if (gskChemicals[i].sales > MAX_SALES_AMOUNT) {
      gskChemicals[i].sales = 0;
      changed = true;
    }
    if (gskChemicals[i].cons > (MAX_LITERS_COUNTER*100)) {
      gskChemicals[i].cons = 0;
      changed = true;
    }
  }
  if (changed) {
    gskEEPROM.putAllChems(gskChemicals);
    gskEEPROM.getAllChems(gskChemicals);
  }
}


void MAIN_ACTIVITY::updateEEPROMAtDispense(unsigned long amount, double dispensed) {
    gskEEPROM.addToToal(amount);
    gskChemicals[selectedChemical].cons += lround(dispensed*100);
    if (gskChemicals[selectedChemical].cons >= (MAX_LITERS_COUNTER*100)) {
      gskChemicals[selectedChemical].cons -= (MAX_LITERS_COUNTER*100);
    }
    gskChemicals[selectedChemical].sales += amount;
    if (gskChemicals[selectedChemical].sales >= (MAX_SALES_AMOUNT)) {
      gskChemicals[selectedChemical].sales -= (MAX_SALES_AMOUNT);
    }
    gskEEPROM.putAllChems(gskChemicals);
    gskEEPROM.getAllChems(gskChemicals);
}

bool MAIN_ACTIVITY::writeToSD(String text) {
#ifdef PROGRAM_SD
  File dataFile = SD.open(logFile, FILE_WRITE);
  if (dataFile) {
    dataFile.print(millis()/1000.0);
    dataFile.print(char(44));
    dataFile.println(text);
    dataFile.close();
    return true;
  } else {
    return false;
  }
#else
  return false;
#endif
}

bool MAIN_ACTIVITY::initTheSD() {
#ifdef PROGRAM_SD
  return SD.begin(CS_PIN_FOR_SD);
#else
  return false;
#endif

}

bool MAIN_ACTIVITY::initAndWriteSD(String TextToWrite) {
#ifdef PROGRAM_SD
  if (SD.begin(CS_PIN_FOR_SD)) {
    File dataFile = SD.open(logFile, FILE_WRITE);
    if (dataFile) {
      dataFile.print(millis()/1000.0);
      dataFile.print(char(44));
      dataFile.println(TextToWrite);
      dataFile.close();
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
#else
  return false;
#endif
}
