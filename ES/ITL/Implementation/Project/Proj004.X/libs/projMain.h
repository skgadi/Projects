/* 
 * File:   projMain.h
 * Author: gadis
 *
 * Created on June 19, 2017, 2:50 PM
 */

#ifndef PROJMAIN_H
#define	PROJMAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum _SWITCH { OFF = 0, ON } SWITCH;
    
#include "../mcc_generated_files/mcc.h"
#include "GenericTypeDefs.h"
#include "ProjectTypeDefs.h"
#include "HD44780.h"
#include "gps.h"

    
#define GPS_SWITCH LATCbits.LC1
#define MAX_NO_OF_EVENTS 24
#define MAX_NO_OF_STATES 160
#define MAX_NO_OF_CYCLE_TYPES 17

UINT8 GLOBAL_CENTURY = 20;


INT GLOBAL_I =0;
INT GLOBAL_USARTSIZE=0;
void Timer0_10ms (void);
void Timer1_1s (void);
void Timer3_1ms (void);


GSK_EVENT EVENTS[MAX_NO_OF_EVENTS];
GSK_STATE STATES[MAX_NO_OF_STATES];
GSK_CYCLE CYCLES[MAX_NO_OF_CYCLE_TYPES];



//EEPROM settings
 __EEPROM_DATA   (1,2,3,4,5);

#ifdef	__cplusplus
}
#endif

#endif	/* PROJMAIN_H */

