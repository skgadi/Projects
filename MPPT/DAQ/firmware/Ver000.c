//************************************************************************************
//**  
//**  File name:     D:\GitHub\Programming\Flowcode\DAQCard\Ver000.c
//**  Title:         
//**  Description:   
//**  
//**  Generated by:  Flowcode v5.4.0.0
//**  Date:          Wednesday, February 15, 2017 15:07:47
//**  Licence:       Professional
//**  Registered to: asdf
//**  Licence key:   DEEZ38
//**  
//**  
//**  http://www.matrixmultimedia.com
//**  
//************************************************************************************


#define MX_PIC

#define MX_USES_UINT8 1
#define MX_USES_SINT16 0
#define MX_USES_CHAR 2
#define MX_USES_FLOAT 0
#define MX_USES_SINT32 0
#define MX_USES_BOOL 1
#define MX_USES_UINT16 1
#define MX_USES_UINT32 0
//Defines for microcontroller
#define P18F14K50
#define FC_CAL_PIC
#define MX_ADC
#define MX_ADC_TYPE_19
#define MX_ADC_BITS_10
#define MX_EE
#define MX_EE_TYPE3
#define MX_EE_SIZE 256
#define MX_SPI_1
#define MX_SPI_1_MISO_PORT portb
#define MX_SPI_1_MISO_TRIS trisb
#define MX_SPI_1_MISO_PIN 0
#define MX_SPI_1_MOSI_PORT portc
#define MX_SPI_1_MOSI_TRIS trisc
#define MX_SPI_1_MOSI_PIN 7
#define MX_SPI_1_CLK_PORT portb
#define MX_SPI_1_CLK_TRIS trisb
#define MX_SPI_1_CLK_PIN 1
#define MX_SPI_1_SS_PORT porta
#define MX_SPI_1_SS_TRIS trisa
#define MX_SPI_1_SS_PIN 5
#define MX_UART_1
#define MX_UART_1_TX_PORT portb
#define MX_UART_1_TX_TRIS trisb
#define MX_UART_1_TX_PIN 7
#define MX_UART_1_RX_PORT portb
#define MX_UART_1_RX_TRIS trisb
#define MX_UART_1_RX_PIN 5
#define MX_I2C
#define MX_MI2C
#define MX_I2C_1
#define MX_I2C_1_SDA_PORT portb
#define MX_I2C_1_SDA_TRIS trisb
#define MX_I2C_1_SDA_PIN 4
#define MX_I2C_1_SCL_PORT portb
#define MX_I2C_1_SCL_TRIS trisb
#define MX_I2C_1_SCL_PIN 6
#define MX_PWM
#define MX_PWM_CNT 1
#define MX_PWM_PSCA1
#define MX_PWM_PSCA4
#define MX_PWM_PSCA16
#define MX_PWM_1_PORT portc
#define MX_PWM_1_TRIS trisc
#define MX_PWM_1_PIN 5
#define MX_USB_TYPE3

//Functions
#define MX_CLK_SPEED 12000000
#ifdef _BOOSTC
#include <system.h>
#endif
#ifdef HI_TECH_C
#include <pic18.h>
#endif

//Configuration data
#ifdef _BOOSTC
#pragma DATA 0x300000, 0x38
#endif
#ifdef _HI_TECH_C
%C__CONFIG(%A, %V);
#endif
#ifdef _BOOSTC
#pragma DATA 0x300001, 0x32
#endif
#ifdef _HI_TECH_C
%C__CONFIG(%A, %V);
#endif
#ifdef _BOOSTC
#pragma DATA 0x300002, 0x1f
#endif
#ifdef _HI_TECH_C
%C__CONFIG(%A, %V);
#endif
#ifdef _BOOSTC
#pragma DATA 0x300003, 0x1e
#endif
#ifdef _HI_TECH_C
%C__CONFIG(%A, %V);
#endif
#ifdef _BOOSTC
#pragma DATA 0x300004, 0xff
#endif
#ifdef _HI_TECH_C
%C__CONFIG(%A, %V);
#endif
#ifdef _BOOSTC
#pragma DATA 0x300005, 0x8
#endif
#ifdef _HI_TECH_C
%C__CONFIG(%A, %V);
#endif
#ifdef _BOOSTC
#pragma DATA 0x300006, 0x88
#endif
#ifdef _HI_TECH_C
%C__CONFIG(%A, %V);
#endif
#ifdef _BOOSTC
#pragma DATA 0x300007, 0xff
#endif
#ifdef _HI_TECH_C
%C__CONFIG(%A, %V);
#endif
#ifdef _BOOSTC
#pragma DATA 0x300008, 0x3
#endif
#ifdef _HI_TECH_C
%C__CONFIG(%A, %V);
#endif
#ifdef _BOOSTC
#pragma DATA 0x300009, 0xc0
#endif
#ifdef _HI_TECH_C
%C__CONFIG(%A, %V);
#endif
#ifdef _BOOSTC
#pragma DATA 0x30000a, 0x3
#endif
#ifdef _HI_TECH_C
%C__CONFIG(%A, %V);
#endif
#ifdef _BOOSTC
#pragma DATA 0x30000b, 0xe0
#endif
#ifdef _HI_TECH_C
%C__CONFIG(%A, %V);
#endif
#ifdef _BOOSTC
#pragma DATA 0x30000c, 0x3
#endif
#ifdef _HI_TECH_C
%C__CONFIG(%A, %V);
#endif
#ifdef _BOOSTC
#pragma DATA 0x30000d, 0x40
#endif
#ifdef _HI_TECH_C
%C__CONFIG(%A, %V);
#endif

