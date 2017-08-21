/* 
 * File:   programming.h
 * Author: gadis
 *
 * Created on May 31, 2017, 9:48 AM
 */

#ifndef PROGPIC18F26K40_H
#define	PROGPIC18F26K40_H

#ifdef	__cplusplus
extern "C" {
#endif

/*Definitions*/
#include "GenericTypeDefs.h"
typedef enum _SEND_DIRECTION { MSBTOLSB = 0, LSBTOMSB } SEND_DIRECTION;
typedef enum _LATCH_TIMED { INTERNALLY = 0, EXTERNALLY } LATCH_TIMED;

/*Delays*/

// Zero delays for T_LZD, T_HZD, T_ERAB, T_ERAR, T_PINT
#define PIC18F26K40_DELAY_MIN()          (__delay_us(1)) // T_ENTS, T_CKL, T_CKH, T_DS, T_DH
#define PIC18F26K40_DELAY_T_ENTH()       (__delay_us(250))
#define PIC18F26K40_DELAY_TENTH()        (__delay_us(250))
#define PIC18F26K40_DELAY_T_PEXT_1()     (__delay_ms(2)) 
#define PIC18F26K40_DELAY_T_PEXT_2()     (__delay_us(100))
#define PIC18F26K40_DELAY_T_DIS()        (__delay_us(100))
#define PIC18F26K40_DELAY_T_EXIT()       (__delay_us(1))
#define PIC18F26K40_DELAY_T_DLY()        (__delay_us(1))
#define PIC18F26K40_DELAY_T_PINT()        (__delay_us(1))

/*Configuring programming bus*/
//#define POLL_WR_FOR_x_TIMES 5
#define USE_LOW_VOLTAGE_PROGRAMMING TRUE

#define PIC18F26K40_MCLR_PORT PORTCbits.RC7
#define PIC18F26K40_PGD_PORT  PORTCbits.RC6
#define PIC18F26K40_PGC_PORT  PORTCbits.RC5
//#define PPIN_PGM_PORT PORTBbits.RB5

#define PIC18F26K40_MCLR_LAT LATCbits.LATC7
#define PIC18F26K40_PGD_LAT  LATCbits.LATC6
#define PIC18F26K40_PGC_LAT  LATCbits.LATC5
//#define PPIN_PGM_LAT LATBbits.LATB5

#define PIC18F26K40_MCLR_TRIS TRISCbits.TRISC7
#define PIC18F26K40_PGD_TRIS  TRISCbits.TRISC6
#define PIC18F26K40_PGC_TRIS  TRISCbits.TRISC5
//#define PPIN_PGM_TRIS TRISBbits.TRISB5

/*Functions*/
/*BYTE PIC18F26K40_readEepromByte(MEMORY_ADDRESS x);
VOID PIC18F26K40_setTrisToOut (VOID);
VOID PIC18F26K40_enterLowVoltageICSP(VOID);
VOID PIC18F26K40_exitLowVoltageICSP(VOID);
VOID PIC18F26K40_enterHighVoltageICSP(VOID);
VOID PIC18F26K40_exitHighVoltageICSP(VOID);
VOID PIC18F26K40_generateWritePulses(UINT command, UINT payLoadMsb, UINT payLoadLsb);
WORD_VAL PIC18F26K40_generateReadPulses (UINT command);
VOID PIC18F26K40_enterICSP(VOID);
VOID PIC18F26K40_exitICSP(VOID);
BYTE PIC18F26K40_writeEepromByte(MEMORY_ADDRESS address, BYTE data);*/
VOID PIC18F26K40_setTrisToOut (VOID);
VOID PIC18F26K40_enterLowVoltageProg (VOID);
VOID PIC18F26K40_exitLowVoltageProg (VOID);
VOID PIC18F26K40_sendByte(BYTE info, SEND_DIRECTION direction);
DWORD_VAL PIC18F26K40_readThreeBytes(SEND_DIRECTION direction, BOOL IncreasePC);
VOID PIC18F26K40_loadPC (DWORD_VAL);
VOID PIC18F26K40_loadDataIntoNVM (DWORD_VAL data, BOOL IncreasePC, SEND_DIRECTION LatchType);
VOID PIC18F26K40_sendByteMsbToLsb(BYTE info);
#ifdef	__cplusplus
}
#endif

#endif	/* PROGPIC18F26K40_H */

