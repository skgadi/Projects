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
    
    Lcd_Command(LCD_CLEAR);
    Lcd_Text(1,1,"GPS:");
    Lcd_Text(2,1,"PIC:");
    Lcd_Text(2,11,":");
    Lcd_Text(1,11,":");
    unsigned char GPSDate[6];
    int32_t PICSec, InitSec, CounterSec;
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
    
    /*Initializing the PICSec*/
    ValidGPS = UART_ReadValidTimeFromGPS_TO(GPSDate,100);
    if (ValidGPS) {
        for (TempVar000=0; TempVar000<6; TempVar000++)
            Lcd_WriteChar(2,TempVar000+5,GPSDate[TempVar000]);
        InitSec = GPS2Sec(GPSDate);
    }
    /*----Timer-----*/
    TMR1CS = true;
    TMR1ON = true;
    __delay_ms(10);
    TMR1H = 0x00;
    TMR1L = 0x00;
    __delay_ms(10);
    TMR1CS = true;
    TMR1ON = true;
    //__delay_ms(2000);
    while (1) {
        ValidGPS = UART_ReadValidTimeFromGPS_TO(GPSDate,100);
        if (ValidGPS) {
            for (TempVar000=0; TempVar000<6; TempVar000++)
                Lcd_WriteChar(1,TempVar000+5,GPSDate[TempVar000]);
            WriteLongInt(1,12,GPS2Sec(GPSDate),5,0);
        }
        
        
        /*
        WriteLongInt(2,5,(int32_t)CounterSec,5,1);
        if (TMR1IF) {
            Lcd_WriteChar(2,12,0x31);
            TMR1IF=false;
        } else {
            Lcd_WriteChar(2,12,0x30);
        }*/
        CounterSec = TMR1H;
        CounterSec = 256*CounterSec + TMR1L;
        //WriteLongInt(2,5,CounterSec,6,0);
        if (TMR1IF) {
            InitSec+=65536;
            TMR1IF = false;
            //WriteLongInt(2,5,GPS2Sec(GPSDate),6,0);
        }
        if (InitSec>86400)
            InitSec-=86400;
        
        PICSec = InitSec + CounterSec;
        if (PICSec>86400)
            PICSec = PICSec-86400;
        
        WriteLongInt(2,12,PICSec,5,0);
    }
}
