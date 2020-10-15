#ifndef COMPLEX_H
#define COMPLEX_H
#include "pair.h"

class Complex : public Pair {
 public:
  Complex( double f = 0, double s = 0 );

  Complex &operator-=( const Complex &oth );
  Complex &operator*=( const Complex &oth );

  friend Complex operator-( const Complex &oth );
  friend Complex operator*( const Complex &oth );

  explicit operator std::string( ) const;
  void Display( ) const;
};

#endif // COMPLEX_H
