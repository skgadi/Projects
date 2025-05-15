#include <Servo.h>

Servo motor1;  // Base
Servo motor2;  // Hombro
Servo motor3;  // Brazo
Servo motor4;  // Mano 1
Servo motor5;  // Mano 2
Servo motor6;  // Mano 3
Servo motor7;  // Pinza

void setup() {
  Serial.begin(9600);
  motor1.attach(2);
  motor2.attach(3);
  motor3.attach(4);
  motor4.attach(5);
  motor5.attach(6);
  motor6.attach(7);
  motor7.attach(8);
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    if (input.length() < 3) return;

    char id = input.charAt(1);
    int angle = input.substring(2).toInt();
    angle = constrain(angle, 0, 180);

    switch (id) {
      case '1': motor1.write(angle); break;
      case '2': motor2.write(angle); break;
      case '3': motor3.write(angle); break;
      case '4': motor4.write(angle); break;
      case '5': motor5.write(angle); break;
      case '6': motor6.write(angle); break;
      case '7': motor7.write(angle); break;
    }
  }
}
