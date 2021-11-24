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

void COINS::checkCoinPulse() {
  bool nowHigh = digitalRead(COINS_PIN);
  if (foundLow) {
    if (nowHigh) {
      if ((millis() - prevTime)*1.0 > (WAIT_x_MILLI_SECONDS_AFTER_BTN_PRESS*1.0)) {
        foundLow = false;
        increaseCredit();
      }
    }
  } else {
    foundLow = !nowHigh;
  }
}