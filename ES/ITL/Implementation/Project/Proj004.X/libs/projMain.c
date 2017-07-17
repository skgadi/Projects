#include "projMain.h"

void Timer0_10ms (void) {
    //LATB = 0xFF;
    GLOBAL_I++;
    if (GLOBAL_I%10==0) {
        LATB ^= 0xFF;
    }
    CENTI_SECOND_COUNT++;
    if (CENTI_SECOND_COUNT == 100) {
        CENTI_SECOND_COUNT = 0;
        DATE_TIME = IncreaseByASecond(DATE_TIME);
    }
}