//Internal functions
#include "C:\Program Files (x86)\Flowcode\v5\FCD\internals.c"

//Macro function declarations


//Variable declarations
#define FCSZ_OUTSTRING 2
#define FCV_TRUE (1)
#define FCV_FALSE (0)
MX_UINT16 FCV_READINPUT;
MX_UINT8 FCV_OUTSTR;
MX_UINT8 FCV_OPERATION;
MX_CHAR FCV_OUTSTRING[FCSZ_OUTSTRING];




//USBSerial(0): //Defines:

/**** Macro Substitutions ****
a = Vendor ID
b = Product ID
c = Device Name
d = Device manufacturer
e = Version Number A
f = Version Number B
g = Enumeration Wait Enable
h = Enumeration Wait Time
k = Length of Device Name String
l = Length of Device Manufacturer String
******************************/

	// Component Defines
	#define MX_VID 			0x12BF				//Eg 0x04D8
	#define MX_PID 			0xF010				//Eg 0x000C

	#define MX_VERSION		(1	<< 8) + 0	//Eg 0x0200 = 2.0
	#define MX_ENUMTIME		10				//Eg 1 - 255
	#define MX_ENUMWAIT		0				//Eg 1 or 0

	#ifdef FC_CAL_PIC							//8-bit PIC specific

		MX_UINT8 MX_USBNAME[40] = {40,3,'F',0,'l',0,'o',0,'w',0,'c',0,'o',0,'d',0,'e',0,' ',0,'U',0,'S',0,'B',0,' ',0,'S',0,'e',0,'r',0,'i',0,'a',0,'l',0};		//Device name
		MX_UINT8 MX_USBMFR[46] = {46,3,'M',0,'a',0,'t',0,'r',0,'i',0,'x',0,' ',0,'M',0,'u',0,'l',0,'t',0,'i',0,'m',0,'e',0,'d',0,'i',0,'a',0,' ',0,'L',0,'t',0,'d',0,'.',0};			//Manufacturer

		// Global Defines
		#define CDC_TX_BUFFER_SIZE 	64
		#define CDC_RX_BUFFER_SIZE 	64
		#define CDC_DATA_ENDPOINT	3
		#define USB_HIGHEST_EP 		3
		#define USB_BUS_POWERED

		#ifdef MX_USB_TYPE1									//2455 Family
			#define USB_DESCRIPTOR_BASE_ADDRESS	0x400
			#define USB_EP0_OUT_ADDR 	0x0500
			#define USB_EP0_IN_ADDR 	0x0508
			#define USB_EP2_IN_ADDR		0x0510
			#define USB_EP3_OUT_ADDR	0x0518
			#define USB_EP3_IN_ADDR		0x0520
		#endif

		#ifdef MX_USB_TYPE2									//2450 Family
			#define USB_DESCRIPTOR_BASE_ADDRESS	0x400
			#define USB_EP0_OUT_ADDR 	0x0480
			#define USB_EP0_IN_ADDR 	0x0488
			#define USB_EP2_IN_ADDR		0x0490
			#define USB_EP3_OUT_ADDR	0x0498
			#define USB_EP3_IN_ADDR		0x04A0
		#endif

		#ifdef MX_USB_TYPE3									//14K50 Family
			#define USB_DESCRIPTOR_BASE_ADDRESS	0x200
			#define USB_EP0_OUT_ADDR 	0x0280
			#define USB_EP0_IN_ADDR 	0x0288
			#define USB_EP2_IN_ADDR		0x0290
			#define USB_EP3_OUT_ADDR	0x0298
			#define USB_EP3_IN_ADDR		0x02A0
		#endif

		#ifdef MX_USB_TYPE4									//24J53 Family
			#define USB_DESCRIPTOR_BASE_ADDRESS	0xD00
			#define USB_EP0_OUT_ADDR 	0x0E00
			#define USB_EP0_IN_ADDR 	0x0E08
			#define USB_EP2_IN_ADDR		0x0E10
			#define USB_EP3_OUT_ADDR	0x0E18
			#define USB_EP3_IN_ADDR		0x0E20
		#endif

		#ifndef USB_DESCRIPTOR_BASE_ADDRESS
			#error "Target device does not have USB functionality"
		#endif

		#ifdef HI_TECH_C
			#error "USB library only supported by the BoostC compiler"
		#endif

		#define USB_EP0_OUT_SIZE 	8
		#define USB_EP0_IN_SIZE 	8
		#define USB_EP2_IN_SIZE		8
		#define USB_EP3_OUT_SIZE	8
		#define USB_EP3_IN_SIZE		8

		#define USB_CALLBACK_ON_SOF
		#define USB_CALLBACK_ON_DEVICE_CONFIGURED
		#define USB_CALLBACK_ON_CTRL_CLASS
		#define USB_EP_DATA_CALLBACK

		//Serial Number
		MX_UINT8 MX_SERIAL[10] = {10,3,'0',0,'0',0,'0',0,'1',0};

		// USB library includes
		#include "USB/pic_utils.h"
		#include "USB/pic_usb_buffer_mgt.c"
		#include "USB/pic_usb.c"
		#include "USB/usb_cdc_class.c"
		#include "USB/usb_config_serial.c"

		// Variable to hold status of the USB connection
		MX_UINT8 CDC_USB_status = 0;

		// Variable to hold incoming data
		MX_UINT8 CDC_USB_Rx_String[CDC_RX_BUFFER_SIZE];

		void usb_device_configured_callback(void)
		{
			CDC_USB_status = 1;
		}

	#endif

	#ifdef FC_CAL_PIC16BIT						//16-bit PIC specific

		#ifndef MX_USB
			#error "Your target device does not support USB components"
		#endif

		// Global Defines
		#define USB_BUS_SENSE       1
		#define self_power          1
		#define tris_usb_bus_sense	1
		#define tris_self_power		1

		#define USB_CONFIG	"usb_serial_config.h"

		// USB library includes
		#include "../../USB/usb_serial_config.h"
		#include "../../USB/usb.h"
		#include "../../USB/usb_function_cdc.h"
		#include "../../USB/GenericTypeDefs.h"
		#include "../../USB/Compiler.h"
		#include "../../USB/usb_device.h"
		#include "../../USB/usb_device.c"
		#include "../../USB/usb_ch9.h"
		#include "../../USB/usb_cdc_handler.c"
		#include "../../USB/usb_hal_pic24.c"
		#include "../../USB/usb_function_cdc.c"
		#include "../../USB/usb_common.h"
		#include "../../USB/usb_hal.h"
		#include "../../USB/usb_hal_pic24.h"

		// Device name and manufacturer
		ROM struct{BYTE bLength;BYTE bDscType;WORD string[40];}sd001={sizeof(sd001),USB_DESCRIPTOR_STRING,{{40,3,'F',0,'l',0,'o',0,'w',0,'c',0,'o',0,'d',0,'e',0,' ',0,'U',0,'S',0,'B',0,' ',0,'S',0,'e',0,'r',0,'i',0,'a',0,'l',0};}};
		ROM struct{BYTE bLength;BYTE bDscType;WORD string[46];}sd002={sizeof(sd002),USB_DESCRIPTOR_STRING,{{46,3,'M',0,'a',0,'t',0,'r',0,'i',0,'x',0,' ',0,'M',0,'u',0,'l',0,'t',0,'i',0,'m',0,'e',0,'d',0,'i',0,'a',0,' ',0,'L',0,'t',0,'d',0,'.',0};}};

		#include "../../USB/usb_serial_descriptors.c"

	#endif




