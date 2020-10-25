#ifndef FUZZUPUBLIC_H
#define FUZZUPUBLIC_H
#include "basefuzzy.h"

class FuzzuPublic : public BaseFuzzy {
 public:
  FuzzuPublic( double e1, double x, double e2 );

  FuzzuPublic& operator+=( const FuzzuPublic& fn );
  FuzzuPublic& operator-=( const FuzzuPublic& fn );
  FuzzuPublic& operator*=( const FuzzuPublic& fn );
  FuzzuPublic& operator/=( const FuzzuPublic& fn );

  friend FuzzuPublic operator+( const FuzzuPublic& fn1,
                                const FuzzuPublic& fn2 );
  friend FuzzuPublic operator-( const FuzzuPublic& fn1,
                                const FuzzuPublic& fn2 );
  friend FuzzuPublic operator*( const FuzzuPublic& fn1,
                                const FuzzuPublic& fn2 );
  friend FuzzuPublic operator/( const FuzzuPublic& fn1,
                                const FuzzuPublic& fn2 );
};

#endif // FUZZUPUBLIC_H
