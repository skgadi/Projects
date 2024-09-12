#ifndef COINS_H
#define COINS_H

#include "global_variables.h"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

struct COINS {
  double volatile credit;
  bool creditChange;
  void increaseCredit();
  void resetCredit();
  void ackChange();
  void checkCoinPulse();
  unsigned long prevTime=0;
  bool foundLow = false;
};




#endif