//USBSerial(0): //Macro function declarations

void FCD_USBSerial0_configure_system();
MX_UINT8 FCD_USBSerial0_Initialise_Serial();
MX_UINT8 FCD_USBSerial0_SendByte(MX_UINT8 byte);
MX_UINT8 FCD_USBSerial0_SendString(MX_STRING String, MX_UINT8 MSZ_String);
MX_UINT8 FCD_USBSerial0_ReadByte(MX_UINT8 timeout_ms);
void FCD_USBSerial0_ReadString(MX_CHAR* FCR_RETVAL, MX_UINT8 FCR_RETVAL_SIZE, MX_UINT8 timeout_ms, MX_UINT8 length);


//ADC(0): //Defines:

/**** Macro Substitutions ****
a = Unique Reference
b = Which ADC Channel
c = Acquisition time
d = Conversion Speed
e = VRef+ Option
f = VRef Voltage x 0.01V
******************************/

//Common Defines

#define ADC_2_MX_ADC_CHANNEL	3
#define ADC_2_MX_ADC_ACTIME	40
#define ADC_2_MX_ADC_CONVSP	3
#define ADC_2_MX_ADC_VREFOP	0
#define ADC_2_MX_ADC_VREFVOL	500

#ifndef MX_ADC_CHANNEL_3
 #define MX_ADC_CHANNEL_3			//Inform CAL ADC channel 3 is now in use.
#endif

#ifndef MX_ADC_REF					//Inform CAL ADC peripheral is now in use
 #define MX_ADC_REF
#endif

extern void FC_CAL_Enable_ADC (MX_UINT8 Channel, MX_UINT8 Conv_Speed, MX_UINT8 Vref, MX_UINT8 T_Charge);
extern MX_UINT16 FC_CAL_Sample_ADC (MX_UINT8 Sample_Mode);
extern void FC_CAL_Disable_ADC (void);




//ADC(0): //Macro function declarations

void FCD_ADC0_SampleADC();
MX_UINT8 FCD_ADC0_ReadAsByte();
MX_UINT16 FCD_ADC0_ReadAsInt();
MX_FLOAT FCD_ADC0_ReadAsVoltage();
void FCD_ADC0_ReadAsString(MX_CHAR* FCR_RETVAL, MX_UINT8 FCR_RETVAL_SIZE);
void FCD_ADC0_ADC_RAW_Configure_Channel();
MX_UINT8 FCD_ADC0_ADC_RAW_Sample_Channel_Byte();
MX_UINT16 FCD_ADC0_ADC_RAW_Sample_Channel_Int();
MX_UINT8 FCD_ADC0_ADC_RAW_Average_Channel_Byte(MX_UINT8 NumSamples, MX_UINT8 DelayUs);
MX_UINT16 FCD_ADC0_ADC_RAW_Average_Channel_Int(MX_UINT8 NumSamples, MX_UINT8 DelayUs);
void FCD_ADC0_ADC_RAW_Disable_Channel();


