#include "../main.h"

void I2C_Master_Init(const unsigned long c)
{
  SSPCON = 0b00101000;
  SSPCON2 = 0;
  SSPADD = (_XTAL_FREQ/(4*c))-1;
  SSPSTAT = 0;
  TRISC3 = 1;        //Setting as input as given in datasheet
  TRISC4 = 1;        //Setting as input as given in datasheet
}

void I2C_Master_Wait()
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void I2C_Master_Start()
{
  I2C_Master_Wait();
  SEN = 1;
}

void I2C_Master_RepeatedStart()
{
  I2C_Master_Wait();
  RSEN = 1;
}

void I2C_Master_Stop()
{
  I2C_Master_Wait();
  PEN = 1;
}

void I2C_Master_Write(unsigned  d)
{
  I2C_Master_Wait();
  SSPBUF = d;
}

unsigned short I2C_Master_Read(unsigned short a)
{
  unsigned short temp;
  I2C_Master_Wait();
  RCEN = 1;
  I2C_Master_Wait();
  temp = SSPBUF;
  I2C_Master_Wait();
  ACKDT = (a)?0:1;
  ACKEN = 1;
  return temp;
}

char I2C_ReadAtAddress(char DevID, char IntAdd) {
    //Read a Register from device
    I2C_Master_Start();
    I2C_Master_Write(DevID);
    I2C_Master_Write(IntAdd);
    I2C_Master_Stop();
    //__delay_us(5);
    I2C_Master_Start();
    I2C_Master_Write(DevID+1);
    char data = I2C_Master_Read(0);
    I2C_Master_Stop();
    return data;
}

void I2C_WriteAtAddress(char DevID, char IntAdd, char data) {
    //Read a Register from device
    I2C_Master_Start();
    I2C_Master_Write(DevID);
    I2C_Master_Write(IntAdd);
    I2C_Master_Write(data);
    I2C_Master_Stop();
}

void DisplayTimeFromRTC (char y, char x) {
    char TempVar000;
    TempVar000 = I2C_ReadAtAddress(0xde, 0x02);
    Lcd_Int(y,x,(TempVar000>>4) & 0x03 ,1);
    Lcd_Int(y,x+1,TempVar000 & 0x0f ,1);
    TempVar000 = I2C_ReadAtAddress(0xde, 0x01);
    Lcd_Int(y,x+2,(TempVar000>>4) & 0x07 ,1);
    Lcd_Int(y,x+3,TempVar000 & 0x0f ,1);
    TempVar000 = I2C_ReadAtAddress(0xde, 0x00);
    Lcd_Int(y,x+4,(TempVar000>>4) & 0x07 ,1);
    Lcd_Int(y,x+5,TempVar000 & 0x0f ,1);
}