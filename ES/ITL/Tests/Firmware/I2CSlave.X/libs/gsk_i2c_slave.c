#include "../main.h"

void interrupt isr(void)
{
  if(SSPIF == 1)
  {
    SSPCON1bits.CKP = 0;

    if ((SSPCON1bits.SSPOV) || (SSPCON1bits.WCOL))
    {
      z = SSPBUF; // Read the previous value to clear the buffer
      SSPCON1bits.SSPOV = 0; // Clear the overflow flag
      SSPCON1bits.WCOL = 0;  // Clear the collision bit
      SSPCON1bits.CKP = 1;
    }

    if(!SSPSTATbits.D_nA && !SSPSTATbits.R_nW)
    {
      z = SSPBUF;
      while(!BF);
      //PORTD = SSPBUF;
      SSPCON1bits.CKP = 1;
      SSPM3 = 0;
    }
    else if(!SSPSTATbits.D_nA && SSPSTATbits.R_nW)
    {
      z = SSPBUF;
      BF = 0;
      //SSPBUF = PORTB ;
      SSPBUF = 0x65 ;
      SSPCON1bits.CKP = 1;
      while(SSPSTATbits.BF);
    }

    SSPIF = 0;
  }
}

void I2C_Slave_Init(short address)
{
  /*ANSELH=0x00;
  ANSEL= 0x00;*/
  SSPSTAT = 0x80;
  SSPADD = address;
  SSPCON1 = 0x36;
  SSPCON2 = 0x01;
  TRISB6 = 1;   //Setting as input as given in datasheet
  TRISB7 = 1;   //Setting as input as given in datasheet
  GIE = 1;
  PEIE = 1;
  SSPIF = 0;
  SSPIE = 1;
}
