#include "storage.h"
#include "global_variables.h"

void STORAGE::putAll(CHEMICAL (&data)[NUMBER_OF_CHEMICALS]){
EEPROM.put(0, data);
}

void STORAGE::getAll(CHEMICAL (&data)[NUMBER_OF_CHEMICALS]) {
EEPROM.get(0, data);
}
