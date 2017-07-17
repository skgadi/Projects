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
    //TMR1_SetInterruptHandler(Timer1_1s);
    //TMR3_SetInterruptHandler(Timer3_1ms);
    Lcd_Init();
    Lcd_Command(LCD_CLEAR);
    //Lcd_Text(2,1, "asdfasdf");
    GPS_SWITCH=ON;
    LoadAllFromEeprom();
    DATE_TIME.SECOND = 30;
    DATE_TIME.DAY.Val = 0x01;
    DATE_TIME.DATE.Day = 1;
    DATE_TIME.DATE.Month = 10;
    DATE_TIME.YEAR = 2017;
    DATE_TIME = AdjustDayLightSaving(DATE_TIME);
    //----------End of add by SKGadi----------
    while (1)
    {
        // Add your application code
        if (ReadGPS_DATE_TIME()) {
            WriteLongInt(2,1, GPS_DATE_TIME.SECOND,5,1);
            WriteLongInt(2,7, GPS_DATE_TIME.DATE.Day,2,0);
            WriteLongInt(2,9, GPS_DATE_TIME.DATE.Month,2,0);
            WriteLongInt(2,11, GPS_DATE_TIME.YEAR,4,0);
            WriteLongInt(2,15, GPS_DATE_TIME.DAY.Val,2,0);
            Lcd_Text(1, 1, ":)");
        } else {
            Lcd_Text(1, 1, ":(");
        }
        WriteLongInt(1, 3, DATE_TIME.SECOND, 5,1);
        WriteLongInt(1, 9, DATE_TIME.YEAR, 4,0);
        WriteLongInt(1, 13, DATE_TIME.DATE.Month, 2,0);
        WriteLongInt(1, 15, DATE_TIME.DATE.Day, 2,0);
        
        //__delay_ms(1000);
        /*Lcd_Command(LCD_CLEAR);
        ShowRawData();*/
    }
}
/**
 End of File
*/