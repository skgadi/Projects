#ifndef STATE_H
#define STATE_H

#include <Arduino.h>
#include "pins.h"

class GSK_STATE {
  float motor_speeds_reference[3] = {0, 0, 0};
  bool motor_directions_reference[3] = {0, 0, 0};
  bool is_motor_active[3] = {false, false, false};
  float motor_speeds[3] = {0, 0, 0};
  int motor_directions[3] = {0, 0, 0};
  GSK_PINS* pins;
public:
  GSK_STATE() {
    pins = new GSK_PINS();
    for (int i = 0; i < 3; i++) {
      is_motor_active[i] = false;
      motor_speeds_reference[i] = false;
      motor_directions_reference[i] = 0;
      motor_speeds[i] = 0;
      motor_directions[i] = 0;
    }
  }
  void setMotorSpeedReference(int motor, float speed) {
    for (int i = 0; i < 3; i++) {
      if (i == motor) {
        motor_speeds_reference[i] = speed;
      } else {
        motor_speeds_reference[i] = 0;
      }
    }
  }
  void setMotorDirectionReference(int motor, int direction) {
    for (int i = 0; i < 3; i++) {
      if (i == motor) {
        motor_directions_reference[i] = direction;
      } else {
        motor_directions_reference[i] = 0;
      }
    }
  }
  void resetAllSpeedsAndDirections() {
    for (int i = 0; i < 3; i++) {
      motor_speeds_reference[i] = 0;
      motor_directions_reference[i] = 0;
      is_motor_active[i] = false;
    }
  }
  void loop() {
    // calculate the motorSpeed and directions
    // Only one motor can be active at a time
    // the motor direction is forward for true and reverse for false
    // the motor speed is a value between 0 and 255 (PWM) convert percent to PWM
    // The is_motor_active array should be going low and then high before the direction could be changed
    // The latest requirements are in the motor_speeds_reference and motor_directions_reference arrays
    // The motor_speeds and motor_directions arrays should be updated with the latest values ensuring that the motor is not active
    // is_motor_active should be false when the motor velocity is 0

    bool changeFoundInMotorDirection = false;
    int changeFoundForMotor = -1;
    for (int i = 0; i < 3; i++) {
      resetAllSpeedsAndDirections();
    }
    if (changeFoundInMotorDirection){
      bool wasThereAMotorActive = is_motor_active[changeFoundForMotor];
      resetAllSpeedsAndDirections();
      if (!wasThereAMotorActive) {
        motor_speeds[changeFoundForMotor] = motor_speeds_reference[changeFoundForMotor];
        motor_directions[changeFoundForMotor] = motor_directions_reference[changeFoundForMotor];
        is_motor_active[changeFoundForMotor] = true;
      }
    } else {
      bool changeFoundInMotorSpeed = false;
      int speedChangeFoundForMotor = -1;
      for (int i = 0; i < 3; i++) {
        if (motor_speeds_reference[i] != motor_speeds[i]) {
          changeFoundInMotorSpeed = true;
          speedChangeFoundForMotor = i;
        }
      }
      if (changeFoundInMotorSpeed) {
        resetAllSpeedsAndDirections();
        if (motor_speeds_reference[speedChangeFoundForMotor] != 0) {
          motor_speeds[speedChangeFoundForMotor] = motor_speeds_reference[speedChangeFoundForMotor];
          is_motor_active[speedChangeFoundForMotor] = true;
        }
      }          
    }
  }
};

#endif // STATE_H