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
    Lcd_Command(LCD_CLEAR);
    UART_Init(9600);
    unsigned char Data[6];
    char i;
    i=0x00;
    while (1) {
        i=i+1;
        Lcd_Int(2,1,i,3);
        UART_ReadFromGPS(Data);
        Data[7] = 0x0;
        Lcd_Text(1,1,Data);
    }
}
