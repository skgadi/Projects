#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

#include "Adafruit_TCS34725.h"

/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs =
    Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

void setup() {
    Serial.begin(115200);

    if (tcs.begin()) {
        Serial.println("Found sensor");
    } else {
        Serial.println("No TCS34725 found ... check your connections");
        while (1);
    }
}

void loop() {
    uint16_t r, g, b, c, colorTemp, lux;

    tcs.getRawData(&r, &g, &b, &c);
    // colorTemp = tcs.calculateColorTemperature(r, g, b);
    colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
    lux = tcs.calculateLux(r, g, b);

    Serial.print("Color Temp: ");
    Serial.print(colorTemp, DEC);
    Serial.print(" K - ");
    Serial.print("Lux: ");
    Serial.print(lux, DEC);
    Serial.print(" - ");
    Serial.print("R: ");
    Serial.print(r, DEC);
    Serial.print(" ");
    Serial.print("G: ");
    Serial.print(g, DEC);
    Serial.print(" ");
    Serial.print("B: ");
    Serial.print(b, DEC);
    Serial.print(" ");
    Serial.print("C: ");
    Serial.print(c, DEC);
    Serial.print(" ");
    Serial.print("CCSS: #");
    Serial.print(r*255/c, HEX);
    Serial.print(g*255/c, HEX);
    Serial.print(b*255/c, HEX);
    Serial.println(" ");

    delay(1000);
}
