# 1 "c:\\Suresh\\git\\Projects\\automatic-liquid-dispenser\\firmware\\esp32\\ver000\\uc\\uc.ino"

# 3 "c:\\Suresh\\git\\Projects\\automatic-liquid-dispenser\\firmware\\esp32\\ver000\\uc\\uc.ino" 2

# 5 "c:\\Suresh\\git\\Projects\\automatic-liquid-dispenser\\firmware\\esp32\\ver000\\uc\\uc.ino" 2
# 6 "c:\\Suresh\\git\\Projects\\automatic-liquid-dispenser\\firmware\\esp32\\ver000\\uc\\uc.ino" 2
# 7 "c:\\Suresh\\git\\Projects\\automatic-liquid-dispenser\\firmware\\esp32\\ver000\\uc\\uc.ino" 2
# 8 "c:\\Suresh\\git\\Projects\\automatic-liquid-dispenser\\firmware\\esp32\\ver000\\uc\\uc.ino" 2
# 9 "c:\\Suresh\\git\\Projects\\automatic-liquid-dispenser\\firmware\\esp32\\ver000\\uc\\uc.ino" 2
# 18 "c:\\Suresh\\git\\Projects\\automatic-liquid-dispenser\\firmware\\esp32\\ver000\\uc\\uc.ino"
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
