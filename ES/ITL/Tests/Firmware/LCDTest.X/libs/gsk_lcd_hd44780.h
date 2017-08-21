/* 
 * File:   gsk_lcd_hd44780.h
 * Author: gadis
 *
 * Created on July 27, 2016, 3:53 PM
 */

#ifndef GSK_LCD_HD44780_H
#define	GSK_LCD_HD44780_H

#ifdef	__cplusplus
extern "C" {
#endif

/******************************************************************************
*                      PIC -> LCD Interface Control pins                      *
******************************************************************************/
// THIS DRIVER USES INDEPENDENT PIN CONTROL                                  //
// MAKE SURE YOU SET THE CORRECT PINS YOU'LL BE USING FOR CONTROLLING THE LCD//


// ADDRESS BUS
#define LCD_RS  	RB5	// Register Select
#define LCD_RS_T    TRISBbits.TRISB5

// CONTROL BUS
//#define LCD_RW  	RB6	// Read/Write
//#define LCD_RW_T    TRISBbits.TRISB6
#define LCD_EN  	RB7	// Enable
#define LCD_EN_T    TRISBbits.TRISB7
#define LCD_CK_DEL	50	// It defines the time (in micro-seconds) that LCD_EN
						// should be kept high (1). Adjust the value if you
						// encounter any issues. In simulators you may encounter
						// "Controller received data whilst busy" errors if the
						// time is too short. Longer times will only make the
						// operation completion take longer, it does no harm.
						
// DATA BUS
#define LCD_DB4 	RB0	// DB4
#define LCD_DB4_T 	TRISBbits.TRISB0	// DB4
#define LCD_DB5 	RB1	// DB5
#define LCD_DB5_T 	TRISBbits.TRISB1	// DB5
#define LCD_DB6 	RB2	// DB6
#define LCD_DB6_T 	TRISBbits.TRISB2	// DB6
#define LCD_DB7 	RB3	// DB7
#define LCD_DB7_T 	TRISBbits.TRISB3	// DB7

/******************************************************************************
*                             LCD Base settings                               *
******************************************************************************/
// FUNCTION SET
#define LCD_DL		0	// 0: 4-bit DTM		| 1: 8-bit Data Transfer Mode
#define LCD_N		1	// 0: 1 line		| 1: 2 lines
#define LCD_F		0	// 0: 5x8 px font	| 1: 5x10 px font

// ENTRY MODE SET
#define LCD_S		0	// 0: SHIFT	OFF		| 1: SHIFT ON
#define LCD_ID		0	// 0: INCREMENT		| 1: DECREMENT

// DISPLAY ON/OFF CONTROL
#define LCD_B		1	// 0: CUR_BLINK OFF	| 1: CUR_BLINK ON
#define LCD_C		1	// 0: CURSOR OFF	| 1: CURSOR ON
#define LCD_D		1	// 0: DISPLAY OFF	| 1: DISPLAY ON

// CURSOR OR DISPLAY SHIFT
#define LCD_SC		0	// 0: SHIFT CURSOR	| 1: SHIFT DISPLAY
#define LCD_RL		1	// 0: SHIFT LEFT	| 1: SHIFT RIGHT

    
    
void WriteToPort (char cmd);


void TRISTOOutput(void);
void lcd_cmd (char cmd);
void lcd_data (unsigned char dat);
void lcd_reset();
void lcd_clear();
void lcd_init ();
void lcd_home();
void lcd_cursor_right (char x);
void lcd_string(char *a);
void  lcd_set_cursor(char x, char y );



#ifdef	__cplusplus
}
#endif

#endif	/* GSK_LCD_HD44780_H */

