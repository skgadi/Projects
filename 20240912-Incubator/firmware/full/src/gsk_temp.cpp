#include "gsk_temp.h"

GSK_TEMP::GSK_TEMP() {
    dht = new DHT(GSK_PIN_TEMP_SENSOR, GSK_DHT_TYPE);
    dht->begin();
}

float GSK_TEMP::getTemperature() { return dht->readTemperature(); }

float GSK_TEMP::getHumidity() { return dht->readHumidity(); }