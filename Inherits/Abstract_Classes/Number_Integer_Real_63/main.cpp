#include <iostream>

#include "integer.h"
#include "real.h"

Number &foo( Number &a, Number &b ) { return a += b; }

int main( ) {
  Number *a = new Integer( 10 );
  Number *b = new Integer( 20 );

  Integer c( 10 );
  Integer d( 20 );

  std::cout << static_cast< Integer & >( foo( *a, *b ) ) << std::endl;
  std::cout << static_cast< Integer & >( foo( c, d ) ) << std::endl;

  delete a;
  delete b;

  Number *r1 = new Real( 11.11 );
  Number *r2 = new Real( 22.22 );

  Real r3( 11.11 );
  Real r4( 22.22 );

  std::cout << static_cast< Real & >( foo( *r1, *r2 ) ) << std::endl;
  std::cout << static_cast< Real & >( foo( r3, r4 ) ) << std::endl;

  delete r1;
  delete r2;
}
