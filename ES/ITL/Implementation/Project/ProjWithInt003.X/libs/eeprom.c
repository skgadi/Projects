#include "../main.h"
#define C_D_EEPROM_ADDRESS 0xA6
#define STATE_BREAKS_EEPROM_ADDRESS 0xA3
#define C_EEPROM_ADDRESS 0x96
#define STATES_EEPROM_ADDRESS 0x00
#define AUDIO_EEPROM_ADDRESS 0x9F

void ReadVars () {
    C_D = eeprom_read(C_D_EEPROM_ADDRESS);
    /*AUDIO = (UINT32) eeprom_read(AUDIO_EEPROM_ADDRESS)*256*256*256
            + (UINT32) eeprom_read(AUDIO_EEPROM_ADDRESS + 1)*256*256
            + (UINT32) eeprom_read(AUDIO_EEPROM_ADDRESS + 2)*256
            + (UINT32) eeprom_read(AUDIO_EEPROM_ADDRESS + 3);
    AUDIO = 8651304;*/
    UINT8 i, j;
    for (i=0; i<AUDIO_STATE_SIZE_IN_BYTES; i++)
        AUDIO.v[0] = eeprom_read(AUDIO_EEPROM_ADDRESS+i);
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