#include <iostream>

#include "fraction35.h"

int main( ) {
  std::cout << "***********fraction35 *************\n";
  Fraction35B fr1( LongLong38B( 112233 ), 0 );
  fr1.Display( );

  Fraction35B fr7( LongLong38B( 5555 ), 5555 );
  Fraction35B fr8( LongLong38B( 2222 ), 2222 );

  // fr7.OneDivFrac( fr8 ).Display( );
  // std::cout << ( 1 / 2222.2222 );

  Fraction35B fr9( LongLong38B( 10 ), 9900 );
  Fraction35B fr10( LongLong38B( 20 ), 00 );

  Fraction35B ccc = fr9 - fr10;

  ccc.Display( );
}
