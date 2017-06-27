#include "../main.h"

void WriteToRTC(char *Time) {
    char TempVar000;
    //Setting Hour
    TempVar000 = 0x00;
    TempVar000 = 0x03 & (Time[0]-0x30);
    TempVar000 = TempVar000<<4;
    TempVar000 = TempVar000 | (0x0f & (Time[1]-0x30));
    I2C_WriteAtAddress(0xde, 0x02, TempVar000);
    //Setting Min
    TempVar000 = 0x00;
    TempVar000 = 0x07 & (Time[2]-0x30);
    TempVar000 = TempVar000<<4;
    TempVar000 = TempVar000 | (0x0f & (Time[3]-0x30));
    TempVar000 = TempVar000|0x80;
    I2C_WriteAtAddress(0xde, 0x01, TempVar000);
    //Setting Second
    TempVar000 = 0x00;
    TempVar000 = 0x07 & (Time[4]-0x30);
    TempVar000 = TempVar000<<4;
    TempVar000 = TempVar000 | (0x0f & (Time[5]-0x30));
    TempVar000 = TempVar000|0x80;
    I2C_WriteAtAddress(0xde, 0x00, TempVar000);
}

uint32_t ReadRTCAsSec() {
    char TempVar000;
    uint32_t Out = 0;
    TempVar000 = I2C_ReadAtAddress(0xde, 0x02);
    Out = ((TempVar000 & 0x0f) + (TempVar000>>4 & 0x03)*10);
    Out = Out*3600;
    
    TempVar000 = I2C_ReadAtAddress(0xde, 0x01);
    Out = Out + ((TempVar000 & 0x0f) + (TempVar000>>4 & 0x07)*10)*60;

    TempVar000 = I2C_ReadAtAddress(0xde, 0x00);
    Out = Out + ((TempVar000 & 0x0f) + (TempVar000>>4 & 0x07)*10);
    return Out;
}

uint8_t GetOSCTRIM () {
    return I2C_ReadAtAddress(0xde, 0x08);
    
}

void SetOSCTRIM (char Val) {
    I2C_WriteAtAddress(0xde, 0x08, Val);
}