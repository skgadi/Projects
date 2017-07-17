#include "projMain.h"
#include "gps.h"

void ShowRawData (void){
    int i=0;
    do {
        if (EUSART1_DataReady){
            Lcd_CharCP(EUSART1_Read());
            i=0;
        } else
            __delay_us(20);
        i++;
    } while(i<1000);
}
void ReadGPSTime(char *Time) {
    const char StartCode[7]="$GPRMC,";
    char Pos=0x00;
    char TempChar = 0x00;
    int i=0;
    do {
        if (EUSART1_DataReady){
            i=0;
            TempChar = EUSART1_Read();
            if ((Pos>=0x07) & (Pos<=0x0c)) {
                Time[Pos-0x07]= TempChar;
                Pos++;
            } else if ((StartCode[Pos] == TempChar) && (Pos<0x07)) {
                Pos++;
            } else if (Pos>0x0c)
                break;
            else
                Pos=0;
        } else
            __delay_us(20);
        i++;
    } while(i<1000);
    return;
}
void ReadGPSDateTime(char *Date, char *Time) {
    const char StartCode[7]="$GPRMC,";
    char Pos=0x00;
    char TempChar = 0x00;
    int i=0;
    UINT8 Commas=0;
    do {
        if (EUSART1_DataReady){
            i=0;
            TempChar = EUSART1_Read();
            if ((Pos>=0x07) & (Pos<=0x0c)) {
                Time[Pos-0x07]= TempChar;
                Pos++;
            } else if ((StartCode[Pos] == TempChar) && (Pos<0x07)) {
                Pos++;
            } else if (Pos>0x0c){
                if (Commas<8) {
                    if (TempChar == 0x2C)
                        Commas++;
                } else {
                    if ((Pos-0x0d)<6) {
                        Date[Pos-0x0d] = TempChar;
                        Pos++;
                    } else
                        return;
                }
            } else
                Pos=0;
        } else
            __delay_us(20);
        i++;
    } while(i<1000);
}
/*
void ReadTimeFromBuffer (char *Output) {
    const char StartCode[7]="$GPRMC,";
    char Pos=0x00;
    char TempChar = 0x00;
    for(INT i=0; i<EUSART1_RX_BUFFER_SIZE; i++) {
        //Output[i] = UART_Read();
        TempChar = eusart1RxBuffer[i];
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

void ReadDateTimeFromBuffer (char *Date, char *Time) {
    char day;
    const char StartCode[7]="$GPRMC,";
    char Pos=0x00;
    char TempChar = 0x00;
    INT i;
    for(i=0; i<EUSART1_RX_BUFFER_SIZE; i++) {
        //Output[i] = UART_Read();
        TempChar = eusart1RxBuffer[i];
        if ((Pos>=0x07) & (Pos<=0x0c)) {
            Time[Pos-0x07]= TempChar;
            Pos++;
        } else if ((StartCode[Pos] == TempChar) && (Pos<0x07)) {
            Pos++;
        } else if (Pos>0x0c)
            break;
        else
            Pos=0;
    }
    Pos=0;
    UINT8 Commas=0;
    for (; i<EUSART1_RX_BUFFER_SIZE; i++) {
        TempChar = eusart1RxBuffer[i];
        if (Commas<8) {
            if (eusart1RxBuffer[i] == 0x2C)
                Commas++;
        } else {
            if (Pos<6) {
                Date[Pos] = eusart1RxBuffer[i];
                Pos++;
            } else
                break;
        }
    }
}
*/

INT8 GetDay (char *Date) {
    UINT8 d = (Date[0]-0x30)*10 + (Date[1]-0x30);
    UINT8 m = (Date[2]-0x30)*10 + (Date[3]-0x30);
    INT y = (Date[4]-0x30)*10 + (Date[5]-0x30) + GLOBAL_CENTURY*100;
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

BOOL ValidateDateTime (char *Date, char *Time) {
    INT8 Item;
    /*for (INT i=0; i<6; i++) {
        if ((Date[i]>=0x30) && (Date[i]<=0x39))
            return false;
        if ((Time[i]>=0x30) && (Time[i]<=0x39))
            return false;
    }*/
    Item = (Date[0]-0x30)*10 + (Date[1]-0x30);
    if (Item<=0 || Item>31) return false;
    Item = (Date[2]-0x30)*10 + (Date[3]-0x30);
    if (Item<=0 || Item>12) return false;
    Item = (Date[4]-0x30)*10 + (Date[5]-0x30);
    if (Item<=0 || Item>99) return false;

    Item = (Time[0]-0x30)*10 + (Time[1]-0x30);
    if (Item<=0 || Item>23) return false;
    Item = (Time[2]-0x30)*10 + (Time[3]-0x30);
    if (Item<=0 || Item>59) return false;
    Item = (Time[4]-0x30)*10 + (Time[5]-0x30);
    if (Item<=0 || Item>59) return false;
    
    return true;
}

void ValidateDateTime1 (char Date[], char Time[]) {
    UINT8 Item;
    /*for (INT i=0; i<6; i++) {
        if ((Date[i]>=0x30) && (Date[i]<=0x39))
            return false;
        if ((Time[i]>=0x30) && (Time[i]<=0x39))
            return false;
    }*/
    Item = (Date[0]-0x30)*10 + (Date[1]-0x30);
    if (Item>31) return ;
    Item = (Date[2]-0x30)*10 + (Date[3]-0x30);
    if (Item>12) return ;
    Item = (Date[4]-0x30)*10 + (Date[5]-0x30);
    if (Item>99) return ;

    Item = (Time[0]-0x30)*10 + (Time[1]-0x30);
    if (Item>23) return ;
    Item = (Time[2]-0x30)*10 + (Time[3]-0x30);
    if (Item>59) return ;
    Item = (Time[4]-0x30)*10 + (Time[5]-0x30);
    if (Item>59) return ;
    
    return ;
}