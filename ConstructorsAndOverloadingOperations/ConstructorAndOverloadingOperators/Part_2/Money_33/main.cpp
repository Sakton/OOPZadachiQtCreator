#include <iomanip>
#include <iostream>

#include "money33.h"

int main( ) {
  Money33 a( 1.0 );
  Display( a );

  Money33 b( 2.0 );
  Display( b );

  //  Money33 c( -2.0 );
  //  Display( c );

  Display( b + a );
  Display( b - a );
  Display( b * a );
  Display( b / a );

  std::cout << std::boolalpha << ( b == a ) << std::endl;
  std::cout << std::boolalpha << ( b < a ) << std::endl;
}
