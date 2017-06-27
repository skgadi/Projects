#include "../main.h"

extern volatile int32_t C[MAX_NO_OF_CYCLES];
extern volatile int32_t S;
extern volatile BYTE_VAL CONFIG0;
extern volatile uint16_t C_T;
extern volatile uint8_t C_ON[MAX_NO_OF_CYCLES][MAX_NO_OF_STATES][3];
extern volatile uint8_t Cycle;
extern volatile uint16_t C_S;
extern volatile uint8_t PresentState;
extern volatile uint8_t C_BLINK[MAX_NO_OF_CYCLES][MAX_NO_OF_STATES][3];
extern volatile int32_t S_InUse;

void DetermineCycleChange (){
    if ((CONFIG0.bits.b0) == 0) {
        uint32_t DiffCycleTime;
        uint32_t MinDiffCycleTime;
        char PrevCycle;
        if (Cycle > 0)
            PrevCycle = Cycle - 1;
        else
            PrevCycle = MAX_NO_OF_CYCLES - 1;
        char MinPos=MAX_NO_OF_CYCLES;
        for (char i = 0; i < MAX_NO_OF_CYCLES; i++) {
            if (i > 0)
                PrevCycle = i - 1;
            else
                PrevCycle = MAX_NO_OF_CYCLES - 1;
            if (C[PrevCycle] < C[i]) {
                if ((S>C[PrevCycle]) && (S<=C[i])) {
                    MinPos = i;
                }
            } else {
                if (((S>C[PrevCycle]) && (S<=SECONDS_IN_A_DAY)) || (S<=SECONDS_IN_A_DAY)) {
                    MinPos = i;
                }
            }
        }
        WriteLongInt(1,5,MinPos,2,0);
        if (MinPos != Cycle)
            CONFIG0.bits.b0 = 1;
    }
}

bool ChangeTheCycle() {
    if ((CONFIG0.bits.b0 == 1) && (C_S == 0)) {
        CONFIG0.bits.b0 = 0;
        Cycle = Cycle + 1;
        if (Cycle >= 0x03)
            Cycle = 0;
        GetCyclePeriod();
        return true;
    }
    return false;
}

void GetCyclePeriod() {
    C_T = 0;
    for (char i=0; i < MAX_NO_OF_STATES; i++) {
        C_T=C_T + (C_ON[Cycle][i][0]);
    }
    
}

void GetCycleSecond() {
    char TempVar = Cycle;
    if (Cycle == 0)
        TempVar = MAX_NO_OF_CYCLES - 1;
    else
        TempVar=TempVar-1;
    C_S = GetModValue((S_InUse-C[TempVar]), C_T);
    if (C_S == 0) {
        DetermineCycleChange();
        if (ChangeTheCycle()) {
            char PrevCycle;
            if (Cycle > 0)
                PrevCycle = Cycle - 1;
            else
                PrevCycle = MAX_NO_OF_CYCLES - 1;
            S_InUse = C[PrevCycle];
        }/* else if ((S-S_InUse) != 0) {
            if (AbsValue(S-S_InUse)>10)
                S_InUse = Sign(S-S_InUse)*10 + S_InUse;
            else
                S_InUse = S;
        }*/
    }
    #ifdef RUN_ON_LCD
    //WriteLongInt(1,1,C_S,5,0);
    #endif     
}

void GetStates() {
    uint16_t TempVar = 0;
    for (char i=0; i<MAX_NO_OF_STATES; i++) {
        TempVar = TempVar+C_ON[Cycle][i][0];
        if (TempVar>C_S) {
            PresentState = i;
            return;
        }
    }
}

void PutOnOff() {
    char Temp_PORT;

    /*For the Port-A */
    Temp_PORT=0x00;
    for (char i=0; i<8; i++) {
        if ((C_BLINK[Cycle][PresentState][1]>>i)& 0x01) {
            if (CONFIG0.bits.b7)
                Temp_PORT = Temp_PORT | (0x01<<i);
        }else if ((C_ON[Cycle][PresentState][1]>>i) & 0x01) {
            Temp_PORT = Temp_PORT | (0x01<<i);
        }
    }
    
    #ifdef RUN_ON_LCD
        WriteLongInt(1,1,Temp_PORT,3,0);
    #else
        PORTA = Temp_PORT;
    #endif

    /*For the Port-B */
    Temp_PORT=0x00;
    for (char i=0; i<8; i++) {
        if ((C_BLINK[Cycle][PresentState][2]>>i) & 0x01) {
            if (CONFIG0.bits.b7)
                Temp_PORT = Temp_PORT | (0x01<<i);
        }else if ((C_ON[Cycle][PresentState][2]>>i) & 0x01) {
            Temp_PORT = Temp_PORT | (0x01<<i);
        }
    }
    
    #ifdef RUN_ON_LCD
        WriteLongInt(2,1,Temp_PORT,3,0);
        //WriteLongInt(2,1,C_ON[Cycle][7][2],3,0);
    #else
        PORTB = Temp_PORT;
    #endif
}

int32_t GetModValue (int32_t a, int32_t b) {
    if (a<0)
        a = a*-1;
    uint32_t TempVar = a/b;
    return (a-TempVar*b);
}

int32_t Sign (int32_t a) {
    if (a<0)
        return -1;
    else
        return 1;
}

int32_t AbsValue (int32_t a) {
    return Sign(a)*a;
}