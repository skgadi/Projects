#line 1 "c:\\Suresh\\git\\Projects\\automatic-liquid-dispenser\\firmware\\esp32\\ver000\\uc\\gsk_eeprom.h"
#ifndef GSK_EEPROM_H
#define GSK_EEPROM_H
#include <Preferences.h>

class GSK_EEPROM {
  private:
  public:
    GSK_EEPROM();
    void storeArray(void * array, int size, int address);
    void readArray(void * array, int size, int address);
};


#endif