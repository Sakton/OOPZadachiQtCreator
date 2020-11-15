#include <iostream>

#include "bitstring.h"

void print( const Bitstring& b );

int main( ) {
  Bitstring bs( 10 );
  print( bs );
  ~bs;
  print( bs );
  bs >>= 3;
  print( bs );

  Bitstring bs1( 10 );
  print( bs1 );
  bs1[ 9 ] = 1;
  print( bs1 );
  bs1.cycleShiftLeft( 5 );
  print( bs1 );
  bs1.cycleShiftRight( 5 );
  print( bs1 );
}

void print( const Bitstring& b ) {
  std::copy( b.begin( ), b.end( ), std::ostream_iterator< int >( std::cout ) );
  std::cout << std::endl;
}
