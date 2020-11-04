#include <iostream>

#include "Array4.h"

int main( ) {
  Array4< int, -10, 0 > ar;
  std::cout << ar << std::endl;
  for ( int i = -10; i < 0; ++i ) {
    ar[ i ] = 100 + i;
  }
  std::cout << ar << std::endl;
  std::copy( ar.begin( ), ar.end( ),
             std::ostream_iterator< int >( std::cout, "-" ) );
  std::cout << std::endl;

  Array4< int, 0, 10 > ar1;
  std::cout << ar1 << std::endl;
  for ( int i = 0; i < 10; ++i ) {
    ar1[ i ] = 100 + i;
  }
  std::cout << ar1 << std::endl;
  std::copy( ar1.begin( ), ar1.end( ),
             std::ostream_iterator< int >( std::cout, "+" ) );
  std::cout << std::endl;

  Array4< int, -10, -5 > ar2;
  std::cin >> ar2;
  std::copy( ar2.begin( ), ar2.end( ),
             std::ostream_iterator< int >( std::cout, "*" ) );
}
