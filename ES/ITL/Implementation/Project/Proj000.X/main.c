/*
 * File:   main.c
 * Author: gadis
 *
 * Created on October 3, 2016, 2:00 PM
 */


#include "main.h"

extern volatile int32_t C[MAX_NO_OF_CYCLES]={0,0,0};
extern volatile uint8_t C_D=0;
extern volatile uint8_t C_ON[MAX_NO_OF_CYCLES][MAX_NO_OF_STATES][3] ={
    {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}
    }, {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}
    }, {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}
    }
};

extern volatile uint8_t C_BLINK[MAX_NO_OF_CYCLES][MAX_NO_OF_STATES][3]={
    {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}
    }, {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}
    }, {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}
    }
};

extern volatile int32_t S = 0; // Correct time
extern volatile int32_t S_InUse = 0;
extern volatile BYTE_VAL CONFIG0=0b00000000;
extern volatile uint16_t C_S=0;
extern volatile uint16_t C_T=0;
extern volatile uint8_t Cycle=0;
extern volatile uint8_t PresentState=0;

void main(void) {
    /*Initialization*/
    #ifdef RUN_ON_LCD
    Lcd_Init();
    Lcd_Text(1,11,"-  -");
    Lcd_Text(2,14,"-");
    #endif
    I2C_Master_Init(400000);
    UART_Init(9600);
    char TempValue; //Temporary Variable
    /*GET FROM EEPROM: C, C_D, C_ON, C_BLINK*/
    ReadVars();
    /*READ "S" FROM RTC*/
    S = ReadRTCAsSec()+C_D;
    if (S>SECONDS_IN_A_DAY)
        S=-SECONDS_IN_A_DAY;
    
    DetermineCycleChange();
    ChangeTheCycle();
    GetCyclePeriod();
    
    /*Firmware cycle Variable*/
    char Firm_Cicle = 0x00;
    
    
    S_InUse = S;
    /*MainLoop*/
    while(1) {
        GetCycleSecond();
        GetStates();
        PutOnOff();
        CONFIG0.bits.b7 = !CONFIG0.bits.b7;
        
        
        Firm_Cicle++;
        if (Firm_Cicle == NO_OF_CYCLES_PER_SECONDS) {
            Firm_Cicle=0;
            S++;
            S_InUse = S_InUse ;
            if (S>=SECONDS_IN_A_DAY)
                S=-SECONDS_IN_A_DAY;
        }
        
        #ifdef RUN_ON_LCD
        WriteLongInt(1,9,PresentState,2,0);
        WriteLongInt(1,12,C_S,2,0);
        WriteLongInt(1,15,Cycle,2,0);
        WriteLongInt(2,9,S,5,0);
        WriteLongInt(2,15,Firm_Cicle,2,0);
        #endif

        __delay_ms(FIRMWARE_LOOP_DELAY_MS);
    }
}
