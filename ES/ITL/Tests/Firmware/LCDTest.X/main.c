/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.15.0
        Device            :  PIC16F1938
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
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

//#include "mcc_generated_files/mcc.h"
#include "main.h"



/*
                         Main application
 */
void main(void)
{
    // initialize the device
    //SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    ANSEL = 0x00;
    ANSELH = 0x00;

    //TRISB = 0x00;
    /*lcd_reset();
    lcd_init();
    lcd_set_cursor(1,1);
    //__delay_ms(1);
    lcd_string("hey");*/
    /*LCD_Initialize();
    LCD_Clear();
    LCD_GoTo(45);
    LCD_WriteString("hey");*/
    /*LCDInit(LS_BLINK);
    LCDClear();*/
    Lcd_Init();
    Lcd_Text(1,1,"Time:");
    Lcd_Text(2,1,"Date:");
    /*USARTInit(115200);
    USARTFlushBuffer();*/
    __delay_ms(1000);
    //USARTInit(9600);
    USARTInit();
    char data;
    uint8_t i;
    TRISC = 0x00;
    while (1) {
        
        Lcd_CharCP(65);
        
        if (RCIF)
            Lcd_CharCP(USARTReadByte());
       /* for (i = 0; i<100; i++){
            if (i>=0x0 && i<0x10) {
                data = sci_GetByte(10);
                Lcd_CharCP(data);
            }
        }*/
       /*uint8_t n= USARTDataAvailable();
        if(n!=0) {
            //Read it
            Lcd_Text(1,1,"A");
            for (i = 0; i<100; i++ ) {
                data = USARTReadData();
                if (i>=0 & i<=14)
                    Lcd_CharCP(data);
            }
            USARTFlushBuffer();
                
        }*/
       __delay_ms(1000);
    }
}
/**
 End of File
*/