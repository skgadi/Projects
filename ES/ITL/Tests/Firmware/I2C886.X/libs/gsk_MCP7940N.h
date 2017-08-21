/* 
 * File:   gsk_MCP7940N.h
 * Author: gadis
 *
 * Created on August 3, 2016, 2:12 PM
 */

#ifndef GSK_MCP7940N_H
#define	GSK_MCP7940N_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
    
    void ReadSec();
    void ReadMin();
    void ReadHour();
    void ReadYear();
    void ReadMonth();
    void ReadDay();
    void BCD2Byte();
    void WriteTimeToRTC(uint32_t time);

#ifdef	__cplusplus
}
#endif

#endif	/* GSK_MCP7940N_H */

