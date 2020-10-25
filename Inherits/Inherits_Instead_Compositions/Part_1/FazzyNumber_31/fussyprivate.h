#ifndef FUSSYPRIVATE_H
#define FUSSYPRIVATE_H
#include <string>

#include "basefuzzy.h"

class FussyPrivate : BaseFuzzy {
 public:
  FussyPrivate( double e1, double x, double e2 );

  friend void Display( const FussyPrivate& fn );
  friend std::string ToString( const FussyPrivate& fn );

  FussyPrivate& operator+=( const FussyPrivate& fn );
  FussyPrivate& operator-=( const FussyPrivate& fn );
  FussyPrivate& operator*=( const FussyPrivate& fn );
  FussyPrivate& operator/=( const FussyPrivate& fn );

  friend FussyPrivate operator+( const FussyPrivate& fn1,
                                 const FussyPrivate& fn2 );
  friend FussyPrivate operator-( const FussyPrivate& fn1,
                                 const FussyPrivate& fn2 );
  friend FussyPrivate operator*( const FussyPrivate& fn1,
                                 const FussyPrivate& fn2 );
  friend FussyPrivate operator/( const FussyPrivate& fn1,
                                 const FussyPrivate& fn2 );
};

#endif // FUSSYPRIVATE_H
