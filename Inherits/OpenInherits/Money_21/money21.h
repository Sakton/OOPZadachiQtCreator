#ifndef MONEY21_H
#define MONEY21_H
#include "pair21.h"

class Money21 : public Pair21 {
 public:
  Money21( int a = 0, int b = 0 );

  Money21 &operator+=( const Money21 &m );
  double operator/=( const Money21 &m );
  Money21 &operator-=( const Money21 &m );

  friend Money21 operator+( const Money21 &m1, const Money21 &m2 );
  friend double operator/( const Money21 &m1, const Money21 &m2 );
  friend Money21 operator-( const Money21 &m1, const Money21 &m2 );
};

#endif // MONEY21_H
