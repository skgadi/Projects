#ifndef GSK_LCD_H
#define GSK_LCD_H

#include <LiquidCrystal_I2C.h>

#include "gsk_global.h"

class GSK_LCD {
    int setPoint;
    int temperature;
    int humidity;
    bool isFanOn;
    bool isSystemOn;
    int newSetPoint;
    int newTemperature;
    int newHumidity;
    bool newIsFanOn;
    bool newIsSystemOn;
    LiquidCrystal_I2C* lcd;

   public:
    void init();
    void setTemperature(int);
    void setHumidity(int);
    void setSetPoint(int);
    void setFanOn(bool);
    void setSystemOn(bool);
    void loop();
};

#endif  // GSK_LCD_H