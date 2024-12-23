#ifndef GSK_PINS_H
#define GSK_PINS_H

#include "gsk_global.h"

// Pin definitions
#define GSK_PIN_PWM 16

#define GSK_PIN_ENCODER_CLK 19
#define GSK_PIN_ENCODER_DT 18
#define GSK_PIN_ENCODER_SW 4

#define GSK_PIN_I2C_SDA 21
#define GSK_PIN_I2C_SCL 22

#define GSK_PIN_TEMP_SENSOR 2

class GSK_PINS {
   public:
    GSK_PINS();
};

#endif  // GSK_PINS_H