#include "main.h"


void main(void) {
    //Initiate communications and other stuff
#ifdef DISPLAY_TO_LCD
    Lcd_Init();
#endif
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
    INT32 TimeSinceTheStartOfCycle;
    INT8 DiffInSecond; //Adjustment made to the period
    UINT16 GPS_On_Time_Counter;
    UINT16 AdjustMilliSecond = 1;
    char GPSData[6];
    
    while (1) { //Loop forever
        GetCycle();
#ifndef ACTIVATE_SIMULATION
        if (CONFIG0 & 0x01) {
            CONFIG0 = CONFIG0 & 0xfe;
            /*The variable "TimeSinceTheStartOfCycle" is used here for saving ram.
            At this point of the program this variable name does not contain the
            value of the name it suggests from its name.*/
            TimeSinceTheStartOfCycle = ReadRTCAsSec() + C_D;
            if (CONFIG0 & 0x02) {
                WriteLongInt(2, 11, (S-TimeSinceTheStartOfCycle), 4, 1);
                AdjustMilliSecond += (S-TimeSinceTheStartOfCycle)*(100.0/LOAD_TIME_FROM_RTC_EVERY_x_SECONDS);//+=(S-TimeSinceTheStartOfCycle);//-= ((S-TimeSinceTheStartOfCycle)/LOAD_TIME_FROM_RTC_EVERY_x_SECONDS);
                WriteLongInt(2, 11, AdjustMilliSecond, 5, 1);                
            } else
                CONFIG0 = CONFIG0 | 0x02;
            S = TimeSinceTheStartOfCycle;
        }
        if (CONFIG0 & 0x04) {
            SwitchGPS(true);
            GPS_On_Time_Counter++;
        } else {
            SwitchGPS(false);
            GPS_On_Time_Counter=0;
        }
        if (GPS_On_Time_Counter >= READ_GPS_AFTER_x_S_AFTER_SWITCHING_ON) {
            UART_ReadValidTimeFromGPS_TO(GPSData,4);
        }
#endif
        (CYCLE_TYPE==0) ? (i = 0) : (i = STATE_BREAKS[CYCLE_TYPE-1]);


        if (C[PREV_CYCLE_TYPE] < C[CYCLE_TYPE])
            TimeSinceTheStartOfCycle = S - C[PREV_CYCLE_TYPE];
        else
            TimeSinceTheStartOfCycle = S + (SECONDS_IN_A_DAY - C[PREV_CYCLE_TYPE]);
        SecError = TimeSinceTheStartOfCycle%STATE_CUMULATIVE_PERIODS[CYCLE_TYPE];
        if (SecError > (STATE_CUMULATIVE_PERIODS[CYCLE_TYPE]/2))
            SecError -= STATE_CUMULATIVE_PERIODS[CYCLE_TYPE];
        for (; i < STATE_BREAKS[CYCLE_TYPE]; i++) { //State loop
            DiffInSecond = 0;
            for (j=0; j<(STATE_PERIODS[i] + DiffInSecond); j++) { //Second loop
                
                
                StateSecRemaining = STATE_PERIODS[i]-j;
                for (k=0; k<1000; k++) {//Milli-second Loop
                    for (l=0; l<NO_OF_PORTS_IN_USE; l++)
                        OutForThePorts[l] = STATE_1[i][l];
                    if (StateSecRemaining <= STATE2_BLINK_FOR_LAST_x_S) {
                        if (State2OnOffCounter < STATE2_ON_TIME_IN_MS) {
                            for (l=0; l<NO_OF_PORTS_IN_USE; l++)
                                    OutForThePorts[l] = (OutForThePorts[l] | STATE_2[i][l]);
                        }
                    }
                    if (StateSecRemaining <= AUDIO_SPL_TONE_FOR_LAST_x_S) {
                        if ((StateAudioNormalOnOffCounter) < AUDIO_SPL_TONE_ON_TIME_IN_MS) {
                            for (l=0; l<NO_OF_PORTS_IN_USE; l++)
                                OutForThePorts[l] = (OutForThePorts[l] | STATE_3[i][l]);
                        }
                    } else {
                        if ((StateAudioSplOnOffCounter) < AUDIO_NORMAL_TONE_ON_TIME_IN_MS) {
                            for (l=0; l<NO_OF_PORTS_IN_USE; l++)
                                OutForThePorts[l] = (OutForThePorts[l] | STATE_3[i][l]);
                        }                        
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
                    PORTB = OutForThePorts[0];
                    PORTC = OutForThePorts[1];
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
                //WriteLongInt(2, 11, SecError, 2, 1);
                //WriteLongInt(2, 14, DiffInSecond, 2, 1);
                //WriteLongInt(2, 9, S, 5, 0);
                //WriteLongInt(2, 14, CONFIG0, 2, 1);
                for (l=0; l<NO_OF_PORTS_IN_USE; l++) {
                    Lcd_Disp_Bin(1, 8*l+1, 0xff, 0x30);
                    Lcd_Disp_Bin(1, 8*l+1, STATE_1[i][l], 0x31);
                    Lcd_Disp_Bin(1, 8*l+1, STATE_2[i][l], 0x32);
                    Lcd_Disp_Bin(1, 8*l+1, STATE_3[i][l], 0x33);
                }
#endif
                S++;
                if (S>=SECONDS_IN_A_DAY)
                    S=0;
                if ((S%LOAD_TIME_FROM_RTC_EVERY_x_SECONDS) == 0)
                    CONFIG0 = CONFIG0 | 0x01;
                if (S == SWITCH_ON_GPS_AT_x_S_UTC) {
                    GPS_ON_OFF_PORT = 1;
                    CONFIG0 = CONFIG0 | 0x04;
                }
            }
        }
    }
    return;
}