/* 
 * File:   hd44780.c
 * Author: |H_e_c_t_o_r|
 *
 * Dot matrix liquid crystal display.
 * Driver HD44780.
 * Interface: 4-bit mode.
*/

#include "../main.h"
#include "HD44780.h"


//==============================================================================
// Initializes the Lcd module.
//==============================================================================
void Lcd_Init(void){
    //modified by skgadi start
    ANSEL = 0x00;
    ANSELH = 0x00;

    //modified by skgadi end
unsigned char data;
TRISRD7 = 0; TRISRD6 = 0; TRISRD5 = 0; TRISRD4 = 0; TRISEN = 0; TRISRS = 0;
LCD_RD7 = 0; LCD_RD6 = 0; LCD_RD5 = 0; LCD_RD4 = 0; LCD_EN = 0; LCD_RS = 0;
Lcd_Delay5500us(); Lcd_Delay5500us(); Lcd_Delay5500us();
Lcd_Delay5500us(); Lcd_Delay5500us(); Lcd_Delay5500us();
for(data = 1; data < 4; data ++)
   {
    LCD_RD7 = 0; LCD_RD6 = 0; LCD_RD5 = 1; LCD_RD4 = 1; LCD_EN = 0; LCD_RS = 0;
    LCD_RD7 = 0; LCD_RD6 = 0; LCD_RD5 = 1; LCD_RD4 = 1; LCD_EN = 1; LCD_RS = 0;
    Lcd_Delay5us();
    LCD_RD7 = 0; LCD_RD6 = 0; LCD_RD5 = 1; LCD_RD4 = 1; LCD_EN = 0; LCD_RS = 0;
    Lcd_Delay5500us();
   }
LCD_RD7 = 0; LCD_RD6 = 0; LCD_RD5 = 1; LCD_RD4 = 0; LCD_EN = 0; LCD_RS = 0;
LCD_RD7 = 0; LCD_RD6 = 0; LCD_RD5 = 1; LCD_RD4 = 0; LCD_EN = 1; LCD_RS = 0;
Lcd_Delay5us();
LCD_RD7 = 0; LCD_RD6 = 0; LCD_RD5 = 1; LCD_RD4 = 0; LCD_EN = 0; LCD_RS = 0;
Lcd_Delay5500us();
data = 40; Lcd_Command(data);
data = 16; Lcd_Command(data);
data = 1;  Lcd_Command(data);
data = 15; Lcd_Command(data);
}

//==============================================================================
// Prints text constant on the Lcd.
// y: Starting position row number. Valid values: 1, 2, 3, 4
// x: Starting position column number. Valid values: 1..20
// buffer: Byte of array.
//==============================================================================
void Lcd_ConstText(unsigned char y, unsigned char x, const char *buffer){
unsigned char data;
switch(y){
case 1: data = 127 + x; break;
case 2: data = 191 + x; break;
case 3: data = 147 + x; break;
case 4: data = 211 + x; break;
default: break;}
Lcd_Command(data);
while(*buffer)                // Write data to LCD up to null
     {
      Lcd_CharCP(*buffer);
      buffer++;               // Increment buffer
     }
return;
}

//==============================================================================
// Prints text variable on the Lcd.
// y: Starting position row number. Valid values: 1, 2, 3, 4
// x: Starting position column number. Valid values: 1..20
// buffer: Byte of array.
//==============================================================================
void Lcd_Text(unsigned char y, unsigned char x, char *buffer){
unsigned char data;
switch(y){
case 1: data = 127 + x; break;
case 2: data = 191 + x; break;
case 3: data = 147 + x; break;
case 4: data = 211 + x; break;
default: break;}
Lcd_Command(data);
while(*buffer)                // Write data to LCD up to null
     {
      Lcd_CharCP(*buffer);
      buffer++;               // Increment buffer
     }
return;
}

