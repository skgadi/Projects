#include <Adafruit_GFX.h>
#include <Adafruit_MLX90614.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <math.h>

#include "displayTemperature.h"
#include "logo.h"

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS \
    0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Temperature sensor
Adafruit_MLX90614 mlx = Adafruit_MLX90614();


int remainingTimeInSeconds = 0;

void setup() {
    Wire.begin();
    Serial.begin(115200);

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);  // Don't proceed, loop forever
    }

    if (!mlx.begin()) {
        Serial.println("Error connecting to MLX sensor. Check wiring.");
        while (1);
    };

    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);

    displayLogo(&display);
}

void loop() {
    if (Serial.available() > 0) {
        int inNumber = Serial.parseInt();
        if (inNumber != 0) {
            remainingTimeInSeconds = inNumber;
        }
    }
    if (remainingTimeInSeconds != 0) {
    for (int i=0; i<remainingTimeInSeconds; i++) {
      double objTemp = mlx.readObjectTempC();
        displayTemperature(&display, round (mlx.readObjectTempC()), remainingTimeInSeconds - i);
        Serial.println(objTemp);
        delay(1000);
    }
    remainingTimeInSeconds = 0;
    displayLogo(&display);
    }
}