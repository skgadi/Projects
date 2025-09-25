#ifndef GSK_PINS_HPP
#define GSK_PINS_HPP

#include <Arduino.h>

#define PIN_POS_SEN_1 36
#define PIN_POS_SEN_2 39
#define PIN_POS_SEN_3 34

#define PIN_DIR_1 25
#define PIN_DIR_2 26
#define PIN_DIR_3 27

#define PIN_PWR_1 19
#define PIN_PWR_2 18
#define PIN_PWR_3 17

#define PIN_SPEED_1 23
#define PIN_SPEED_2 4
#define PIN_SPEED_3 13

#define PIN_I2C_SDA 21
#define PIN_I2C_SCL 22

#define PIN_ENC_SWT 35
#define PIN_ENC_DIR 32
#define PIN_ENC_CLK 33

class GSK_PINS
{
public:
    GSK_PINS()
    {
        pinMode(PIN_POS_SEN_1, INPUT);
        pinMode(PIN_POS_SEN_2, INPUT);
        pinMode(PIN_POS_SEN_3, INPUT);
        pinMode(PIN_DIR_1, OUTPUT);
        pinMode(PIN_DIR_2, OUTPUT);
        pinMode(PIN_DIR_3, OUTPUT);
        pinMode(PIN_PWR_1, OUTPUT);
        pinMode(PIN_PWR_2, OUTPUT);
        pinMode(PIN_PWR_3, OUTPUT);
        pinMode(PIN_SPEED_1, OUTPUT);
        pinMode(PIN_SPEED_2, OUTPUT);
        pinMode(PIN_SPEED_3, OUTPUT);
        pinMode(PIN_I2C_SDA, OUTPUT);
        pinMode(PIN_I2C_SCL, OUTPUT);
        pinMode(PIN_ENC_SWT, INPUT);
        pinMode(PIN_ENC_DIR, INPUT);
        pinMode(PIN_ENC_CLK, INPUT);
    }
};

#endif // GSK_PINS_HPP