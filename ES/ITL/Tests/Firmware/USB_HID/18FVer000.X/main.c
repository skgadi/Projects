/*
 * File:   newmain.c
 * Author: gadis
 *
 * Created on September 24, 2016, 9:45 AM
 */


#include "main.h"

//#include "app_device_custom_hid.h"

void main(void) {
    USBDeviceInit();
    USBDeviceAttach();
    //USBDeviceTasks();
    //APP_DeviceCustomHIDInitialize();
    while (1) {
                //#if defined(USB_POLLING)
            // Interrupt or polling method.  If using polling, must call
            // this function periodically.  This function will take care
            // of processing and responding to SETUP transactions
            // (such as during the enumeration process when you first
            // plug in).  USB hosts require that USB devices should accept
            // and process SETUP packets in a timely fashion.  Therefore,
            // when using polling, this function should be called
            // regularly (such as once every 1.8ms or faster** [see
            // inline code comments in usb_device.c for explanation when
            // "or faster" applies])  In most cases, the USBDeviceTasks()
            // function does not take very long to execute (ex: <100
            // instruction cycles) before it returns.
          //  USBDeviceTasks(); // Check bus status and service USB interrupts.
        //#endif
        USBActivity();
    }
    return;
}


