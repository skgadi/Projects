
#include "gsk_global.h"

#include "gsk_lcd.h"
#include "gsk_motor.h"
#include "gsk_button.h"
#include "gsk_coin.h"
#include "gsk_eeprom.h"









GSK_MOTOR gsk_motor;
GSK_LCD gsk_display;
GSK_BUTTON gsk_button;
GSK_COIN gsk_coin;

int test_count = 0;
void setup() {
  Serial.begin(115200);
  gsk_motor.start(-1);
  gsk_display.setup();
  gsk_display.showWelcome();
}

void loop() {

  int count = gsk_coin.read();
  if (count > 0) {
    gsk_display.printNumber(count);
  }
  int button = gsk_button.read();
  if (!(button<0)) {
    gsk_display.printNumber(button);
  }
}

