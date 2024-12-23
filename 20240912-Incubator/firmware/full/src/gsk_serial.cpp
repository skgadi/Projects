#include "gsk_serial.h"

GSK_SERIAL::GSK_SERIAL() { Serial.begin(115200); }

void GSK_SERIAL::loop() {
    if (Serial.available() > 0) {
        char c = Serial.read();
        Serial.write(c);
    }
}