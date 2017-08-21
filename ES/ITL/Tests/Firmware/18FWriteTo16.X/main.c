/*
 * File:   main.c
 * Author: gadis
 *
 * Created on August 10, 2016, 5:37 PM
 */


#include "main.h"

void main(void) {
    ANSEL = 0x00;
    ANSELH = 0x00;

    TRISB = 0X00;
    I2C_Master_Init(400000);
    WriteToRTC("000000");
    while(1) {
        WriteToRTC("000000");
        ReadRTCAsSec();
        /*LATB = 0x00;
        for (char i=0; i<20; i++)
            __delay_ms(50);
        LATB = 0xff;
        for (char i=0; i<20; i++)
            __delay_ms(50);*/
        
    }
    
    return;
}
