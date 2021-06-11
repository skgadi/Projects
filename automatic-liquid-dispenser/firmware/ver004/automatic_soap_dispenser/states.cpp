#include "main_activity.h"
void MAIN_ACTIVITY::changeState(STATE newState) {
    gskRelays.stopAll();
    currentState = newState;
    stateStartTime = millis();
    gskDisp.clearAll();
    gskDisp.enable();
}


unsigned long  MAIN_ACTIVITY::timeSinceStateChange() {
    return millis() - stateStartTime;
}

void MAIN_ACTIVITY::resetStateStarttime() {
    stateStartTime = millis();
}