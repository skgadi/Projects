#ifndef COINS_H
#define COINS_H



struct COINS {
  unsigned int volatile credit;
  void increaseCredit();
  void resetCredit();
};




#endif
