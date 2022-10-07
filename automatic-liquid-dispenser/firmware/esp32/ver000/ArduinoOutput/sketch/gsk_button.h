#line 1 "c:\\Suresh\\git\\Projects\\automatic-liquid-dispenser\\firmware\\esp32\\ver000\\uc\\gsk_button.h"
#ifndef GSK_BUTTON_H
#define GSK_BUTTON_H

#include "gsk_global.h"

class GSK_BUTTON {
private:
  int pins[4] = {PIN_SEL_BTN_0, PIN_SEL_BTN_1, PIN_SEL_BTN_2, PIN_SEL_BTN_3};
  int actPIN = PIN_BTN_uC;
  int lastBtn = -1;
public:
  GSK_BUTTON();
  int read();
};

#endif