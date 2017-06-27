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
    
    INTCONbits.T0IE = 1;               // Enable interrupt on TMR0 overflow
    OPTION_REGbits.INTEDG = 0;             // falling edge trigger the interrupt
    INTCONbits.INTE = 1;               // enable the external interrupt
    INTCONbits. GIE = 1;
    OPTION_REGbits.PS = 0x01;
    while (1) { //Loop forever
    }
    return;
}

void interrupt   tc_int  (void)        // interrupt function 
{
        if(INTCONbits.T0IF && INTCONbits.T0IE) 
    {                                     // if timer flag is set & interrupt enabled
                TMR0 -= 250;               // reload the timer - 250uS per interrupt
                INTCONbits.T0IF = 0;                  // clear the interrupt flag 
                PORTB = 0x40;             // toggle a bit to say we're alive
        }
 
}