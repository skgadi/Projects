/* 
 * File:   programming.h
 * Author: gadis
 *
 * Created on May 31, 2017, 9:48 AM
 */

#ifndef PROGRAMMING_H
#define	PROGRAMMING_H

#ifdef	__cplusplus
extern "C" {
#endif

/*Definitions*/
#include "GenericTypeDefs.h"
typedef DWORD_VAL	MEMORY_ADDRESS;				// 32-bit unsigned

/*Delays*/
//#define DELAY_P2()        (__delay_us(1))
#define DELAY_P9()        (__delay_ms(1))
#define DELAY_P9A()       (__delay_ms(5))
#define DELAY_P10()       (__delay_us(100))
#define DELAY_P11()       (__delay_us(5))
#define DELAY_P11A()      (__delay_ms(4))
#define DELAY_P12()       (__delay_us(2))
#define DELAY_P12A()      (__delay_us(70))
#define DELAY_P12A()      (__delay_us(70))
#define DELAY_P13()       (__delay_us(1))
#define DELAY_P13A()      (__delay_us(70))
#define DELAY_P14()       (__delay_us(1))
#define DELAY_P15()       (__delay_us(2))
#define DELAY_P16()       (__delay_us(0))
#define DELAY_P17()       (__delay_us(0))
#define DELAY_P18()       (__delay_us(0))
#define DELAY_P19()       (__delay_us(0))
#define DELAY_P20()       (__delay_us(5))
#define DELAY_MIN()       (__delay_us(1)) // P2, P2A, P2B, P3, P4, P5, P5A, P6, 

/*Configuring programming bus*/
#define POLL_WR_FOR_x_TIMES 5
#define USE_LOW_VOLTAGE_PROGRAMMING TRUE

#define PPIN_VPP_PORT PORTCbits.RC6
#define PPIN_PGD_PORT PORTCbits.RC4
#define PPIN_PGC_PORT PORTBbits.RB6
#define PPIN_PGM_PORT PORTBbits.RB5

#define PPIN_VPP_LAT LATCbits.LATC6
#define PPIN_PGD_LAT LATCbits.LATC4
#define PPIN_PGC_LAT LATBbits.LATB6
#define PPIN_PGM_LAT LATBbits.LATB5

#define PPIN_VPP_TRIS TRISCbits.TRISC6
#define PPIN_PGD_TRIS TRISCbits.TRISC4
#define PPIN_PGC_TRIS TRISBbits.TRISB6
#define PPIN_PGM_TRIS TRISBbits.TRISB5

/*Functions*/
BYTE readEepromByte(MEMORY_ADDRESS x);
VOID setTrisToOut (VOID);
VOID enterLowVoltageICSP(VOID);
VOID exitLowVoltageICSP(VOID);
VOID enterHighVoltageICSP(VOID);
VOID exitHighVoltageICSP(VOID);
VOID generateWritePulses(UINT command, UINT payLoadMsb, UINT payLoadLsb);
WORD_VAL generateReadPulses (UINT command);
VOID enterICSP(VOID);
VOID exitICSP(VOID);
BYTE writeEepromByte(MEMORY_ADDRESS address, BYTE data);
#ifdef	__cplusplus
}
#endif

#endif	/* PROGRAMMING_H */

