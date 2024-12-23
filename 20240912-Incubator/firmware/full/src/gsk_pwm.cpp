#include "gsk_pwm.h"

GSK_PWM::GSK_PWM() { setDutyCycle(0); }

void GSK_PWM::setDutyCycle(int dc) {
    dutyCycle = dc;
    analogWrite(GSK_PIN_PWM, dc);
}