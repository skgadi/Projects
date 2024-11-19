#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
//#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

// put function declarations here:
int myFunction(int, int);

void setup() {
    // put your setup code here, to run once:
    //Wire.setPins(26, 27);
    delay(1000);
    //LiquidCrystal_I2C lcd(0x27, 20, 4);
    delay(1000);
    lcd.init();
    delay(1000);
    lcd.backlight();
}

void loop() {
    // put your main code here, to run repeatedly:
    lcd.setCursor(0, 0);
    lcd.print("Hello, World!");

    delay(1000);
}
