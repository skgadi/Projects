#line 1 "c:\\Suresh\\git\\Projects\\automatic-liquid-dispenser\\firmware\\esp32\\ver000\\uc\\gsk_coin.h"
#ifndef GSK_COIN_H
#define GSK_COIN_H


#include "gsk_global.h"
#include "driver/pcnt.h"

void isrForCoin(void *arg);

class GSK_COIN {
private:
  int count;
  int pins[1] = {PIN_COIN};
public:
  GSK_COIN();
  void setup();
  int read();
  void clear();
  int readAndClear();
  void incCount();
};



#endif