//ADC(1): //Defines:

/**** Macro Substitutions ****
a = Unique Reference
b = Which ADC Channel
c = Acquisition time
d = Conversion Speed
e = VRef+ Option
f = VRef Voltage x 0.01V
******************************/

//Common Defines

#define ADC_3_MX_ADC_CHANNEL	4
#define ADC_3_MX_ADC_ACTIME	40
#define ADC_3_MX_ADC_CONVSP	3
#define ADC_3_MX_ADC_VREFOP	0
#define ADC_3_MX_ADC_VREFVOL	500

#ifndef MX_ADC_CHANNEL_4
 #define MX_ADC_CHANNEL_4			//Inform CAL ADC channel 4 is now in use.
#endif

#ifndef MX_ADC_REF					//Inform CAL ADC peripheral is now in use
 #define MX_ADC_REF
#endif

extern void FC_CAL_Enable_ADC (MX_UINT8 Channel, MX_UINT8 Conv_Speed, MX_UINT8 Vref, MX_UINT8 T_Charge);
extern MX_UINT16 FC_CAL_Sample_ADC (MX_UINT8 Sample_Mode);
extern void FC_CAL_Disable_ADC (void);




//ADC(1): //Macro function declarations

void FCD_ADC1_SampleADC();
MX_UINT8 FCD_ADC1_ReadAsByte();
MX_UINT16 FCD_ADC1_ReadAsInt();
MX_FLOAT FCD_ADC1_ReadAsVoltage();
void FCD_ADC1_ReadAsString(MX_CHAR* FCR_RETVAL, MX_UINT8 FCR_RETVAL_SIZE);
void FCD_ADC1_ADC_RAW_Configure_Channel();
MX_UINT8 FCD_ADC1_ADC_RAW_Sample_Channel_Byte();
MX_UINT16 FCD_ADC1_ADC_RAW_Sample_Channel_Int();
MX_UINT8 FCD_ADC1_ADC_RAW_Average_Channel_Byte(MX_UINT8 NumSamples, MX_UINT8 DelayUs);
MX_UINT16 FCD_ADC1_ADC_RAW_Average_Channel_Int(MX_UINT8 NumSamples, MX_UINT8 DelayUs);
void FCD_ADC1_ADC_RAW_Disable_Channel();



//USBSerial(0): //Macro implementations


void FCD_USBSerial0_configure_system()
{
	
	  #ifdef FC_CAL_PIC							//8-bit PIC specific
		kill_interrupts();						//turn off interrupts just in case
		usb_cdc_setup();
		usb_setup();
		turn_peripheral_ints_on();
		turn_global_ints_on();
	  #endif

}

MX_UINT8 FCD_USBSerial0_Initialise_Serial()
{
	
	  #ifdef FC_CAL_PIC															//8-bit PIC specific
		usb_configure_structures();
		FCD_USBSerial0_configure_system();
		usb_enable_module();
	  #else																		//16-bit PIC specific
		USBDeviceInit();
		if(USB_BUS_SENSE && (USBGetDeviceState() == DETACHED_STATE))
			USBDeviceAttach();
	  #endif

		#if MX_ENUMWAIT == 1

			MX_UINT16 delay_counter = 0;

		  #ifdef FC_CAL_PIC														//8-bit PIC specific
			while(CDC_USB_status == 0 && delay_counter < 10000)					//Wait for USB to startup and enumerate
		  #else
		  	while(USBDeviceState != CONFIGURED_STATE && delay_counter < 10000)	//Wait for USB to startup and enumerate
		  #endif
			{
				delay_counter = delay_counter + 1;
				delay_10us(MX_ENUMTIME);										//Max wait
				delay_10us(MX_ENUMTIME);
				delay_10us(MX_ENUMTIME);
				delay_10us(MX_ENUMTIME);
				delay_10us(MX_ENUMTIME);
				delay_10us(MX_ENUMTIME);
				delay_10us(MX_ENUMTIME);
				delay_10us(MX_ENUMTIME);
				delay_10us(MX_ENUMTIME);
				delay_10us(MX_ENUMTIME);
			}

		  #ifdef FC_CAL_PIC														//8-bit PIC specific
			if (CDC_USB_status == 1)
		  #else																	//16-bit PIC specific
		  	if (USBDeviceState == CONFIGURED_STATE)
		  #endif
				return 0;
			return 0xFF;

		#else
		  #ifdef FC_CAL_PIC														//8-bit PIC specific
			while(CDC_USB_status == 0);
		  #else																	//16-bit PIC specific
		  	while(USBDeviceState != CONFIGURED_STATE);
		  #endif

		#endif
		return 0;

}

MX_UINT8 FCD_USBSerial0_SendByte(MX_UINT8 byte)
{
	
		MX_UINT16 timeout = 0;

	  #ifdef FC_CAL_PIC														//8-bit PIC specific

		while (usb_cdc_tx_empty() == 0 && timeout < 32000)					//Wait for outgoing buffer to empty
			timeout = timeout + 1;

		if (timeout == 32000)												//Pipeline full or disconnected
			return(1);

		usb_cdc_putc(byte);

	  #endif

	  #ifdef FC_CAL_PIC16BIT												//16-bit PIC specific

	  	if((USBDeviceState < CONFIGURED_STATE)||(USBSuspendControl==1))
	  	{
	  		return(2);														//USB Not Configured
	  	}
	  	else
	  	{
			CDCTxService();													//Required or every other send fails
			while (mUSBUSARTIsTxTrfReady() == 0 && timeout < 32000)			//Wait for outgoing buffer to empty
				timeout = timeout + 1;

			if (timeout == 32000)											//Pipeline full or disconnected
			{
				return(1);													//USB Not Ready
			}
			else
			{
				putUSBUSART(&byte,1);
			}
		}
		CDCTxService();

	  #endif

		return(0);

}

