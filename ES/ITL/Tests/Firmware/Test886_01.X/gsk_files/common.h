/* 
 * File:   common.h
 * Author: gadis
 *
 * Created on July 24, 2016, 11:23 AM
 */

#ifndef COMMON_H
#define	COMMON_H


#include <xc.h>
#include "pin_manager.h"

#include <stdint.h>
#include <stdbool.h>

#include "tmr0.h"
#include "interrupt_manager.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define _XTAL_FREQ  20000000
void SYSTEM_Initialize(void);
void OSCILLATOR_Initialize(void);



#ifdef	__cplusplus
}
#endif

#endif	/* COMMON_H */

