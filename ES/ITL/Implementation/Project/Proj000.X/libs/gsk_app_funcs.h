/* 
 * File:   gsk_app_funcs.h
 * Author: gadis
 *
 * Created on October 11, 2016, 9:20 AM
 */

#ifndef GSK_APP_FUNCS_H
#define	GSK_APP_FUNCS_H

#ifdef	__cplusplus
extern "C" {
#endif

void DetermineCycleChange();
bool ChangeTheCycle();
void GetCycleSecond();
void GetStates();
void GetCyclePeriod();
void PutOnOff();
int32_t GetModValue (int32_t a, int32_t b);
int32_t Sign (int32_t a);
int32_t AbsValue (int32_t a);
#ifdef	__cplusplus
}
#endif

#endif	/* GSK_APP_FUNCS_H */

