#ifndef RATIONAL_H
#define RATIONAL_H
#include "pair.h"

class Rational : public Pair {
 public:
  Rational( int cel = 0, int dr = 0 );

  Rational &operator+=( const Rational &oth );
  Rational &operator-=( const Rational &oth );
  Rational &operator/=( const Rational &oth );

  friend Rational operator+( const Rational &r1, const Rational &r2 );
  friend Rational operator-( const Rational &r1, const Rational &r2 );
  friend Rational operator/( const Rational &r1, const Rational &r2 );

  explicit operator std::string( ) const;
  void Display( ) const;
};

#endif // RATIONAL_H
