/* 
 * File:   gsk_i2c.h
 * Author: gadis
 *
 * Created on August 1, 2016, 3:17 PM
 */

#ifndef GSK_I2C_H
#define	GSK_I2C_H

#ifdef	__cplusplus
extern "C" {
#endif

void I2C_Master_Init(const unsigned long c);
void I2C_Master_Write(unsigned  d);
unsigned short I2C_Master_Read(unsigned short a);
void I2C_Master_Wait();
void I2C_Master_Start();
void I2C_Master_RepeatedStart();
void I2C_Master_Stop();
char I2C_ReadAtAddress(char DevID, char IntAdd);
void I2C_WriteAtAddress(char DevID, char IntAdd, char data);
void DisplayTimeFromRTC (char y, char x);

#ifdef	__cplusplus
}
#endif

#endif	/* GSK_I2C_H */

