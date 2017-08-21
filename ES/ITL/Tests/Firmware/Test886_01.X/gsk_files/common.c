#include "common.h"

void SYSTEM_Initialize(void)
{
    
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    TMR0_Initialize();
}

void OSCILLATOR_Initialize(void)
{
    // SCS FOSC; SPLLEN disabled; IRCF 500KHz_MF; 
    OSCCON = 0x38;
    // LFIOFR disabled; HFIOFL not stable; OSTS intosc; PLLR disabled; HFIOFS not stable; HFIOFR disabled; MFIOFR disabled; T1OSCR disabled; 
//    OSCSTAT = 0x00;
    // TUN 0; 
    OSCTUNE = 0x00;
    // Set the secondary oscillator
    
}
