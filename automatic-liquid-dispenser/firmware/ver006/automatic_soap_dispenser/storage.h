#ifndef STORAGE_H
#define STORAGE_H

#include <EEPROM.h>
#include "chemical.h"
#include "global_variables.h"

struct STORAGE {
  void putAllChems(CHEMICAL (&)[NUMBER_OF_CHEMICALS]);
  void getAllChems(CHEMICAL (&)[NUMBER_OF_CHEMICALS]);
  void addToToal(unsigned int);
  unsigned long getTotal();
  void resetTotal();
};

#endif
