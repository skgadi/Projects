/*
 * File:   main.c
 * Author: gadis
 *
 * Created on August 10, 2016, 3:29 PM
 */

#include "main.h"

void main(void) {
    Lcd_Init();
    Lcd_Command(LCD_CLEAR);
    /*Lcd_Text(1,1,"WtnToEEPROM:");
    Lcd_Text(2,1,"RedFmEEPROM:");
    for (int i=0; i<=255; i++) {
        eeprom_write(i, i);
        Lcd_WriteChar(1,13,i);
        WriteLongInt(1,14,i,3);
        __delay_ms(250);
    }
    for (int i=0; i<=255; i++) {
        Lcd_WriteChar(2,13,eeprom_read(i));
        WriteLongInt(2,14,i,3);
        __delay_ms(250);
    }
    while (1) {
    
    }*/
    eeprom char data[50]="1234";
    char i=0;
    while (1) {
        Lcd_Text(1,1,"EEPROM:");
        WriteLongInt(1,8,i,3);
        Lcd_Text(1,11,":");
        Lcd_WriteChar(1,12,eeprom_read(i));
        i++;
        __delay_ms(100);
    }
    return;
}
