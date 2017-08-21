/////////////////////////////////////////////////////////
// LCD Settings
/////////////////////////////////////////////////////////

/* DATA_PORT defines the port to which the LCD data lines are connected */

#define    XLCD_DATAPORT       PORTB
#define    XLCD_DATAPORT_TRIS  TRISB
#define    XLCD_4BIT            // For 4 bit communication
#define    XLCD_UPPER           // Upper Nibble of 4 bit used for data
//#define    XLCD_LOWER         // Lower Nibble of 4 bit used for data
//#define    XLCD_8BIT          // For 8 bit communication

/* CTRL_PORT defines the port where the control lines are connected.
 * These are just samples, change to match your application.
 */

#define XLCD_RWPIN       LATCbits.LATC1
#define XLCD_RWPIN_TRIS  TRISCbits.TRISC1
#define XLCD_RSPIN       LATCbits.LATC0
#define XLCD_RSPIN_TRIS  TRISCbits.TRISC0
#define XLCD_ENPIN       LATCbits.LATC2
#define XLCD_ENPIN_TRIS  TRISCbits.TRISC2

/* LCD command setting */
#define    XLCD_READBFMODE      // Check Busy flag
//#define    XLCD_DELAYMODE     // Use Delay
//#define    XLCD_RW_GROUND     // If Delay mode and only write is needed

/* LCD function Setting */
#define    XLCD_2LINE
#define    XLCD_FONT5x8   
#define    XLCD_BLOCK
#define    XLCD_DISPLAYON
#define    XLCD_CURSOROFF
#define    XLCD_BLINKOFF
#define    XLCD_CURSOR_INCREMENT
#define    XLCD_DISPLAY_NOSHIFT