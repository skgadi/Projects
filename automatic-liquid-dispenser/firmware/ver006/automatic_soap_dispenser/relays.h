#ifndef RELAYS_H
#define RELAYS_H



struct RELAYS {
  int rlyPins[NUMBER_OF_IN_OUT_PINS+1];
  void configure();
  void stopAll();
  void on(int);
  void setRelayPins(int);
};




#endif
