/* 
 * File:   interrupt_manager.h
 * Author: gadis
 *
 * Created on July 24, 2016, 4:21 PM
 */

#ifndef INTERRUPT_MANAGER_H
#define	INTERRUPT_MANAGER_H

#ifdef	__cplusplus
extern "C" {
#endif


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    This macro will enable global interrupts.
 * @Example
    INTERRUPT_GlobalInterruptEnable();
 */
#define INTERRUPT_GlobalInterruptEnable() (INTCONbits.GIE = 1)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    This macro will disable global interrupts.
 * @Example
    INTERRUPT_GlobalInterruptDisable();
 */
#define INTERRUPT_GlobalInterruptDisable() (INTCONbits.GIE = 0)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    This macro will enable peripheral interrupts.
 * @Example
    INTERRUPT_PeripheralInterruptEnable();
 */
#define INTERRUPT_PeripheralInterruptEnable() (INTCONbits.PEIE = 1)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    This macro will disable peripheral interrupts.
 * @Example
    INTERRUPT_PeripheralInterruptDisable();
 */
#define INTERRUPT_PeripheralInterruptDisable() (INTCONbits.PEIE = 0)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Main interrupt service routine. Calls module interrupt handlers.
 * @Example
    INTERRUPT_InterruptManager();
 */
void interrupt INTERRUPT_InterruptManager(void);


#ifdef	__cplusplus
}
#endif

#endif	/* INTERRUPT_MANAGER_H */

