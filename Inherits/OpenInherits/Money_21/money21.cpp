#include "money21.h"

#include <stdexcept>

Money21::Money21( int a, int b ) : Pair21( 0, 0 ) {
  if ( a < 0 || b < 0 ) {
    throw std::runtime_error( "ERROR ARG" );
  }
  setA( a );
  setB( b );
}

Money21 &Money21::operator+=( const Money21 &m ) {
  Pair21::operator+=( m );
  return *this;
}

double Money21::operator/=( const Money21 &m ) {
  double x = getA( ) + double( getB( ) ) / 100;
  double y = m.getA( ) + double( m.getB( ) ) / 100;
  return x / y;
}

Money21 &Money21::operator-=( const Money21 &m ) {
  setA( getA( ) - m.getA( ) );
  setB( getB( ) - m.getB( ) );
  return *this;
}

Money21 operator+( const Money21 &m1, const Money21 &m2 ) {
  Money21 loc = m1;
  loc += m2;
  return loc;
}

double operator/( const Money21 &m1, const Money21 &m2 ) {
  Money21 loc = m1;
  return loc /= m2;
}

Money21 operator-( const Money21 &m1, const Money21 &m2 ) {
  Money21 loc = m1;
  loc -= m2;
  return loc;
}
