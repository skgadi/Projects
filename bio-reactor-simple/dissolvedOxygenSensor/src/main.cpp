#include <Arduino.h>


#define VREF    5000//VREF(mv)
#define ADC_RES 4096//ADC resolution
uint32_t raw;

// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(115200);
}

void loop() {
  raw=analogRead(27);
  Serial.println("raw:\t"+String(raw)+"\tVoltage(mv)"+String(raw*VREF/ADC_RES));
  delay(1000);
}
