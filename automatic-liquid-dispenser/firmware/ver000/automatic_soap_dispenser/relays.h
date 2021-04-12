#ifndef RELAYS_H
#define RELAYS_H



struct RELAYS {
  int btnPins[NUMBER_OF_CHEMICALS];
  void configure();
  void stopAll();
  void on(int);
};




#endif
