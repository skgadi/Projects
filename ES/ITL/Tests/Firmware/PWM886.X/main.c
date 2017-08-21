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
    
    Lcd_Command(LCD_CLEAR);
    Lcd_Text(1,1,"PWM Period:");
    Lcd_Text(2,1,"PWM Duty C:");
    uint8_t PWMPeriod, PWMDutyC;
    PWM1_Init(5000);
    while (1) {
        PWM1_Duty(200);
    }
}
