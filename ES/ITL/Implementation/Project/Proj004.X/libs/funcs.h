/* 
 * File:   funcs.h
 * Author: gadis
 *
 * Created on July 17, 2017, 5:27 PM
 */

#ifndef FUNCS_H
#define	FUNCS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "projMain.h"
    
GSK_DATE_TIME IncreaseByASecond (GSK_DATE_TIME dt);
GSK_DATE_TIME IncreaseByADay (GSK_DATE_TIME dt);
GSK_DATE_TIME IncreaseByAMonth (GSK_DATE_TIME dt);
GSK_DATE_TIME IncreaseByAYear (GSK_DATE_TIME dt);
GSK_DATE_TIME DecreaseByASecond (GSK_DATE_TIME dt);
GSK_DATE_TIME DecreaseByADay (GSK_DATE_TIME dt);
GSK_DATE_TIME DecreaseByAMonth (GSK_DATE_TIME dt);
GSK_DATE_TIME DecreaseByAYear (GSK_DATE_TIME dt);
GSK_DATE_TIME AdjustDayLightSaving (GSK_DATE_TIME dt);
BOOL ReadGPS_DATE_TIME (void);
INT32 TimeTextToSecond (char *Time);
void SwitchOnGPS (void);
void VerifyForGPSOnTIme (void);
void ReadGPS (void);
void StopGPS (void);
void TestGPSStartCondition (void);
INT8 GetEventNumber(void);
UINT8 GetThisCycle (void);
#ifdef	__cplusplus
}
#endif

#endif	/* FUNCS_H */

