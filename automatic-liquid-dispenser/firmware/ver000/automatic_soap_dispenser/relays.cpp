#include "main_activity.h"

void RELAYS::on(int rlyNumber) {
  digitalWrite(btnPins[rlyNumber], 0);
  #ifdef ENABLE_SERIAL
  Serial.print("Relay ");
  Serial.print(rlyNumber);
  Serial.println(" is on");
  #endif
}

void RELAYS::configure(){
  for (int  i = 0; i < NUMBER_OF_CHEMICALS; i++) {
    pinMode(btnPins[i], OUTPUT);
  }
}


void RELAYS::stopAll() {
  for (int  i = 0; i < NUMBER_OF_CHEMICALS; i++) {
    digitalWrite(btnPins[i], 1);
  }
  #ifdef ENABLE_SERIAL
  Serial.println("All relays off");
  #endif
}