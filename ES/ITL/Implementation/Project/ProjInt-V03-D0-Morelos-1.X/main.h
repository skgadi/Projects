/* 
 * File:   main.h
 * Author: gadis
 *
 * Created on October 3, 2016, 2:00 PM
 */

// Synchronization with only the GPS
// at the swith ON and at the 10 h UTC.
// 22 May 2017.

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif
//--------------------ONLY FOR DEBUG PURPOSE
//#define DISPLAY_TO_LCD//
//#define ACTIVATE_SIMULATION
//#define START_TIME_OF_SIMULATION 63000
#define SET_IOS_ON
#define GPS_SYNC_EVERY_DAY_x_SEC 
    
//--------------------Variable for Temporal Sincronizaton
#define LOAD_TIME_FROM_GPS_EVERY_DAY_x_SEC (9*60*60) // A maximum of 86,400 s.
#define READ_GPS_AFTER_SWITCHING_ON_x_SEC (6*60) //(16*60). A maximum of 65535. 
#define DISABLE_GPS_AFTER_x_NON_SYNC_CYCLES (4) // (4) number of cycles 
    
    //STATE 2 ON and BLINK state
#define STATE2_BLINK_FOR_LAST_x_S 60 // 4 s.
#define STATE2_ON_TIME_IN_MS 600 // 700 s.
#define STATE2_OFF_TIME_IN_MS 400 // 300 s.
    
    //AUDIO STATE
#define AUDIO_NORMAL_TONE_ON_TIME_IN_MS 80
#define AUDIO_NORMAL_TONE_OFF_TIME_IN_MS 1920
    
#define AUDIO_SPL_TONE_FOR_LAST_x_S 5
#define AUDIO_SPL_TONE_ON_TIME_IN_MS 80
#define AUDIO_SPL_TONE_OFF_TIME_IN_MS 420
        
//--------------------FIRMWARE CONSTANTS
#define MAX_NO_OF_TYPES_OF_CYCLES 3
#define NO_OF_TYPES_OF_STATES 2 //Different types of states. Eg. ON, ON AND BLINK
#define MAX_NO_OF_STATES 30
#define NO_OF_PORTS_IN_USE 2
#define PORT_0 PORTA
#define PORT_1 PORTB
#define SIZE_OF_EACH_PORT 8
#define SECONDS_IN_A_DAY 86400
#define GPS_ON_OFF_PORT RC1
#define AUDIO_PORT RC0
#define AUDIO_STATE_SIZE_IN_BYTES 4
#define SWITCH_ON 1
#define SWITCH_OFF 0
#define RAISE_FLAG 1
#define DROP_FLAG 0
#define FLAG_GET_TIME_FROM_RTC FLAGS.bits.b0
#define FLAG_ADJUST_SECOND_RATE FLAGS.bits.b1
#define FLAG_GPS_IS_ON FLAGS.bits.b2
#define FLAG_GPS_SYNCED FLAGS.bits.b3
#define FLAG_CALIBRATE_RTC FLAGS.bits.b4
#define FLAG_END_OF_MILLI_SECOND FLAGS.bits.b5
#define FLAG_TIMER_EVEN_CYCLE FLAGS.bits.b6


#define MILLISECOND_ADJUST_PID_P 1
#define MILLISECOND_ADJUST_PID_I 1
#define MILLISECOND_ADJUST_PID_D 1
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
#include "libs/HD44780.h"
#include "libs/eeprom.h"
#include "libs/gsk_RTC_GPS.h"
#include "libs/gsk_i2c.h"
#include "libs/gsk_algo_funcs.h"
#include "libs/gsk_usart.h"

//Data to EEPROM 
eeprom char EE_Settings[167]={10,0x24,0x90,0x00,0x00,10,0x09,0x28,0x00,0x00,10,0x00,0x00,0x12,0x40,10,0x00,0x00,0x24,0x80,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0,0x00,0x00,0x00,0x00,0, 1, 44,0, 2, 88,0, 3, 132,0x40,0x00,0x00,0x00,2,3,30,0};

    
//Global variables
extern volatile UINT8 STATE_PERIODS[MAX_NO_OF_STATES] @(0x190) = {
    0,0,0,0,0, 0,0,0,0,0,
    0,0,0,0,0, 0,0,0,0,0,
    0,0,0,0,0, 0,0,0,0,0,
};
extern volatile UINT8 STATE_1[MAX_NO_OF_STATES][NO_OF_PORTS_IN_USE] @(0x1AE) = {
    {0,0},{0,0},{0,0},{0,0},{0,0}, {0,0},{0,0},{0,0},{0,0},{0,0},
    {0,0},{0,0},{0,0},{0,0},{0,0}, {0,0},{0,0},{0,0},{0,0},{0,0},
    {0,0},{0,0},{0,0},{0,0},{0,0}, {0,0},{0,0},{0,0},{0,0},{0,0},
};
extern volatile UINT8 STATE_2[MAX_NO_OF_STATES][NO_OF_PORTS_IN_USE] @(0x110) = {
    {0,0},{0,0},{0,0},{0,0},{0,0}, {0,0},{0,0},{0,0},{0,0},{0,0},
    {0,0},{0,0},{0,0},{0,0},{0,0}, {0,0},{0,0},{0,0},{0,0},{0,0},
    {0,0},{0,0},{0,0},{0,0},{0,0}, {0,0},{0,0},{0,0},{0,0},{0,0},
};
extern volatile DWORD_VAL AUDIO @(0x167) = NULL;
extern volatile INT32 C[MAX_NO_OF_TYPES_OF_CYCLES] @(0x14C) ={0,0,0};
extern volatile UINT8 STATE_BREAKS[MAX_NO_OF_TYPES_OF_CYCLES] @(0x164) = {0,0,0};
extern volatile UINT16 STATE_CUMULATIVE_PERIODS[MAX_NO_OF_TYPES_OF_CYCLES] @(0x1EA) = {0,0,0};
extern volatile INT8 C_D @(0x16F) = NULL;
extern volatile INT32 S @(0x16B) = NULL;
extern volatile UINT8 CYCLE_TYPE = NULL;
extern volatile UINT8 PREV_CYCLE_TYPE = MAX_NO_OF_TYPES_OF_CYCLES-1;
extern volatile BYTE_BITS FLAGS = NULL;
#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */
