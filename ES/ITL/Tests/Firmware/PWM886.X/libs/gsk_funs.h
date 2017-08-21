/* 
 * File:   gsk_funs.h
 * Author: gadis
 *
 * Created on August 9, 2016, 4:09 PM
 */

#ifndef GSK_FUNS_H
#define	GSK_FUNS_H

#ifdef	__cplusplus
extern "C" {
#endif


void WriteToRTC(char *Time);
uint32_t ReadRTCAsSec();

int8_t GetOSCTRIM ();
void SetOSCTRIM (int8_t Val);
void AdjustSec (int8_t TimeDiff);
uint32_t GPS2Sec(char *GPSTime);

#ifdef	__cplusplus
}
#endif

#endif	/* GSK_FUNS_H */

