/*
 * File:   main.c
 * Author: gadis
 *
 * Created on August 4, 2016, 9:57 AM
 */

#include "main.h"

void main(void) {
    ANSEL=0x00;
    ANSELH=0x00;
    TRISA = 0X00;
    TRISB = 0X00;
    Lcd_Init();
    
    I2C_Master_Init(400000);
    
    
    Lcd_Command(LCD_CLEAR);
    uint32_t Second;
    char TempVar000, i;
    i=0x00;
    SetOSCTRIM (0x00);
    while (1) {
        i++;
        WriteLongInt(1,14,i,3);
        WriteLongInt(2,14,GetOSCTRIM(),3);
    }
}
