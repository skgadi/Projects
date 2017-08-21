/*
 * File:   main.c
 * Author: gadis
 *
 * Created on August 4, 2016, 9:57 AM
 */

#include "main.h"

void main(void) {
    TRISC=0x00;
    char a=0x00;
    while (1) {
        a=!a;
        PORTC = a;
        __delay_ms(500);
    }
}
