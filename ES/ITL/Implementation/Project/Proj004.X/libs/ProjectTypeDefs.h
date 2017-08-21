/* 
 * File:   ProjectTypeDefs.h
 * Author: gadis
 *
 * Created on June 28, 2017, 12:21 PM
 */

#ifndef PROJECTTYPEDEFS_H
#define	PROJECTTYPEDEFS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "GenericTypeDefs.h"

#define NO_OF_PORTS 2

typedef enum _SWITCH { OFF = 0, ON } SWITCH;
typedef enum _GSK_AUDIO { AUDIO_OFF = 0, AUDIO_NORMAL, AUDIO_SPECIAL} GSK_AUDIO;
typedef union _GSK_WEEK {
    struct {
        unsigned :1;
        unsigned Sunday:1;
        unsigned Monday:1;
        unsigned Tuesday:1;
        unsigned Wednesday:1;
        unsigned Thursday:1;
        unsigned Friday:1;
        unsigned Saturday:1;
    };
    struct {
        unsigned :1;
        unsigned Val :7;
    };
} GSK_WEEK;

typedef union _GSK_YEAR_DAY {
    struct {
        unsigned Day:5;
        unsigned Month:4;
    };
} GSK_YEAR_DAY;

typedef INT32 GSK_SECOND_IN_DAY;
typedef UINT8 GSK_CYCLE_TYPE;

typedef union _GSK_CYCLE {
    struct {
        UINT16 PERIOD;
        UINT8 START_STATE;
        UINT8 END_STATE;
    };
} GSK_CYCLE;

typedef union _GSK_EVENT
{
    struct {
        GSK_SECOND_IN_DAY START_TIME;
        GSK_SECOND_IN_DAY END_TIME;
        GSK_CYCLE_TYPE CYCLE;
        GSK_WEEK SELECTED_WEEKS;
    };
} GSK_EVENT;

typedef union _GSK_STATE
{
    struct {
        UINT8 PERIOD;
        UINT8 ON[NO_OF_PORTS];
        UINT8 BLINK[NO_OF_PORTS];
        GSK_AUDIO AUDIO;
    };
} GSK_STATE;


#ifdef	__cplusplus
}
#endif

#endif	/* PROJECTTYPEDEFS_H */

