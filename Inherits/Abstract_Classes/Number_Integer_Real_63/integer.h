#ifndef INTEGER_H
#define INTEGER_H
#include <iostream>

#include "number.h"

class Integer : public Number {
 public:
  Integer( int x = 0 );
  ~Integer( ) {}

  // Number interface
 public:
  Integer &operator+=( const Number &oth ) override;
  Integer &operator-=( const Number &oth ) override;
  Integer &operator*=( const Number &oth ) override;
  Integer &operator/=( const Number &oth ) override;

  friend std::ostream &operator<<( std::ostream &out, const Integer &val );

 private:
  int x_;
};

#endif // INTEGER_H
