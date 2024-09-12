#include <Arduino.h>
#include "pins.h"

GSK_PINS* pins;






void setup() {
  Serial.begin(115200);
  pins = new GSK_PINS();
  /*pinMode(PIN_DIRECTION_1, OUTPUT);
  pinMode(PIN_DIRECTION_2, OUTPUT);
  pinMode(PIN_DIRECTION_3, OUTPUT);
  pinMode(PIN_ENABLE_1, OUTPUT);
  pinMode(PIN_ENABLE_2, OUTPUT);
  pinMode(PIN_ENABLE_3, OUTPUT);*/
}

bool isHigh = false;
void loop() {
  isHigh = !isHigh;
  pins->setMotorDirection(0, isHigh);
  pins->setMotorEnable(0, true);
  for (int i=0; i<255; i++) {
    pins->setMotorSpeed(0, i);
    delay(50);
  }
  for (int i=255; i>0; i--) {
    pins->setMotorSpeed(0, i);
    delay(50);
  }
  pins->setMotorEnable(0, false);
  delay(1000);
}
