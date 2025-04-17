#ifndef GSK_MAIN_H
#define GSK_MAIN_H

#include <Arduino.h>

#include "WiFi.h"
#include "gsk_comm.h"
#include "gsk_core.h"
#include "gsk_eeprom.h"
#include "gsk_pins.h"
#include "gsk_wifi_config.h"

class GSK_MAIN {
   public:
    GSK_CORE* core_0;
    GSK_CORE* core_1;
    GSK_COMM* comm;
    GSK_WIFI_CONFIG* wifiConfig;
    GSK_EEPROM* eeprom;
    GSK_PINS* pins;
    void setup();
};

void core0Setup();
void core0Loop();
void core1Setup();
void core1Loop();

#endif  // GSK_MAIN_H