MX_UINT8 FCD_USBSerial0_SendString(MX_STRING String, MX_UINT8 MSZ_String)
{
		MX_UINT16 timeout = 0;

	  #ifdef FC_CAL_PIC														//8-bit PIC specific

		while (usb_cdc_tx_empty() == 0 && timeout < 32000)					//Wait for outgoing buffer to empty
			timeout = timeout + 1;

		if (timeout == 32000)												//Pipeline full or disconnected
			return(1);

		usb_cdc_print_str(String);

	  #endif

	  #ifdef FC_CAL_PIC16BIT												//16-bit PIC specific

		if((USBDeviceState < CONFIGURED_STATE)||(USBSuspendControl==1))
		{
			return(2);														//USB Not Configured
		}
		else
		{
			CDCTxService();													//Required or every other send fails

			while (mUSBUSARTIsTxTrfReady() == 0 && timeout < 32000)			//Wait for outgoing buffer to empty
				timeout = timeout + 1;

			if (timeout == 32000)											//Pipeline full or disconnected
			{
				retval(1);													//USB Not Ready
			}
			else
			{
				putUSBUSART(String,MSZ_String);
			}
		}
		CDCTxService();

	  #endif

		return 0;
}

MX_UINT8 FCD_USBSerial0_ReadByte(MX_UINT8 timeout_ms)
{
	
		MX_UINT8 waitforever = 0;

	  #ifdef FC_CAL_PIC											//8-bit PIC specific

		static MX_UINT8 position = 0;
		static MX_UINT8 length = 0;
		MX_UINT8 retval = 255;

		if(timeout_ms == 255)
			waitforever = 1;

		if (position == length)									// end of local string?
		{
			position = 0;

			length = usb_cdc_rx_avail();						// get length of incoming data string

			while (length == 0 && (timeout_ms || waitforever))	// wait for timeout_ms
			{
				Wdt_Delay_Ms(1);
				length = usb_cdc_rx_avail();					// get length of incoming data string
				timeout_ms = timeout_ms - 1;					// decrement timeout_ms
			}

			if(length == 0)
				return (retval);								// return no data flag 255 / 0xFF

			usb_ep_get_rx_buffer(length, CDC_USB_Rx_String);	// copy data string to local buffer
		}

		retval = CDC_USB_Rx_String[position];

		position = position + 1;

		return (retval);

	  #endif

	  #ifdef FC_CAL_PIC16BIT									//16-bit PIC specific

		MX_UINT8 retval[1];
		MX_UINT8 inner = 0;
		MX_UINT16 numBytesRead = 0;

		retval[0] = 255;

		if(timeout_ms == 255)
			waitforever = 1;

		while(numBytesRead == 0 && timeout_ms > 0)
		{
			numBytesRead = getsUSBUSART(retval,1);
			if (waitforever == 0 && numBytesRead == 0)
			{
				inner++;
				delay_us(10);
				if (inner == 100)
				{
					inner = 0;
					timeout_ms--;
				}
			}
		}
		return (retval[0]);

	  #endif

}

void FCD_USBSerial0_ReadString(MX_CHAR* FCR_RETVAL, MX_UINT8 FCR_RETVAL_SIZE, MX_UINT8 timeout_ms, MX_UINT8 length)
{
		MX_UINT8 waitforever = 0;

	  #ifdef FC_CAL_PIC											//8-bit PIC specific

		MX_UINT8 Rx_Length;

		if(length > FCR_RETVAL_SIZE)
			length = FCR_RETVAL_SIZE;

		if(timeout_ms == 255)
			waitforever = 1;

		while (timeout_ms || waitforever)
		{
			Rx_Length = usb_cdc_rx_avail();						// get length of incoming data string
			if (Rx_Length)
			{
				if (Rx_Length > length)
					Rx_Length = length;

				usb_ep_get_rx_buffer(Rx_Length, FCR_RETVAL);	// copy data string to local buffer

				if (Rx_Length < length)
					FCR_RETVAL[Rx_Length] = 0;					//Add null MX_UINT8acter to end of string
				return;
			}
			else
			{
				Wdt_Delay_Ms(1);
				timeout_ms = timeout_ms - 1;
			}
		}

	  #endif

	  #ifdef FC_CAL_PIC16BIT									//16-bit PIC specific

		MX_UINT8 inner = 0;
		MX_UINT16 numBytesRead = 0;

		if(length > FCR_RETVAL_SIZE)
			length = FCR_RETVAL_SIZE;

		if(timeout_ms == 255)
			waitforever = 1;

		while(numBytesRead == 0 && timeout_ms > 0)
		{
			numBytesRead = getsUSBUSART(FCR_RETVAL, length);
			if (waitforever == 0 && numBytesRead == 0)
			{
				inner++;
				delay_us(10);
				if (inner == 100)
				{
					inner = 0;
					timeout_ms--;
				}
			}
		}

	  #endif

}



//ADC(0): //Macro implementations


