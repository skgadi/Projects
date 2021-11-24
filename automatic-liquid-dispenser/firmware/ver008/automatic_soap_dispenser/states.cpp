#include "main_activity.h"
void MAIN_ACTIVITY::changeState(STATE newState) {
    gskRelays.stopAll();
    currentState = newState;
    resetStateStarttime();
    gskDisp.clearAll();
    gskDisp.enable();
    tymOfLastDisp = 0;
}


double  MAIN_ACTIVITY::timeSinceStateChange() {
    return millis()/1000.0 - stateStartTime;
}

void MAIN_ACTIVITY::resetStateStarttime() {
    stateStartTime = millis()/1000.0;
}