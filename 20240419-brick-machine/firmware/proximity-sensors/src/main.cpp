#include <Arduino.h>
#include <ESP32SharpIR.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int trigPin = 32;
const int echoPin = 33;

// define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

void setup() {
  Serial.begin(115200);

  // LCD settings

  lcd.init();
  lcd.backlight();

  // HC-SR04 settings
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Display Titles
  lcd.setCursor(0, 0);
  lcd.print("Sensor de ultrasonido");
  lcd.setCursor(0, 2);
  lcd.print("Sensore de luz");

  // Sharp IR sensor
  // Setting the filter resolution to 0.1
}

void loop() {
  // Ultrasonic sensor readings
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  float distance = duration * SOUND_SPEED / 2;
  if (distance > 400 || distance < 2) {
    distance = -1;
  }

  lcd.setCursor(0, 1);
  lcd.print(String(distance, 2) + " cm           ");

  // Sharp IR sensor readings
  float voltage = map(analogRead(27), 0, 4095, 0, 3300) / 1000.0;
  // Calculate the distance in cm using the following resources
  // https://global.sharp/products/device/lineup/data/pdf/datasheet/gp2y0a21yk_e.pdf
  //https://apps.automeris.io/wpd/
  //https://plot.ly/create/
  distance = 0.009933944209016285
  -0.03957482651686597 * voltage
  + 0.1794261012941814 * pow(voltage, 2)
  -0.20925021017163184 * pow(voltage, 3)
  + 0.13108194899734532 * pow(voltage, 4)
  -0.0405092397239265 * pow(voltage, 5)
  + 0.004835180731525765 * pow(voltage, 6);

  distance = 1 / distance;

  //distance = 16.2537 * pow(voltage, 4) - 129.893 * pow(voltage, 3) + 382.268 * pow(voltage, 2) - 512.611 * voltage + 301.439;

  Serial.println(distance);
  Serial.println(voltage);
  /*if (distance > 80 || distance < 10) {
    distance = -1;
  }*/
  // float sharpDistance = sensor.getDistanceFloat();
  lcd.setCursor(0, 3);
  lcd.print(String(distance, 2) + " cm       ");

  delay(1000);
}
