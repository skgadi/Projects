#include "gsk_main.h"

extern GSK_MAIN gskMain;

void core0Setup() {
    Serial.println("Core 0 Setup");
    gskMain.wifiConfig->setMode(WIFI_MODE_NORMAL);
}
void core0Loop(void) {
    gskMain.wifiConfig->loop();
    gskMain.comm->loop();
}
