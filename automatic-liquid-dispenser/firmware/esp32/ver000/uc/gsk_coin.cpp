#include "gsk_coin.h"

GSK_COIN::GSK_COIN() {
  setup();
}

void GSK_COIN::setup() {
  pinMode(pins[0],INPUT);
  attachInterruptArg (pins[0], isrForCoin, (void*) this, FALLING);
}

void GSK_COIN::incCount() {
  count++;
}

void isrForCoin(void *coidHandle) {
  GSK_COIN* gsk_coin = (GSK_COIN*)(coidHandle);
  gsk_coin->incCount();
}

void GSK_COIN::clear() {
  count = 0;
}

int GSK_COIN::read() {
  return count;
}

int GSK_COIN::readAndClear() {
  int temp = count;
  clear();
  return temp;
}
