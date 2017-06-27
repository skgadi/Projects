#include "../main.h"

/*
#define _BAUD_RATE  9600        // Baud Rate
 
// Calculate Value for SPBRGH:SPBRG
#define SPBRG_X1   ((((10UL*(_XTAL_FREQ)/(64UL*(_BAUD_RATE)))+5)/10UL)-1)  // Low Speed
#define SPBRG_X2   ((((10UL*(_XTAL_FREQ)/(16UL*(_BAUD_RATE)))+5)/10UL)-1)  // Mid Speed
#define SPBRG_X3   ((((10UL*(_XTAL_FREQ)/( 4UL*(_BAUD_RATE)))+5)/10UL)-1)  // High Speed
 
// Actual Baud Rate x 100
#define BAUD_RATE1   (100UL*(_XTAL_FREQ)/(64UL*(SPBRG_X1+1)))
#define BAUD_RATE2   (100UL*(_XTAL_FREQ)/(16UL*(SPBRG_X2+1)))
#define BAUD_RATE3   (100UL*(_XTAL_FREQ)/( 4UL*(SPBRG_X3+1)))
 
#define DESIRED_RATE (100UL*(_BAUD_RATE))
 
// Calculate Baud Rate Error in Parts Per 100,000
#define PP100K  100000UL
 
#if BAUD_RATE1 >= DESIRED_RATE
    #define BAUD_ERR1   (PP100K*(BAUD_RATE1-DESIRED_RATE)/DESIRED_RATE)
#else
    #define BAUD_ERR1   (PP100K*(DESIRED_RATE-BAUD_RATE1)/DESIRED_RATE)
#endif
#if BAUD_RATE2 >= DESIRED_RATE
    #define BAUD_ERR2   (PP100K*(BAUD_RATE2-DESIRED_RATE)/DESIRED_RATE)
#else
    #define BAUD_ERR2   (PP100K*(DESIRED_RATE-BAUD_RATE2)/DESIRED_RATE)
#endif
#if BAUD_RATE3 >= DESIRED_RATE
    #define BAUD_ERR3   (PP100K*(BAUD_RATE3-DESIRED_RATE)/DESIRED_RATE)
#else
    #define BAUD_ERR3   (PP100K*(DESIRED_RATE-BAUD_RATE3)/DESIRED_RATE)
#endif
 
// Choose Setting With Minimum Baud Rate Error
#if BAUD_ERR3 <= BAUD_ERR1  &&  BAUD_ERR3 <= BAUD_ERR2  &&  SPBRG_X3 <= 0xFFFF
    #define BAUD_ERR    BAUD_ERR3
    #define BRG_SPBRG   SPBRG_X3
    #define BRG_BRG16   1
    #define BRG_BRGH    1
#elif BAUD_ERR1 <= BAUD_ERR2  &&  BAUD_ERR1 <= BAUD_ERR3  &&  SPBRG_X1 <= 0xFF
    #define BAUD_ERR    BAUD_ERR1
    #define BRG_SPBRG   SPBRG_X1
    #define BRG_BRG16   0
    #define BRG_BRGH    0
#else
    #define BAUD_ERR    BAUD_ERR2
    #define BRG_SPBRG   SPBRG_X2
    #define BRG_BRG16   ( (BRG_SPBRG <= 0xFF) ? 0 : 1 )
    #define BRG_BRGH    ( (BRG_SPBRG <= 0xFF) ? 1 : 0 )
#endif
 
#if BAUD_ERR > 5*PP100K
    #error  "Baud rate error exceeds 5%"
#endif
#if BRG_SPBRG > 0xFFFF
    #error  "Baud rate value overflows SPBRGH:SPBRG"
#endif
 
// Setup Registers Associated With Baud Rate Generator
#define BaudRateGen() \
    do { \
        SPBRGH = BRG_SPBRG >> 8; \
        SPBRG = BRG_SPBRG; \
        TXSTAbits.BRGH = BRG_BRGH; \
        BAUDCTLbits.BRG16 = BRG_BRG16; \
    } while (0)
 
void init_uart(void)
{
    SPBRGH = BRG_SPBRG >> 8;
    SPBRG = BRG_SPBRG;
    BAUDCTL = 0b00000000 | (BRG_BRG16<<_BAUDCTL_BRG16_POSN);  // BRG16
    TXSTA = 0b00100000 | (BRG_BRGH<<_TXSTA_BRGH_POSN);  // 8-bit, TXEN, async, BRGH
    RCSTA = 0b10010000;                                 // SPEN, 8-bit, CREN
}

void init_usart(void)
{
    TXSTA = 0b00100000;     // 8-bit, TXEN, async, BRGH=0
    RCSTA = 0b10010000;     // SPEN, 8-bit, CREN
    BAUDCTL = 0b00000000;   // BRG16=0
    BaudRateGen();          // init SPBRG, BRGH, BRG16
}
 
void putch(unsigned char data)
{
    while (!TXIF)           // wait until TXREG empty
        ;
    TXREG = data;           // send character
}
 




*/













unsigned char
sci_Init(unsigned long int baud, unsigned char ninebits)
{
 int X;
 unsigned long tmp;
 
 /* calculate and set baud rate register */
 /* for asynchronous mode */
 tmp = 16UL * baud;
 X = (int)(_XTAL_FREQ/tmp) - 1;
 if((X>255) || (X<0))
 {
  tmp = 64UL * baud;
  X = (int)(_XTAL_FREQ/tmp) - 1;
  if((X>255) || (X<0))
  {
   return 1; /* panic - baud rate unobtainable */
  }
  else
   BRGH = 0; /* low baud rate */
 }
 else
  BRGH = 1; /* high baud rate */
 SPBRG = X; /* set the baud rate */

 SYNC = 0; /* asynchronous */
 SPEN = 1; /* enable serial port pins */
 CREN = 1; /* enable reception */
 SREN = 0; /* no effect */
 TXIE = 0; /* disable tx interrupts */
 RCIE = 0; /* disable rx interrupts */
 TX9 = ninebits?1:0; /* 8- or 9-bit transmission */
 RX9 = ninebits?1:0; /* 8- or 9-bit reception */
 TXEN = 1; /* enable the transmitter */

 return 0;
}

void
sci_PutByte(unsigned char byte)
{
 while(!TXIF) /* set when register is empty */
  continue;
 TXREG = byte;

 return;
}


//Modified by SKGadi
unsigned char
sci_GetByte(uint8_t timeOutMs)
{
    uint8_t t=0;
    while(!RCIF) {/* set when register is not empty */
        if (t>timeOutMs)
            return 66;
        else {
            t++;
            __delay_ms(1);
        }
            
        
    }

    return RCREG; /* RXD9 and FERR are gone now */
}

unsigned char
sci_CheckOERR(void)
{
 if(OERR) /* re-enable after overrun error */
 {
  CREN = 0;
  CREN = 1;
  return 1;
 }
 
 return 0;
}

#define sci_PutNinth(bitnine) (TX9D = bitnine?1:0;)

unsigned char
sci_GetNinth(void)
{
 while(!RCIF)
  continue;
 
 return RX9D; /* RCIF is not cleared until RCREG is read */
}

unsigned char
sci_GetFERR(void)
{
 while(!RCIF)
  continue;
 
 return FERR; /* RCIF is not cleared until RCREG is read */
}
