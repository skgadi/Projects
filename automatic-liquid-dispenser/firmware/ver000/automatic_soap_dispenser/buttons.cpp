#include "main_activity.h"


int BUTTONS::getPressed() {
  for (int i=0; i<NUMBER_OF_CHEMICALS; i++) {
    if (digitalRead(btnPins[i]) == 0) {
      delay(WAIT_x_MILLI_SECONDS_AFTER_BTN_PRESS);
      pressed = true;
      lastActivatedButton = i;
      return -1;
    }
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
  for (int i=0; i<NUMBER_OF_CHEMICALS; i++) {
    pinMode(btnPins[i], INPUT_PULLUP);
  }
  pinMode(progBtnPin, INPUT_PULLUP);
}
