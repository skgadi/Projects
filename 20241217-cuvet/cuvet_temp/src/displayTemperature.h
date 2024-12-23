#include <Adafruit_SSD1306.h>

void displayTemperature(Adafruit_SSD1306* display, int temperature,
                        int remainingTime) {
    display->clearDisplay();
    display->setTextSize(5);
    display->setCursor(20, 10);
    if (temperature < 10) {
        display->print("0");
    }
    display->print(temperature);
    display->setCursor(90, 10);
    display->print("C");
    display->setTextSize(1.5);
    display->setCursor(82, 8);
    display->print("o");
    display->setTextSize(1);
    display->setCursor(100, 55);
    display->print(remainingTime);
    display->display();
    delay(100);
}