#include "coins.h"

void COINS::increaseCredit() {
  credit++;
  creditChange = true;
}

void COINS::resetCredit() {
  credit=0;
  creditChange = true;
}

void COINS::ackChange() {
  creditChange = false;
}
