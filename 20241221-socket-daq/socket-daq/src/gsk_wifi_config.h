#ifndef GSK_WIFI_CONFIG_H
#define GSK_WIFI_CONFIG_H

#include <Arduino.h>
#include <WiFi.h>
#include "OneButton.h"

#include "nlohmann/json.hpp"
using json = nlohmann::json;

enum GSK_WIFI_MODE { WIFI_MODE_CONFIG, WIFI_MODE_NORMAL };

class GSK_WIFI_CONFIG {
    GSK_WIFI_MODE mode;
    String ssid;
    String password;
    void setup();
    unsigned long lastButtonPress = 0;
    OneButton *configBtn;
    bool isCommSetupComplete = false;

    void toggleMode();

   public:
    GSK_WIFI_CONFIG();
    void setMode(GSK_WIFI_MODE mode);
    json prepareListOfNetworks();
    void loop();
};

#endif  // GSK_WIFI_CONFIG_H