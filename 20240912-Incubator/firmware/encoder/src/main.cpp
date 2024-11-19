#include <Arduino.h>
#include <ESP32Encoder.h>

#define ENCODER_CLK 14 
#define ENCODER_DTA 27 
#define ENCODER_BTN 26 

ESP32Encoder encoder;
int64_t tempPos = 0;

void setup() {
  encoder.attachHalfQuad(ENCODER_DTA, ENCODER_CLK);
  encoder.setCount(0);
  Serial.begin ( 115200 );

}

void loop() {
  long newPosition = encoder.getCount();
  if (tempPos != newPosition) {
    tempPos = newPosition;
    Serial.println(newPosition);
  }
  delay(1);
}
