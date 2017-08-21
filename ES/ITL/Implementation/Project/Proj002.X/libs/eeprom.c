#include "../main.h"
#define C_D_EEPROM_ADDRESS 0xDE
#define STATE_BREAKS_EEPROM_ADDRESS 0xDB
#define C_EEPROM_ADDRESS 0xD2
#define STATES_EEPROM_ADDRESS 0x00

void ReadVars () {
    C_D = eeprom_read(C_D_EEPROM_ADDRESS);
    UINT8 i, j;
    for (i = 0; i<MAX_NO_OF_TYPES_OF_CYCLES; i++) {
        C[i] = (uint32_t) eeprom_read(C_EEPROM_ADDRESS + 3*i)*256*256
                + (uint16_t) eeprom_read(C_EEPROM_ADDRESS + 1 + 3*i)*256
                + eeprom_read(C_EEPROM_ADDRESS + 2 + 3*i);
        STATE_BREAKS[i] = eeprom_read(STATE_BREAKS_EEPROM_ADDRESS+i);
    }
    for (i = 0; i<MAX_NO_OF_STATES; i++) {
        STATE_PERIODS[i] = eeprom_read(STATES_EEPROM_ADDRESS
                + i*(1 + NO_OF_PORTS_IN_USE*NO_OF_TYPES_OF_STATES));
        for (j = 0; j<NO_OF_PORTS_IN_USE; j++) {
            STATE_1[i][j] = eeprom_read(STATES_EEPROM_ADDRESS
                    + i*(1 + NO_OF_PORTS_IN_USE*NO_OF_TYPES_OF_STATES)
                    + (1 + j));
            STATE_2[i][j] = eeprom_read(STATES_EEPROM_ADDRESS
                    + i*(1 + NO_OF_PORTS_IN_USE*NO_OF_TYPES_OF_STATES)
                    + (3 + j));
            /*STATE_3[i][j] = eeprom_read(STATES_EEPROM_ADDRESS
                    + i*(1 + NO_OF_PORTS_IN_USE*NO_OF_TYPES_OF_STATES)
                    + (5 + j));*/
        }
    }
}