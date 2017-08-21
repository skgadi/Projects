/* 
 * File:   gsk_algo_funcs.h
 * Author: gadis
 *
 * Created on November 3, 2016, 4:48 PM
 */

#ifndef GSK_ALGO_FUNCS_H
#define	GSK_ALGO_FUNCS_H

#ifdef	__cplusplus
extern "C" {
#endif

void GetCumulativePeriodsForStates(void);
void GetCycle (void);
UINT8 GetPrevCycle (UINT8 cycle);
int32_t GetModValue (int32_t a, int32_t b);
void SwitchGPS(bool a);
INT16 GetAbs(INT16 a);
INT8 GetSign(INT16 a);
void DelayInUSec(UINT8 a);
INT32 GetTimePeriod(INT32 PrevTime, INT32 PresentTime);
void ResetTimer (void);
void StopTheTimer (void);
#ifdef	__cplusplus
}
#endif

#endif	/* GSK_ALGO_FUNCS_H */

