#include <Arduino.h>
#include <ESP32Servo.h>

Servo myservo;      // create servo object to control a servo
int servoPin = 18;  // control pin for servo
int pos = 0;

void setup() {
    Serial.begin(115200);
    Serial.println("Hello, world!");

    // Allow allocation of all timers
    ESP32PWM::allocateTimer(0);
    ESP32PWM::allocateTimer(1);
    ESP32PWM::allocateTimer(2);
    ESP32PWM::allocateTimer(3);
    myservo.setPeriodHertz(50);  // standard 50 hz servo
    myservo.attach(servoPin, 544,
                   2400);  // attaches the servo on pin 18 to the servo object
                           // using default min/max of 1000us and 2000us
    // different servos may require different min/max settings
    // for an accurate 0 to 180 sweep
}

void loop() {
    if (Serial.available()) {
        int val = Serial.parseInt();
        if (val >= 0 && val <= 180) {
            pos = val;
            Serial.println(val);
        }
    }
    myservo.write(pos);
}