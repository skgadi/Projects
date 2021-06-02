#include "main_activity.h"


int BUTTONS::getPressed() {
  if (digitalRead(btnPins[NUMBER_OF_IN_OUT_PINS]) == 0) {
    lastActivatedButton = getButton();
    pressed = true;
    delay(WAIT_x_MILLI_SECONDS_AFTER_BTN_PRESS);
    return -1;
  }
  if (pressed) {
    pressed = false;
      #ifdef ENABLE_SERIAL
      Serial.print("Pressed button: ");
      Serial.println(lastActivatedButton);
      #endif
    return lastActivatedButton;
  }
  return -1;
}


bool BUTTONS::isProgBtnPressed() {
  if (digitalRead(progBtnPin) == 0) {
    delay(WAIT_x_MILLI_SECONDS_AFTER_BTN_PRESS);
    progPressed = true;
    return false;
  }
  if (progPressed) {
    progPressed = false;
    return true;
  }
  return false;
}

void BUTTONS::configure() {
  btnPins[0] = 9;
  btnPins[1] = 10;
  btnPins[2] = A0;
  btnPins[3] = A1;
  btnPins[4] = A2;
  btnPins[NUMBER_OF_IN_OUT_PINS] = A3;
  progBtnPin = 11;

  for (int i=0; i<(NUMBER_OF_IN_OUT_PINS + 1); i++) {
    pinMode(btnPins[i], INPUT_PULLUP);
  }
  pinMode(progBtnPin, INPUT_PULLUP);
}


int BUTTONS::getButton() {
  int out = 0;
  for (int i=0; i<NUMBER_OF_IN_OUT_PINS; i++) {
    int tempPinOut = 0 | (!digitalRead(btnPins[i]));
      tempPinOut <<= i;
      out |= tempPinOut;
  }
  return out;
}