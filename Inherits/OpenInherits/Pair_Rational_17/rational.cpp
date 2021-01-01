#include "rational.h"

#include <iostream>

Rational::Rational( int cel, int dr ) : Pair( cel, dr ) {}

Rational &Rational::operator+=( const Rational &oth ) {
  setFirst( first( ) * oth.second( ) + second( ) * oth.first( ) );
  setSecond( second( ) * oth.second( ) );
  return *this;
}

Rational &Rational::operator-=( const Rational &oth ) {
  setFirst( first( ) * oth.second( ) - second( ) * oth.first( ) );
  setSecond( second( ) * oth.second( ) );
  return *this;
}

Rational &Rational::operator/=( const Rational &oth ) {
  setFirst( first( ) * oth.second( ) );
  setSecond( second( ) * oth.first( ) );
  return *this;
}

void Rational::Display( ) const {
  std::cout << std::string( *this ) << std::endl;
}

Rational::operator std::string( ) const {
  return "rational: " + std::to_string( first( ) ) + "," +
         std::to_string( second( ) );
}

Rational operator+( const Rational &r1, const Rational &r2 ) {
  Rational loc = r1;
  loc += r2;
  return loc;
}

Rational operator-( const Rational &r1, const Rational &r2 ) {
  Rational loc = r1;
  loc -= r2;
  return loc;
}

Rational operator/( const Rational &r1, const Rational &r2 ) {
  Rational loc = r1;
  loc /= r2;
  return loc;
}
