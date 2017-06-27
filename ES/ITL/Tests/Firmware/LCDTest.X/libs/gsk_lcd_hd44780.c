//#include <stdint.h>
#include <stdbool.h>
#include "../main.h"
#include "gsk_lcd_hd44780.h"


    
#define lcd_port    PORTB
#define LCD_EN_ON      0x80
#define LCD_RS_ON      0x20
  
#define delayms(x) (__delay_ms(x))
#define delayus(x) (__delay_us(x))



void TRISTOOutput(void) {
    LCD_DB4_T=0; LCD_DB5_T=0; LCD_DB6_T=0; LCD_DB7_T=0;
    LCD_EN_T=0; LCD_RS_T=0; //LCD_RW_T=0;
}

void LCD_Clock(){
    LCD_RS=1;
	//LCD_EN=1;
	//__delay_us(LCD_CK_DEL);
    //__delay_ms(1001);
	LCD_EN=0;
}

void WriteToPort (char Nib) {
    TRISTOOutput();
    //LCD_RS = (((cmd>>5) | 0xfe) == 0xff);
    //LCD_EN = (((cmd>>7) | 0xfe) == 0xff);

    if (((Nib>>0) & 0x01) == 0x01)
        LCD_DB4 = 1;
    else
        LCD_DB4 = 0;
    
    if (((Nib>>1) & 0x01) == 0x01)
        LCD_DB5 = 1;
    else
        LCD_DB5 = 0;
    
    if (((Nib>>2) & 0x01) == 0x01)
        LCD_DB6 = 1;
    else
        LCD_DB6 = 0;
    
    if (((Nib>>3) & 0x01) == 0x01)
        LCD_DB7 = 1;
    else
        LCD_DB7 = 0;
    /*LCD_DB5 = (((cmd>>1) | 0xfe) == 0xff);
    LCD_DB6 = (((cmd>>2) | 0xfe) == 0xff);
    LCD_DB7 = (((cmd>>3) | 0xfe) == 0xff);*/
    
}


void lcd_cmd (char cmd) {
    TRISTOOutput();
	lcd_port = ((cmd >> 4) & 0x0F)|LCD_EN_ON;
	lcd_port = ((cmd >> 4) & 0x0F);
    //lcd_port = (LCD_EN_ON);
    delayms(1);
	lcd_port = (cmd & 0x0F)|LCD_EN_ON;
	lcd_port = (cmd & 0x0F);
	delayms(2);
    //lcd_port = (LCD_EN_ON);
}

void lcd_data (unsigned char dat) {
    /*LCD_RS = 1;
    WriteToPort(dat >> 4);
    LCD_Clock();
    delayms(1);
    LCD_RS = 1;
    WriteToPort(dat);
    LCD_Clock();*/
	/*lcd_port = (((dat >> 4) & 0x0F)|LCD_EN_ON|LCD_RS_ON);
	lcd_port = (((dat >> 4) & 0x0F)|LCD_RS_ON);
	delayms(1);
	lcd_port = ((dat & 0x0F)|LCD_EN_ON|LCD_RS_ON);
	lcd_port = ((dat & 0x0F)|LCD_RS_ON);*/
    //WriteToPort((dat >> 4) & 0x0F);
    lcd_port = (((dat >> 4) & 0x0F)|LCD_EN_ON|LCD_RS_ON);
    //lcd_port = (((dat >> 4) & 0x0F)|LCD_RS_ON);
    //delayms(1);
    LCD_Clock();
    delayms(1);
    lcd_port = ((dat & 0x0F)|LCD_EN_ON|LCD_RS_ON);
    //lcd_port = ((dat & 0x0F)|LCD_RS_ON);
    //LCD_Clock();
    LCD_Clock();
	delayms(2);
}

void lcd_reset() {
	lcd_port = 0xFF;
	delayms(20);
	lcd_port = (0x03|LCD_EN_ON);
	lcd_port = 0x03;
	delayms(10);
	lcd_port = (0x03|LCD_EN_ON);
	lcd_port = 0x03;
	delayms(1);
	lcd_port = (0x03|LCD_EN_ON);
	lcd_port = 0x03;
	delayms(1);
	lcd_port = (0x02|LCD_EN_ON);
	lcd_port = 0x02;
	delayms(1);
}

void lcd_clear() {
    lcd_cmd(0x01);
    delayms(5);
    lcd_cmd(0x0D);
}

void lcd_init () {
	lcd_reset();         // Call LCD reset
	lcd_cmd(0x28);       // 4-bit mode - 2 line - 5x7 font. 
	lcd_cmd(0x0C);       // Display no cursor - no blink.
	lcd_cmd(0x06);       // Automatic Increment - No Display shift.
	lcd_cmd(0x80);       // Address DDRAM with 0 offset 80h.*/
    lcd_clear();
}

void lcd_home() {
    lcd_cmd(0x02);
}

void lcd_cursor_right (char x) {
    for (int i = 0; i< x; i++)
        lcd_cmd(0x14);
}

void lcd_string(char *a) {
	int i;
	for(i=0;a[i]!='\0';i++) {
	   lcd_data(a[i]);
       delayms(2);
    }
}

void  lcd_set_cursor(char x, char y ) {
    x=3;y=1;
    lcd_home();
    lcd_cursor_right(x+y*40);
    //delayus(200);
}

