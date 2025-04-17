#ifndef GSK_CORE_H
#define GSK_CORE_H

#include <Arduino.h>

class GSK_CORE {
    TaskHandle_t *taskHandle;
    void (*taskRoutine)();
    void taskLoop(void);
    int samplingTime;

   public:
    GSK_CORE();
    void setup(void (*)(), int, int);
};

#endif  // GSK_CORE_1_H