void FCD_ADC0_SampleADC()
{
	
	    //unused

}

MX_UINT8 FCD_ADC0_ReadAsByte()
{
	
		MX_UINT8 retVal;

		//Configure & Enable ADC Channel
		FC_CAL_Enable_ADC ( ADC_2_MX_ADC_CHANNEL , ADC_2_MX_ADC_CONVSP , ADC_2_MX_ADC_VREFOP , ADC_2_MX_ADC_ACTIME );

		retVal = FC_CAL_Sample_ADC( 0 );				//Perform Sample - Return as byte

		FC_CAL_Disable_ADC ();

		return (retVal);

}

MX_UINT16 FCD_ADC0_ReadAsInt()
{
	
		MX_UINT16 retVal;

		//Configure & Enable ADC Channel
		FC_CAL_Enable_ADC ( ADC_2_MX_ADC_CHANNEL , ADC_2_MX_ADC_CONVSP , ADC_2_MX_ADC_VREFOP , ADC_2_MX_ADC_ACTIME );

		retVal = FC_CAL_Sample_ADC( 1 );				//Perform Sample - Return as MX_UINT16

		FC_CAL_Disable_ADC ();

		return (retVal);

}

MX_FLOAT FCD_ADC0_ReadAsVoltage()
{
	
		MX_UINT16 iSample;
		MX_FLOAT fSample, fVoltage, fVperDiv;

		//Configure & Enable ADC Channel
		FC_CAL_Enable_ADC ( ADC_2_MX_ADC_CHANNEL , ADC_2_MX_ADC_CONVSP , ADC_2_MX_ADC_VREFOP , ADC_2_MX_ADC_ACTIME );

	  #ifdef MX_ADC_BITS_8
		iSample = FC_CAL_Sample_ADC( 0 );								//Perform Sample - Return as byte
	  #else
		iSample = FC_CAL_Sample_ADC( 1 );								//Perform Sample - Return as MX_UINT16
	  #endif

	  	FC_CAL_Disable_ADC ();											//Switch off ADC peripheral
		fVoltage = flt_fromi( ADC_2_MX_ADC_VREFVOL );						//Convert reference voltage count to floating point (0 - 500 x 10mV)
		fVoltage = flt_mul(fVoltage, 0.01);								//Convert reference voltage count to actual voltage (0 - 5)

	  #ifdef MX_ADC_BITS_8
		fVperDiv = flt_mul(fVoltage, 0.00390625);						//Convert actual voltage to voltage per division (VRef / 256)
	  #endif
	  #ifdef MX_ADC_BITS_10
		fVperDiv = flt_mul(fVoltage, 0.000976);							//Convert actual voltage to voltage per division (VRef / 1024)
	  #endif
	  #ifdef MX_ADC_BITS_12
		fVperDiv = flt_mul(fVoltage, 0.00024414);						//Convert actual voltage to voltage per division (VRef / 4096)
	  #endif

		fSample = flt_fromi(iSample);									//Convert to floating point variable
		fVoltage = flt_mul(fSample, fVperDiv);							//Calculate floating point voltage

		return (fVoltage);

}

void FCD_ADC0_ReadAsString(MX_CHAR* FCR_RETVAL, MX_UINT8 FCR_RETVAL_SIZE)
{
	
		MX_FLOAT fVoltage;

		fVoltage = FCD_ADC0_ReadAsVoltage();
		FCI_FLOAT_TO_STRING(fVoltage, 2, FCR_RETVAL, FCR_RETVAL_SIZE);	//Convert to String

}

void FCD_ADC0_ADC_RAW_Configure_Channel()
{
	
		//Configure & Enable ADC Channel
		FC_CAL_Enable_ADC ( ADC_2_MX_ADC_CHANNEL , ADC_2_MX_ADC_CONVSP , ADC_2_MX_ADC_VREFOP , ADC_2_MX_ADC_ACTIME );

}

MX_UINT8 FCD_ADC0_ADC_RAW_Sample_Channel_Byte()
{
	
		return FC_CAL_Sample_ADC( 0 );									//Perform Sample - Return as byte

}

MX_UINT16 FCD_ADC0_ADC_RAW_Sample_Channel_Int()
{
	
		return FC_CAL_Sample_ADC( 1 );									//Perform Sample - Return as MX_UINT16

}

MX_UINT8 FCD_ADC0_ADC_RAW_Average_Channel_Byte(MX_UINT8 NumSamples, MX_UINT8 DelayUs)
{
	
		MX_UINT32 average = 0;
		MX_UINT8 count;

		for (count=0; count<NumSamples; count++)
		{
			average = average + FC_CAL_Sample_ADC( 0 );					//Perform Sample - Return as byte - add to average

			if (DelayUs)
				delay_us(DelayUs);										//If delay is not 0 then pause between samples
		}
		average = average / count;

		return (average & 0xFF);										//Return average as byte

}

MX_UINT16 FCD_ADC0_ADC_RAW_Average_Channel_Int(MX_UINT8 NumSamples, MX_UINT8 DelayUs)
{
	
		MX_UINT32 average = 0;
		MX_UINT8 count;

		for (count=0; count<NumSamples; count++)
		{
			average = average + FC_CAL_Sample_ADC( 1 );					//Perform Sample - Return as MX_UINT16 - add to average

			if (DelayUs)
				delay_us(DelayUs);										//If delay is not 0 then pause between samples
		}
		average = average / count;

		return (average & 0x1FFF);										//Return average as MX_SINT16

}

