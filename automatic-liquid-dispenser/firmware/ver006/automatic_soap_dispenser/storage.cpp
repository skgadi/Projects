#include "storage.h"
#include "global_variables.h"

void STORAGE::putAllChems(CHEMICAL (&data)[NUMBER_OF_CHEMICALS]){
  EEPROM.put(10, data);
}

void STORAGE::getAllChems(CHEMICAL (&data)[NUMBER_OF_CHEMICALS]) {
  EEPROM.get(10, data);
}

void STORAGE::addToToal(unsigned int b){
  unsigned long a = 0;
  EEPROM.get(0, a);
  a += b;
  if (a >= (MAX_SALES_AMOUNT)) {
    a -= (MAX_TOTAL_SALES_FACTOR * MAX_SALES_AMOUNT);
  }
  EEPROM.put(0, a);
}

unsigned long STORAGE::getTotal(){
  unsigned long a = 0;
  EEPROM.get(0, a);
  return a;
}

void STORAGE::resetTotal(){
  unsigned long a = 0.0;
  EEPROM.put(0, a);
}