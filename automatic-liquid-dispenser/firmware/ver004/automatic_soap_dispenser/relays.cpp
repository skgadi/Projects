#include "main_activity.h"

void RELAYS::on(int rlyNumber) {
  setRelayPins(rlyNumber);
  digitalWrite(rlyPins[NUMBER_OF_IN_OUT_PINS], 1);
  #ifdef ENABLE_SERIAL
  Serial.print("Relay ");
  Serial.print(rlyNumber);
  Serial.println(" is on");
  #endif
}

void RELAYS::configure(){
  rlyPins[0] = 10;
  rlyPins[1] = 9;
  rlyPins[2] = 8;
  rlyPins[3] = 7;
  rlyPins[4] = 6;
  rlyPins[NUMBER_OF_IN_OUT_PINS] = 5;
  for (int  i = 0; i < (NUMBER_OF_IN_OUT_PINS+1) ; i++) {
    pinMode(rlyPins[i], OUTPUT);
  }
  stopAll();
}


void RELAYS::stopAll() {
  digitalWrite(rlyPins[NUMBER_OF_IN_OUT_PINS], 0);
  #ifdef ENABLE_SERIAL
  Serial.println("All relays off");
  #endif
}


void RELAYS::setRelayPins(int rlyNumber) {
  for (int i=0; i<NUMBER_OF_IN_OUT_PINS; i++) {
    digitalWrite(rlyPins[i], !!(rlyNumber & (1<<i)));
  }
}