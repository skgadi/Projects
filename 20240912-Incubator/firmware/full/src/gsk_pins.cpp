#include "gsk_pins.h"

GSK_PINS::GSK_PINS() {
    // Set pin modes
    pinMode(GSK_PIN_PWM, OUTPUT);

    pinMode(GSK_PIN_ENCODER_CLK, INPUT);
    pinMode(GSK_PIN_ENCODER_DT, INPUT);
    pinMode(GSK_PIN_ENCODER_SW, INPUT);

    pinMode(GSK_PIN_I2C_SDA, INPUT);
    pinMode(GSK_PIN_I2C_SCL, INPUT);

    pinMode(GSK_PIN_TEMP_SENSOR, INPUT);
}