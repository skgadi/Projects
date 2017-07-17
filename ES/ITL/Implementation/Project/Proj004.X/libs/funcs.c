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
        GLOBAL_CENTURY++;
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
        GLOBAL_CENTURY--;
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
    char Date[] = "------";
    char Time[] = "------";
    EUSART1_Initialize();
    ReadGPSDateTime(Date, Time);
    if (ValidateDateTime(Date, Time)) {
        GPS_DATE_TIME.DATE.Day = (Date[0]-0x30)*10 + (Date[1]-0x30);
        GPS_DATE_TIME.DATE.Month = (Date[2]-0x30)*10 + (Date[3]-0x30);
        GPS_DATE_TIME.DAY.Val = (0x40 >> GetDay(Date));
        GPS_DATE_TIME.YEAR = (Date[4]-0x30)*10 + (Date[5]-0x30) + GLOBAL_CENTURY*100;
        GPS_DATE_TIME.SECOND = TimeTextToSecond (Time);
        GPS_DATE_TIME.SECOND += TIME_ZONE;
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
