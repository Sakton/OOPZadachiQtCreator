#include <iostream>

#include "rational.h"

Pair& foo( Pair& p ) {
  p.Display( );
  return p;
}

const Pair& foo( const Pair& p ) {
  p.Display( );
  return p;
}

int main( ) {
  Pair p1( 10, 10 );
  Pair p2( 10, 10 );
  // p1.Display( );

  Rational r1( 10, 10 );
  Rational r2( 10, 10 );
  // r1.Display( );

  //  static_cast< Rational& >( foo( r2 ) ).Display( );
  //  static_cast< Rational& >( foo( p1 ) ).Display( );
  static_cast< const Rational& >( foo( ( p1 - p2 ) ) ).Display( );
  static_cast< const Rational& >( foo( ( r1 - r2 ) ) ).Display( );
  Rational r3 = r1 - r2;
  r3.Display( );

  r3 = r1 + r2;
  foo( r3 );
  r3.Display( );

  r3 = r1 / r2;
  foo( r3 );
  r3.Display( );
}
