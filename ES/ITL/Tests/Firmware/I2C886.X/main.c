/*
 * File:   main.c
 * Author: gadis
 *
 * Created on August 1, 2016, 2:54 PM
 */



#include "main.h"

void main(void) {
    ANSEL = 0x00;
    ANSELH = 0x00;
    Lcd_Init();
    Lcd_Text(1,1,"Time:");
    Lcd_Text(2,1,"Date:");
    Lcd_Text(1,8,":");
    Lcd_Text(1,11,":");
    Lcd_Text(2,8,"/");
    Lcd_Text(2,11,"/20");
    I2C_Master_Init(400000);
    char data;
    char i=0;
    //I2C_WriteAtAddress(0xde, 0x00, 0b10010010);
    //WriteTimeToRTC(1);
    while (1) {
        //Time
        data = I2C_ReadAtAddress(0xde, 0x02);
        Lcd_Int(1,6,(data>>4) & 0x03 ,1);
        Lcd_Int(1,7,data & 0x0f ,1);
        data = I2C_ReadAtAddress(0xde, 0x01);
        Lcd_Int(1,9,(data>>4) & 0x07 ,1);
        Lcd_Int(1,10,data & 0x0f ,1);
        data = I2C_ReadAtAddress(0xde, 0x00);
        Lcd_Int(1,12,(data>>4) & 0x07 ,1);
        Lcd_Int(1,13,data & 0x0f ,1);
        //Date
        data = I2C_ReadAtAddress(0xde, 0x04);
        Lcd_Int(2,6,(data>>4) & 0x03 ,1);
        Lcd_Int(2,7,data & 0x0f ,1);
        data = I2C_ReadAtAddress(0xde, 0x05);
        Lcd_Int(2,9,(data>>4) & 0x01 ,1);
        Lcd_Int(2,10,data & 0x0f ,1);
        data = I2C_ReadAtAddress(0xde, 0x06);
        Lcd_Int(2,14,(data>>4) & 0x0f ,1);
        Lcd_Int(2,15,data & 0x0f ,1);
        
        i++;
        __delay_ms(100);
    }
}
