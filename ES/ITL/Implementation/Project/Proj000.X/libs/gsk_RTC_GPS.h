/* 
 * File:   gsk_funs.h
 * Author: gadis
 *
 * Created on August 9, 2016, 4:09 PM
 */

#ifndef GSK_RTC_GPS_H
#define	GSK_RTC_GPS_H

#ifdef	__cplusplus
extern "C" {
#endif


void WriteToRTC(char *Time);
uint32_t ReadRTCAsSec();

int8_t GetOSCTRIM ();
void SetOSCTRIM (int8_t Val);
void AdjustSec (int8_t TimeDiff);

#ifdef	__cplusplus
}
#endif

#endif	/* GSK_RTC_GPS_H */

