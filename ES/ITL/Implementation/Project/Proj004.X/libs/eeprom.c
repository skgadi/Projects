#include "eeprom.h"

BYTE ReadEeprom(WORD_VAL Address){
    //Page 142 of 40001816D document
    //Address.Val -= 0x310000;
    NVMCON1bits.NVMREG = 00;
    NVMADRL = Address.v[0];
    NVMADRH = Address.v[1];
    NVMCON1bits.RD = 1;
    //while(NVMCON1bits.RD); // Not required since this operation is very fast.
    NVMCON1bits.NVMREG1 = 1; // to fix the error mentioned in 4th page of http://ww1.microchip.com/downloads/en/DeviceDoc/80000712A.pdf 
    return NVMDAT;
}

void LoadSettingsFromEeprom (void) {
    WORD_VAL Temp16, Address;
    DWORD_VAL Temp32;
    // Reading TIME_ZONE
    Address.Val = EEPROM_ADDRESS_TIME_ZONE;
    Temp16.v[0] = ReadEeprom(Address);
    Address.Val++;
    Temp16.v[1] = ReadEeprom(Address);
    TIME_ZONE = (INT16) 60*Temp16.Val;
    // Reading DAY_LIGHT_START
    Address.Val = EEPROM_ADDRESS_DAY_LIGHT_START;
    DAY_LIGHT_START.Day = ReadEeprom (Address);
    Address.Val++;
    DAY_LIGHT_START.Month = ReadEeprom (Address);
    // Reading DAY_LIGHT_END
    Address.Val = EEPROM_ADDRESS_DAY_LIGHT_END;
    DAY_LIGHT_END.Day = ReadEeprom (Address);
    Address.Val++;
    DAY_LIGHT_END.Month = ReadEeprom (Address);
    //Reading CENTURY
    Address.Val = EEPROM_ADDRESS_CENTURY;
    CENTURY = ReadEeprom(Address);
    // Reading CYCLE_DELAY
    Address.Val = EEPROM_ADDRESS_CYCLE_DELAY;
    Temp16.v[0] = ReadEeprom(Address);
    Address.Val++;
    Temp16.v[1] = ReadEeprom(Address);
    CYCLE_DELAY = (INT16) Temp16.Val;
    //Reading BLINK_ON_TIME
    Address.Val = EEPROM_ADDRESS_BLINK_ON_TIME;
    BLINK_ON_TIME = ReadEeprom(Address);
    //Reading BLINK_OFF_TIME
    Address.Val = EEPROM_ADDRESS_BLINK_OFF_TIME;
    BLINK_OFF_TIME = ReadEeprom(Address);
    //Reading BLINK_LAST_X_SECONDS
    Address.Val = EEPROM_ADDRESS_BLINK_LAST_X_SECONDS;
    BLINK_LAST_X_SECONDS = ReadEeprom(Address);
    //Reading AUDIO_NORMAL_ON_TIME
    Address.Val = EEPROM_ADDRESS_AUDIO_NORMAL_ON_TIME;
    AUDIO_NORMAL_ON_TIME = ReadEeprom(Address);
    //Reading AUDIO_NORMAL_OFF_TIME
    Address.Val = EEPROM_ADDRESS_AUDIO_NORMAL_OFF_TIME;
    AUDIO_NORMAL_OFF_TIME = ReadEeprom(Address);
    //Reading AUDIO_SPECIAL_ON_TIME
    Address.Val = EEPROM_ADDRESS_AUDIO_SPECIAL_ON_TIME;
    AUDIO_SPECIAL_ON_TIME = ReadEeprom(Address);
    //Reading AUDIO_SPECIAL_OFF_TIME
    Address.Val = EEPROM_ADDRESS_AUDIO_SPECIAL_OFF_TIME;
    AUDIO_SPECIAL_OFF_TIME = ReadEeprom(Address);
    //Reading SPECIAL_AUDIO_LAST_X_SECONDS
    Address.Val = EEPROM_ADDRESS_SPECIAL_AUDIO_LAST_X_SECONDS;
    SPECIAL_AUDIO_LAST_X_SECONDS = ReadEeprom(Address);
    //Reading GPS_SYNC_AT_START
    Address.Val = EEPROM_ADDRESS_GPS_SYNC_AT_START;
    GPS_SYNC_AT_START = ReadEeprom(Address);
    //Reading GPS_SYNC_EVERY_x_SECONDS
    Address.Val = EEPROM_ADDRESS_GPS_SYNC_EVERY_x_SECONDS;
    Temp32.Val = 0;
    Temp32.v[0] = ReadEeprom(Address);
    Address.Val++;
    Temp32.v[1] = ReadEeprom(Address);
    Address.Val++;
    Temp32.v[2] = ReadEeprom(Address);
    GPS_SYNC_EVERY_x_SECONDS = Temp32.Val;
    //Reading GPS_SYNC_EVERY_DAY_AT_LOCAL_TIME
    Address.Val = EEPROM_ADDRESS_GPS_SYNC_EVERY_DAY_AT_LOCAL_TIME;
    Temp16.v[0] = ReadEeprom(Address);
    Address.Val++;
    Temp16.v[1] = ReadEeprom(Address);
    GPS_SYNC_EVERY_DAY_AT_LOCAL_TIME = Temp16.v[1]*60*60 + Temp16.v[0]*60;
}

