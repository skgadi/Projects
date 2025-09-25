#ifndef GSK_MOTOR_HPP
#define GSK_MOTOR_HPP

#include <Arduino.h>

#define MIN_TIME_BETWEEN_DIRECTION_CHANGE \
    1000  // can be for relays to latch and for motor to change direction

class GSK_MOTOR {
   private:
    bool isForward = false;
    bool isMoving = false;
    float speed = 0;
    /* PINS */
    int pin_dir;
    int pin_pwr;
    int pin_speed;
    int getSpeedDuty(float speed) { return map(abs(speed), 0, 100, 0, 255); }

   public:
    GSK_MOTOR(int, int, int);
    void setSpeed(float speed);
};

GSK_MOTOR::GSK_MOTOR(int pin_dir, int pin_pwr, int pin_speed) {
    this->pin_dir = pin_dir;
    this->pin_pwr = pin_pwr;
    this->pin_speed = pin_speed;
    pinMode(pin_dir, OUTPUT);
    pinMode(pin_pwr, OUTPUT);
    pinMode(pin_speed, OUTPUT);
}

void GSK_MOTOR::setSpeed(float speed) {
    if (speed == 0) {
        digitalWrite(pin_dir, LOW);
        digitalWrite(pin_pwr, LOW);
        analogWrite(pin_speed, getSpeedDuty(0));
        isForward = false;
        isMoving = false;
        speed = 0;
    } else {
        if ((speed >= 0 && !isForward) || (speed < 0 && isForward)) {
            isForward = speed >= 0;
            analogWrite(pin_speed, getSpeedDuty(0));
            digitalWrite(pin_pwr, LOW);
            delay(MIN_TIME_BETWEEN_DIRECTION_CHANGE);
            digitalWrite(pin_dir, isForward ? HIGH : LOW);
            digitalWrite(pin_pwr, HIGH);
            analogWrite(pin_speed, getSpeedDuty(speed));
            Serial.println("Changing direction ...");
        } else {
            analogWrite(pin_speed, getSpeedDuty(speed));
        }
    }
}

#endif  // GSK_MOTOR_HPP