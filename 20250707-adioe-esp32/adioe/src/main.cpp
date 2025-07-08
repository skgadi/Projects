/*
 * Analog and Digital Input and Output Server for MATLAB - ESP32 Version
 * Originally by Giampiero Campa, Copyright 2012 The MathWorks, Inc
 * Rewritten for ESP32 by an AI assistant, 2023.
 *
 * This version is adapted for the ESP32 platform under the Arduino framework.
 * Key Changes from the Arduino Uno Version:
 * 1.  Servo Control: Uses the <ESP32Servo.h> library. Note the default limit of
 * 16 servos.
 * 2.  Interrupts: Removed the AVR-specific getIntNum() function. Any GPIO can
 * be an interrupt pin. ISRs are placed in IRAM for performance using IRAM_ATTR.
 * 3.  ISR Debouncing: Replaced the blocking delay loop with a non-blocking
 * micros() timer, which is critical for ESP32 stability.
 * 4.  Analog Input: ESP32's 12-bit ADC (0-4095) is scaled down to 10-bit
 * (0-1023) to maintain compatibility with clients expecting Uno behavior.
 * 5.  Analog Reference: The analogReference() command is disabled as it's not
 * supported by the ESP32.
 * 6.  Pin numbers still use the original character-based mapping.
 *     - Digital Pins: 'c' (2) to '¦' (166). Check your ESP32 board's pinout.
 *     - Analog Pins: 'a' (0) to 'p' (15). On most ESP32s, ADC1 pins are GPIOs
 * 32-39. ADC2 pins cannot be used when WiFi is active. It's safest to use ADC1
 * pins.
 */

#include <Arduino.h>
#include <ESP32Servo.h>

// --- ESP32 Specific Configuration ---
#define MAX_SERVOS 16  // ESP32Servo library supports up to 16 servos by default
#define DEBOUNCE_TIME_US \
    100  // Base time unit for debounce delay in microseconds

