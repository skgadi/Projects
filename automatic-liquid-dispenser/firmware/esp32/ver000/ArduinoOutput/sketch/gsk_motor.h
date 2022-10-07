#line 1 "c:\\Suresh\\git\\Projects\\automatic-liquid-dispenser\\firmware\\esp32\\ver000\\uc\\gsk_motor.h"
#ifndef GSK_MOTOR_H
#define GSK_MOTOR_H

#include "gsk_global.h"

class GSK_MOTOR {
private:
  int pins[4] = {PIN_SEL_MTR_0, PIN_SEL_MTR_1, PIN_SEL_MTR_2, PIN_SEL_MTR_3};
  int ctrlPIN = PIN_CTL_uC;
public:
  GSK_MOTOR ();
  void start (int motorNum);
};

#endif