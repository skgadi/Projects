#ifndef COINS_H
#define COINS_H



struct COINS {
  int volatile credit;
  bool creditChange;
  void increaseCredit();
  void resetCredit();
  void ackChange();
};




#endif