void FCD_ADC0_ADC_RAW_Disable_Channel()
{
	
		FC_CAL_Disable_ADC ();											//Disable ADC Channel

}



//ADC(1): //Macro implementations


void FCD_ADC1_SampleADC()
{
	
	    //unused

}

MX_UINT8 FCD_ADC1_ReadAsByte()
{
	
		MX_UINT8 retVal;

		//Configure & Enable ADC Channel
		FC_CAL_Enable_ADC ( ADC_3_MX_ADC_CHANNEL , ADC_3_MX_ADC_CONVSP , ADC_3_MX_ADC_VREFOP , ADC_3_MX_ADC_ACTIME );

		retVal = FC_CAL_Sample_ADC( 0 );				//Perform Sample - Return as byte

		FC_CAL_Disable_ADC ();

		return (retVal);

}

MX_UINT16 FCD_ADC1_ReadAsInt()
{
	
		MX_UINT16 retVal;

		//Configure & Enable ADC Channel
		FC_CAL_Enable_ADC ( ADC_3_MX_ADC_CHANNEL , ADC_3_MX_ADC_CONVSP , ADC_3_MX_ADC_VREFOP , ADC_3_MX_ADC_ACTIME );

		retVal = FC_CAL_Sample_ADC( 1 );				//Perform Sample - Return as MX_UINT16

		FC_CAL_Disable_ADC ();

		return (retVal);

}

MX_FLOAT FCD_ADC1_ReadAsVoltage()
{
	
		MX_UINT16 iSample;
		MX_FLOAT fSample, fVoltage, fVperDiv;

		//Configure & Enable ADC Channel
		FC_CAL_Enable_ADC ( ADC_3_MX_ADC_CHANNEL , ADC_3_MX_ADC_CONVSP , ADC_3_MX_ADC_VREFOP , ADC_3_MX_ADC_ACTIME );

	  #ifdef MX_ADC_BITS_8
		iSample = FC_CAL_Sample_ADC( 0 );								//Perform Sample - Return as byte
	  #else
		iSample = FC_CAL_Sample_ADC( 1 );								//Perform Sample - Return as MX_UINT16
	  #endif

	  	FC_CAL_Disable_ADC ();											//Switch off ADC peripheral
		fVoltage = flt_fromi( ADC_3_MX_ADC_VREFVOL );						//Convert reference voltage count to floating point (0 - 500 x 10mV)
		fVoltage = flt_mul(fVoltage, 0.01);								//Convert reference voltage count to actual voltage (0 - 5)

	  #ifdef MX_ADC_BITS_8
		fVperDiv = flt_mul(fVoltage, 0.00390625);						//Convert actual voltage to voltage per division (VRef / 256)
	  #endif
	  #ifdef MX_ADC_BITS_10
		fVperDiv = flt_mul(fVoltage, 0.000976);							//Convert actual voltage to voltage per division (VRef / 1024)
	  #endif
	  #ifdef MX_ADC_BITS_12
		fVperDiv = flt_mul(fVoltage, 0.00024414);						//Convert actual voltage to voltage per division (VRef / 4096)
	  #endif

		fSample = flt_fromi(iSample);									//Convert to floating point variable
		fVoltage = flt_mul(fSample, fVperDiv);							//Calculate floating point voltage

		return (fVoltage);

}

void FCD_ADC1_ReadAsString(MX_CHAR* FCR_RETVAL, MX_UINT8 FCR_RETVAL_SIZE)
{
	
		MX_FLOAT fVoltage;

		fVoltage = FCD_ADC1_ReadAsVoltage();
		FCI_FLOAT_TO_STRING(fVoltage, 2, FCR_RETVAL, FCR_RETVAL_SIZE);	//Convert to String

}

void FCD_ADC1_ADC_RAW_Configure_Channel()
{
	
		//Configure & Enable ADC Channel
		FC_CAL_Enable_ADC ( ADC_3_MX_ADC_CHANNEL , ADC_3_MX_ADC_CONVSP , ADC_3_MX_ADC_VREFOP , ADC_3_MX_ADC_ACTIME );

}

MX_UINT8 FCD_ADC1_ADC_RAW_Sample_Channel_Byte()
{
	
		return FC_CAL_Sample_ADC( 0 );									//Perform Sample - Return as byte

}

MX_UINT16 FCD_ADC1_ADC_RAW_Sample_Channel_Int()
{
	
		return FC_CAL_Sample_ADC( 1 );									//Perform Sample - Return as MX_UINT16

}

MX_UINT8 FCD_ADC1_ADC_RAW_Average_Channel_Byte(MX_UINT8 NumSamples, MX_UINT8 DelayUs)
{
	
		MX_UINT32 average = 0;
		MX_UINT8 count;

		for (count=0; count<NumSamples; count++)
		{
			average = average + FC_CAL_Sample_ADC( 0 );					//Perform Sample - Return as byte - add to average

			if (DelayUs)
				delay_us(DelayUs);										//If delay is not 0 then pause between samples
		}
		average = average / count;

		return (average & 0xFF);										//Return average as byte

}