/* define encoder structure - modified for non-blocking debounce */
typedef struct {
    int pinA;
    int pinB;
    volatile int pos;
    volatile unsigned long del;           // Debounce delay in microseconds
    volatile unsigned long last_microsA;  // Last interrupt time for pin A
    volatile unsigned long last_microsB;  // Last interrupt time for pin B
} Encoder;
volatile Encoder Enc[3] = {
    {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};

/* create servo vector - limited by ESP32 capabilities */
Servo servo[MAX_SERVOS];

void setup() {
    /* initialize serial */
    Serial.begin(115200);

    // Allow allocation of all timers for servos
    ESP32PWM::allocateTimer(0);
    ESP32PWM::allocateTimer(1);
    ESP32PWM::allocateTimer(2);
    ESP32PWM::allocateTimer(3);
}

// --- Forward declaration of ISRs ---
void IRAM_ATTR isrPinAEn0();
void IRAM_ATTR isrPinBEn0();
void IRAM_ATTR isrPinAEn1();
void IRAM_ATTR isrPinBEn1();
void IRAM_ATTR isrPinAEn2();
void IRAM_ATTR isrPinBEn2();

void loop() {
    /* variables declaration and initialization */
    static int s = -1;   /* state */
    static int pin = 13; /* generic pin number */
    static int enc = 0;  /* generic encoder number */

    int val = 0; /* generic value read from serial */
    int agv = 0; /* generic analog value */
    int dgv = 0; /* generic digital value */

    if (Serial.available() > 0) {
        val = Serial.read();

        switch (s) {
            /* s=-1 means NOTHING RECEIVED YET ******************* */
            case -1:
                if (val > 47 && val < 90) {
                    s = 10 * (val - 48);
                }
                if ((s > 90 && s < 210) || (s > 250 && s != 340 && s != 400)) {
                    s = -1;
                }
                break;

            /* s=0 or 1 means CHANGE PIN MODE */
            case 0:
                if (val > 98 && val < 167) {
                    pin = val - 97;
                    s = 1;
                } else {
                    s = -1;
                }
                break;
            case 1:
                if (val > 47 && val < 50) {
                    if (val == 48) {
                        pinMode(pin, INPUT);
                    } else {
                        pinMode(pin, OUTPUT);
                    }
                }
                s = -1;
                break;

            /* s=10 means DIGITAL INPUT ************************** */
            case 10:
                if (val > 98 && val < 167) {
                    pin = val - 97;
                    dgv = digitalRead(pin);
                    Serial.println(dgv);
                }
                s = -1;
                break;

            /* s=20 or 21 means DIGITAL OUTPUT ******************* */
            case 20:
                if (val > 98 && val < 167) {
                    pin = val - 97;
                    s = 21;
                } else {
                    s = -1;
                }
                break;
            case 21:
                if (val > 47 && val < 50) {
                    dgv = val - 48;
                    digitalWrite(pin, dgv);
                }
                s = -1;
                break;

            /* s=30 means ANALOG INPUT *************************** */
            case 30:
                if (val > 96 && val < 113) {
                    pin = val - 97;
                    // ESP32 ADC is 12-bit (0-4095). Scale to 10-bit (0-1023)
                    // for compatibility. Note: Use ADC1 pins (e.g., GPIO 32-39)
                    // for best results.
                    agv = analogRead(pin) >> 2;
                    Serial.println(agv);
                }
                s = -1;
                break;

            /* s=40 or 41 means ANALOG OUTPUT (PWM) **************** */
            case 40:
                if (val > 98 && val < 167) {
                    pin = val - 97;
                    s = 41;
                } else {
                    s = -1;
                }
                break;
            case 41:
                // ESP32 `analogWrite` uses LEDC peripheral. Default is 8-bit
                // resolution (0-255).
                analogWrite(pin, val);
                s = -1;
                break;

            /* s=50 means SERVO STATUS *************************** */
            case 50:
                if (val > 98 && val < 167) {
                    pin = val - 97;
                    if (pin < MAX_SERVOS) {
                        dgv = servo[pin].attached();
                        Serial.println(dgv);
                    }
                }
                s = -1;
                break;

            /* s=60 or 61 means SERVO ATTACH/DETACH ************** */
            case 60:
                if (val > 98 && val < 167) {
                    pin = val - 97;
                    s = 61;
                } else {
                    s = -1;
                }
                break;
            case 61:
                if (val > 47 && val < 50) {
                    if (pin < MAX_SERVOS) {
                        dgv = val - 48;
                        if (dgv)
                            servo[pin].attach(pin);
                        else
                            servo[pin].detach();
                    }
                }
                s = -1;
                break;

            /* s=70 means SERVO READ ***************************** */
            case 70:
                if (val > 98 && val < 167) {
                    pin = val - 97;
                    if (pin < MAX_SERVOS) {
                        agv = servo[pin].read();
                        Serial.println(agv);
                    }
                }
                s = -1;
                break;

            /* s=80 or 81 means SERVO WRITE ********************** */
            case 80:
                if (val > 98 && val < 167) {
                    pin = val - 97;
                    s = 81;
                } else {
                    s = -1;
                }
                break;
            case 81:
                if (pin < MAX_SERVOS) {
                    servo[pin].write(val);
                }
                s = -1;
                break;

            /* s=90 means Query Script Type */
            case 90:
                if (val == 57) {
                    Serial.println(2);  // Script type 2 (adiosrv)
                }
                s = -1;
                break;

            /* s=210 to 212 means ENCODER ATTACH ***************** */
            case 210:
                if (val > 47 && val < 51) {
                    enc = val - 48;
                    s = 211;
                } else {
                    s = -1;
                }
                break;
            case 211:
                if (val > 98 && val < 167) {
                    pin = val - 97;
                    Enc[enc].pinA = pin;
                    s = 212;
                } else {
                    s = -1;
                }
                break;
            case 212:
                if (val > 98 && val < 167) {
                    pin = val - 97;
                    Enc[enc].pinB = pin;
                    pinMode(Enc[enc].pinA, INPUT_PULLUP);
                    pinMode(Enc[enc].pinB, INPUT_PULLUP);

                    // Attach interrupts directly to pins. No getIntNum()
                    // needed.
                    switch (enc) {
                        case 0:
                            attachInterrupt(digitalPinToInterrupt(Enc[0].pinA),
                                            isrPinAEn0, CHANGE);
                            attachInterrupt(digitalPinToInterrupt(Enc[0].pinB),
                                            isrPinBEn0, CHANGE);
                            break;
                        case 1:
                            attachInterrupt(digitalPinToInterrupt(Enc[1].pinA),
                                            isrPinAEn1, CHANGE);
                            attachInterrupt(digitalPinToInterrupt(Enc[1].pinB),
                                            isrPinBEn1, CHANGE);
                            break;
                        case 2:
                            attachInterrupt(digitalPinToInterrupt(Enc[2].pinA),
                                            isrPinAEn2, CHANGE);
                            attachInterrupt(digitalPinToInterrupt(Enc[2].pinB),
                                            isrPinBEn2, CHANGE);
                            break;
                    }
                }
                s = -1;
                break;

            /* s=220 means ENCODER DETACH *********************** */
            case 220:
                if (val > 47 && val < 51) {
                    enc = val - 48;
                    detachInterrupt(digitalPinToInterrupt(Enc[enc].pinA));
                    detachInterrupt(digitalPinToInterrupt(Enc[enc].pinB));
                }
                s = -1;
                break;

            /* s=230 means GET ENCODER POSITION ****************** */
            case 230:
                if (val > 47 && val < 51) {
                    enc = val - 48;
                    noInterrupts();  // Ensure atomic read
                    long pos = Enc[enc].pos;
                    interrupts();
                    Serial.println(pos);
                }
                s = -1;
                break;

            /* s=240 means RESET ENCODER POSITION **************** */
            case 240:
                if (val > 47 && val < 51) {
                    enc = val - 48;
                    noInterrupts();  // Ensure atomic write
                    Enc[enc].pos = 0;
                    interrupts();
                }
                s = -1;
                break;

            /* s=250 and 251 mean SET ENCODER DEBOUNCE DELAY ***** */
            case 250:
                if (val > 47 && val < 51) {
                    enc = val - 48;
                    s = 251;
                } else {
                    s = -1;
                }
                break;
            case 251:
                if (val > 96 && val < 167) {
                    // Map value to microseconds. e.g. 'a'(97)->0,
                    // 'b'(98)->100us, 'c'(99)->200us etc.
                    Enc[enc].del = (val - 97) * DEBOUNCE_TIME_US;
                }
                s = -1;
                break;

            /* s=340 means ANALOG REFERENCE (Not Supported on ESP32) */
            case 340:
                // This function is ignored. ESP32 does not support changing the
                // analog reference. The ADC reference is tied to the 3.3V
                // supply. You can use ADC attenuation for different voltage
                // ranges, but that's not implemented in this compatibility
                // sketch.
                s = -1;
                break;

            /* s=400 roundtrip example function ******************* */
            case 400:
                Serial.println(val);
                s = -1;
                break;

            /* ******* UNRECOGNIZED STATE *********************** */
            default:
                s = -1;
        }
    }
}

// --- Interrupt Service Routines (ISRs) for Encoders ---
// Note: These are identical in logic, just operating on different encoder
// structs. They use a non-blocking debounce method suitable for the ESP32.

void IRAM_ATTR isrPinAEn0() {
    unsigned long time_now = micros();
    if (time_now - Enc[0].last_microsA < Enc[0].del) return;  // Debounce
    Enc[0].last_microsA = time_now;

    if (digitalRead(Enc[0].pinA) == digitalRead(Enc[0].pinB)) {
        Enc[0].pos++;
    } else {
        Enc[0].pos--;
    }
}

void IRAM_ATTR isrPinBEn0() {
    unsigned long time_now = micros();
    if (time_now - Enc[0].last_microsB < Enc[0].del) return;  // Debounce
    Enc[0].last_microsB = time_now;

    if (digitalRead(Enc[0].pinA) == digitalRead(Enc[0].pinB)) {
        Enc[0].pos--;
    } else {
        Enc[0].pos++;
    }
}

void IRAM_ATTR isrPinAEn1() {
    unsigned long time_now = micros();
    if (time_now - Enc[1].last_microsA < Enc[1].del) return;
    Enc[1].last_microsA = time_now;

    if (digitalRead(Enc[1].pinA) == digitalRead(Enc[1].pinB)) {
        Enc[1].pos++;
    } else {
        Enc[1].pos--;
    }
}

void IRAM_ATTR isrPinBEn1() {
    unsigned long time_now = micros();
    if (time_now - Enc[1].last_microsB < Enc[1].del) return;
    Enc[1].last_microsB = time_now;

    if (digitalRead(Enc[1].pinA) == digitalRead(Enc[1].pinB)) {
        Enc[1].pos--;
    } else {
        Enc[1].pos++;
    }
}

void IRAM_ATTR isrPinAEn2() {
    unsigned long time_now = micros();
    if (time_now - Enc[2].last_microsA < Enc[2].del) return;
    Enc[2].last_microsA = time_now;

    if (digitalRead(Enc[2].pinA) == digitalRead(Enc[2].pinB)) {
        Enc[2].pos++;
    } else {
        Enc[2].pos--;
    }
}

void IRAM_ATTR isrPinBEn2() {
    unsigned long time_now = micros();
    if (time_now - Enc[2].last_microsB < Enc[2].del) return;
    Enc[2].last_microsB = time_now;

    if (digitalRead(Enc[2].pinA) == digitalRead(Enc[2].pinB)) {
        Enc[2].pos--;
    } else {
        Enc[2].pos++;
    }
}