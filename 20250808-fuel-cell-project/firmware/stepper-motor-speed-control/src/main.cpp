#include <Arduino.h>
#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 120.0f
#define PUMP_FACTOR 1.6f
#define MULTIPLYING_FACTOR (STEPS * PUMP_FACTOR)
#define STEP_VALUE 1//(MULTIPLYING_FACTOR / 100.f)

// the previous reading from the analog input
int previous = 0;

#define POT_PIN 34
#define LED_PIN 2

//#define STEPPER_PIN_A1 12
//#define STEPPER_PIN_B1 14
//#define STEPPER_PIN_A2 27
//#define STEPPER_PIN_B2 26

#define STEPPER_PIN_A1 12
#define STEPPER_PIN_B1 27
#define STEPPER_PIN_A2 14
#define STEPPER_PIN_B2 26


// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, STEPPER_PIN_A1, STEPPER_PIN_B1, STEPPER_PIN_A2,
                STEPPER_PIN_B2);

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(
    0x27, 20,
    4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#include <ESP32RotaryEncoder.h>
#define DI_ENCODER_A 35
#define DI_ENCODER_B 32
#define DI_ENCODER_SW 33
#define DO_ENCODER_VCC 25

long motorSpeed = 50;
bool isEditing = false;
RotaryEncoder rotaryEncoder(DI_ENCODER_A, DI_ENCODER_B, DI_ENCODER_SW,
                            DO_ENCODER_VCC);

void showLCD() {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("Biorem Lab");
    lcd.setCursor(0, 2);
    lcd.print("Pump speed:");
    lcd.setCursor(12, 2);
    float pumpSpeedMl = motorSpeed / 10.0f;
    lcd.print(pumpSpeedMl, 1);
    lcd.print("ml/h");
    if (isEditing) {
        lcd.setCursor(14, 2);
        lcd.blink_on();
    } else {
        lcd.setCursor(14, 2);
        lcd.blink_off();
    }
}


void knobCallback(long knobValue) {
    if (isEditing) {
        Serial.printf("Value: %ld\n", knobValue);
        motorSpeed = knobValue;
        showLCD();
    }
}

void buttonCallback(unsigned long duration) {
    Serial.printf("boop! button was down for %lu ms\n", duration);
    isEditing = !isEditing;
    showLCD();
}


int motorSpeedPrevious = 0;
unsigned long lastPrintTime = 0;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(POT_PIN, INPUT);
    stepper.setSpeed(30);
    Serial.begin(115200);

    lcd.init();  // initialize the lcd
    lcd.backlight();

    rotaryEncoder.setEncoderType(EncoderType::FLOATING);
    rotaryEncoder.setBoundaries(50, 250, false);
    showLCD();

    // The function specified here will be called every time the knob is turned
    // and the current value will be passed to it
    rotaryEncoder.onTurned(&knobCallback);

    // The function specified here will be called every time the button is
    // pushed and the duration (in milliseconds) that the button was down will
    // be passed to it
    rotaryEncoder.onPressed(&buttonCallback);

    // This is where the inputs are configured and the interrupts get attached
    rotaryEncoder.begin();
}

int previousMotorSpeed = 0;

void loop() {
    if (previousMotorSpeed != motorSpeed) {
        previousMotorSpeed = motorSpeed;
        stepper.setSpeed(motorSpeed);
        // step 1/100 of a revolution:
    }
    stepper.step(STEP_VALUE);

}
