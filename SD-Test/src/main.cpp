#include <Arduino.h>
#include "skg_sd.h"

SKG_SD sd;

void setup() {
  Serial.begin(115200);    // Set serial baud rate to 9600
}

void loop() {
  if (Serial.available()) {
    float input = Serial.parseFloat();
    if (input == 1.0) {
      unsigned long startTime = micros();
      bool isSDCardPresent = sd.isSDCardPresent();
      unsigned long endTime = micros();
      Serial.print("isSDCardPresent: ");
      Serial.println(isSDCardPresent?"Yes :)":"No :(");
      Serial.print("Time taken: ");
      float timeTaken;
      if (endTime > startTime) {
        timeTaken = (float)(endTime - startTime) / 1000.0;
      } else {
        timeTaken = (float)(endTime + (4294967295 - startTime)) / 1000.0;
      }
      Serial.print(timeTaken);
      Serial.println(" ms");
    }
    if (input == 2.0) {
      sd.closeMainFile();
      sd.closeTestFile();
      Serial.println("Files closed");
    }
    if (input == 3.0) {
      sd.openMainFile();
      sd.openTestFile();
      Serial.println("Files opened");
    }
    if (input == 4.0) {
      int arrayLength = 1000;
      float array[arrayLength];
      for (int i = 0; i < arrayLength; i++) {
        array[i] = i;
      }
      unsigned long startTime = micros();
      sd.appendMainFile(array, 10);
      unsigned long endTime = micros();
      Serial.print("Time taken: ");
      float timeTaken;
      if (endTime > startTime) {
        timeTaken = (float)(endTime - startTime) / 1000.0;
      } else {
        timeTaken = (float)(endTime + (4294967295 - startTime)) / 1000.0;
      }
      Serial.print(timeTaken);
      Serial.println(" ms");
    }
  }
}