MX_UINT16 FCD_ADC1_ADC_RAW_Average_Channel_Int(MX_UINT8 NumSamples, MX_UINT8 DelayUs)
{
	
		MX_UINT32 average = 0;
		MX_UINT8 count;

		for (count=0; count<NumSamples; count++)
		{
			average = average + FC_CAL_Sample_ADC( 1 );					//Perform Sample - Return as MX_UINT16 - add to average

			if (DelayUs)
				delay_us(DelayUs);										//If delay is not 0 then pause between samples
		}
		average = average / count;

		return (average & 0x1FFF);										//Return average as MX_SINT16

}

void FCD_ADC1_ADC_RAW_Disable_Channel()
{
	
		FC_CAL_Disable_ADC ();											//Disable ADC Channel

}

#include "C:\Program Files (x86)\Flowcode\v5\CAL\includes.c"

//Macro implementations


void main()
{
	//Initialization
	ansel = 0x00;
anselh = 0x00;

	
	  #ifdef FC_CAL_PIC								//8-bit PIC specific
	    #if defined(P18F24J50) || defined(P18F25J55) || defined(P18F26J50) || defined(P18F44J50) || defined(P18F45J50) || defined(P18F46J55) || defined(P18F87J50) ||  defined(P18F86J55) || defined(P18F86J50) || defined(P18F85J50) || defined(P18F67J50) || defined(P18F66J55) || defined(P18F66J50) || defined(P18F65J50)
		//On the PIC18F87J50 Family of USB microcontrollers, the PLL will not power up and be enabled
		//by default, even if a PLL enabled oscillator configuration is selected (such as HS+PLL).
		//This allows the device to power up at a lower initial operating frequency, which can be
		//advantageous when powered from a source which is not gauranteed to be adequate for 48MHz
		//operation.  On these devices, user firmware needs to manually set the OSCTUNE<PLLEN> bit to
		//power up the PLL.
	    {
	        MX_UINT16 pll_startup_counter = 600;
	        OSCTUNEbits.PLLEN = 1;  //Enable the PLL and wait 2+ms until the PLL locks before enabling USB module
	        while(pll_startup_counter--);
	    }
	    //Device switches over automatically to PLL output after PLL is locked and ready.
	    #endif
	  #endif

	  #ifdef FC_CAL_PIC16BIT						//16-bit PIC specific
	    #if defined(P24FJ64GB004) || defined(P24FJ64GB002) || defined(P24FJ32GB004) || defined(P24FJ32GB002)
		//On the PIC24FJ64GB004 Family of USB microcontrollers, the PLL will not power up and be enabled
		//by default, even if a PLL enabled oscillator configuration is selected (such as HS+PLL).
		//This allows the device to power up at a lower initial operating frequency, which can be
		//advantageous when powered from a source which is not gauranteed to be adequate for 48MHz
		//operation.  On these devices, user firmware needs to manually set the CLKDIV<PLLEN> bit to
		//power up the PLL.
	    {
	        MX_UINT16 pll_startup_counter = 600;
	        CLKDIVbits.PLLEN = 1;
	        while(pll_startup_counter--);
	    }
	    #endif
	  #endif


	//Interrupt initialization code
	


	//Call Component Macro
	//Call Component Macro: Initialise_Serial()
	FCD_USBSerial0_Initialise_Serial();

	//Loop
	//Loop: While 1
	while (1)
	{

		//Call Component Macro
		//Call Component Macro: Operation=ReadByte(10)
		FCV_OPERATION = FCD_USBSerial0_ReadByte(10);

		//Switch
		//Switch: Operation?
		switch (FCV_OPERATION)
		{
			case 0x31:
			{
				//Call Component Macro
				//Call Component Macro: ReadInput=ReadAsInt()
				FCV_READINPUT = FCD_ADC0_ReadAsInt();

				#if 0 // Disabled code
				//Calculation
				//Calculation:
				//  OutStr = OutStr + 1
				FCV_OUTSTR = FCV_OUTSTR + 1;

				#endif // #if 0: Disabled code
				#if 0 // Disabled code
				//Call Component Macro
				//Call Component Macro: SendByte(OutStr)
				FCD_USBSerial0_SendByte(FCV_OUTSTR);

				#endif // #if 0: Disabled code
				#if 0 // Disabled code
				//Calculation
				//Calculation:
				//  ReadInput = 23456
				FCV_READINPUT = 23456;

				#endif // #if 0: Disabled code
				//Calculation
				//Calculation:
				//  ReadInput = ReadInput | 0x1001
				//  OutString[0] = ReadInput
				//  OutString[1] = (ReadInput >> 8)
				FCV_READINPUT = FCV_READINPUT | 0x1001;
				FCV_OUTSTRING[0] = FCV_READINPUT;
				FCV_OUTSTRING[1] = (FCV_READINPUT >> 8);

				//Call Component Macro
				//Call Component Macro: SendString(OutString)
				FCD_USBSerial0_SendString(FCV_OUTSTRING, FCSZ_OUTSTRING);

				break;
			}
			case 0x32:
			{
				//Call Component Macro
				//Call Component Macro: OutStr=ReadAsByte()
				FCV_OUTSTR = FCD_ADC1_ReadAsByte();

				//Call Component Macro
				//Call Component Macro: SendByte(OutStr)
				FCD_USBSerial0_SendByte(FCV_OUTSTR);

				break;
			}
			// default:

		}


	}

	mainendloop: goto mainendloop;
}

void MX_INTERRUPT_MACRO(void)
{
	
	  #ifdef FC_CAL_PIC							//8-bit PIC specific
		usb_handle_isr();
	  #endif


}



