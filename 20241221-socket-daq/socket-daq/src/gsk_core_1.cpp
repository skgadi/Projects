#include "gsk_main.h"

extern GSK_MAIN gskMain;

void core1Setup() { Serial.println("Core 1 Setup"); }
void core1Loop(void) {
    Serial.print("My IP address: ");
    Serial.println(WiFi.localIP());
}
