#include "fraction.h"
#include <iostream>

int main( ) {
  Fraction f( "100.55" );
  Fraction ff( "100.99" );

  std::cout << f << std::endl;
  std::cout << ff << std::endl;
  //  std::cout << f.getSizeCel( ) << std::endl;
  //  std::cout << f.getSizeDrobn( ) << std::endl;

  ff += f;
  std::cout << ff << std::endl;

  //  Fraction ff( "111.999" );
  //  ff += f;
  //  // ff = f;

  //  int arr[ 10 ] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  //  int64_t x = 257000;
  //  int i = 0;
  //  while ( x ) {
  //    arr[ i++ ] = x % 256;
  //    x /= 256;
  //  }
  //  for ( int i = 9; i >= 0; --i ) std::cout << ( arr[ i ] ) << ' ';
}
