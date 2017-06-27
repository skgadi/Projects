#include "gsk_MCP7940N.h"
#include "../main.h"

void WriteTimeToRTC(char data, char Pos, char mask) {
    I2C_WriteAtAddress(0xde, Pos, (data));
}