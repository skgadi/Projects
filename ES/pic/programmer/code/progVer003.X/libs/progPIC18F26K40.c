#include "../main.h"
#include "progPIC18F26K40.h"

VOID PIC18F26K40_setTrisToOut (VOID) {
    PIC18F26K40_MCLR_TRIS = 0;
    PIC18F26K40_PGD_TRIS  = 0;
    PIC18F26K40_PGC_TRIS  = 0;
}

VOID PIC18F26K40_enterLowVoltageProg (VOID) {
    PIC18F26K40_setTrisToOut ();
    PIC18F26K40_DELAY_MIN();
    //Set all values to zero
    PIC18F26K40_MCLR_LAT = 0;
    PIC18F26K40_PGD_LAT  = 0;
    PIC18F26K40_PGC_LAT  = 0;
    PIC18F26K40_DELAY_T_ENTH();
    // Start the pattern
    DWORD_VAL code;
    code.Val = (0x4d434850);
    PIC18F26K40_sendByte(code.v[3], MSBTOLSB);
    PIC18F26K40_sendByte(code.v[2], MSBTOLSB);
    PIC18F26K40_sendByte(code.v[1], MSBTOLSB);
    PIC18F26K40_sendByte(code.v[0], MSBTOLSB);
}

VOID PIC18F26K40_exitLowVoltageProg (VOID) {
    PIC18F26K40_MCLR_TRIS = 0;
    PIC18F26K40_DELAY_MIN();
    PIC18F26K40_MCLR_LAT = 1;
}

VOID PIC18F26K40_sendByte(BYTE info, SEND_DIRECTION direction) {
    PIC18F26K40_setTrisToOut ();
    BYTE i, j;
    for (i = 0; i < 8; i++) {
        if (direction)
            j = i;
        else
            j = 7-i;
        PIC18F26K40_PGC_LAT = 1;
        PIC18F26K40_DELAY_MIN();
        if ((info >> j) & 0x01)
            PIC18F26K40_PGD_LAT = 1;
        else
            PIC18F26K40_PGD_LAT = 0;
        PIC18F26K40_DELAY_MIN();
        PIC18F26K40_PGC_LAT = 0;
        PIC18F26K40_DELAY_MIN();
    }
}

DWORD_VAL PIC18F26K40_readThreeBytes(SEND_DIRECTION direction, BOOL IncreasePC) {
    if (IncreasePC)
        PIC18F26K40_sendByte(0xFE, MSBTOLSB);
    else
        PIC18F26K40_sendByte(0xFC, MSBTOLSB);
    PIC18F26K40_DELAY_T_DLY();
    DWORD_VAL data;
    data.Val = 0x000000;
    BYTE i, j;
    PIC18F26K40_PGD_TRIS = 1;
    for (i = 0; i < 23; i++) {
        if (direction)
            j = i;
        else
            j = 22-i;
        PIC18F26K40_PGC_LAT = 1;
        PIC18F26K40_DELAY_MIN();
        if (PIC18F26K40_PGD_PORT == 1)
            data.Val = data.Val | ((DWORD)(0x1<<j));
        PIC18F26K40_DELAY_MIN();
        PIC18F26K40_PGC_LAT = 0;
        PIC18F26K40_DELAY_MIN();
    }
    PIC18F26K40_PGC_LAT = 1;
    PIC18F26K40_DELAY_MIN();
    PIC18F26K40_PGC_LAT = 0;
    PIC18F26K40_DELAY_MIN();
    
    PIC18F26K40_PGD_TRIS = 0;
    return data;
}


VOID PIC18F26K40_loadPC (DWORD_VAL address) {
    DWORD_VAL tempAddress;
    tempAddress.Val= (address.Val<<1);
    tempAddress.bits.b0 = 0;
    tempAddress.bits.b23 = 0;
    PIC18F26K40_sendByte(0x80, MSBTOLSB);
    PIC18F26K40_DELAY_T_DLY();
    PIC18F26K40_sendByte(tempAddress.v[2], MSBTOLSB);
    PIC18F26K40_sendByte(tempAddress.v[1], MSBTOLSB);
    PIC18F26K40_sendByte(tempAddress.v[0], MSBTOLSB);
}

VOID PIC18F26K40_loadDataIntoNVM (DWORD_VAL data, BOOL IncreasePC) {
    DWORD_VAL tempData;
    tempData.Val = (data.Val <<1 );
    tempData.bits.b0 = 0;
    if (IncreasePC==TRUE)
        PIC18F26K40_sendByteMsbToLsb(0x02);
    else
        PIC18F26K40_sendByteMsbToLsb(0x00);
    PIC18F26K40_DELAY_T_DLY();
    PIC18F26K40_sendByteMsbToLsb(tempData.v[2]);
    PIC18F26K40_sendByteMsbToLsb(tempData.v[1]);
    PIC18F26K40_sendByteMsbToLsb(tempData.v[0]);
    PIC18F26K40_DELAY_T_DLY();
    /*Internally Timed Programming procedure*/
    PIC18F26K40_sendByteMsbToLsb(0xE0);
    __delay_ms(6);
    /*End of Internally Timed Programming procedure*/
    /*Externally Timed Programming procedure*/
    /*PIC18F26K40_sendByteMsbToLsb(0xC0);
    PIC18F26K40_DELAY_T_PEXT_1();
    PIC18F26K40_DELAY_T_PEXT_2();
    PIC18F26K40_sendByteMsbToLsb(0x82);
    PIC18F26K40_DELAY_T_PEXT_1();
    PIC18F26K40_DELAY_T_PEXT_2();
    /* End of Externally Timed Programming*/
}

VOID PIC18F26K40_sendByteMsbToLsb(BYTE info) {
    PIC18F26K40_setTrisToOut ();
    for (INT8 i = 7; i >= 0; i--) {
        PIC18F26K40_PGC_LAT = 1;
        PIC18F26K40_DELAY_MIN();
        if ((info >> i) & 0x01)
            PIC18F26K40_PGD_LAT = 1;
        else
            PIC18F26K40_PGD_LAT = 0;
        PIC18F26K40_DELAY_MIN();
        PIC18F26K40_PGC_LAT = 0;
        PIC18F26K40_DELAY_MIN();
    }
}
