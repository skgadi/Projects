#include "projMain.h"

void Timer0_10ms (void) {
    //LATB = 0xFF;
    GLOBAL_I++;
    if (GLOBAL_I%10==0) {
        LATB ^= 0xFF;
    }
    if (GLOBAL_I%5000==0) {
        //GPS_SWITCH = !GPS_SWITCH;
      /*  char Time[] = "------";
        ReadGPSTime(Time);
        Lcd_Text(2,1, Time);*/
    }
}


void Timer1_1s (void) {
    //if (eusart1RxCount>120) {
        //eusart1RxCount -= 100;
        //GLOBAL_USARTSIZE += 100;
        //if (GLOBAL_USARTSIZE>300) {
    //INTERRUPT_PeripheralInterruptEnable();
    //GLOBAL_I++;
    /*if (GLOBAL_I%5 == 0) {
        Lcd_Int(1, 1, GLOBAL_I, 3);
        char Date[] = "------";
        char Time[] = "------";
        ReadDateTimeFromBuffer(Date, Time);
        if (ValidateDateTime(Date, Time)) {
            Lcd_Text(2,1, Time);
            ReadTimeFromBuffer(Time);
            Lcd_Text(2,8, Date);
            Lcd_Int(1, 5, GetDay(Date), 3);
            Lcd_Text(1, 10, ":)");
            //INTERRUPT_PeripheralInterruptDisable();
        } else {
            Lcd_Text(2,1, Time);
            Lcd_Text(1, 10, ":(");
        }
        
    }*/
    /*char Time[] = "------";
    ReadGPSTime(Time);
    Lcd_Text(2,1, Time);*/
        //}
    //}
}