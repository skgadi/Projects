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
    if( USBUSARTIsTxTrfReady() == true) {
        uint8_t i;
        uint8_t numBytesRead;
        numBytesRead = getsUSBUSART(readBuffer, sizeof(readBuffer));
        if(numBytesRead > 0) {
            DWORD_VAL a, Data;
            switch (readBuffer[0]) {
                case 0x30:
                    PIC18F26K40_enterLowVoltageProg();
                    a.v[3] = 0;
                    a.v[2] = readBuffer[1];
                    a.v[1] = readBuffer[2];
                    a.v[0] = readBuffer[3];
                    PIC18F26K40_loadPC(a);
                    a = PIC18F26K40_readThreeBytes(MSBTOLSB, FALSE);
                    writeBuffer[0] = a.v[1];
                    writeBuffer[1] = a.v[0];
                    PIC18F26K40_exitLowVoltageProg();
                    break;
                case 0x31:
                    PIC18F26K40_enterLowVoltageProg();
                    a.v[3] = 0;
                    a.v[2] = readBuffer[1];
                    a.v[1] = readBuffer[2];
                    a.v[0] = readBuffer[3];
                    PIC18F26K40_loadPC(a);
                    a.v[3] = 0x0;
                    a.v[2] = 0x0;
                    a.v[1] = readBuffer[4];
                    a.v[0] = readBuffer[5];
                    PIC18F26K40_loadDataIntoNVM(a, FALSE, EXTERNALLY);
                    a = PIC18F26K40_readThreeBytes(MSBTOLSB, FALSE);
                    writeBuffer[0] = a.v[1];
                    writeBuffer[1] = a.v[0];
                    PIC18F26K40_exitLowVoltageProg();
                    break;
                case 0x32:
                    PIC18F26K40_enterLowVoltageProg();
                    a.v[3] = 0;
                    a.v[2] = readBuffer[1];
                    a.v[1] = readBuffer[2];
                    a.v[0] = readBuffer[3];
                    Data.v[3] = 0x00;
                    Data.v[2] = 0x0;
                    Data.v[1] = readBuffer[4];
                    Data.v[0] = readBuffer[5];
                    PIC18F26K40_loadPC(a);
                    PIC18F26K40_loadDataIntoNVM(Data, FALSE, EXTERNALLY);
                    PIC18F26K40_loadPC(a);
                    Data = PIC18F26K40_readThreeBytes(MSBTOLSB, FALSE);
                    if ((Data.v[0] == readBuffer[5]) && (Data.v[1] == readBuffer[4]))
                        writeBuffer[0] = 0x01;
                    else
                        writeBuffer[0] = 0x00;
                    PIC18F26K40_exitLowVoltageProg();
                    break;
                case 0x33:
                    PIC18F26K40_enterLowVoltageProg();
                    break;
                case 0x34:
                    PIC18F26K40_exitLowVoltageProg();
                    break;
                case 0x35:
                    a.v[3] = 0;
                    a.v[2] = readBuffer[1];
                    a.v[1] = readBuffer[2];
                    a.v[0] = readBuffer[3];
                    Data.v[3] = 0x00;
                    Data.v[2] = 0x0;
                    Data.v[1] = readBuffer[4];
                    Data.v[0] = readBuffer[5];
                    PIC18F26K40_loadPC(a);
                    PIC18F26K40_loadDataIntoNVM(a, FALSE, EXTERNALLY);
                    PIC18F26K40_loadPC(a);
                    a = PIC18F26K40_readThreeBytes(MSBTOLSB, FALSE);
                    if ((Data.v[0] == readBuffer[5]) && (Data.v[1] == readBuffer[4]))
                        writeBuffer[0] = 0x01;
                    else
                        writeBuffer[0] = 0x00;
                    writeBuffer[1] = readBuffer[0];
                    writeBuffer[2] = readBuffer[1];
                    writeBuffer[3] = readBuffer[2];
                    writeBuffer[4] = readBuffer[3];
                    writeBuffer[5] = readBuffer[4];
                    writeBuffer[6] = readBuffer[5];
                    break;
                case 0x36:
                    for (UINT8 gsk_i=0; gsk_i<10; gsk_i++){
                        a.v[3] = 0;
                        a.v[2] = gsk_i;
                        a.v[1] = 0x00;
                        a.v[0] = 0x31;
                        Data.v[3] = 0x00;
                        Data.v[2] = 0x00;
                        Data.v[1] = gsk_i;
                        Data.v[0] = 0x00;
                        PIC18F26K40_loadPC(a);
                        PIC18F26K40_loadDataIntoNVM(a, FALSE, INTERNALLY);
                        PIC18F26K40_loadPC(a);
                        Data = PIC18F26K40_readThreeBytes(MSBTOLSB, FALSE);
                        writeBuffer[gsk_i] = Data.v[1];
                    }
                    break;
                default:
                    writeBuffer[0] = readBuffer[0];
                    writeBuffer[1] = readBuffer[1];
            }
            putUSBUSART(writeBuffer,15);
        }
    }
    CDCTxService();
}