#include "gsk_main.h"

extern GSK_MAIN gskMain;

GSK_WIFI_CONFIG::GSK_WIFI_CONFIG() {
    String mac = WiFi.macAddress();
    mac.replace(":", "");
    ssid = "Uyamak";
    password = "y5?*tFrdQU";
    configBtn = new OneButton(PIN_BTN_CONFIG, true);

    configBtn->attachLongPressStart([]() {
        Serial.println("Long Press Start");
        gskMain.wifiConfig->toggleMode();
    });

    mode = WIFI_MODE_NORMAL;
    setup();
}

void GSK_WIFI_CONFIG::setup() {
    WiFi.mode(WIFI_STA);

    WiFi.begin(ssid.c_str(), password.c_str());
    Serial.println("Configuring WiFi network: " + ssid);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to Wi-Fi...");
    }
    delay(100);
    if (!isCommSetupComplete) {
        isCommSetupComplete = true;
        gskMain.comm->setup();
    }
    Serial.println("Connected to the WiFi network");

    /*

        if (mode == WIFI_MODE_NORMAL) {
            WiFi.disconnect();
            WiFi.mode(WIFI_STA);
            // WiFi.begin(gskMain.eeprom.getSSID(), gskMain.eeprom.getPass());

            Serial.println("Connecting to WiFi network: ");
            // Serial.println("Connecting to WiFi network: " +
            // String(gskMain.eeprom.getSSID()));

        } else {
            WiFi.disconnect();
            WiFi.mode(WIFI_STA);
            IPAddress local_ip(192, 168, 1, 1);
            IPAddress gateway(192, 168, 1, 1);
            IPAddress subnet(255, 255, 255, 0);
            WiFi.softAP(ssid, password);
            Serial.println("Configuring WiFi network: " + ssid);
            WiFi.softAPConfig(local_ip, gateway, subnet);
            delay(100);

            gskMain.comm->setup();
        }

    */
}

void GSK_WIFI_CONFIG::setMode(GSK_WIFI_MODE inMode) {
    if (inMode != mode) {
        mode = inMode;
        setup();
    }
}

void GSK_WIFI_CONFIG::toggleMode() {
    if (mode == WIFI_MODE_NORMAL) {
        setMode(WIFI_MODE_CONFIG);
    } else {
        setMode(WIFI_MODE_NORMAL);
    }
}

void GSK_WIFI_CONFIG::loop() {
    configBtn->tick();
    /* if (digitalRead(PIN_BTN_CONFIG) == LOW) {
         if (lastButtonPress == 0) {
             lastButtonPress = millis();
         }
     } else {
         if (lastButtonPress != 0) {
             if (millis() - lastButtonPress > 5000) {
                 toggleMode();
             }

             lastButtonPress = 0;
         }
     }*/
}

json prepareListOfNetworks() {
    json networks;
    int n = WiFi.scanNetworks();
    if (n == 0) {
        return networks;
    } else {
        for (int i = 0; i < n; ++i) {
            json network;
            network["ssid"] = WiFi.SSID(i).c_str();
            network["rssi"] = WiFi.RSSI(i);
            network["encryption"] = (WiFi.encryptionType(i) == WIFI_AUTH_OPEN)
                                        ? "OPEN"
                                        : "WEP/WPA/WPA2";
            networks.push_back(network);
        }
    }
    return networks;
}