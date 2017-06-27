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
    TRISB = 0X00;
    Lcd_Init();
    UART_Init(9600);
    I2C_Master_Init(400000);
    
    
    Lcd_Command(LCD_CLEAR);
    Lcd_Text(1,1,"GPS:");
    Lcd_Text(2,1,"RTC:");
    Lcd_Text(2,11,"-");
    unsigned char Data[6];
    uint32_t Second;
    char TempVar000;
    TRISA = 0XFF;
    while (1) {
        UART_ReadFromGPS(Data);
        for (TempVar000=0; TempVar000<6; TempVar000++)
            Lcd_WriteChar(1,TempVar000+5,Data[TempVar000]);
        //WriteToRTC(Data);
        Second = ReadRTCAsSec();
        WriteLongInt(2,12,Second,5);
        TempVar000 = I2C_ReadAtAddress(0xde, 0x02);
        Lcd_Int(2,5,(TempVar000>>4) & 0x03 ,1);
        Lcd_Int(2,6,TempVar000 & 0x0f ,1);
        TempVar000 = I2C_ReadAtAddress(0xde, 0x01);
        Lcd_Int(2,7,(TempVar000>>4) & 0x07 ,1);
        Lcd_Int(2,8,TempVar000 & 0x0f ,1);
        TempVar000 = I2C_ReadAtAddress(0xde, 0x00);
        Lcd_Int(2,9,(TempVar000>>4) & 0x07 ,1);
        Lcd_Int(2,10,TempVar000 & 0x0f ,1);
        if (RA3 == 1)
            WriteToRTC(Data);
        if (RA4 == 1)
            WriteToRTC("000000");
        __delay_ms(500);

    }
}
