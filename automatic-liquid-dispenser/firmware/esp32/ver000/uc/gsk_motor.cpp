#include "gsk_motor.h"

GSK_MOTOR::GSK_MOTOR() {
  for (int i=0; i<4; i++) {
    pinMode(pins[i], OUTPUT);
  }
  pinMode(ctrlPIN, OUTPUT);
  start(-1);
}

void GSK_MOTOR::start (int motorNum) {
  if (motorNum>=0 && motorNum<16) {
    for (int i=0; i<4; i++) {
      digitalWrite(pins[i], ((motorNum>>i) & 0x01) == 0x01);
    }
    digitalWrite(ctrlPIN, LOW);
  } else {
    digitalWrite(ctrlPIN, HIGH);
  }
}