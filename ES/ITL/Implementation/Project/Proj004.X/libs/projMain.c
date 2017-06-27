#include "projMain.h"

void Timer_1ms (void) {
    //LATB = 0xFF;
    GLOBAL_I++;
    if (GLOBAL_I==1000) {
        GLOBAL_I -= 1000;
        LATB ^= 0xFF;
        INTERRUPT_PeripheralInterruptEnable();
    }
    if (eusart1RxCount>63) {
        //eusart1RxCount -= 100;
        //GLOBAL_USARTSIZE += 100;
        //if (GLOBAL_USARTSIZE>300) {
            char Date[] = "------";
            char Time[] = "------";
            Lcd_Int(1, 1, eusart1RxCount, 3);
            ReadDateTimeFromBuffer(Date, Time);
            if (ValidateDateTime(Date, Time)) {
                Lcd_Text(2,1, Time);
                ReadTimeFromBuffer(Time);
                Lcd_Text(2,8, Date);
                Lcd_Int(1, 5, GetDay(Date), 3);
            }
            INTERRUPT_PeripheralInterruptDisable();
            eusart1RxCount=0;
            GLOBAL_USARTSIZE = 0;
        //}
    }
}