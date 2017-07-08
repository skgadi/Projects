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


    
#include "../mcc_generated_files/mcc.h"
#include "GenericTypeDefs.h"
#include "ProjectTypeDefs.h"
#include "HD44780.h"
#include "gps.h"
#include "eeprom.h"

    
#define GPS_SWITCH LATCbits.LC1
#define MAX_NO_OF_EVENTS 24
#define MAX_NO_OF_STATES 160
#define MAX_NO_OF_CYCLE_TYPES 17
#define DATA_BUS_SIZE 8

UINT8 GLOBAL_CENTURY = 20;


INT GLOBAL_I =0;
INT GLOBAL_USARTSIZE=0;
void Timer0_10ms (void);
void Timer1_1s (void);
void Timer3_1ms (void);

INT16 TIME_ZONE = 0;
INT16 CYCLE_DELAY = 0;
GSK_YEAR_DAY DAY_LIGHT_START, DAY_LIGHT_END;
GSK_SECOND_IN_DAY GPS_SYNC_EVERY_x_SECONDS, GPS_SYNC_EVERY_DAY_AT_LOCAL_TIME;
UINT8 CENTURY = 20;
UINT8 BLINK_ON_TIME, BLINK_OFF_TIME, BLINK_LAST_X_SECONDS, AUDIO_NORMAL_ON_TIME, AUDIO_NORMAL_OFF_TIME, AUDIO_SPECIAL_ON_TIME, AUDIO_SPECIAL_OFF_TIME, SPECIAL_AUDIO_LAST_X_SECONDS, GPS_SYNC_AT_START;


GSK_EVENT EVENTS[MAX_NO_OF_EVENTS];
GSK_STATE STATES[MAX_NO_OF_STATES];
GSK_CYCLE CYCLES[MAX_NO_OF_CYCLE_TYPES];



//EEPROM settings


#ifdef	__cplusplus
}
#endif

#endif	/* PROJMAIN_H */

