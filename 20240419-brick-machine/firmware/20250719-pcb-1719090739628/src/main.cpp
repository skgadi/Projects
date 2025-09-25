#include "main.h"

GSK_PINS pins;
GSK_MOTOR motors[] = {
    GSK_MOTOR(PIN_DIR_1, PIN_PWR_1, PIN_SPEED_1),
    GSK_MOTOR(PIN_DIR_2, PIN_PWR_2, PIN_SPEED_2),
    GSK_MOTOR(PIN_DIR_3, PIN_PWR_3, PIN_SPEED_3),
};

int allPins[3][4] = {
    {PIN_POS_SEN_1, PIN_DIR_1, PIN_PWR_1, PIN_SPEED_1},
    {PIN_POS_SEN_2, PIN_DIR_2, PIN_PWR_2, PIN_SPEED_2},
    {PIN_POS_SEN_3, PIN_DIR_3, PIN_PWR_3, PIN_SPEED_3},
};

void increaseSpeed() {
    for (int i = 0; i < 255; i++) {
        analogWrite(PIN_SPEED_2, i);
        delay(10);
    }
}

float getPositionSensorValue(int pin) {
    // read the input on analog pin and map 0 as 0 and 4095 as 100
    int sensorValue = analogRead(pin);
    float voltage = sensorValue * (5.0 / 4095.0);
    float percentage = (voltage - 0) * (100 - 0) / (5 - 0) + 0;
    return percentage;
}

void setup() { Serial.begin(115200); }

bool isForward = true;
int selectedMotor = 0;
int selectedSpeed = 0;
bool direction = true;
bool isMoving = false;
void loop() {
    if (Serial.available() > 0) {
        int command = Serial.parseInt();
        if (command != 0) {
            Serial.print("Command: ");
            Serial.println(command);

            if (command > 0 && command <= 255) {
                selectedSpeed = command;
            } else if (command < 0 && command > -4) {
                selectedMotor = abs(command) - 1;
            } else if (command == -4) {
                isMoving = !isMoving;
            } else if (command == -5) {
                direction = !direction;
            }
            Serial.print("Selected Motor: ");
            Serial.println((selectedMotor + 1));
            Serial.print("Selected Speed: ");
            Serial.println(selectedSpeed);
            Serial.print("Direction: ");
            Serial.println(direction ? "Forward" : "Backward");
            Serial.print("Moving: ");
            Serial.println(isMoving ? "Yes" : "No");
            Serial.print("Position Sensor 1: ");
            Serial.println(getPositionSensorValue(PIN_POS_SEN_1));
            Serial.print("Position Sensor 2: ");
            Serial.println(getPositionSensorValue(PIN_POS_SEN_2));
            Serial.print("Position Sensor 3: ");
            Serial.println(getPositionSensorValue(PIN_POS_SEN_3));
        }
        if (!isMoving) {
            analogWrite(allPins[selectedMotor][3], 0);
            digitalWrite(allPins[selectedMotor][3], LOW);  // stop the motor
            digitalWrite(allPins[selectedMotor][2],
                         HIGH);  // turn power off to the motor
            digitalWrite(allPins[selectedMotor][1],
                         LOW);  // set direction to low to relax the relays
        } else {
            // pinMode(allPins[selectedMotor][3], OUTPUT);
            analogWrite(allPins[selectedMotor][3], selectedSpeed);  // set speed
            digitalWrite(allPins[selectedMotor][1],
                         direction ? HIGH : LOW);  // set direction
            digitalWrite(allPins[selectedMotor][2],
                         LOW);  // turn power on to the motor
        }
    }
}
