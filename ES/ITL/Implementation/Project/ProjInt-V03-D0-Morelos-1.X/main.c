// Synchronization with only the GPS
// at the swith ON and at the 10 h UTC.
// 22 May 2017.

#include "main.h"

void main(void) {
    //Initiate communications and other stuff
#ifdef DISPLAY_TO_LCD
    Lcd_Init();
#endif
    ResetTimer();
    ANSEL = 0x00;
    ANSELH = 0x00;
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x00;
//    GPS_ON_OFF_PORT = SWITCH_OFF;
//    FLAG_GPS_SYNCED = DROP_FLAG;

    GPS_ON_OFF_PORT = SWITCH_ON;
    FLAG_GPS_IS_ON = RAISE_FLAG;

    //FLAG_GPS_SYNCED = DROP_FLAG;

    ReadVars();
    //STATE_BREAKS[MAX_NO_OF_TYPES_OF_CYCLES-1] = 0;
    GetCumulativePeriodsForStates();
    
#ifdef ACTIVATE_SIMULATION
    S = START_TIME_OF_SIMULATION;
#else
    S = C[2] + 1 + C_D;  // why not + C_D
//    UART_Init(9600);
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
    INT32 TimeSinceTheStartOfCycle;
    INT8 DiffInSecond; //Adjustment made to the period
    UINT16 GPS_On_Time_Counter = 0;
    UINT8 GPS_Non_Sync_Times = 0;
    //UINT8 AdjustMilliSecond = 0x66;
    //UINT16 LoadRTCAfterXSec=LOAD_TIME_FROM_RTC_EVERY_x_SECONDS_INITIAL;
    //UINT16 NumberOfSystemCyclesSinceLastRTC;
    //INT16 SyncY_1=0, SyncY_2=0, SyncX_1=0, SyncX_2=0, SyncM=0, SyncC=0;
    //BOOL ReadyForCalcOfSystemSync=false;
    char GPSData[6];
    
    while (1) { //Loop forever
        AUDIO_PORT = SWITCH_OFF;
#ifndef ACTIVATE_SIMULATION
        
#ifdef GPS_SYNC_EVERY_DAY_x_SEC
        if (GPS_On_Time_Counter >= READ_GPS_AFTER_SWITCHING_ON_x_SEC) {
            INT32 TempS;
            TempS = ReadGPSToS(100);
            if(TempS >= 0) {
                S = TempS + C_D;
                GPS_On_Time_Counter = NULL;
                GPS_ON_OFF_PORT = SWITCH_OFF;
                FLAG_GPS_IS_ON = DROP_FLAG;
                GPS_Non_Sync_Times = 0;
            } 
            else {
                S++;
                GPS_Non_Sync_Times++;
                if (GPS_Non_Sync_Times >= DISABLE_GPS_AFTER_x_NON_SYNC_CYCLES) {
                    GPS_On_Time_Counter = NULL;
                    GPS_ON_OFF_PORT = SWITCH_OFF;
                    FLAG_GPS_IS_ON = DROP_FLAG;
                    GPS_Non_Sync_Times = 0;
                }
            }
        }
#endif
#endif
        if (S >= SECONDS_IN_A_DAY)
            S -= SECONDS_IN_A_DAY;
        GetCycle();
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
                    if (StateSecRemaining > AUDIO_SPL_TONE_FOR_LAST_x_S) {
                        if ((StateAudioNormalOnOffCounter) < AUDIO_NORMAL_TONE_ON_TIME_IN_MS) {
                            if ((AUDIO.v[i/8]) & (0x80>>(i%8)))
                                AUDIO_PORT = SWITCH_ON;
                            else
                                AUDIO_PORT = SWITCH_OFF;
                        } else
                            AUDIO_PORT = SWITCH_OFF;
                    } else {
                        if ((StateAudioSplOnOffCounter) < AUDIO_SPL_TONE_ON_TIME_IN_MS) {
                            if ((AUDIO.v[i/8]) & (0x80>>(i%8)))
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
#ifndef ACTIVATE_SIMULATION
                    while (!FLAG_END_OF_MILLI_SECOND);
#endif
                    FLAG_END_OF_MILLI_SECOND = DROP_FLAG;

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
                WriteLongInt(1, 7, GPS_On_Time_Counter, 5, 1);
                WriteLongInt(1, 13, GPS_Non_Sync_Times, 2, 1);
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
/*
                if (S == LOAD_TIME_FROM_GPS_EVERY_DAY_x_SEC) {
                    GPS_ON_OFF_PORT = SWITCH_ON;
                    FLAG_GPS_IS_ON = RAISE_FLAG;
                }
                if (FLAG_GPS_IS_ON)
                    GPS_On_Time_Counter++;
 */
            }
        }
    }
    return;
}

void interrupt tc_int (void) {
    if(PIR1bits.TMR1IF && PIE1bits.TMR1IE) {
        PIR1bits.TMR1IF = 0;
        TMR1 -= 997; // correct value is 997       
        FLAG_END_OF_MILLI_SECOND = RAISE_FLAG;
    }
}