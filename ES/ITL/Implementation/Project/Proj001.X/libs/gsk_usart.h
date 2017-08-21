/* 
 * File:   gsk_usart.h
 * Author: gadis
 *
 * Created on August 4, 2016, 10:44 AM
 */

#ifndef GSK_USART_H
#define	GSK_USART_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdbool.h>
    
bool UART_Init(const long int baudrate);
void UART_Write(char data);
bool UART_TX_Empty();
void UART_Write_Text(char *text);
bool UART_Data_Ready();
char UART_Read();
void UART_Read_Text(char *Output, unsigned int length);
void UART_ReadFromGPS(char *Output);
void UART_ReadFromGPS_TO(char *Output, char TimeOut);
bool UART_ReadValidTimeFromGPS_TO(char *Output, char TimeOut);
char UART_Read_TO(char TimeOut);
bool IsValidGPS(char *GPSData);

#ifdef	__cplusplus
}
#endif

#endif	/* GSK_USART_H */

