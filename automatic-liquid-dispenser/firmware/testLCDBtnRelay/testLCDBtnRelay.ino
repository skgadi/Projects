#include <LiquidCrystal_I2C.h>


#define NUMBER_OF_IN_OUT_PINS 5
#define IS_SMD_MICRO



LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

int rlyPins[NUMBER_OF_IN_OUT_PINS+1];

  int btnPins[(NUMBER_OF_IN_OUT_PINS + 1)];
  int progBtnPin;

void setup() {

  lcd.init();
  lcd.backlight();
  // put your setup code here, to run once:

  #ifdef IS_SMD_MICRO
  rlyPins[0] = 10;
  rlyPins[1] = 9;
  rlyPins[2] = 8;
  rlyPins[3] = 7;
  rlyPins[4] = 6;
  rlyPins[NUMBER_OF_IN_OUT_PINS] = 5;
  #else
  rlyPins[0] = 0;
  rlyPins[1] = 1;
  rlyPins[2] = 5;
  rlyPins[3] = 6;
  rlyPins[4] = 7;
  rlyPins[NUMBER_OF_IN_OUT_PINS] = 8;
  #endif
for (int  i = 0; i < (NUMBER_OF_IN_OUT_PINS+1) ; i++) {
    pinMode(rlyPins[i], OUTPUT);
  }



  #ifdef IS_SMD_MICRO
  btnPins[0] = A2;
  btnPins[1] = A3;
  btnPins[2] = A0;
  btnPins[3] = A1;
  btnPins[4] = 0;
  btnPins[NUMBER_OF_IN_OUT_PINS] = 1;
  progBtnPin = 3;
  #else
  btnPins[0] = 9;
  btnPins[1] = 10;
  btnPins[2] = A0;
  btnPins[3] = A1;
  btnPins[4] = A2;
  btnPins[NUMBER_OF_IN_OUT_PINS] = A3;
  progBtnPin = 11;
  #endif


  for (int i=0; i<(NUMBER_OF_IN_OUT_PINS + 1); i++) {
    pinMode(btnPins[i], INPUT_PULLUP);
  }
  pinMode(progBtnPin, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
if(!digitalRead(btnPins[NUMBER_OF_IN_OUT_PINS])) {
int btnValRead = getButton();
lcd.clear();
lcd.setCursor(1,1);
lcd.print(btnValRead);
setRelayPins(btnValRead);
digitalWrite(rlyPins[NUMBER_OF_IN_OUT_PINS], HIGH);
} else {
  digitalWrite(rlyPins[NUMBER_OF_IN_OUT_PINS], LOW);
  lcd.clear();
  lcd.setCursor(1,1);
  lcd.print("Waiting");
}
delay(1000);
}



void setRelayPins(int rlyNumber) {
  for (int i=0; i<NUMBER_OF_IN_OUT_PINS; i++) {
    digitalWrite(rlyPins[i], !!(rlyNumber & (1<<i)));
  }
}


int getButton() {
  int out = 0;
  for (int i=0; i<NUMBER_OF_IN_OUT_PINS; i++) {
    int tempPinOut = 0 | (!digitalRead(btnPins[i]));
      tempPinOut <<= i;
      out |= tempPinOut;
  }
  return out;
}
