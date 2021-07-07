#include "storage.h"
#include "global_variables.h"

void STORAGE::putAllChems(CHEMICAL (&data)[NUMBER_OF_CHEMICALS]){
  EEPROM.put(20, data);
}

void STORAGE::getAllChems(CHEMICAL (&data)[NUMBER_OF_CHEMICALS]) {
  EEPROM.get(20, data);
}

void STORAGE::putTheSummary(SUMMARY_DATA &summary) {
  EEPROM.put(0, summary);  
}
void STORAGE::getTheSummary(SUMMARY_DATA &summary) {
  EEPROM.get(0, summary);  
}

void STORAGE::addToTotal(double b){
  double a = 0.0;
  EEPROM.get(0, a);
  a += b;
  if (a >= (MAX_SALES_AMOUNT*1.0)) {
    a -= (MAX_TOTAL_SALES_FACTOR * MAX_SALES_AMOUNT*1.0);
  }
  EEPROM.put(0, a);
}

double STORAGE::getTotal(){
  double a = 0.0;
  EEPROM.get(0, a);
  return a;
}

void STORAGE::resetTotal(){
  double a = 0.0;
  EEPROM.put(0, a);
}

void STORAGE::addToSubTotal(double b){
  double a = 0.0;
  EEPROM.get(10, a);
  a += b;
  if (a >= (MAX_SALES_AMOUNT*1.0)) {
    a -= (MAX_TOTAL_SALES_FACTOR * MAX_SALES_AMOUNT*1.0);
  }
  EEPROM.put(10, a);
}

double STORAGE::getSubTotal(){
  double a = 0.0;
  EEPROM.get(10, a);
  return a;
}

void STORAGE::resetSubTotal(){
  double a = 0.0;
  EEPROM.put(10, a);
}