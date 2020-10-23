#include <iostream>

#include "set.h"

const uint64_t SET_ARRAY[ 18 ] = { 1,    2,    4,     8,     16,    32,
                                   64,   128,  256,   512,   1024,  2048,
                                   4096, 8192, 16384, 32768, 65536, 131072 };

int main( ) {
  Set test( uint64_t( 0 ) );
  test.Display( );
  Set test1( uint64_t( 0 ) );
  test1.Display( );
  for ( int i = 0; i < 9; i++ ) {
    test += Set( Bitstring37B( SET_ARRAY[ i ] ) );
    test.Display( );
  }
  for ( int i = 9; i < 18; i++ ) {
    test1 += Set( Bitstring37B( SET_ARRAY[ i ] ) );
    test1.Display( );
  }

  Set summ = test + test1;
  summ.Display( );
  Set sub = summ - test1;
  sub.Display( );
  Set intersec = summ * test1;
  intersec.Display( );
}
