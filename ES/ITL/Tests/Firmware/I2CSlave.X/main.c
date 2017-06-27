/*
 * File:   main.c
 * Author: gadis
 *
 * Created on August 1, 2016, 4:39 PM
 */

#include "main.h"

void main(void) {
    TRISB=0Xff;
    I2C_Slave_Init(0x42);
    while(1){
    /*PORTB=0XFF;
    __delay_ms(65);
    PORTB=0X00;
    __delay_ms(65);
    */
    }
}
