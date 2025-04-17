#include "gsk_core.h"

GSK_CORE::GSK_CORE() { taskHandle = new TaskHandle_t; }

void GSK_CORE::setup(void (*inTaskRoutine)() , int inSamplingTime, int core) {
    samplingTime = inSamplingTime;
    taskRoutine = inTaskRoutine;

    xTaskCreatePinnedToCore([](void* param) {
                                static_cast<GSK_CORE*>(param)->taskLoop();
                            },
                            std::to_string(core).c_str(), 10000, this, 1, taskHandle,
                            core);
}

void GSK_CORE::taskLoop(void) {
    TickType_t requiredTicks = samplingTime / portTICK_PERIOD_MS;
    while (1) {
        ((void (*)())taskRoutine)();
        vTaskDelay(requiredTicks);
    }
}