#define _XTAL_FREQ 20000000

#define RS RD2
#define EN RD3
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7
// BEGIN CONFIG
#pragma config FOSC = HS,WDTE=OFF ,PWRTE = OFF,BOREN = OFF, LVP = OFF 
//END CONFIG
#include <xc.h>

#include "lcd.h";


void main()
{
  unsigned int a;
  TRISD = 0x00;
  Lcd_Init();
  while(1)
  {
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("LCD Library for");
    Lcd_Set_Cursor(2,1);
    Lcd_Write_String("MPLAB XC8");
    __delay_ms(2000);
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("WWW.ALSELECTRO.COM");
    __delay_ms(2000);
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("Saravana Electronics");

    for(a=0;a<15;a++)
    {
        __delay_ms(1000);
        Lcd_Shift_Left();
    }

    for(a=0;a<15;a++)
    {
        __delay_ms(1000);
        Lcd_Shift_Right();
    }

    Lcd_Clear();
    Lcd_Set_Cursor(2,1);
    Lcd_Write_Char('S');
    Lcd_Write_Char('E');
    __delay_ms(2000);
  }
  
}