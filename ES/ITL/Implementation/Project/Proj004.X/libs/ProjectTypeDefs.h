/* 
 * File:   ProjectTypeDefs.h
 * Author: gadis
 *
 * Created on June 28, 2017, 12:21 PM
 */

#ifndef PROJECTTYPEDEFS_H
#define	PROJECTTYPEDEFS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "GenericTypeDefs.h"
    

typedef union _OUTPUT
{
    BYTE Val;
    struct
    {
        unsigned char b0:1;
        unsigned char b1:1;
        unsigned char b2:1;
        unsigned char b3:1;
        unsigned char b4:1;
        unsigned char b5:1;
        unsigned char b6:1;
        unsigned char b7:1;
    } bits;
} OUTPUT;

#ifdef	__cplusplus
}
#endif

#endif	/* PROJECTTYPEDEFS_H */

