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
//--------------------ONLY FOR DEBUG PURPOSE
//#define DISPLAY_TO_LCD
//#define ACTIVATE_SIMULATION
//#define START_TIME_OF_SIMULATION 22000
#define SET_IOS_ON
    

    
    
    
    
    
    
    
    
//--------------------Change by user
#define LOAD_TIME_FROM_RTC_EVERY_x_SECONDS (60*60)
    
    //STATE 2 ON and BLINK state
#define STATE2_BLINK_FOR_LAST_x_S 4
#define STATE2_ON_TIME_IN_MS 700
#define STATE2_OFF_TIME_IN_MS 300
    
    //AUDIO STATE
    //Make sure sum of the following is a multiple of 1000
#define AUDIO_NORMAL_TONE_ON_TIME_IN_MS 500
#define AUDIO_NORMAL_TONE_OFF_TIME_IN_MS 500
    
#define AUDIO_SPL_TONE_FOR_LAST_x_S 3
#define AUDIO_SPL_TONE_ON_TIME_IN_MS 500
#define AUDIO_SPL_TONE_OFF_TIME_IN_MS 500
#define SWITCH_ON_GPS_AT_x_S_UTC 36000
#define READ_GPS_AFTER_x_S_AFTER_SWITCHING_ON (20*60)//A maximum of 65535
    
    
    
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
#define LOAD_TIME_FROM_RTC_EVERY_x_SECONDS_INITIAL (5)
#define MILLISECOND_ADJUST_PID_P 1
#define MILLISECOND_ADJUST_PID_I 1
#define MILLISECOND_ADJUST_PID_D 1
#define _XTAL_FREQ 4000000
#define INITIAL_ADJUST_MILLISECOND_VALUE 0X66
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
eeprom char EE_C_D =0x00;eeprom char EE_C[3][3] = {{1, 81, 127},{1, 81, 127},{1, 81, 127},};eeprom char EE_STATE_BREAKS[3] = {8,21,30,};eeprom char EE_STATES[30][5]= {{82,0x20,0x90,0x01,0x00},{3,0x22,0x90,0x00,0x00},{6,0x0C,0x90,0x00,0x00},{2,0x04,0x90,0x08,0x00},{2,0x14,0x90,0x00,0x00},{21,0x24,0x28,0x00,0x00},{2,0x24,0x10,0x00,0x20},{2,0x24,0x50,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},{0,0x00,0x00,0x00,0x00},};eeprom char EE_AUDIO[4]= {0xE5,0x00,0x00,0x00,};
//Global variables
extern volatile UINT8 STATE_PERIODS[MAX_NO_OF_STATES] @(0x20) = {
    0,0,0,0,0, 0,0,0,0,0,
    0,0,0,0,0, 0,0,0,0,0,
    0,0,0,0,0, 0,0,0,0,0,
};
extern volatile UINT8 STATE_1[MAX_NO_OF_STATES][NO_OF_PORTS_IN_USE] @(0x3E) = {
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
extern volatile UINT16 STATE_CUMULATIVE_PERIODS[3] @(0x7A) = {0,0,0};
extern volatile INT8 C_D @(0x16F) = NULL;
extern volatile INT32 S @(0x16B) = NULL;
extern volatile UINT8 CYCLE_TYPE = NULL;
extern volatile UINT8 PREV_CYCLE_TYPE = MAX_NO_OF_TYPES_OF_CYCLES-1;
extern volatile BYTE_BITS FLAGS = NULL;
#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

