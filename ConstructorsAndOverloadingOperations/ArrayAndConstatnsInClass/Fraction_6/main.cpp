#include <iostream>

#include "fractionnew.h"

int main( ) {
  // FractionNew f( 1000000000.9565, 10000 );
  //  FractionNew ff( 1000000.89L, 10000 );

  //  std::cout << f << std::endl;
  //  std::cout << ff << std::endl;
  //  std::cout << f.getSizeCel( ) << std::endl;
  //  std::cout << f.getSizeDrobn( ) << std::endl;

  //  ff += f;
  //  std::cout << ff << std::endl;

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

  FractionNew rf( 3, 3 );
  rf[ 0 ] = 9;
  rf[ 1 ] = 9;
  rf[ 2 ] = 9;
  rf[ 3 ] = 9;
  rf[ 4 ] = 9;
  rf[ 5 ] = 9;
  std::cout << rf << std::endl;

  FractionNew rf1( 3, 3 );
  for ( int i = 0; i < 6; ++i ) {
    rf1[ i ] = i;
  }
  std::cout << rf1 << std::endl;
  rf += rf1;

  std::cout << rf << std::endl;
}
