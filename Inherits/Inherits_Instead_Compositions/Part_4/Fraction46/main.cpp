#include <iostream>

#include "fraction35.h"

int main( ) {
  std::cout << "***********fraction35 *************\n";
  Fraction35B fr1( 112233, 0 );
  fr1.Display( );

  Fraction35B fr7( 5555, 5555 );
  Fraction35B fr8( 2222, 2222 );

  // fr7.OneDivFrac( fr8 ).Display( );
  // std::cout << ( 1 / 2222.2222 );

  Fraction35B ccc = fr7 / fr8;

  ccc.Display( );
}
