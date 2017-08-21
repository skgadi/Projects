/* 
 * File:   usart_new.h
 * Author: gadis
 *
 * Created on July 28, 2016, 4:46 PM
 */

#ifndef USART_NEW_H
#define	USART_NEW_H

#ifdef	__cplusplus
extern "C" {
#endif

    /*
void init_uart(void);
void init_usart(void);
void putch(unsigned char data);
*/







#define SCI_EIGHT (0)
#define SCI_NINE (1)

unsigned char sci_Init(unsigned long int, unsigned char);
void    sci_PutByte(unsigned char);
unsigned char sci_GetByte(uint8_t timeOutMs);
void    sci_PutNinth(unsigned char);
unsigned char sci_GetNinth(void);
unsigned char sci_GetFERR(void);
unsigned char sci_CheckOERR(void);
 



#ifdef	__cplusplus
}
#endif

#endif	/* USART_NEW_H */

