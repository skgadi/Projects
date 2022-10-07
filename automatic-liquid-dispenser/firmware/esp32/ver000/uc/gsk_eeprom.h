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