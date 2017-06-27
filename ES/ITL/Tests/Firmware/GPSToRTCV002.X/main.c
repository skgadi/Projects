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
    Lcd_Text(2,11,":");
    Lcd_Text(1,11,":");
    unsigned char Data[6];
    int32_t Second;
    int32_t PSec=1920;
    //SetOSCTRIM(0);
    char TempVar000;
    TRISCbits.TRISC2 = 0;
    RC2=1;
    bool Synced=false;
    //WriteToRTC("020000");
    
    /*GPS ON*/
    TRISCbits.TRISC1= 0;
    RC1=1;
    /*------*/
    int32_t TempInt;
    char Itr=0x00;
    bool ValidGPS;
    while (1) {
        if (Synced)
            Itr++;
        if (!Itr)
            Synced=false;
        
        /*if (UART_ReadValidTimeFromGPS_TO(Data, 100)) {
            WriteToRTC(Data);
            for (TempVar000=0; TempVar000<6; TempVar000++)
                Lcd_WriteChar(1,TempVar000+5,Data[TempVar000]);
            } else
                Lcd_Text(1,5,"GPSERR");*/

        
        //*/
        ValidGPS = UART_ReadValidTimeFromGPS_TO(Data,100);
        
        /*Firmware snippet for initializing*/
        /*SetOSCTRIM(0);
        if (ValidGPS)
            WriteToRTC(Data); /**/
        Second = ReadRTCAsSec();
        //Sync        
        if ((Second==PSec) && (!Synced) && ValidGPS) {
            Second = ReadRTCAsSec(WriteToRTC(Data));
            AdjustSec(PSec-Second);
            Synced=1;
        }
        if (ValidGPS)
            for (TempVar000=0; TempVar000<6; TempVar000++)
                Lcd_WriteChar(1,TempVar000+5,Data[TempVar000]);
        //AdjustSec(Second-PSec);
        
        DisplayTimeFromRTC (2,5);
        WriteLongInt(2,12,Second,5,0);
        WriteLongInt(1,12,GetOSCTRIM(),4,1);
        //WriteLongInt(2,5,SPBRG,5);
        //WriteLongInt(2,12,SPBRGH,5);
        /* //
        /*Second = ReadRTCAsSec();
        DisplayTimeFromRTC ();
        WriteLongInt(2,12,Second,5);
        __delay_ms(1000);*/
    }
}
