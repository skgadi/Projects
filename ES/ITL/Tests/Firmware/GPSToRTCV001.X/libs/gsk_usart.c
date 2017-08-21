#include "../main.h"

bool UART_Init(const long int baudrate) {
    uint16_t x;
    x = round(_XTAL_FREQ/(baudrate*4.0))-1;
    SPBRG = x;
    SPBRGH = (x>>8);
    BRGH = 1;
    BRG16 = 1;
    CREN = 1;                                     //Enables Continuous Reception
    SYNC = 0;                                     //Setting Asynchronous Mode, ie UART
    SPEN = 1;                                     //Enables Serial Port
    /*TRISC7 = 0;                                 //As Prescribed in Datasheet
    TRISC6 = 0;                                   //As Prescribed in Datasheet*/
    TXEN = 1;                                     //Enables Transmission
    return 1;                                     //Returns 1 to indicate Successful Completion
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
    while(!RCIF);
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
    CREN = 0;
}

void UART_ReadFromGPS_TO(char *Output, char TimeOut) {
    Output[0]=0x00; // This is required to see the read GPS is valid or invalid.
    const char StartCode[7]="$GPRMC,";
    char Pos=0x00;
    char TempChar = 0x00;
    CREN = 0;
    CREN = 1;
    for(uint16_t i=0; i<=768; i++) {
        //Output[i] = UART_Read();
        TempChar = UART_Read_TO(TimeOut);
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
    CREN = 0;
}

char UART_Read_TO(char TimeOut) {
    while(!RCIF && TimeOut !=0) {
        __delay_us(1);
        TimeOut--;
    }
    if (RCIF)
        return RCREG;
    else
        return 0x41;
}

char UART_ReadValidTimeFromGPS_TO(char *Output, char TimeOut) {
    char Result = 0x01;
    UART_ReadFromGPS_TO (Output, TimeOut);
    if (Output[0]<0x30 || Output[0]>0x32)
        Result = 0x00;
    if (Output[1]<0x30 || Output[1]>0x39)
        Result = 0x00;
    if (Output[2]<0x30 || Output[2]>0x36)
        Result = 0x00;
    if (Output[3]<0x30 || Output[3]>0x39)
        Result = 0x00;
    if (Output[4]<0x30 || Output[4]>0x36)
        Result = 0x00;
    if (Output[5]<0x30 || Output[5]>0x39)
        Result = 0x00;
    return Result;
}