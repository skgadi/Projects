/* 
 * File:   main.h
 * Author: gadis
 *
 * Created on October 3, 2016, 2:00 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

#define _XTAL_FREQ 4000000
// PIC16F886 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR21V   // Brown-out Reset Selection bit (Brown-out Reset set to 2.1V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "libs/GenericTypeDefs.h"
#include "libs/gsk_i2c.h"
#include "libs/gsk_usart.h"
#include "libs/gsk_RTC_GPS.h"
#include "libs/eeprom.h"
#include "libs/HD44780.h"
#include "libs/gsk_app_funcs.h"
    
#define MAX_NO_OF_CYCLES 3
#define MAX_NO_OF_STATES 10
#define SECONDS_IN_A_DAY 86400
#define FIRMWARE_LOOP_DELAY_MS 1000
#define NO_OF_CYCLES_PER_SECONDS (1000/FIRMWARE_LOOP_DELAY_MS)
    
#define C_D_MEMORY_ADDRESS 0X00
#define C_MEMORY_ADDRESS 0X01
#define C_ON_MEMORY_ADDRESS 0X0A
#define C_BLINK_MEMORY_ADDRESS 0X64

#define RUN_ON_LCD
    
#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

