#ifndef STORAGE_H
#define STORAGE_H

#include <EEPROM.h>
#include "chemical.h"
#include "global_variables.h"

struct STORAGE {
  void putAll(CHEMICAL (&)[NUMBER_OF_CHEMICALS]);
  void getAll(CHEMICAL (&)[NUMBER_OF_CHEMICALS]);
};

#endif
