#include <Arduino.h>
int pwmType = 0;  // 0-blink slowly, 1-blink fast, 2- very fast blink 3 - on, 4
                  // - off, 5 - set duty cycle
float dutyCycle = 0;
int PWM_PIN = 13;

TaskHandle_t Task1;
TaskHandle_t Task2;

void Task1code(void* pvParameters) {
    for (;;) {
        switch (pwmType) {
            case 0:
                for (int i = 0; i < 256; i++) {
                    analogWrite(PWM_PIN, i);
                    delay(20);
                }
                for (int i = 255; i >= 0; i--) {
                    analogWrite(PWM_PIN, i);
                    delay(20);
                }
                break;
            case 1:
                for (int i = 0; i < 256; i++) {
                    analogWrite(PWM_PIN, i);
                    delay(10);
                }
                for (int i = 255; i >= 0; i--) {
                    analogWrite(PWM_PIN, i);
                    delay(10);
                }
                break;
            case 2:
                for (int i = 0; i < 256; i++) {
                    analogWrite(PWM_PIN, i);
                    delay(1);
                }
                for (int i = 255; i >= 0; i--) {
                    analogWrite(PWM_PIN, i);
                    delay(1);
                }
            case 3:
                analogWrite(PWM_PIN, 255);
                break;
            case 4:
                analogWrite(PWM_PIN, 0);
                break;
            case 5:
                analogWrite(PWM_PIN, dutyCycle);
                break;
            default:
                analogWrite(PWM_PIN, dutyCycle);
                break;
        }

        delay(2);
    }
}

void Task2code(void* pvParameters) {
    for (;;) {
        if (Serial.available() > 0) {
            int input = Serial.parseInt();
            if (input >= 0 && input <= 5) {
                pwmType = input;
                Serial.println("PWM type set to " + String(input));
            }
            if (input < 0 && input >= -100) {
                dutyCycle = input * -1 * 2.55;
                Serial.println("Duty cycle set to " + String(dutyCycle));
            }
        }
        delay(10);
    }
}

void setup() {
    Serial.begin(115200);

    // create a task that will be executed in the Task1code() function, with
    // priority 1 and executed on core 0
    xTaskCreatePinnedToCore(
        Task1code, /* Task function. */
        "Task1",   /* name of task. */
        10000,     /* Stack size of task */
        NULL,      /* parameter of the task */
        1,         /* priority of the task */
        &Task1,    /* Task handle to keep track of created task */
        0);        /* pin task to core 0 */
    delay(500);

    // create a task that will be executed in the Task2code() function, with
    // priority 1 and executed on core 1
    xTaskCreatePinnedToCore(
        Task2code, /* Task function. */
        "Task2",   /* name of task. */
        10000,     /* Stack size of task */
        NULL,      /* parameter of the task */
        1,         /* priority of the task */
        &Task2,    /* Task handle to keep track of created task */
        1);        /* pin task to core 1 */
    delay(500);
}

void loop() {}
