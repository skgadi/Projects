/* 
 * File:   usart00.h
 * Author: gadis
 *
 * Created on August 4, 2016, 6:02 PM
 */

#ifndef USART00_H
#define	USART00_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../main.h"
    
// config communications here
#define BAUD 9600
#define FREQUENCY 4000000L

// refer to data sheet to set these. Typical settings are below
#define MULTIPLIER 16UL // muiltiplier is typically 64UL, 16UL or 4UL
#define HIGH_SPEED 1 // refer to BRGH in datasheet to determine if you need high speed

// not common
#define NINE 0     /* Use 9bit communication? FALSE=8bit */

// Set TX & RX pins. Below are for 16f628; update for your chip
#define RX_PIN TRISB1
#define TX_PIN TRISB2


/*
 * The rest is calculated, so no need to edit below this line
 */

#define DIVIDER ((int)(FREQUENCY/(MULTIPLIER * BAUD) -1))

#if NINE == 1
#define NINE_BITS 0x40
#else
#define NINE_BITS 0
#endif

#if HIGH_SPEED == 1
#define SPEED 0x4
#else
#define SPEED 0
#endif

// basic settings to enable serial
// RCSTA is 0x90: 10010000 (SPEN RX9 SREN CREN ADEN FERR OERR RX9D)
// TXSTA is 0x20: 00100000 (CSRC TX9 TXEN SYNC - BRGH TRMT TX9D)
#define RCSTA_DEFAULT 0x90
#define TXSTA_DEFAULT 0x20

/* Serial initialization */
#define init_comms()\
    RX_PIN = 1;    \
    TX_PIN = 1;          \
    SPBRG = DIVIDER;         \
    RCSTA = (NINE_BITS|RCSTA_DEFAULT);    \
    TXSTA = (SPEED|NINE_BITS|TXSTA_DEFAULT)

void putch(unsigned char);
unsigned char getch(void);
unsigned char getche(void);


#ifdef	__cplusplus
}
#endif

#endif	/* USART00_H */

