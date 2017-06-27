
#include "usb.h"
#include "usb_device_hid.h"
#include <string.h>
#include "system.h"

#if defined(FIXED_ADDRESS_MEMORY)
    #if defined(COMPILER_MPLAB_C18)
        #pragma udata HID_CUSTOM_OUT_DATA_BUFFER = HID_CUSTOM_OUT_DATA_BUFFER_ADDRESS
        unsigned char ReceivedDataBuffer[64];
        #pragma udata HID_CUSTOM_IN_DATA_BUFFER = HID_CUSTOM_IN_DATA_BUFFER_ADDRESS
        unsigned char ToSendDataBuffer[64];
        #pragma udata

    #else defined(__XC8)
        unsigned char ReceivedDataBuffer[64] @ HID_CUSTOM_OUT_DATA_BUFFER_ADDRESS;
        unsigned char ToSendDataBuffer[64] @ HID_CUSTOM_IN_DATA_BUFFER_ADDRESS;
    #endif
#else
    unsigned char ReceivedDataBuffer[64];
    unsigned char ToSendDataBuffer[64];
#endif

volatile USB_HANDLE USBOutHandle;    
volatile USB_HANDLE USBInHandle;

/** DEFINITIONS ****************************************************/
typedef enum
{
    COMMAND_TOGGLE_LED = 0x80,
    COMMAND_GET_BUTTON_STATUS = 0x81,
    COMMAND_READ_POTENTIOMETER = 0x37
} CUSTOM_HID_DEMO_COMMANDS;

/** FUNCTIONS ******************************************************/

/*********************************************************************
* Function: void APP_DeviceCustomHIDInitialize(void);
*
* Overview: Initializes the Custom HID demo code
*
* PreCondition: None
*
* Input: None
*
* Output: None
*
********************************************************************/
void APP_DeviceCustomHIDInitialize()
{
    //initialize the variable holding the handle for the last
    // transmission
    USBInHandle = 0;

    //enable the HID endpoint
    USBEnableEndpoint(CUSTOM_DEVICE_HID_EP, USB_IN_ENABLED|USB_OUT_ENABLED|USB_HANDSHAKE_ENABLED|USB_DISALLOW_SETUP);

    //Re-arm the OUT endpoint for the next packet
    USBOutHandle = (volatile USB_HANDLE)HIDRxPacket(CUSTOM_DEVICE_HID_EP,(uint8_t*)&ReceivedDataBuffer,64);
}

/*********************************************************************
* Function: void APP_DeviceCustomHIDTasks(void);
*
* Overview: Keeps the Custom HID demo running.
*
* PreCondition: The demo should have been initialized and started via
*   the APP_DeviceCustomHIDInitialize() and APP_DeviceCustomHIDStart() demos
*   respectively.
*
* Input: None
*
* Output: None
*
********************************************************************/
void APP_DeviceCustomHIDTasks(int *MState)
{   
    int i, nSteps;
    //Check if we have received an OUT data packet from the host
    if(HIDRxHandleBusy(USBOutHandle) == false)
    {   
        //We just received a packet of data from the USB host.
        //Check the first uint8_t of the packet to see what command the host
        //application software wants us to fulfill.
        switch(ReceivedDataBuffer[0])				//Look at the data the host sent, to see what kind of application specific command it sent.
        {
            case 1:
                MotorLeft(MState);
                break;
            case 2:
                MotorRight(MState);
                break;
            case 3:
                nSteps = ReceivedDataBuffer[1];
                for(i=1; i<=nSteps; i++) {
                    MotorLeft(MState);
                }
                break;
            case 4:
                nSteps = ReceivedDataBuffer[1];
                for(i=1; i<=nSteps; i++) {
                    MotorRight(MState);
                }           
                break;
            case 5:
                MotorSetZero(MState);
                break;             
            case 6:
                if(!HIDTxHandleBusy(USBInHandle)) {
                    ToSendDataBuffer[0] = 0x37; //Echo back to the host.
                        ADCON0bits.CHS = 0b0111; // Channel ANS7, RC3
                        ADCON0bits.GO = 1;          // Start AD conversion
                        while(ADCON0bits.NOT_DONE); // Wait for conversion
                        ToSendDataBuffer[1] = ADRESL; //LSB
                        ToSendDataBuffer[2] = ADRESH; //MSB
                        
                        ADCON0bits.CHS = 0b1000; // Channel ANS8, RC6
                        ADCON0bits.GO = 1;          // Start AD conversion
                        while(ADCON0bits.NOT_DONE); // Wait for conversion
                        ToSendDataBuffer[3] = ADRESL; //LSB
                        ToSendDataBuffer[4] = ADRESH; //MSB
                       
                        ADCON0bits.CHS = 0b1001; // Channel ANS9, RC7
                        ADCON0bits.GO = 1;          // Start AD conversion
                        while(ADCON0bits.NOT_DONE); // Wait for conversion
                        ToSendDataBuffer[5] = ADRESL; //LSB
                        ToSendDataBuffer[6] = ADRESH; //MSB
                    USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
                }                
                break;
            }
        //Re-arm the OUT endpoint, so we can receive the next OUT data packet 
        //that the host may try to send us.
        USBOutHandle = HIDRxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ReceivedDataBuffer,64);
    }
}