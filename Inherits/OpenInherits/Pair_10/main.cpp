#include <iostream>

#include "rightangled.h"

Pair10& foo( Pair10& pr ) {
  pr.Display( );
  return pr;
}

int main( ) {
  RightAngled ra( 10, 10 );
  foo( ra );
  ra.Display( );
  ra.setFirst( 5 );
  ra.setSecond( 5 );
  ra.Display( );
}
