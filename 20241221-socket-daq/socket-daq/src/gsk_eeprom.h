#ifndef GSK_EEPROM_H
#define GSK_EEPROM_H

#include <EEPROM.h>

class GSK_EEPROM {
    int SSID_ADDR = 0;          // 0 to 31
    int PASS_ADDR = 32;         // max size of 64. 32 to 95
    int DEVICE_NAME_ADDR = 96;  // max size of 32. 96 to 127

   public:
    GSK_EEPROM();
    bool setSSID(char *inSSID);
    bool setPass(char *inPass);
    bool setDeviceName(char *inDeviceName);
    char *getSSID();
    char *getPass();
    char *getDeviceName();
};

#endif  // GSK_EEPROM_H