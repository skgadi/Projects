#include "../main.h"

void GetCumulativePeriodsForStates(void) {
    char i, j;
    for (i=0; i< NO_OF_TYPES_OF_STATES; i++) {
        STATE_CUMULATIVE_PERIODS[i] = 0;
        if (i==0)
            j = 0;
        else
            j = STATE_BREAKS[GetPrevCycle(i)];
        for (; j < STATE_BREAKS[i]; j++) {
            STATE_CUMULATIVE_PERIODS[i] = STATE_CUMULATIVE_PERIODS[i]
                    + STATE_PERIODS[j];
        }
    }
}

UINT8 GetPrevCycle (UINT8 cycle) {
    UINT8 PrevCycle;
    if (cycle > 0)
        PrevCycle = cycle - 1;
    else
        PrevCycle = MAX_NO_OF_TYPES_OF_CYCLES - 1;
    return PrevCycle;
}

void GetCycle (void) {
    char PrevCycle;
    for (char i = 0; i < MAX_NO_OF_TYPES_OF_CYCLES; i++) {
        PrevCycle = GetPrevCycle(i);
        if (C[PrevCycle] <= C[i]) {
            if ((S>C[PrevCycle]) && (S<=C[i])) {
                CYCLE_TYPE = i;
            }
        } else {
            if ((S>C[PrevCycle]) || (S<=C[i])) {
                CYCLE_TYPE = i;
            }
        }
    }
    PREV_CYCLE_TYPE = GetPrevCycle(CYCLE_TYPE);
}

int32_t GetModValue (int32_t a, int32_t b) {
    if (a<0)
        a = a*-1;
    uint32_t TempVar = a/b;
    return (a-TempVar*b);
}

void SwitchGPS(bool a) {
    RC1 = a;
}

INT16 GetAbs(INT16 a) {
    if (a<0)
        a=a*(-1);
    return a;
}

INT8 GetSign(INT16 a) {
    if (a<0)
        return -1;
    else
        return 0;
}

void DelayInUSec(UINT8 a) {
    for (UINT8 i = 0; i<a; i++);
        //__delay_us(1);
}

INT32 GetTimePeriod(INT32 PrevTime, INT32 PresentTime) {
    if (PrevTime<=PresentTime)
        return (PresentTime - PrevTime);
    else
        return (SECONDS_IN_A_DAY-PrevTime + PresentTime);
}

void ResetTimer (void) {
    TMR1 = -1000;
    PIR1bits.TMR1IF = 0;
    PIE1bits.TMR1IE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    T1CONbits.TMR1ON = 1;
    T1CONbits.TMR1CS = 0;
    T1CONbits.T1CKPS = 0x0;
}

void StopTheTimer (void) {
    INTCONbits.PEIE = 0;
    INTCONbits.GIE = 0;
}