void LoadEventsFromEeprom (void) {
    WORD_VAL Temp16, Address;
    Address.Val = EEPROM_ADDRESS_EVENTS;
    for (int i=0; i<MAX_NO_OF_EVENTS; i++) {
        Temp16.v[0] = ReadEeprom(Address);
        Address.Val++;
        Temp16.v[1] = ReadEeprom(Address);
        EVENTS[i].START_TIME = Temp16.v[1]*60*60+Temp16.v[0]*60;
        Address.Val++;
        Temp16.v[0] = ReadEeprom(Address);
        Address.Val++;
        Temp16.v[1] = ReadEeprom(Address);
        EVENTS[i].END_TIME = Temp16.v[1]*60*60+Temp16.v[0]*60;
        Address.Val++;
        EVENTS[i].CYCLE = ReadEeprom(Address);
        Address.Val++;
        EVENTS[i].SELECTED_WEEKS.Val = ReadEeprom(Address);
        Address.Val++;
    }
}

void LoadStatesFromEeprom (void) {
    WORD_VAL AddStates, AddAudioNormal, AddAudioSpecial, TempNormalAdd, TempSpecialAdd;
    UINT8 AudAddInc;
    AddStates.Val = EEPROM_ADDRESS_STATES;
    AddAudioNormal.Val = EEPROM_ADDRESS_AUDIO_NORMAL;
    AddAudioSpecial.Val = EEPROM_ADDRESS_AUDIO_SPECIAL;
    for (int i=0; i<MAX_NO_OF_STATES; i++) {
        STATES[i].PERIOD = ReadEeprom(AddStates);
        AddStates.Val++;
        for (int j=0; j<NO_OF_PORTS; j++) {
            STATES[i].ON[j] = ReadEeprom(AddStates);
            AddStates.Val++;
        }
        for (int j=0; j<NO_OF_PORTS; j++) {
            STATES[i].BLINK[j] = ReadEeprom(AddStates);
            AddStates.Val++;
        }
        AudAddInc = i/DATA_BUS_SIZE;
        TempNormalAdd.Val = AddAudioNormal.Val + AudAddInc;
        TempSpecialAdd.Val = AddAudioSpecial.Val + AudAddInc;
        if (ReadEeprom(TempNormalAdd) & ((0x80)>>(i%DATA_BUS_SIZE)))
            STATES[i].AUDIO = AUDIO_NORMAL;
        else if (ReadEeprom(TempSpecialAdd) & ((0x80)>>(i%DATA_BUS_SIZE)))
            STATES[i].AUDIO = AUDIO_SPECIAL;
        else
            STATES[i].AUDIO = AUDIO_OFF;
    }
}

void LoadCyclesFromEeprom (void) {
    WORD_VAL Address;
    Address.Val = EEPROM_ADDRESS_CYCLE_TYPES;
    //Loading from EEPROM
    for (int i=0; i<MAX_NO_OF_CYCLE_TYPES; i++) {
        CYCLES[i].END_STATE = ReadEeprom(Address);
        Address.Val++;
    }
    //Preparing the information
    for (int i=0; i<MAX_NO_OF_CYCLE_TYPES; i++) {
        if (i==0)
            CYCLES[i].START_STATE = 0;
        else /*if (CYCLES[i].END_STATE == CYCLES[i-1].END_STATE)
            CYCLES[i].START_STATE = CYCLES[i].END_STATE;
        else*/
            CYCLES[i].START_STATE = CYCLES[i-1].END_STATE+1;
        CYCLES[i].PERIOD = 0;
        for (int j=CYCLES[i].START_STATE; j<=CYCLES[i].END_STATE; j++ )
            CYCLES[i].PERIOD += STATES[j].PERIOD;
    }
}

void LoadAllFromEeprom (void) {
    LoadSettingsFromEeprom ();
    LoadEventsFromEeprom ();
    LoadStatesFromEeprom();
    LoadCyclesFromEeprom();
}