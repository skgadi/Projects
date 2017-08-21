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
    UART_Init(9600);
    
    I2C_Master_Init(400000);
    
    
    Lcd_Command(LCD_CLEAR);
    Lcd_Text(1,1,"GPS:");
    Lcd_Text(2,1,"RTC:");
    Lcd_Text(2,11,"-");
    Lcd_Text(1,11,"-");
    unsigned char Data[6];
    uint32_t Second;
    char TempVar000, i;
    TRISCbits.TRISC2 = 0;
    RC2=1;
    i=0x00;
    //WriteToRTC("020000");
    
    /*GPS ON*/
    TRISCbits.TRISC1= 0;
    RC1=1;
    
    /*------*/
    while (1) {
        i++;
        WriteLongInt(1,12,i,5);

        if (UART_ReadValidTimeFromGPS_TO(Data, 100)) {
            //WriteToRTC(Data);
            for (TempVar000=0; TempVar000<6; TempVar000++)
                Lcd_WriteChar(1,TempVar000+5,Data[TempVar000]);
        }
        else
            Lcd_Text(1,5,"GPSERR");
        Second = ReadRTCAsSec();
        DisplayTimeFromRTC (2,5);
        WriteLongInt(2,12,Second,5);
        //WriteLongInt(2,5,SPBRG,5);
        //WriteLongInt(2,12,SPBRGH,5);
        /* //
        /*Second = ReadRTCAsSec();
        DisplayTimeFromRTC ();
        WriteLongInt(2,12,Second,5);
        __delay_ms(1000);*/
    }
}
