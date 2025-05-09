/* 
 * File:   hd44780.h
 * Author: |H_e_c_t_o_r|
 *
 * Dot matrix liquid crystal display.
 * Driver HD44780.
 * Interface: 4-bit mode.
*/

#ifndef HD44780_H
#define	HD44780_H

//==============================================================================
// Lcd Connection.
// Set in  digital mode these pins in your code.
// Pin RW connect to GND.
//==============================================================================
#define LCD_RD7     RB3       // D7
#define TRISRD7     TRISBbits.TRISB3

#define LCD_RD6     RB2       // D6
#define TRISRD6     TRISBbits.TRISB2

#define LCD_RD5     RB1       // D5
#define TRISRD5     TRISBbits.TRISB1

#define LCD_RD4     RB0       // D4
#define TRISRD4     TRISBbits.TRISB0

#define LCD_EN      RB4       // EN
#define TRISEN      TRISBbits.TRISB4

#define LCD_RS      RB5       // RS
#define TRISRS      TRISBbits.TRISB5

//==============================================================================
// Available Lcd Commands.
//==============================================================================
#define      LCD_FIRST_ROW           128
#define      LCD_SECOND_ROW          192
#define      LCD_THIRD_ROW           148
#define      LCD_FOURTH_ROW          212
#define      LCD_CLEAR               1
#define      LCD_RETURN_HOME         2
#define      LCD_CURSOR_OFF          12
#define      LCD_UNDERLINE_ON        14
#define      LCD_BLINK_CURSOR_ON     15
#define      LCD_MOVE_CURSOR_LEFT    16
#define      LCD_MOVE_CURSOR_RIGHT   20
#define      LCD_TURN_OFF            0
#define      LCD_TURN_ON             8
#define      LCD_SHIFT_LEFT          24
#define      LCD_SHIFT_RIGHT         28

//==============================================================================
// Function Prototypes.
//==============================================================================
void Lcd_Init(void);
void Lcd_ConstText(unsigned char y, unsigned char x, const char *buffer);
void Lcd_Text(unsigned char y, unsigned char x, char *buffer);
void Lcd_WriteChar(unsigned char y, unsigned char x, char c);
void Lcd_Int(unsigned char y, unsigned char x, char val, char size);
void Lcd_CharCP(char c);
void Lcd_Command(unsigned char command);
void Lcd_Delay5us(void);
void Lcd_Delay5500us(void);
void WriteLongInt(unsigned char y, unsigned char x, uint32_t Val, char size);

#endif	/* HD44780_H */