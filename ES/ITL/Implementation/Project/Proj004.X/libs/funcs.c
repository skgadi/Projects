#include "funcs.h"

GSK_DATE_TIME IncreaseByASecond (GSK_DATE_TIME dt) {
    dt.SECOND++;
    if (dt.SECOND == NO_OF_SECONDS_IN_A_DAY) {
        dt.SECOND = 0;
        dt = IncreaseByADay(dt);
    }
    return dt;
}

GSK_DATE_TIME IncreaseByADay (GSK_DATE_TIME dt) {
    dt.DATE.Day++;
    if (dt.DAY.Val == 0x01)
        dt.DAY.Val = 0x40;
    else
        dt.DAY.Val >>= 1;
    INT8 MonthDays = NO_OF_DAYS_IN_A_MONTH[dt.DATE.Month-1];
    if ((dt.DATE.Month == 2) && (dt.YEAR%4 == 0))
        MonthDays = 29;
    if ((dt.DATE.Month == 2) && (dt.YEAR%100 == 0))
        MonthDays = 28;
    if ((dt.DATE.Month == 2) && (dt.YEAR%400 == 0))
        MonthDays = 29;
    if (dt.DATE.Day > MonthDays) {
        dt.DATE.Day = 1;
        dt = IncreaseByAMonth(dt);
    }
    return dt;
}

GSK_DATE_TIME IncreaseByAMonth (GSK_DATE_TIME dt) {
    dt.DATE.Month++;
    if (dt.DATE.Month == 13) {
        dt.DATE.Month = 1;
        dt = IncreaseByAYear(dt);
    }
    return dt;
}

GSK_DATE_TIME IncreaseByAYear (GSK_DATE_TIME dt) {
    dt.YEAR++;
    if (dt.YEAR % 100 == 0)
        CENTURY++;
    return dt;
}

GSK_DATE_TIME DecreaseByASecond (GSK_DATE_TIME dt) {
    if (dt.SECOND == 0) {
        dt.SECOND = NO_OF_SECONDS_IN_A_DAY;
        dt = DecreaseByADay(dt);
    }
    dt.SECOND--;
    return dt;
}

GSK_DATE_TIME DecreaseByADay (GSK_DATE_TIME dt) {
    if (dt.DAY.Val == 0x40)
        dt.DAY.Val = 0x01;
    else
        dt.DAY.Val <<= 1;
    if (dt.DATE.Day == 1) {
        dt = DecreaseByAMonth(dt);
        INT8 MonthDays = NO_OF_DAYS_IN_A_MONTH[dt.DATE.Month-1];
        if ((dt.DATE.Month == 2) && (dt.YEAR%4 == 0))
            MonthDays = 29;
        if ((dt.DATE.Month == 2) && (dt.YEAR%100 == 0))
            MonthDays = 28;
        if ((dt.DATE.Month == 2) && (dt.YEAR%400 == 0))
            MonthDays = 29;
        dt.DATE.Day = MonthDays;
    } else
        dt.DATE.Day--;
    return dt;
}

GSK_DATE_TIME DecreaseByAMonth (GSK_DATE_TIME dt) {
    if (dt.DATE.Month == 1) {
        dt.DATE.Month = 12;
        dt = DecreaseByAYear(dt);
    } else
        dt.DATE.Month--;
    return dt;
}

GSK_DATE_TIME DecreaseByAYear (GSK_DATE_TIME dt) {
    if (dt.YEAR % 100 == 0)
        CENTURY--;
    dt.YEAR--;
    return dt;
}

GSK_DATE_TIME AdjustDayLightSaving (GSK_DATE_TIME dt) {
    UINT16 Start, End, Present;
    Start = (UINT16) DAY_LIGHT_START.Month*100 + DAY_LIGHT_START.Day;
    End = (UINT16) DAY_LIGHT_END.Month*100 + DAY_LIGHT_END.Day;
    Present = (UINT16) dt.DATE.Month*100 + dt.DATE.Day;
    if (Start > End) {
        if ((Present >= Start) || (Present <= End))
            dt.SECOND += SECONDS_TO_ADJUST_FOR_DAY_LIGHT_SAVING;
    } else {
        if ((Present >= Start) && (Present <= End))
            dt.SECOND += SECONDS_TO_ADJUST_FOR_DAY_LIGHT_SAVING;
    }
    if (dt.SECOND < 0) {
        dt.SECOND += NO_OF_SECONDS_IN_A_DAY;
        dt = DecreaseByADay(dt);
    }
    if (dt.SECOND > NO_OF_SECONDS_IN_A_DAY) {
        dt.SECOND -= NO_OF_SECONDS_IN_A_DAY;
        dt = IncreaseByADay(dt);
    }
    return dt;
}
BOOL ReadGPS_DATE_TIME (void) {
    BOOL IsValidGPS = false;
    char Date[] = "------";
    char Time[] = "------";
    EUSART1_Initialize();
    for (UINT8 TempItr=0; TempItr<5; TempItr++ ) {
        ReadGPSDateTime(Date, Time);
        if (ValidateDateTime(Date, Time)) {
            IsValidGPS = true;
            break;
        }
    }
    if (IsValidGPS) {
        GPS_DATE_TIME.DATE.Day = (Date[0]-0x30)*10 + (Date[1]-0x30);
        GPS_DATE_TIME.DATE.Month = (Date[2]-0x30)*10 + (Date[3]-0x30);
        GPS_DATE_TIME.DAY.Val = (0x40 >> GetDay(Date));
        GPS_DATE_TIME.YEAR = (Date[4]-0x30)*10 + (Date[5]-0x30) + CENTURY*100;
        GPS_DATE_TIME.SECOND = TimeTextToSecond (Time);
        GPS_DATE_TIME.SECOND += (TIME_ZONE - CYCLE_DELAY);
        if (GPS_DATE_TIME.SECOND < 0) {
            GPS_DATE_TIME.SECOND += NO_OF_SECONDS_IN_A_DAY;
            GPS_DATE_TIME = DecreaseByADay(GPS_DATE_TIME);
        }
        if (GPS_DATE_TIME.SECOND > NO_OF_SECONDS_IN_A_DAY) {
            GPS_DATE_TIME.SECOND -= NO_OF_SECONDS_IN_A_DAY;
            GPS_DATE_TIME = IncreaseByADay(GPS_DATE_TIME);
        }
        GPS_DATE_TIME = AdjustDayLightSaving(GPS_DATE_TIME);
        return true;
    } else
        return false;
}

