/* 
 * File:   gps.h
 * Author: gadis
 *
 * Created on June 22, 2017, 2:06 PM
 */

#ifndef GPS_H
#define	GPS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "projMain.h"
#include "../mcc_generated_files/eusart1.h"

#define EUSART1_RX_BUFFER_SIZE 64
extern volatile uint8_t eusart1RxBuffer[EUSART1_RX_BUFFER_SIZE];
    
    
void ReadGPSTime(char *Output);
void ReadTimeFromBuffer (char *Output);
void ReadDateTimeFromBuffer (char *Date, char *Time);
INT8 GetDay (char *Date);
BOOL ValidateDateTime (char *Date, char *Time);
void ValidateDateTime1 (char Date[], char Time[]);

#ifdef	__cplusplus
}
#endif

#endif	/* GPS_H */

