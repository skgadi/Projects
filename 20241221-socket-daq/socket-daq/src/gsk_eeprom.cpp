#include "gsk_eeprom.h"

GSK_EEPROM::GSK_EEPROM() { EEPROM.begin(512); }

bool GSK_EEPROM::setSSID(char *inSSID) {
    if (strlen(inSSID) > 32) {
        return false;
    }
    for (int i = 0; i < strlen(inSSID); ++i) {
        EEPROM.write(i, inSSID[i]);
    }
    if (strlen(inSSID) < 32) {
        EEPROM.write(strlen(inSSID), '\0');
    }
}

bool GSK_EEPROM::setPass(char *inPass) {
    if (strlen(inPass) > 64) {
        return false;
    }
    for (int i = 0; i < strlen(inPass); ++i) {
        EEPROM.write(32 + i, inPass[i]);
    }
    if (strlen(inPass) < 64) {
        EEPROM.write(32 + strlen(inPass), '\0');
    }
}

bool GSK_EEPROM::setDeviceName(char *inDeviceName) {
    if (strlen(inDeviceName) > 32) {
        return false;
    }
    for (int i = 0; i < strlen(inDeviceName); ++i) {
        EEPROM.write(96 + i, inDeviceName[i]);
    }
    if (strlen(inDeviceName) < 32) {
        EEPROM.write(96 + strlen(inDeviceName), '\0');
    }
}

char *GSK_EEPROM::getSSID() {
    char *ssid = new char[32];
    for (int i = 0; i < 32; ++i) {
        ssid[i] = EEPROM.read(i);
        if (ssid[i] == '\0') {
            break;
        }
    }
    return ssid;
}

char *GSK_EEPROM::getPass() {
    char *pass = new char[64];
    for (int i = 0; i < 64; ++i) {
        pass[i] = EEPROM.read(32 + i);
        if (pass[i] == '\0') {
            break;
        }
    }
    return pass;
}

char *GSK_EEPROM::getDeviceName() {
    char *deviceName = new char[32];
    for (int i = 0; i < 32; ++i) {
        deviceName[i] = EEPROM.read(96 + i);
        if (deviceName[i] == '\0') {
            break;
        }
    }
    return deviceName;
}