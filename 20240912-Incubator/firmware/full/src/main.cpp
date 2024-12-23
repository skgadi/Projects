#include "gsk_global.h"

GSK_PINS gsk_pins;
GSK_SERIAL gsk_serial;
GSK_TEMP gsk_temp;
GSK_PWM gsk_pwm;
GSK_LCD gsk_lcd;
GSK_ENCODER gsk_encoder;

void setup() { gsk_lcd.init(); }

void loop() {
    gsk_serial.loop();

    gsk_lcd.loop();
}
