#ifndef PINS_H
#define PINS_H

#include <Arduino.h>

#define PIN_VELOCITY_1 2
#define PIN_VELOCITY_2 5
#define PIN_VELOCITY_3 15

#define PIN_DIRECTION_1 25
#define PIN_DIRECTION_2 26
#define PIN_DIRECTION_3 27

#define PIN_ENABLE_1 12
#define PIN_ENABLE_2 13
#define PIN_ENABLE_3 14

#define PIN_SENSOR_1 34
#define PIN_SENSOR_2 36
#define PIN_SENSOR_3 39

class GSK_PINS {
  int velocity_pins[3] = {PIN_VELOCITY_1, PIN_VELOCITY_2, PIN_VELOCITY_3};
  int direction_pins[3] = {PIN_DIRECTION_1, PIN_DIRECTION_2, PIN_DIRECTION_3};
  int enable_pins[3] = {PIN_ENABLE_1, PIN_ENABLE_2, PIN_ENABLE_3};
  int sensor_pins[3] = {PIN_SENSOR_1, PIN_SENSOR_2, PIN_SENSOR_3};
  int led_channels[3] = {0, 1, 2};
  int frequency = 5000;
  int resolution = 8;
public:
  GSK_PINS() {
    for (int i = 0; i < 3; i++) {
      pinMode(direction_pins[i], OUTPUT);
      pinMode(enable_pins[i], OUTPUT);
      //pinMode(sensor_pins[i], INPUT);

      // Set velocity pins as PWM output and set frequency and resolution
      ledcSetup(led_channels[i], frequency, resolution);
      ledcAttachPin(velocity_pins[i], led_channels[i]);

      // reset all
      //setMotorSpeed(i, 0);
      setMotorDirection(i, false);
      setMotorEnable(i, false);
    }
  }
  void setMotorSpeed(int motor, float speed) {
    ledcWrite(led_channels[motor], speed);
  }
  void setMotorDirection(int motor, bool direction) {
    digitalWrite(direction_pins[motor], !direction);
  }
  void setMotorEnable(int motor, bool enable) {
    digitalWrite(enable_pins[motor], !enable);
  }
  float getMotorSensor(int motor) {
    return analogRead(sensor_pins[motor]);
  }
};


#endif // PINS_H