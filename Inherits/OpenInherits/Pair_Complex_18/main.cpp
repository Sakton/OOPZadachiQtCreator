#include <iostream>

#include "complex.h"

Pair &foo( Pair &p ) {
  p.Display( );
  return p;
}

const Pair &foo( const Pair &p ) {
  p.Display( );
  return p;
}

int main( ) {
  Pair *p = new Pair( 10, 10 );
  Pair *p1 = new Pair( 20, 20 );

  Pair *p3 = new Complex( 10, 10 );
  Pair *p4 = new Complex( 20, 20 );

  foo( *p );
  foo( *p1 );
  static_cast< Complex & >( foo( *p3 ) ).Display( );
  static_cast< Complex & >( foo( *p4 ) ).Display( );
  static_cast< const Complex & >( foo( *p3 + *p4 ) ).Display( );

  delete p;
  delete p1;
  delete p3;
  delete p4;
}
