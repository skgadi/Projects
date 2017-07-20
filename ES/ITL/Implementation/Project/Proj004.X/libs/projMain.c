#include "projMain.h"

void Timer0_10ms (void) {
    if (ACTION_NEW_STATE) {
        PRESENT_STATE = NEXT_STATE;
        STATE_SECONDS = 0;
        ACTION_NEW_STATE = RESET;
        STATE_SECONDS_REMAINING = STATES[PRESENT_STATE].PERIOD;
    }
    UINT8 OutForThePorts[NO_OF_PORTS];
    for (UINT8 i =0; i<NO_OF_PORTS; i++) {
        OutForThePorts[i] = 0x00;
    }
    for (UINT8 i =0; i<NO_OF_PORTS; i++) {
        OutForThePorts[i] = STATES[PRESENT_STATE].ON[i];
    }
    if (STATE_SECONDS_REMAINING <= BLINK_LAST_X_SECONDS) {
        if (BLINK_STATE_ON_OFF_COUNTER < BLINK_ON_TIME) {
            for (UINT8 i =0; i<NO_OF_PORTS; i++)
                OutForThePorts[i] = (OutForThePorts[i] | STATES[PRESENT_STATE].BLINK[i]);
        }
    } else {
        for (UINT8 i =0; i<NO_OF_PORTS; i++)
            OutForThePorts[i] = (OutForThePorts[i] | STATES[PRESENT_STATE].BLINK[i]);
    }
#ifndef RUN_ON_LCD
    for (UINT8 i =0; i<NO_OF_PORTS; i++) {
        *(LIGHTS[i]) = OutForThePorts[i];
    }
#endif
    if ((STATES[PRESENT_STATE].AUDIO == AUDIO_NORMAL) 
            || ((STATES[PRESENT_STATE].AUDIO == AUDIO_SPECIAL)
            && (STATE_SECONDS_REMAINING <= SPECIAL_AUDIO_LAST_X_SECONDS))) {
        if (NORMAL_AUDIO_STATE_ON_OFF_COUNTER < AUDIO_NORMAL_ON_TIME)
            AUDIO_SWITCH = ON;
        else
            AUDIO_SWITCH = OFF;
    } else if (STATES[PRESENT_STATE].AUDIO == AUDIO_SPECIAL) {
        if (SPECIAL_AUDIO_STATE_ON_OFF_COUNTER < AUDIO_SPECIAL_ON_TIME)
            AUDIO_SWITCH = ON;
        else
            AUDIO_SWITCH = OFF;
    } else
        AUDIO_SWITCH = OFF;
    CENTI_SECOND_COUNT++;
    BLINK_STATE_ON_OFF_COUNTER++;
    if (BLINK_STATE_ON_OFF_COUNTER >= (BLINK_ON_TIME + BLINK_OFF_TIME))
        BLINK_STATE_ON_OFF_COUNTER=0;
    NORMAL_AUDIO_STATE_ON_OFF_COUNTER++;
    if (NORMAL_AUDIO_STATE_ON_OFF_COUNTER >= (AUDIO_NORMAL_ON_TIME + AUDIO_NORMAL_OFF_TIME))
        NORMAL_AUDIO_STATE_ON_OFF_COUNTER=0;
    SPECIAL_AUDIO_STATE_ON_OFF_COUNTER++;
    if (SPECIAL_AUDIO_STATE_ON_OFF_COUNTER >= (AUDIO_SPECIAL_ON_TIME + AUDIO_SPECIAL_OFF_TIME))
        SPECIAL_AUDIO_STATE_ON_OFF_COUNTER=0;
    
    
    if (CENTI_SECOND_COUNT == 99) {
        CENTI_SECOND_COUNT = 0;
        DATE_TIME = IncreaseByASecond(DATE_TIME);
        STATE_SECONDS_REMAINING = STATES[PRESENT_STATE].PERIOD - STATE_SECONDS-1;
        if (STATE_SECONDS_REMAINING == 0)
            ACTION_NEW_STATE = SET;
        STATE_SECONDS++;
    }
    if (CENTI_SECOND_COUNT == 90) {
        UINT8 ThisCycle = 0;
        if (PRESENT_EVENT <0)
            ThisCycle = 0;
        else
            ThisCycle = EVENTS[PRESENT_EVENT].CYCLE;
        NEXT_STATE = PRESENT_STATE+1;
        if (NEXT_STATE > CYCLES[ThisCycle].END_STATE) {
            PRESENT_EVENT = NEXT_EVENT;
            if (PRESENT_EVENT <0)
                ThisCycle = 0;
            else
                ThisCycle = EVENTS[PRESENT_EVENT].CYCLE;
            NEXT_STATE = CYCLES[ThisCycle].START_STATE;
        }
    }
}

