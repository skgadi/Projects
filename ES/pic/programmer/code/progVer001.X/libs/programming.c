#include "../main.h"
#include "programming.h"

VOID setTrisToOut (VOID) {
    PPIN_VPP_TRIS = 0;
    PPIN_PGD_TRIS = 0;
    PPIN_PGC_TRIS = 0;
    PPIN_PGM_TRIS = 0;
}

VOID enterLowVoltageICSP(VOID) {
    setTrisToOut ();
    
    PPIN_VPP_LAT = 0;
    PPIN_PGD_LAT = 0;
    PPIN_PGC_LAT = 0;
    PPIN_PGM_LAT = 0;
    __delay_ms(1);
    PPIN_PGM_LAT = 1;
    DELAY_P15();
    PPIN_VPP_LAT = 1;
    DELAY_P12();
}

VOID exitLowVoltageICSP(VOID) {
    setTrisToOut ();
    PPIN_PGD_LAT = 0;
    PPIN_PGC_LAT = 0;
    DELAY_P16();
    PPIN_VPP_LAT = 0;
    DELAY_P18();
    PPIN_PGM_LAT = 0;
}
VOID enterHighVoltageICSP(VOID){
    
}

VOID exitHighVoltageICSP(VOID) {
    
}

VOID enterICSP(VOID) {
    if (USE_LOW_VOLTAGE_PROGRAMMING)
        enterLowVoltageICSP();
    else
        enterHighVoltageICSP();
}
VOID exitICSP(VOID){
    if (USE_LOW_VOLTAGE_PROGRAMMING)
        exitLowVoltageICSP();
    else
        exitHighVoltageICSP();
}

VOID generateWritePulses(UINT command, UINT payLoadMsb, UINT payLoadLsb) {
    DELAY_MIN(); //P5
    for (BYTE i = 0; i < 4; i++) {
        PPIN_PGC_LAT = 1;
        DELAY_MIN();
        if ((command >> i) & 0x01)
            PPIN_PGD_LAT = 1;
        else
            PPIN_PGD_LAT = 0;
        DELAY_MIN();
        PPIN_PGC_LAT = 0;
        DELAY_MIN();
    }
    DELAY_MIN(); //P5A
    for (BYTE i = 0; i < 8; i++) {
        PPIN_PGC_LAT = 1;
        DELAY_MIN();
        if ((payLoadLsb >> i) & 0x01)
            PPIN_PGD_LAT = 1;
        else
            PPIN_PGD_LAT = 0;
        DELAY_MIN();
        PPIN_PGC_LAT = 0;
        DELAY_MIN();
    }        
    for (BYTE i = 0; i < 8; i++) {
        PPIN_PGC_LAT = 1;
        DELAY_MIN();
        if ((payLoadMsb >> i) & 0x01)
            PPIN_PGD_LAT = 1;
        else
            PPIN_PGD_LAT = 0;
        DELAY_MIN();
        PPIN_PGC_LAT = 0;
        DELAY_MIN();
    }
}

WORD_VAL generateReadPulses (UINT command) {
    WORD_VAL OUT;
    OUT.Val = 0x0000;
    for (BYTE i = 0; i < 4; i++) {
        PPIN_PGC_LAT = 1;
        DELAY_MIN();
        if ((command >> i) & 0x01)
            PPIN_PGD_LAT = 1;
        else
            PPIN_PGD_LAT = 0;
        DELAY_MIN();
        PPIN_PGC_LAT = 0;
        DELAY_MIN();
    }
    PPIN_PGD_TRIS = 1;
    for (BYTE i = 0; i < 16; i++) {
        PPIN_PGC_LAT = 1;
        DELAY_MIN();
        if (PPIN_PGD_PORT == 1)
            OUT.Val = OUT.Val | ((WORD)(0x0001<<i));
        DELAY_MIN();
        PPIN_PGC_LAT = 0;
        DELAY_MIN();
    }
    PPIN_PGD_TRIS = 0;
    return OUT;
}


BYTE readEepromByte(MEMORY_ADDRESS address) {
    enterICSP();
    generateWritePulses(0, 0x9E, 0xA6);
    generateWritePulses(0, 0x9C, 0xA6);
    generateWritePulses(0, 0x0E, address.v[0]);
    generateWritePulses(0, 0x6E, 0xA9);
    generateWritePulses(0, 0x0E, address.v[1]);
    generateWritePulses(0, 0x6E, 0xAA);
    generateWritePulses(0, 0x80, 0xA6);
    generateWritePulses(0, 0x50, 0xA8);
    generateWritePulses(0, 0x6E, 0xF5);
    generateWritePulses(0, 0x00, 0x00);
    WORD_VAL Data = generateReadPulses (0x02);
    exitICSP();
    return Data.v[1];
}

BYTE writeEepromByte(MEMORY_ADDRESS address, BYTE data) {
    UINT i=0;
    BYTE Success = 0x00;
    enterICSP();
    generateWritePulses(0, 0x9E, 0xA6);
    generateWritePulses(0, 0x9C, 0xA6);
    generateWritePulses(0, 0x0E, address.v[0]);
    generateWritePulses(0, 0x6E, 0xA9);
    generateWritePulses(0, 0x0E, address.v[1]);
    generateWritePulses(0, 0x6E, 0xAA);
    generateWritePulses(0, 0x0E, data);
    generateWritePulses(0, 0x6E, 0xA8);
    generateWritePulses(0, 0x84, 0xA6);
    generateWritePulses(0, 0x82, 0xA6);
    generateWritePulses(0, 0x00, 0x00);
    generateWritePulses(0, 0x00, 0x00);
    do {
        generateWritePulses(0, 0x50, 0xA6);
        generateWritePulses(0, 0x6E, 0xF5);
        generateWritePulses(0, 0x00, 0x00);
        WORD_VAL Data = generateReadPulses (0x02);
        if (Data.v[1] == 0x00)
            Success = TRUE;
        i++;
    } while ((!Success) && (i<POLL_WR_FOR_x_TIMES));
    PPIN_PGC_LAT = 0;
    DELAY_P10();
    generateWritePulses(0, 0x94, 0xA6);
    exitICSP();
    return Success;
}