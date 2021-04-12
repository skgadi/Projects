#ifndef BUTTONS_H
#define BUTTONS_H


struct BUTTONS {
  bool pressed=false;
  int btnPins[NUMBER_OF_CHEMICALS];
  int lastActivatedButton=0;
  int getPressed();
  int progPressed = false;
  int progBtnPin;
  bool isProgBtnPressed();
  void configure();
};


#endif
