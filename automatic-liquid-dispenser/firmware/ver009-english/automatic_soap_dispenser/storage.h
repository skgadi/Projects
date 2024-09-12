#ifndef STORAGE_H
#define STORAGE_H

#include <EEPROM.h>
#include "chemical.h"
#include "summary_data.h"
#include "global_variables.h"


struct STORAGE {
  void putAllChems(CHEMICAL (&)[NUMBER_OF_CHEMICALS]);
  void getAllChems(CHEMICAL (&)[NUMBER_OF_CHEMICALS]);
  void putTheSummary(SUMMARY_DATA & );
  void getTheSummary(SUMMARY_DATA & );
  void addToTotal(double);
  double getTotal();
  void resetTotal();
  void addToSubTotal(double);
  double getSubTotal();
  void resetSubTotal();
};

#endif
