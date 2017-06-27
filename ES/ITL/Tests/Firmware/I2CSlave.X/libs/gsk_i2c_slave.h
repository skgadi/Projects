/* 
 * File:   gsk_i2c_slave.h
 * Author: gadis
 *
 * Created on August 1, 2016, 4:39 PM
 */

#ifndef GSK_I2C_SLAVE_H
#define	GSK_I2C_SLAVE_H

#ifdef	__cplusplus
extern "C" {
#endif


void interrupt isr(void);
void I2C_Slave_Init(short address);


#ifdef	__cplusplus
}
#endif

#endif	/* GSK_I2C_SLAVE_H */

