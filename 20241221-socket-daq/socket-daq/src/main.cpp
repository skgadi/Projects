#include "gsk_main.h"

void GSK_MAIN::setup() {
    Serial.begin(115200);
    Serial.println("Starting GSK");

    pins = new GSK_PINS();
    eeprom = new GSK_EEPROM();
    wifiConfig = new GSK_WIFI_CONFIG();
    comm = new GSK_COMM();
    core_0 = new GSK_CORE();
    core_1 = new GSK_CORE();

    delay(1000);
    core0Setup();
    core1Setup();

    // This part will act as the loop for the core 0 and core 1
    core_0->setup(core0Loop, 1, 0);
    core_1->setup(core1Loop, 5000, 1);
}

GSK_MAIN gskMain;

void setup() {
    gskMain.setup();
}

void loop() {}
