#include <iostream>

#include "complex21.h"

int main( ) {
  Complex a( 10, 10 );
  Display( a );
  Complex c( 5, 10 );

  Complex1 b( 5, 5 );
  Display( b );
  // Display( static_cast< BaseComplex >( b ) );

  // Display( ( a + c ) );
}
