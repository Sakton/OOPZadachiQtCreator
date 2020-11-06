#include <iostream>

#include "money21.h"

int main()
{
  Pair21 *ar[ 10 ];
  for ( int i = 0; i < 10; ++i ) {
    ar[ i ] = new Money21( 100 + i, 10 + i );
  }

  for ( int i = 0; i < 10; ++i ) {
    ar[ i ]->display( );
  }
}
