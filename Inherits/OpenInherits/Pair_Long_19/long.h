#ifndef LONG_H
#define LONG_H
#include "pair.h"

class Long : public Pair {
 public:
  explicit Long( int f = 0, int s = 0 );

  //
  // Long &operator+=( const Long &l );

  Long &operator-=( const Long &l );
  Long &operator*=( const Long &l );

  friend Long operator-( const Long &l1, const Long &l2 );
  friend Long operator*( const Long &l1, const Long &l2 );
};

#endif // LONG_H
