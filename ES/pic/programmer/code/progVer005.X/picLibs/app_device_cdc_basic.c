/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

To request to license the code under the MLA license (www.microchip.com/mla_license), 
please contact mla_licensing@microchip.com
*******************************************************************************/

/** INCLUDES *******************************************************/
#include "../main.h"
#include "system.h"

#include <stdint.h>
#include <string.h>
#include <stddef.h>

#include "usb.h"

#include "app_led_usb_status.h"
#include "app_device_cdc_basic.h"
#include "usb_config.h"

/** VARIABLES ******************************************************/

static bool buttonPressed;
static char buttonMessage[] = "Button pressed.\r\n";
static uint8_t readBuffer[CDC_DATA_OUT_EP_SIZE];
static uint8_t writeBuffer[CDC_DATA_IN_EP_SIZE];

/*********************************************************************
* Function: void APP_DeviceCDCBasicDemoInitialize(void);
*
* Overview: Initializes the demo code
*
* PreCondition: None
*
* Input: None
*
* Output: None
*
********************************************************************/
void APP_DeviceCDCBasicDemoInitialize()
{   
    line_coding.bCharFormat = 0;
    line_coding.bDataBits = 8;
    line_coding.bParityType = 0;
    line_coding.dwDTERate = 9600;

    buttonPressed = false;
}

/*********************************************************************
* Function: void APP_DeviceCDCBasicDemoTasks(void);
*
* Overview: Keeps the demo running.
*
* PreCondition: The demo should have been initialized and started via
*   the APP_DeviceCDCBasicDemoInitialize() and APP_DeviceCDCBasicDemoStart() demos
*   respectively.
*
* Input: None
*
* Output: None
*
********************************************************************/
void APP_DeviceCDCBasicDemoTasks()
{
    /* If the USB device isn't configured yet, we can't really do anything
     * else since we don't have a host to talk to.  So jump back to the
     * top of the while loop. */
    if( USBGetDeviceState() < CONFIGURED_STATE )
    {
        return;
    }

    /* If we are currently suspended, then we need to see if we need to
     * issue a remote wakeup.  In either case, we shouldn't process any
     * keyboard commands since we aren't currently communicating to the host
     * thus just continue back to the start of the while loop. */
    if( USBIsDeviceSuspended()== true )
    {
        return;
    }
        
    /* If the user has pressed the button associated with this demo, then we
     * are going to send a "Button Pressed" message to the terminal.
     */
    if(BUTTON_IsPressed(BUTTON_DEVICE_CDC_BASIC_DEMO) == true)
    {
        /* Make sure that we only send the message once per button press and
         * not continuously as the button is held.
         */
        if(buttonPressed == false)
        {
            /* Make sure that the CDC driver is ready for a transmission.
             */
            if(mUSBUSARTIsTxTrfReady() == true)
            {
                putrsUSBUSART(buttonMessage);
                buttonPressed = true;
            }
        }
    }
    else
    {
        /* If the button is released, we can then allow a new message to be
         * sent the next time the button is pressed.
         */
        buttonPressed = false;
    }

    /* Check to see if there is a transmission in progress, if there isn't, then
     * we can see about performing an echo response to data received.
     */
    if( USBUSARTIsTxTrfReady() == true)
    {
        uint8_t i;
        uint8_t numBytesRead;
        DWORD_VAL Address, Data;

        numBytesRead = getsUSBUSART(readBuffer, sizeof(readBuffer));

        /* For every byte that was read... */
        //for(i=0; i<numBytesRead; i++)
        if (numBytesRead>0)
        {
            switch(readBuffer[0])
            {
                case 0x0A:
                case 0x0D:
                    putrsUSBUSART("\n\r");
                    /*writeBuffer[i] = readBuffer[i];*/
                    break;
                case 0x30: {
                    PIC18F26K40_enterLowVoltageProg();
                    break;
                }
                case 0x31: {
                    PIC18F26K40_exitLowVoltageProg();
                    break;
                }
                case 0x32: {
                    Address.v[0] = readBuffer[3];
                    Address.v[1] = readBuffer[2];
                    Address.v[2] = readBuffer[1];
                    Address.v[3] = 0;
                    Data.v[0] = readBuffer[5];
                    Data.v[1] = readBuffer[4];
                    Data.v[2] = 0;
                    Data.v[3] = 0;
                    PIC18F26K40_loadPC(Address);
                    PIC18F26K40_loadDataIntoNVM(Data, FALSE);
                    __delay_ms(5);
                    Data.v[0] = 0xff;
                    Data.v[1] = 0xff;
                    Data = PIC18F26K40_readThreeBytes(MSBTOLSB, FALSE);
                    if (Data.v[0] == readBuffer[5])
                        putrsUSBUSART("1");
                    else
                        putrsUSBUSART("0");
                    break;
                }
                case 0x33: {
                    Address.v[0] = (readBuffer[5]-0x30)*10 + (readBuffer[6]-0x30);
                    Address.v[1] = (readBuffer[3]-0x30)*10 + (readBuffer[4]-0x30);
                    Address.v[2] = (readBuffer[1]-0x30)*10 + (readBuffer[2]-0x30);
                    Address.v[3] = 0;
                    Data.v[0] = (readBuffer[9]-0x30)*10 + (readBuffer[10]-0x30);
                    Data.v[1] = (readBuffer[7]-0x30)*10 + (readBuffer[8]-0x30);
                    Data.v[2] = 0;
                    Data.v[3] = 0;
                    PIC18F26K40_loadPC(Address);
                    PIC18F26K40_loadDataIntoNVM(Data, FALSE);
                    __delay_ms(5);
                    Data.v[0] = 0xff;
                    Data.v[1] = 0xff;
                    Data = PIC18F26K40_readThreeBytes(MSBTOLSB, FALSE);
                    /*if (Data.v[0] == readBuffer[5])
                        putrsUSBUSART("1");
                    else
                        putrsUSBUSART("0");*/
                    writeBuffer[0] = Address.v[2];
                    writeBuffer[1] = Address.v[1];
                    writeBuffer[2] = Address.v[0];
                    writeBuffer[3] = Data.v[1];
                    writeBuffer[4] = Data.v[0];
                    putUSBUSART(writeBuffer,5);
                    break;
                }
                case 0x41: {
                    for (i=0; i<10;i++){
                        Address.Val = 0x310000+i;
                        PIC18F26K40_loadPC(Address);
                        Data.Val = GLOBAL_COUNTER;
                        //putrsUSBUSART("GLOBAL_COUNTER is placed at 0x00310002\n\r");
                        PIC18F26K40_loadDataIntoNVM(Data, FALSE);
                        __delay_ms(5);
                        GLOBAL_COUNTER++;
                        if (GLOBAL_COUNTER>122)
                            GLOBAL_COUNTER = 0x30;
                    }
                    putrsUSBUSART("Done Writing.");
                    break;
                }
                default: {
                    for (i=0; i<10;i++){
                        Address.Val = 0x310000+i;
                        PIC18F26K40_loadPC(Address);
                        Data = PIC18F26K40_readThreeBytes(MSBTOLSB, FALSE);
                        writeBuffer[i] = Data.v[0];
                    }
                    putUSBUSART(writeBuffer,10);
                    break;
                }
            }
        }
    }

    CDCTxService();
}