#ifndef GSK_TEMP_H
#define GSK_TEMP_H

#include "DHT.h"
#include "gsk_global.h"

#define GSK_DHT_TYPE DHT22

class GSK_TEMP {
    DHT* dht;

   public:
    GSK_TEMP();
    float getTemperature();
    float getHumidity();
};

#endif  // GSK_TEMP_H
