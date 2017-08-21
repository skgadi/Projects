/*
 * File:   main.c
 * Author: |H_e_c_t_o_r|
 * 
 */

#include <xc.h>
//#include <pic18f4520.h>
#include <stdio.h>
#include <stdlib.h>
#include "bit_settings.h"
#include "hd44780.h"
#include "my_delays.h"

void main(void) {
unsigned char i;
char buffer1[20];
ADCON1 = 15;
Lcd_Init();
Lcd_Command(LCD_CLEAR);
Lcd_Command(LCD_CURSOR_OFF);
Delay_ms(100);

for(i=110; i>0; i--)
{
sprintf(buffer1,"%3d",i);      //Right aligned text
//sprintf(buffer1,"%03d",i);   //Right aligned text and adding zeros if necessary
//sprintf(buffer1,"%d   ",i);  //Left  aligned text
Lcd_Text(1, 1, buffer1);
Delay_ms(100);
}

Lcd_ConstText(2, 1, "Hello World");
Delay_ms(600);

Lcd_ConstText(3, 1, "Open source");
Delay_ms(1000);

Lcd_Command(LCD_BLINK_CURSOR_ON);
Lcd_ConstText(4, 1, "Free download");
Delay_ms(1000);

Lcd_Command(LCD_CLEAR);
Lcd_WriteChar(1, 1, 'B'); Delay_ms(600);
Lcd_WriteChar(1, 2, 'y'); Delay_ms(600);
Lcd_WriteChar(1, 3, ' '); Delay_ms(600);
Lcd_WriteChar(1, 4, 'H'); Delay_ms(600);
Lcd_WriteChar(1, 5, 'e'); Delay_ms(600);
Lcd_WriteChar(1, 6, 'c'); Delay_ms(600);
Lcd_WriteChar(1, 7, 't'); Delay_ms(600);
Lcd_WriteChar(1, 8, 'o'); Delay_ms(600);
Lcd_WriteChar(1, 9, 'r'); Delay_ms(600);
Lcd_WriteChar(1, 10,' '); Delay_ms(600);
Lcd_WriteChar(1, 11,'R'); Delay_ms(600);
Lcd_WriteChar(1, 12,'.'); Delay_ms(600);

while(1){}
}
