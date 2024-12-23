#ifndef GSK_STATE_H
#define GSK_STATE_H

#include "gsk_global.h"

class GSK_STATE {
    int setPoint;
    float temperature;
    float humidity;
    bool isFanOn;
    bool isSystemOn;
    bool Kp;
    bool Ki;
    bool Kd;

   public:
    void init();
    void setTemperature(int);
    void setHumidity(int);
    void setSetPoint(int);
    void setFanOn(bool);
    void setSystemOn(bool);
    void loop();
};

#endif  // GSK_STATE_H