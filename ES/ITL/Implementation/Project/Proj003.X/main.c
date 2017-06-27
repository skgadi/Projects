#include "main.h"


void main(void) {
    //Initiate communications and other stuff
#ifdef DISPLAY_TO_LCD
    Lcd_Init();
#endif
    ANSEL = 0x00;
    ANSELH = 0x00;
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x00;
    GPS_ON_OFF_PORT = SWITCH_OFF;
    ReadVars();
    STATE_BREAKS[MAX_NO_OF_TYPES_OF_CYCLES-1] = 0;
    GetCumulativePeriodsForStates();
    
#ifdef ACTIVATE_SIMULATION
    S = START_TIME_OF_SIMULATION;
#else
    I2C_Master_Init(400000);
    S = ReadRTCAsSec();
    UART_Init(9600);
#endif
    
#ifdef DISPLAY_TO_LCD
    Lcd_Text(1,1,"   -   ");
    Lcd_Text(2,1,"C-St-Se/Pr+Df-Rm");
#endif
    //Local variables declaration.
    UINT8 i, j, StateSecRemaining;
    UINT16 k, l, State2OnOffCounter=0, StateAudioNormalOnOffCounter=0, StateAudioSplOnOffCounter=0;
    UINT8 OutForThePorts[NO_OF_PORTS_IN_USE];
    INT16 SecError; //Error in Second
    INT32 TimeSinceTheStartOfCycle, PrevRTCSyncTime;
    INT8 DiffInSecond; //Adjustment made to the period
    UINT16 GPS_On_Time_Counter=0;
    UINT8 AdjustMilliSecond = INITIAL_ADJUST_MILLISECOND_VALUE;
    UINT16 LoadRTCAfterXSec=LOAD_TIME_FROM_RTC_EVERY_x_SECONDS_INITIAL;
    UINT16 NumberOfSystemCyclesSinceLastRTC;
    INT16 SyncY_1=0, SyncY_2=0, SyncX_1=0, SyncX_2=0, SyncM=0, SyncC=0;
    BOOL ReadyForCalcOfSystemSync=false;
    char GPSData[6];
    
    while (1) { //Loop forever
        AUDIO_PORT = SWITCH_OFF;
        GetCycle();
#ifndef ACTIVATE_SIMULATION
        if (FLAG_GET_TIME_FROM_RTC) {
            FLAG_GET_TIME_FROM_RTC = DROP_FLAG;
            /*The variable "TimeSinceTheStartOfCycle" is used here for saving ram.
            At this point of the program this variable name does not contain the
            value of the name it suggests from its name.*/
            TimeSinceTheStartOfCycle = ReadRTCAsSec() + C_D;
            if (TimeSinceTheStartOfCycle>=SECONDS_IN_A_DAY)
                TimeSinceTheStartOfCycle-SECONDS_IN_A_DAY;
            if (FLAG_ADJUST_SECOND_RATE) {
                LoadRTCAfterXSec = LOAD_TIME_FROM_RTC_EVERY_x_SECONDS;
                if (SyncY_1) 
                    ReadyForCalcOfSystemSync = true;
                SyncY_1 = GetTimePeriod(PrevRTCSyncTime, TimeSinceTheStartOfCycle)*(1000.0/NumberOfSystemCyclesSinceLastRTC);
                SyncX_1 = AdjustMilliSecond;
                
                if (ReadyForCalcOfSystemSync){
                    if (SyncX_1 != SyncX_2) {
                        SyncM = (SyncY_2-SyncY_1)/(SyncX_2-SyncX_1);
                        SyncC = SyncY_2 - SyncM*SyncX_2;
                        AdjustMilliSecond = (1000-SyncC)/SyncM;
                        if (AdjustMilliSecond>250)
                            AdjustMilliSecond = 250;
                    }
                } else 
                    AdjustMilliSecond += 1;
                SyncY_2 = SyncY_1;
                SyncX_2 = SyncX_1;
                //EEPROM_WRITE(0xA7, AdjustMilliSecond);
            }
            else
                FLAG_ADJUST_SECOND_RATE = RAISE_FLAG;
            S = TimeSinceTheStartOfCycle;
            PrevRTCSyncTime = S;
            NumberOfSystemCyclesSinceLastRTC = 0;
        }
        if (GPS_On_Time_Counter >= READ_GPS_AFTER_x_S_AFTER_SWITCHING_ON) {
            if (UART_ReadValidTimeFromGPS_TO(GPSData,100)) {
                /*The variable "TimeSinceTheStartOfCycle" is used here for saving ram.
                At this point of the program this variable name does not contain the
                value of the name it suggests from its name.*/
                TimeSinceTheStartOfCycle = ReadRTCAsSec();
                WriteToRTC(GPSData);
                if (FLAG_CALIBRATE_RTC)
                    AdjustSec(TimeSinceTheStartOfCycle - ReadRTCAsSec());
                else
                    FLAG_CALIBRATE_RTC = RAISE_FLAG;
                S = ReadRTCAsSec() + C_D;
                FLAG_GPS_SYNCED = RAISE_FLAG;
                GPS_On_Time_Counter = NULL;
                GPS_ON_OFF_PORT = SWITCH_OFF;
                FLAG_GPS_IS_ON = DROP_FLAG;
#ifdef DISPLAY_TO_LCD
                WriteLongInt(1, 7, S, 5, 1);
#endif
            } else {
                S++;
#ifdef DISPLAY_TO_LCD
                WriteLongInt(1, 10, S, 5, 1);
#endif
            }
        }
#endif
        if (C[PREV_CYCLE_TYPE] < C[CYCLE_TYPE])
            TimeSinceTheStartOfCycle = S - C[PREV_CYCLE_TYPE];
        else
            TimeSinceTheStartOfCycle = S + (SECONDS_IN_A_DAY - C[PREV_CYCLE_TYPE]);
        SecError = TimeSinceTheStartOfCycle%STATE_CUMULATIVE_PERIODS[CYCLE_TYPE];
        (CYCLE_TYPE==0) ? (i = 0) : (i = STATE_BREAKS[CYCLE_TYPE-1]);
        if (SecError > (STATE_CUMULATIVE_PERIODS[CYCLE_TYPE]/2))
            SecError -= STATE_CUMULATIVE_PERIODS[CYCLE_TYPE];
        for (; i < STATE_BREAKS[CYCLE_TYPE]; i++) { //State loop
            DiffInSecond = 0;
            for (j=0; j<(STATE_PERIODS[i] + DiffInSecond); j++) { //Second loop
                StateSecRemaining = (STATE_PERIODS[i] + DiffInSecond)-j;
                for (k=0; k<1000; k++) {//Milli-second Loop
                    for (l=0; l<NO_OF_PORTS_IN_USE; l++)
                        OutForThePorts[l] = STATE_1[i][l];
                    if (StateSecRemaining <= STATE2_BLINK_FOR_LAST_x_S) {
                        if (State2OnOffCounter < STATE2_ON_TIME_IN_MS) {
                            for (l=0; l<NO_OF_PORTS_IN_USE; l++)
                                    OutForThePorts[l] = (OutForThePorts[l] | STATE_2[i][l]);
                        }
                    } else {
                        for (l=0; l<NO_OF_PORTS_IN_USE; l++)
                                    OutForThePorts[l] = (OutForThePorts[l] | STATE_2[i][l]);
                        
                    }
                    if (StateSecRemaining <= AUDIO_SPL_TONE_FOR_LAST_x_S) {
                        if ((StateAudioNormalOnOffCounter) < AUDIO_SPL_TONE_ON_TIME_IN_MS) {
                            if ((AUDIO.v[i/4]>>(i%4)) & 0x01)
                                AUDIO_PORT = SWITCH_ON;
                            else
                                AUDIO_PORT = SWITCH_OFF;
                        } else
                            AUDIO_PORT = SWITCH_OFF;
                    } else {
                        if ((StateAudioSplOnOffCounter) < AUDIO_NORMAL_TONE_ON_TIME_IN_MS) {
                            if ((AUDIO.v[i/4]>>(i%4)) & 0x01)
                                AUDIO_PORT = SWITCH_ON;
                            else
                                AUDIO_PORT = SWITCH_OFF;
                        } else
                            AUDIO_PORT = SWITCH_OFF;
                    }
                    State2OnOffCounter++;
                    StateAudioNormalOnOffCounter++;
                    StateAudioSplOnOffCounter++;
                    if (State2OnOffCounter >= (STATE2_ON_TIME_IN_MS
                                + STATE2_OFF_TIME_IN_MS))
                        State2OnOffCounter=0;
                    if (StateAudioNormalOnOffCounter >= (AUDIO_NORMAL_TONE_ON_TIME_IN_MS
                                + AUDIO_NORMAL_TONE_OFF_TIME_IN_MS))
                        StateAudioNormalOnOffCounter=0;
                    if (StateAudioSplOnOffCounter >= (AUDIO_SPL_TONE_ON_TIME_IN_MS
                                + AUDIO_SPL_TONE_OFF_TIME_IN_MS))
                        StateAudioSplOnOffCounter=0;
#ifdef SET_IOS_ON
                    PORT_0 = OutForThePorts[0];
                    PORT_1 = OutForThePorts[1];
#endif
                    DelayInUSec(AdjustMilliSecond);
                }
                if (j==0) {
                    DiffInSecond = STATE_PERIODS[i]/3;
                    //DiffInSecond = DiffInSecond*GetSign(SecError);
                    if (GetAbs(SecError)<GetAbs(DiffInSecond))
                        DiffInSecond = GetAbs(SecError);
                    if (SecError>0)
                        DiffInSecond = -DiffInSecond;
                    SecError = SecError+DiffInSecond;
                }
#ifdef DISPLAY_TO_LCD
                WriteLongInt(2, 1, CYCLE_TYPE , 1, 0);
                WriteLongInt(2, 3, i, 2, 0);
                WriteLongInt(2, 6, j, 2, 0);
                WriteLongInt(2, 9, STATE_PERIODS[i], 2, 0);
                WriteLongInt(2, 11, SecError, 2, 1);
                WriteLongInt(2, 14, DiffInSecond, 2, 1);
                WriteLongInt(1, 1, S, 5, 1);
                //WriteLongInt(2, 14, CONFIG0, 2, 1);
                //WriteLongInt(2, 11, PrevRTCSyncTime, 5, 1);
                /*for (l=0; l<NO_OF_PORTS_IN_USE; l++) {
                    Lcd_Disp_Bin(1, 8*l+1, 0xff, 0x30);
                    Lcd_Disp_Bin(1, 8*l+1, STATE_1[i][l], 0x31);
                    Lcd_Disp_Bin(1, 8*l+1, STATE_2[i][l], 0x32);
                    //Lcd_Disp_Bin(1, 8*l+1, STATE_3[i][l], 0x33);
                }*/
#endif
                S++;
                if (S>=SECONDS_IN_A_DAY)
                    S=0;
                if ((S%LoadRTCAfterXSec) == 0)
                    FLAG_GET_TIME_FROM_RTC = RAISE_FLAG;
                if (S < SWITCH_ON_GPS_AT_x_S_UTC) {
                    FLAG_GPS_SYNCED = DROP_FLAG;
                    WriteLongInt(1, 16, 1, 0, 0);
                }
                if (FLAG_GPS_SYNCED){
                    GPS_ON_OFF_PORT = SWITCH_OFF;
                    FLAG_GPS_IS_ON = DROP_FLAG;
                } else if (S >= SWITCH_ON_GPS_AT_x_S_UTC) {
                    GPS_ON_OFF_PORT = SWITCH_ON;
                    FLAG_GPS_IS_ON = RAISE_FLAG;
                }
                NumberOfSystemCyclesSinceLastRTC++;
                if (FLAG_GPS_IS_ON)
                    GPS_On_Time_Counter++;
            }
        }
    }
    return;
}