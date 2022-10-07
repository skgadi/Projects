#ifndef MAIN_H
#define MAIN_H

#define SHOW_READING_EVERY_x_SECONDS (5*60)

#define HUMIDITY_SENSOR_1 26
#define HUMIDITY_SENSOR_2 27
#define TEMP_SENSOR_PIN 14

#include <Arduino.h>

#include <OneWire.h>
#include <DallasTemperature.h>

void printAddress(DeviceAddress deviceAddress);



#endif