//==============================================================================
// Prints character on the Lcd.
// y: Starting position row number. Valid values: 1, 2, 3, 4
// x: Starting position column number. Valid values: 1..20
// c: character to be written.
//==============================================================================
void Lcd_WriteChar(unsigned char y, unsigned char x, char c){
    unsigned char data;
    switch(y) {
        case 1: data = 127 + x; break;
        case 2: data = 191 + x; break;
        case 3: data = 147 + x; break;
        case 4: data = 211 + x; break;
        default: break;
    }
    Lcd_Command(data);
    Lcd_CharCP(c);
}

//==============================================================================
// Prints text on Lcd at current cursor position.
// c: character to be written.
//==============================================================================
void Lcd_CharCP(char c){
    LCD_EN = 0; LCD_RS = 1;
    LCD_RD7 = (c & 0b10000000)>>7; LCD_RD6 = (c & 0b01000000)>>6;
    LCD_RD5 = (c & 0b00100000)>>5; LCD_RD4 = (c & 0b00010000)>>4;
    _delay(10);
    LCD_EN = 1; Lcd_Delay5us(); LCD_EN = 0;
    LCD_RD7 = (c & 0b00001000)>>3; LCD_RD6 = (c & 0b00000100)>>2;
    LCD_RD5 = (c & 0b00000010)>>1; LCD_RD4 = (c & 0b00000001);
    _delay(10);
    LCD_EN = 1; Lcd_Delay5us(); LCD_EN = 0;
    Lcd_Delay5us(); //Lcd_Delay5500us();
}

//==============================================================================
// Sends command to Lcd.
// command: command to be sent.
//==============================================================================
void Lcd_Command(unsigned char command){
    LCD_EN = 0; LCD_RS = 0;
    LCD_RD7 = (command & 0b10000000)>>7; LCD_RD6 = (command & 0b01000000)>>6;
    LCD_RD5 = (command & 0b00100000)>>5; LCD_RD4 = (command & 0b00010000)>>4;
    _delay(10);
    LCD_EN = 1; Lcd_Delay5us(); LCD_EN = 0;
    LCD_RD7 = (command & 0b00001000)>>3; LCD_RD6 = (command & 0b00000100)>>2;
    LCD_RD5 = (command & 0b00000010)>>1; LCD_RD4 = (command & 0b00000001);
    _delay(10);
    LCD_EN = 1; Lcd_Delay5us(); LCD_EN = 0;
    //Lcd_Delay5500us();//
    Lcd_Delay5us();
}

//==============================================================================
// Delays.
//==============================================================================
void Lcd_Delay5us(void){
__delay_us(5);
}
void Lcd_Delay5500us(void){
__delay_us(5500);
}

void Lcd_Int(unsigned char y, unsigned char x, char val,char size) {
    if ((size>0) && (size<=3)) {
        unsigned int tempVal=val;
        unsigned char data;
        switch(y){
            case 1: data = 127 + x; break;
            case 2: data = 191 + x; break;
            case 3: data = 147 + x; break;
            case 4: data = 211 + x; break;
            default: break;}
        Lcd_Command(data);
        if (size>=3){
            tempVal = val/100;
            Lcd_CharCP(0x30+(tempVal));            
        }
        if (size>=2){
            tempVal = (val-tempVal*100)/10;
            Lcd_CharCP(0x30+(tempVal));
        }
        if (size>=1){
            tempVal = val/10;
            Lcd_CharCP(0x30+(val - tempVal*10));
        }
    }
}

void WriteLongInt(unsigned char y, unsigned char x, INT64 Val, int8_t size, char Sign) {
    int8_t POS = 0;
    if (Sign) {
        POS++;
        if (Val<0) {
            Lcd_WriteChar (y, x, 0x2D);
            Val=-1*Val;
        } else
            Lcd_WriteChar (y, x, 0x2B);
    }
    while(size) {
        size--;
        Lcd_WriteChar (y, x+size+POS, ((Val - ((Val/10)*10))+0x30));
        Val = Val/10;
    }
}

void Lcd_Disp_Bin(unsigned char y, unsigned char x, char val, char DispChar){
    for (char i=0; i<8; i++){
        if ((val) & (0x01<<i))
            Lcd_WriteChar(y, x+i, DispChar);
    }
}