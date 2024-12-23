#include "gsk_lcd.h"

void GSK_LCD::init() {
    setPoint = -1;
    temperature = -1;
    humidity = -1;
    isFanOn = true;
    isSystemOn = true;

    lcd = new LiquidCrystal_I2C(0x27, 20, 4);
    lcd->init();
    lcd->backlight();

    setTemperature(0);
    setHumidity(0);
    setSetPoint(0);
    setFanOn(false);
    setSystemOn(false);

    loop();
}

void GSK_LCD::setTemperature(int t) { newTemperature = t; }

void GSK_LCD::setHumidity(int h) { newHumidity = h; }

void GSK_LCD::setSetPoint(int sp) { newSetPoint = sp; }

void GSK_LCD::setFanOn(bool fo) { newIsFanOn = fo; }

void GSK_LCD::setSystemOn(bool so) { newIsSystemOn = so; }

void GSK_LCD::loop() {
    if (newSetPoint != setPoint) {
        setPoint = newSetPoint;

        lcd->setCursor(0, 0);
        lcd->print("Set Point:          ");
        lcd->setCursor(11, 0);
        lcd->print(setPoint);
        lcd->print("C");
    }

    if (newTemperature != temperature) {
        temperature = newTemperature;
        // Clear the line before printing the new value
        lcd->setCursor(0, 1);
        lcd->print("Temp:               ");
        lcd->setCursor(6, 1);
        lcd->print(temperature);
        lcd->print("C");
    }
    if (newHumidity != humidity) {
        humidity = newHumidity;
        lcd->setCursor(0, 2);
        lcd->print("Humidity:          ");
        lcd->setCursor(10, 2);
        lcd->print(humidity);
        lcd->print("%");
    }

    if (newIsFanOn != isFanOn) {
        isFanOn = newIsFanOn;
        lcd->setCursor(0, 3);
        lcd->print("Fan: ");
        lcd->print(isFanOn ? "On " : "Off");
    }

    if (newIsSystemOn != isSystemOn) {
        isSystemOn = newIsSystemOn;
        lcd->setCursor(10, 3);
        lcd->print("Sys: ");
        lcd->print(isSystemOn ? "On " : "Off");
    }
}