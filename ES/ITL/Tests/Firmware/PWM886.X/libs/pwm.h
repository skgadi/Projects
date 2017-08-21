/* 
 * File:   pwm.h
 * Author: gadis
 *
 * Created on September 20, 2016, 4:44 PM
 */

#ifndef PWM_H
#define	PWM_H

#ifdef	__cplusplus
extern "C" {
#endif

int PWM_Max_Duty(long freq);
PWM1_Init(long fre);
PWM2_Init(long fre);
PWM1_Duty(unsigned int duty);
PWM2_Duty(unsigned int duty);
PWM1_Start();
PWM1_Stop();
PWM2_Start();
PWM2_Stop();


#ifdef	__cplusplus
}
#endif

#endif	/* PWM_H */

