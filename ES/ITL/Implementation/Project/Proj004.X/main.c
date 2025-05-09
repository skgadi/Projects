/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs 

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs  - 1.45
        Device            :  PIC18F26K40
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"
//----------Start of add by SKGadi----------
#include "libs/projMain.h"
//----------End of add by SKGadi----------
/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    //----------Start of add by SKGadi----------
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    TMR0_SetInterruptHandler(Timer0_10ms);
#ifdef SET_EEPROM
    for (INT16 i=0; i<1024; i++)
        WriteEeprom(i,EE_Settings[i]);
#endif
    LoadAllFromEeprom();
#ifdef LCD_SHOW
    Lcd_Init();
    //Lcd_Command(LCD_UNDERLINE_ON);
#endif
#ifdef SET_START_TIME
    DATE_TIME.SECOND = SET_START_TIME;
    DATE_TIME.YEAR = 2017;
    DATE_TIME.DATE.Day = 1;
    DATE_TIME.DATE.Month = 1;
    DATE_TIME.DAY.Val = 0x40;
#endif
    if (GPS_SYNC_AT_START == 1)
        ACTION_GPS_START = SET;
    AUDIO_SWITCH = OFF;
    //Temp Code goes here
    //----------End of add by SKGadi----------
    while (1)
    {
        // Add your application code
        if (ACTION_GPS_START) SwitchOnGPS();
        if (ACTION_GPS_VERIFY_WAIT_TIME) VerifyForGPSOnTIme();
        if (ACTION_GPS_READ) ReadGPS();
        if (ACTION_GPS_STOP) StopGPS();
        TestGPSStartCondition();
        NEXT_EVENT = GetEventNumber();
#ifdef LCD_SHOW
#if LCD_SHOW == 0
        WriteLongInt(1, 1, DATE_TIME.SECOND, 6, 0);
        WriteLongInt(1, 7, GPS_DATE_TIME.SECOND, 6, 1);
        WriteLongInt(1, 14, NO_OF_TIMES_GPS_FAILED, 2, 1);
        WriteLongInt(2, 1, TIME_AT_LAST_GPS_SYNC, 6, 0);
        WriteLongInt(2, 7, TIME_WHEN_GPS_IS_SWITCHED_ON, 6,1);
#elif LCD_SHOW == 1
        WriteLongInt(1, 1, DATE_TIME.SECOND, 6, 1);
        WriteLongInt(1, 9, PRESENT_STATE, 3, 1);
        WriteLongInt(1, 13, NEXT_STATE, 3, 1);
        WriteLongInt(2, 1, STATE_SECONDS_REMAINING, 3, 1);
        WriteLongInt(2, 5, STATES[PRESENT_STATE].ON[0], 3, 1);
        WriteLongInt(2, 9, STATES[PRESENT_STATE].BLINK[0], 3, 1);
        WriteLongInt(2, 13, STATES[PRESENT_STATE].AUDIO, 3, 1);
#elif LCD_SHOW == 2
        WriteLongInt(1, 1, DATE_TIME.SECOND, 6, 1);
        WriteLongInt(1, 9, PRESENT_STATE, 3, 1);
        WriteLongInt(1, 13, NEXT_STATE, 3, 1);
        WriteLongInt(2, 1, GetThisCycle(), 3, 1);
        WriteLongInt(2, 5, CYCLES[GetThisCycle()].PERIOD, 3, 1);
        WriteLongInt(2, 9, STATE_SECONDS_REMAINING, 3, 1);
        WriteLongInt(2, 13, SECONDS_TO_ADJUST, 3, 1);
#elif LCD_SHOW == 3
        WriteLongInt(1, 1, DATE_TIME.SECOND, 6, 1);
        WriteLongInt(1, 9, PRESENT_STATE, 3, 1);
        WriteLongInt(1, 13, NEXT_STATE, 3, 1);
        WriteLongInt(2, 1, CYCLES[PRESENT_STATE].START_STATE, 3, 1);
        WriteLongInt(2, 5, CYCLES[PRESENT_STATE].PERIOD, 3, 1);
        WriteLongInt(2, 9, CYCLES[PRESENT_STATE].END_STATE, 3, 1);
        WriteLongInt(2, 13, STATE_SECONDS_REMAINING, 3, 1);
#elif LCD_SHOW == 4
        WriteLongInt(1, 1, DATE_TIME.SECOND, 6, 1);
        WriteLongInt(1, 9, PRESENT_EVENT, 3, 1);
        WriteLongInt(1, 13, NEXT_EVENT, 3, 1);
        WriteLongInt(2, 1, EVENTS[PRESENT_EVENT].CYCLE, 3, 1);
        WriteLongInt(2, 5, EVENTS[NEXT_EVENT].START_TIME, 6, 1);
        WriteLongInt(2, 13, EVENTS[NEXT_EVENT].CYCLE, 3, 1);
#elif LCD_SHOW == 5
        ReadGPS_DATE_TIME();
        Lcd_WriteChar(1,1,0x54);
        WriteLongInt(1, 2, DATE_TIME.SECOND, 6, 0);
        Lcd_WriteChar(1,9,0x53);
        WriteLongInt(1, 10, TIME_AT_LAST_GPS_SYNC, 6, 0);
        Lcd_WriteChar(2,1,0x47);
        WriteLongInt(2, 2, GPS_DATE_TIME.SECOND, 6, 0);
        Lcd_WriteChar(2,9,'I');
        WriteLongInt(2, 10, TIME_WHEN_GPS_IS_SWITCHED_ON, 6, 0);
#endif
#endif
    }
}
/**
 End of File
*/