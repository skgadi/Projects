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

bool UART_ReadValidTimeFromGPS_TO(char *Output, char TimeOut) {
    UART_ReadFromGPS_TO (Output, TimeOut);
    return IsValidGPS(Output);
}


bool IsValidGPS(char *GPSData) {
    bool Result;
    if (GPSData[0]<0x30 || GPSData[0]>0x32)
        Result = false;
    if (GPSData[1]<0x30 || GPSData[1]>0x39)
        Result = false;
    if (GPSData[2]<0x30 || GPSData[2]>0x36)
        Result = false;
    if (GPSData[3]<0x30 || GPSData[3]>0x39)
        Result = false;
    if (GPSData[4]<0x30 || GPSData[4]>0x36)
        Result = false;
    if (GPSData[5]<0x30 || GPSData[5]>0x39)
        Result = false;
    return Result;
}

INT32 ReadGPSToS(char TimeOut){
    INT32 Sec;
    char Output[6];
    if (UART_ReadValidTimeFromGPS_TO(Output, TimeOut)) {
        Sec = (INT32)(Output[0] - 0x30)*10*60*60;
        Sec += (INT32)(Output[1] - 0x30)*1*60*60;
        Sec += (INT32)(Output[2] - 0x30)*10*60;
        Sec += (INT32)(Output[3] - 0x30)*1*60;
        Sec += (INT32)(Output[4] - 0x30)*10;
        Sec += (INT32)(Output[5] - 0x30);
        return Sec;
    } else
        return -1;
        
}
