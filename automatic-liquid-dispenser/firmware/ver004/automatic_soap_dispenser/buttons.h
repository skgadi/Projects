#ifndef BUTTONS_H
#define BUTTONS_H


struct BUTTONS {
  bool pressed=false;
  int btnPins[(NUMBER_OF_IN_OUT_PINS + 1)];
  bool btnActivity;
  int lastActivatedButton=0;
  int getPressed();
  int progPressed = false;
  int progBtnPin;
  bool isProgBtnPressed();
  void configure();
  int getButton();
};


#endif
