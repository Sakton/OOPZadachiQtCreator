#include <iostream>

#include "BitString.h"
#include "bitstringnew.h"

int main( ) {
  /*
  BitString s1( 12 );
  std::cout << s1 << std::endl;

  BitString s2( "testNullString" );
  std::cout << s2 << std::endl;

  BitString s3;
  std::cin >> s3;
  if ( !std::cin ) std::cout << "ERROR ENTER" << std::endl;
  std::cout << "s3 = " << s3 << std::endl;
  std::cout << "Size = " << s3.Size( ) << std::endl;

  BitString s4 = s3;
  std::cout << s4 << std::endl;
  s4 <<= 3;
  std::cout << s4 << std::endl;
  s4 >>= 3;
  std::cout << s4 << std::endl;

  BitString s5 = ( s4 << 2 );
  std::cout << "S5 !!! = " << s5 << std::endl;

  BitString s6 = ( s5 << 2 << 1 );
  std::cout << "S6 << = " << s6 << std::endl;
  ~s6;
  std::cout << "~S6 = " << s6 << std::endl;

  std::cout << "s6 << = " << s6 << std::endl;
  s6 ^= s3;
  std::cout << "s3    = " << s3 << std::endl;
  std::cout << "s6   |= " << s6 << std::endl;

  BitString s7 = ( s3 | s6 ^ s4 ) & s3;
  std::cout << "s7 = " << s7 << std::endl;
  std::cout << ( s3 | s6 ) << std::endl;
  std::cout << ( s3 | s6 ^ s4 ) << std::endl;
  std::cout << ( ( s3 | s6 ^ s4 ) & s3 ) << std::endl;

  s7[ 0 ] = '1';
  std::cout << "s7 [] = " << s7 << std::endl;
*/

  //***************
  BitstringNew bs( 10 );
  std::cout << bs << std::endl;
  BitstringNew bs1( "101010101010" );
  std::cout << bs1 << std::endl;
  BitstringNew bs2( 1, true );
  std::cout << bs2 << std::endl;

  for ( int i = 0; i < bs1.getCount( ); ++i ) {
    std::cout << int( bs1[ i ] ) << '-';
  }
  std::cout << std::endl;

  BitstringNew bs4( "000001010101" );
  bs4 <<= 5;
  std::cout << bs4 << std::endl;
  bs4 >>= 5;
  std::cout << bs4 << std::endl;

  bs4 ^= bs1;
  std::cout << bs4 << std::endl;
  bs4 ^= bs1;
  std::cout << bs4 << std::endl;
  ~bs4;
  std::cout << bs4 << std::endl;

  // BitstringNew tmp =
}
