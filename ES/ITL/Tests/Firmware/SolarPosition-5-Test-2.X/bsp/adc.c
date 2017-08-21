/********************************************************************
 Software License Agreement:

 The software supplied herewith by Microchip Technology Incorporated
 (the "Company") for its PIC(R) Microcontroller is intended and
 supplied to you, the Company's customer, for use solely and
 exclusively on Microchip PIC Microcontroller products. The
 software is owned by the Company and/or its supplier, and is
 protected under applicable copyright laws. All rights are reserved.
 Any use in violation of the foregoing restrictions may subject the
 user to criminal sanctions under applicable laws, as well as to
 civil liability for the breach of the terms and conditions of this
 license.

 THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
 WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *******************************************************************/

#include <adc.h>
#include <stdint.h>
#include <stdbool.h>
#include <xc.h>

#include <adc.h>

#define _XTAL_FREQ 12000000
#define delay 20
// G. Calderon. Sep.25, 2015

#define PIN_ANALOG    1
#define PIN_DIGITAL   0

#define PIN_INPUT     1
#define PIN_OUTPUT    0

/*********************************************************************
* Function: ADC_ReadPercentage(ADC_CHANNEL channel);
*
* Overview: Reads the requested ADC channel and returns the percentage 
*            of that conversions result (0-100%).
*
* PreCondition: channel is configured via the ADCConfigure() function
*
* Input: ADC_CHANNEL channel - enumeration of the ADC channels
*        available in this demo.  They should be meaningful names and 
*        not the names of the ADC pins on the device (as the demo code 
*        may be ported to other boards).
*         i.e. ADC_ReadPercentage(ADC_CHANNEL_POTENTIOMETER);
*
* Output: uint8_t indicating the percentage of the result 0-100% or
*         0xFF for an error
*
********************************************************************/
uint8_t ADC_ReadPercentage
    (ADC_CHANNEL channel) {
    uint8_t percent;

    switch(channel)
    {
        case ADC_CHANNEL_10:
            break;
        default:
            return 0xFF;
    }
    
    //A very crude percentage calculation
    percent = (ADC_Read10bit(channel) / 10);

    if(percent > 100)
    {
        percent = 100;
    }
    return percent;
}

/*********************************************************************
* Function: ADC_Read10bit(ADC_CHANNEL channel);
*
* Overview: Reads the requested ADC channel and returns the 10-bit
*           representation of this data.
*
* PreCondition: channel is configured via the ADCConfigure() function
*
* Input: ADC_CHANNEL channel - enumeration of the ADC channels
*        available in this demo.  They should be meaningful names and
*        not the names of the ADC pins on the device (as the demo code
*        may be ported to other boards).
*         i.e. - ADCReadPercentage(ADC_CHANNEL_POTENTIOMETER);
*
* Output: uint16_t the right adjusted 10-bit representation of the ADC
*         channel conversion or 0xFFFF for an error.
*
********************************************************************/
uint16_t ADC_Read10bit(ADC_CHANNEL channel)
{
    uint16_t result;

    switch(channel)
    {
        case ADC_CHANNEL_10:
            break;
        default:
            return 0xFFFF;
    }

    ADCON0bits.CHS = channel;

    ADCON0bits.GO = 1;              // Start AD conversion
    while(ADCON0bits.NOT_DONE);     // Wait for conversion

    result = ADRESH;
    result <<=8;
    result |= ADRESL;

    return result;
}

/*********************************************************************
* Function: bool ADC_Enable(ADC_CHANNEL channel, ADC_CONFIGURATION configuration);
*
* Overview: Configures the ADC module to specified setting
*
* PreCondition: none
*
* Input: ADC_CHANNEL channel - the channel to enable
*        ADC_CONFIGURATION configuration - the mode in which to run the ADC
*
* Output: bool - true if successfully configured.  false otherwise.
*
********************************************************************/
bool ADC_Enable(ADC_CHANNEL channel)
{
    switch(channel)
    {
        case ADC_CHANNEL_10:
            TRISBbits.TRISB4 = PIN_INPUT;
            ANSELHbits.ANS10 = PIN_ANALOG;
            return true;

        default:
            return false;
    }
}

/*********************************************************************
* Function: bool ADC_SetConfiguration(ADC_CONFIGURATION configuration)
*
* Overview: Configures the ADC module to specified setting
*
* PreCondition: none
*
* Input: ADC_CONFIGURATION configuration - the mode in which to run the ADC
*
* Output: bool - true if successfully configured.  false otherwise.
*
********************************************************************/
bool ADC_SetConfiguration(ADC_CONFIGURATION configuration)
{
    if(configuration == ADC_CONFIGURATION_DEFAULT)
    {
        ADCON0=0x29;
        ADCON1=0;
        ADCON2=0x3E;
        ADCON2bits.ADFM = 1;

        return true;
    }

    return false;
}


//Full Step(2-2)
void MotorRight(int *MState)
{   
    switch(*MState) {
        case 0:
            PORTB = 0b10100000;
            *MState = 3;
            break;
        case 1:
            PORTB = 0b10010000;
            *MState = 0;
            break;
        case 2:
            PORTB = 0b01010000;
            *MState = 1;
            break;
        case 3:
            PORTB = 0b01100000;
            *MState = 2;
            break;
    }
    __delay_s(delay);
    PORTB = 0x00;
}

void MotorLeft(int *MState)
{   
    switch(*MState) {
        case 0:
            PORTB = 0b01010000;
            *MState = 1;
            break;
        case 1:
            PORTB = 0b01100000;
            *MState = 2;
            break;
        case 2:
            PORTB = 0b10100000;
            *MState = 3;
            break;
        case 3:
            PORTB = 0b10010000;
            *MState = 0;
            break;
    }
    __delay_s(delay);
    PORTB = 0x00;
}

void MotorSetZero(int *MState)
{
    PORTC = 0b10010000;
    __delay_s(delay);
    PORTC = 0b01010000;
    __delay_s(delay);
    PORTC = 0b01100000;
    __delay_s(delay);
    PORTC = 0b10100000;
    __delay_s(delay);
    PORTC = 0b01100000;
    __delay_s(delay);
    PORTC = 0b01010000;
    __delay_s(delay);
    PORTC = 0b10010000;
    __delay_s(delay);

    PORTB = 0x00;  
}

void __delay_s(int ms)
{
    while (ms--) {
        __delay_ms(1);
    }
}


// G. Calderon
void ADC_IniConfig(void)
{
    // ADC Channel 7
    TRISCbits.TRISC3 = PIN_INPUT;
    ANSELbits.ANS7 = PIN_ANALOG;
    // ADC Channel 8
    TRISCbits.TRISC6 = PIN_INPUT;
    ANSELHbits.ANS8 = PIN_ANALOG;
    // ADC Channel 9
    TRISCbits.TRISC7 = PIN_INPUT;
    ANSELHbits.ANS9 = PIN_ANALOG;
    
//    ADCON0=0x29;  
//    ADCON1 = 0;   
    // Positive voltage reference
    ADCON1bits.PVCFG0 = 0;
    ADCON1bits.PVCFG1 = 0;
    // Negative voltage reference
    ADCON1bits.NVCFG0 = 0;
    ADCON1bits.NVCFG1 = 0; 
    
//    ADCON2 = 0x3E;  
    // 20 T_AD
    ADCON2bits.ACQT = 0b010;
    // T_AD = Fosc/64 = 
    ADCON2bits.ADCS = 0b110;
    // Rigth justified
    ADCON2bits.ADFM = 1;
}
