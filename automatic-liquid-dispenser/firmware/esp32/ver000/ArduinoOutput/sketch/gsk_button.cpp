#line 1 "c:\\Suresh\\git\\Projects\\automatic-liquid-dispenser\\firmware\\esp32\\ver000\\uc\\gsk_button.cpp"
#include "gsk_button.h"

GSK_BUTTON::GSK_BUTTON() {
  for (int i=0; i<4; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], HIGH);
  }
  pinMode(actPIN, INPUT_PULLUP);
}

int GSK_BUTTON::read() {
  if (lastBtn<0 || lastBtn >= MAXIMUM_NUMBER_OF_PRODUCTS) {
    for (int i=0; i<MAXIMUM_NUMBER_OF_PRODUCTS; i++) {
      for (int j=0; j<4; j++) {
        digitalWrite(pins[j], i&(1<<j) ? HIGH : LOW);
      }
      delay(1);
      if (!digitalRead(actPIN)) {
        lastBtn = i;
        return -1;
      }
    }
    return -1;
  } else {

    for (int j=0; j<4; j++) {
      digitalWrite(pins[j], lastBtn&(1<<j) ? HIGH : LOW);
    }
    if (digitalRead(actPIN)) {
      delay(5);
      int tempLastButton = lastBtn;
      lastBtn = -1;
      #ifdef SERIAL_DEBUG_ENABLED
      Serial.print("Button pressed: ");
      Serial.println(tempLastButton);
      #endif
      return tempLastButton;
    }
  }
  return -1;
}