INT32 TimeTextToSecond (char *Time) {
    INT32 Second;
    Second = (INT32) 3600*((Time[0]-0x30)*10 + (Time[1]-0x30)) 
            + (INT32) 60*((Time[2]-0x30)*10 + (Time[3]-0x30))
            + (INT32) ((Time[4]-0x30)*10 + (Time[5]-0x30));
    return Second;
}

void SwitchOnGPS (void) {
    GPS_SWITCH = ON;
    NO_OF_TIMES_GPS_FAILED = 0;
    TIME_WHEN_GPS_IS_SWITCHED_ON = DATE_TIME.SECOND;
    ACTION_GPS_VERIFY_WAIT_TIME = SET;
    ACTION_GPS_START = RESET;
}

void VerifyForGPSOnTIme (void) {
    INT32 TimeDiff = DATE_TIME.SECOND - TIME_WHEN_GPS_IS_SWITCHED_ON;
    if (TimeDiff<0)
        TimeDiff += NO_OF_SECONDS_IN_A_DAY;
    if (TimeDiff >= WAIT_x_SECONDS_AFTER_SWITCHING_ON_GPS) {
        ACTION_GPS_READ = SET;
        ACTION_GPS_VERIFY_WAIT_TIME = RESET;
    }
}

void ReadGPS (void) {
    if (ReadGPS_DATE_TIME()) {
        /*DATE_TIME.DATE.Day = GPS_DATE_TIME.DATE.Day;
        DATE_TIME.DATE.Month = GPS_DATE_TIME.DATE.Month;
        DATE_TIME.DAY.Val = GPS_DATE_TIME.DAY.Val;
        DATE_TIME.SECOND = GPS_DATE_TIME.SECOND;
        DATE_TIME.YEAR = GPS_DATE_TIME.YEAR;*/
        DATE_TIME = GPS_DATE_TIME;
        TIME_AT_LAST_GPS_SYNC = DATE_TIME.SECOND;
        ACTION_GPS_STOP = SET;
    } else {
        NO_OF_TIMES_GPS_FAILED++;
        if (NO_OF_TIMES_GPS_FAILED > MAX_ALLOWED_GPS_FAILURES) {
            ACTION_GPS_STOP = SET;
        } else {
            TIME_WHEN_GPS_IS_SWITCHED_ON = DATE_TIME.SECOND -
                    (WAIT_x_SECONDS_AFTER_SWITCHING_ON_GPS - TIME_GAP_BETWEEN_TWO_GPS_READINGS);
            if (TIME_WHEN_GPS_IS_SWITCHED_ON<0)
                TIME_WHEN_GPS_IS_SWITCHED_ON += NO_OF_SECONDS_IN_A_DAY;
            ACTION_GPS_VERIFY_WAIT_TIME = SET;
        }
    }
    ACTION_GPS_READ = RESET;
}

void StopGPS (void) {
    GPS_SWITCH = OFF;
    ACTION_GPS_STOP = RESET;
}

void TestGPSStartCondition (void) {
    if ((DATE_TIME.SECOND == GPS_SYNC_EVERY_DAY_AT_LOCAL_TIME) 
            || (TIME_AT_LAST_GPS_SYNC >= GPS_SYNC_EVERY_x_SECONDS))
        ACTION_GPS_START = SET;
}

INT8 GetEventNumber(void) {
    for (UINT i=0; i<MAX_NO_OF_EVENTS; i++) {
        if ((EVENTS[i].START_TIME>0) && 
                (DATE_TIME.DAY.Val & EVENTS[i].SELECTED_WEEKS.Val & 0x7F)) {
            if (EVENTS[i].START_TIME < EVENTS[i].END_TIME) {
                if ((DATE_TIME.SECOND > EVENTS[i].START_TIME) 
                        && (DATE_TIME.SECOND < EVENTS[i].END_TIME)) {
                    return i;
                }
            } else {
                if ((DATE_TIME.SECOND > EVENTS[i].START_TIME) 
                        || (DATE_TIME.SECOND < EVENTS[i].END_TIME)) {
                    return i;
                }
            }
        }
    }
    return -1;
}

UINT8 GetThisCycle (void) {
    if (PRESENT_EVENT <0)
        return 0;
    else
        return EVENTS[PRESENT_EVENT].CYCLE;
}