#include "gsk_pins.h"

GSK_PINS::GSK_PINS() {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_BTN_CONFIG, INPUT);
}