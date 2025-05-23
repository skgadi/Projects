#include "../main.h"

bool UART_Init(const long int baudrate) {
  unsigned int x;
  x = (_XTAL_FREQ - baudrate*64)/(baudrate*64);   //SPBRG for Low Baud Rate
  if(x>255)                                       //If High Baud Rage Required
  {
    x = (_XTAL_FREQ - baudrate*16)/(baudrate*16); //SPBRG for High Baud Rate
    BRGH = 1;                                     //Setting High Baud Rate
  }
  if(x<256)
  {
    SPBRG = x;                                    //Writing SPBRG Register
    SYNC = 0;                                     //Setting Asynchronous Mode, ie UART
    SPEN = 1;                                     //Enables Serial Port
    TRISC7 = 1;                                   //As Prescribed in Datasheet
    TRISC6 = 1;                                   //As Prescribed in Datasheet
    CREN = 1;                                     //Enables Continuous Reception
    TXEN = 1;                                     //Enables Transmission
    return 1;                                     //Returns 1 to indicate Successful Completion
  }
  return 0;                                       //Returns 0 to indicate UART initialization failed
}

void UART_Write(char data) {
  while(!TRMT);
  TXREG = data;
}

bool UART_TX_Empty() {
  return TRMT;
}

void UART_Write_Text(char *text) {
  int i;
  for(i=0;text[i]!='\0';i++)
    UART_Write(text[i]);
}

bool UART_Data_Ready() {
  return RCIF;
}

char UART_Read() {
    while(!RCIF);/*{
        i++;
        __delay_ms(1);
        if (i==TimeOut)
            return 0x00;
    }*/
    return RCREG;
}

void UART_Read_Text(char Output[], unsigned int length) {
  unsigned int i;
  CREN = 0;
  __delay_us(10);
  CREN = 1;
  for(int i=0;i<length;i++)
          Output[i] = UART_Read();
  CREN = 0;
  //UART_Flush();
}

void UART_ReadFromGPS(char *Output) {
    /*Output[0] = 0x47;
    Output[1] = 0x48;
    Output[2] = 0x49;*/
    
    const char StartCode[7]="$GPRMC,";
    char Pos=0x00;
    char TempChar = 0x00;
    CREN = 0;
    CREN = 1;
    for(char i=0; i<255; i++) {
        //Output[i] = UART_Read();
        TempChar = UART_Read();
        if ((Pos>=0x07) & (Pos<=0x0c)) {
            Output[Pos-0x07]= TempChar;
            Pos++;
        } else if ((StartCode[Pos] == TempChar) && (Pos<0x07)) {
            Pos++;
        } else if (Pos>0x0c)
            return;
        else
            Pos=0;
    }
}

