#ifndef GSK_PWM_H
#define GSK_PWM_H

#include "gsk_global.h"

class GSK_PWM {
    float dutyCycle;

   public:
    GSK_PWM();
    void setDutyCycle(int);
};

#endif  // GSK_PWM_H