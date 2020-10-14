#ifndef REAL_H
#define REAL_H
#include <iostream>

#include "number.h"

class Real : public Number {
 public:
  Real( double x );
  ~Real( ) {}
  // Number interface
 public:
  Real &operator+=( const Number &oth ) override;
  Real &operator-=( const Number &oth ) override;
  Real &operator*=( const Number &oth ) override;
  Real &operator/=( const Number &oth ) override;

  friend std::ostream &operator<<( std::ostream &out, const Real &val );

 private:
  double x_;
};

#endif // REAL_H
