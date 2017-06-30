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
    
typedef union _GSK_WEEK {
    unsigned char val:7;
    struct {
        unsigned char Sunday:1;
        unsigned char Monday:1;
        unsigned char Tuesday:1;
        unsigned char Wednesday:1;
        unsigned char Thursday:1;
        unsigned char Friday:1;
        unsigned char Saturday:1;
    };
} GSK_WEEK;

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
        UINT16 START_TIME;
        UINT16 END_TIME;
        GSK_WEEK SELECTED_WEEKS;
    };
} GSK_EVENT;

typedef union _GSK_STATE
{
    struct {
        UINT8 PERIOD;
        UINT8 PORTS[NO_OF_PORTS];
    };
} GSK_STATE;


#ifdef	__cplusplus
}
#endif

#endif	/* PROJECTTYPEDEFS_H */

