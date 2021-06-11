#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H



#include "coins.h"


// The following settings are configured by the app
#ifndef PROGRAM_FROM_APP
#define NUMBER_OF_CHEMICALS 10
#define MAX_MONEY_PER_LITER 100
#define HIDE_PRICE_AFTER_x_SECONDS (2*60)
#define REMOVE_CREDIT_AFTER_x_SECONDS (10*60)
#define PROGRAM_SUMMARY
#define PIN_MODEL 0 // 0 for through hole boards, 1 for SMD
#define CLIENT_COMPANY_NAME "       ecoTec       "
#endif



#define RESET_LCD_AFTER_x_MINUTES 60

#define NUMBER_OF_IN_OUT_PINS 5

#define MIN_CENTI_SEC_PER_LITER (5*10)
#define MAX_CENTI_SEC_PER_LITER (10*60*10)


#define MAX_LITERS_COUNTER (100*1000)
#define MAX_SALES_AMOUNT (1000*1000)
#define MAX_TOTAL_SALES_FACTOR 100


#define COINS_PIN 2



#define WAIT_x_MILLI_SECONDS_AFTER_BTN_PRESS (50)



#define MEGA_TESTBOX_HOUSE


#ifdef MEGA_TESTBOX_HOUSE


#endif



#endif
