#include <Arduino.h>
#line 1 "c:\\Suresh\\git\\Projects\\pressure-control\\firmware\\code\\code.ino"
#include <LiquidCrystal_I2C.h>
#include <PID_v1.h>

LiquidCrystal_I2C lcd (0x27, 16, 2);



double output = 0;
double setPoint = 0;
double value = 0;


PID myPID(&value, &output, &setPoint, 2, 5, 0, DIRECT);


#line 16 "c:\\Suresh\\git\\Projects\\pressure-control\\firmware\\code\\code.ino"
void setup();
#line 32 "c:\\Suresh\\git\\Projects\\pressure-control\\firmware\\code\\code.ino"
void loop();
#line 16 "c:\\Suresh\\git\\Projects\\pressure-control\\firmware\\code\\code.ino"
void setup() {

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Set point: ");
  lcd.setCursor(0,1);
  lcd.print("Value: ");


  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(2, 0);
  myPID.SetMode(AUTOMATIC);
}

void loop() {
  setPoint = analogRead(A0) *26.0/1023.0;
  double a = -(analogRead(A1)-375)*26.0/300.0;
  if (a >26) {
    value = 26;
  } else if (a < 0) {
    value = 0;
  } else {
    value = a;
  }

  /*if (setPoint>value) {
    analogWrite(3, 255);
  } else {
    analogWrite(3, 0);
  }*/

  myPID.Compute();

  analogWrite(3, output);


  lcd.setCursor(11, 0);
  lcd.print(setPoint);
  lcd.print("  ");
  lcd.setCursor(7, 1);
  lcd.print(value);
  lcd.print("  ");
  delay(100);
}
