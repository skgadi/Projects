/* 
 * File:   gsk_funcs.h
 * Author: gadis
 *
 * Created on September 24, 2016, 10:55 AM
 */

#ifndef GSK_FUNCS_H
#define	GSK_FUNCS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

void interrupt SYS_InterruptHigh(void);
void APP_DeviceCustomHIDInitialize();
void USBActivity();
#ifdef	__cplusplus
}
#endif

#endif	/* GSK_FUNCS_H */

