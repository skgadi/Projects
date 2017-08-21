/* 
 * File:   eeprom.h
 * Author: gadis
 *
 * Created on October 4, 2016, 11:34 AM
 */

#ifndef EEPROM_H
#define	EEPROM_H

#ifdef	__cplusplus
extern "C" {
#endif

void ReadVars ();
void ReadC (uint8_t *);
void ReadC_D (uint8_t *);
void ReadC_ON (uint8_t *);
void ReadC_BLINK (uint8_t *);


#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_H */

