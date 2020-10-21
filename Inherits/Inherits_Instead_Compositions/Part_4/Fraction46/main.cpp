#include <iostream>

#include "fraction35.h"
#include "fraction46private.h"

int main( ) {
  std::cout << "*********** fraction46 *************\n";
  Fraction35B fr1( 112233, 0 );
  fr1.Display( );

  Fraction35B fr7( 5555, 5555 );
  Fraction35B fr8( 2222, 2222 );

  // fr7.OneDivFrac( fr8 ).Display( );
  // std::cout << ( 1 / 2222.2222 );

  Fraction35B ccc = fr7 / fr8;

  ccc.Display( );

  std::cout << "XXXXXXXXXXXXXXXXXXXX privte XXXXXXXXXXXXXXXXXXXXXXXX"
            << std::endl;

  Fraction35B pfr1( 112233, 0 );
  fr1.Display( );

  Fraction35B pfr7( 5555, 5555 );
  Fraction35B pfr8( 2222, 2222 );

  // fr7.OneDivFrac( fr8 ).Display( );
  // std::cout << ( 1 / 2222.2222 );

  Fraction35B pccc = fr7 / fr8;
  pccc.Display( );
}
