#include "../main.h"

extern volatile int32_t C[MAX_NO_OF_CYCLES];
extern volatile uint8_t C_D;
extern volatile uint8_t C_ON[MAX_NO_OF_CYCLES][MAX_NO_OF_STATES][3]; 
extern volatile uint8_t C_BLINK[MAX_NO_OF_CYCLES][MAX_NO_OF_STATES][3];
extern volatile double C_T;

void ReadVars(){
    C_D = eeprom_read(C_D_MEMORY_ADDRESS);
    for (char i = 0; i<MAX_NO_OF_CYCLES; i++)
        C[i] = (uint32_t)eeprom_read(C_MEMORY_ADDRESS + MAX_NO_OF_CYCLES*i)*256*256 + (uint16_t)eeprom_read(0x02 + MAX_NO_OF_CYCLES*i)*256 + eeprom_read(0x03 + MAX_NO_OF_CYCLES*i);
    for (char i = 0; i < MAX_NO_OF_CYCLES; i++)
        for (char j = 0; j < MAX_NO_OF_STATES; j++)
            for (char k = 0; k< 3 ; k++) {
                C_ON[i][j][k] = eeprom_read(C_ON_MEMORY_ADDRESS + i*MAX_NO_OF_STATES*3 + j*3 + k);
                C_BLINK[i][j][k] = eeprom_read(C_BLINK_MEMORY_ADDRESS + i*MAX_NO_OF_STATES*3 + j*3 + k);
            }
}





/*Dario Greggio
--
Rule of thumb: Always read inputs from PORTx and write outputs to LATx. If you need to read what you set an output to, read LATx.*/