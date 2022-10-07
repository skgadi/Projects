#include <Wire.h>

int i=0;
int inc = 0;
void setup() {

  Wire.setClock(10000);
  Wire.begin();


  pinMode(5, OUTPUT);
  pinMode(1, INPUT);
}

void loop() {
  if(!digitalRead(1)) {
    if (inc==0) {
      i++;
    }
    inc=1;

    if (i>5) {
      delay(500);
      digitalWrite(5, LOW);
      delay(500);
      digitalWrite(5, HIGH);    
      Wire.beginTransmission(0x27);
      Wire.write(0xff);
      Wire.endTransmission();
    } else {
      digitalWrite(5, HIGH); 
    }
  } else {
    inc = 0;
    digitalWrite(5, LOW);  
  }
  delay(100);
}
