#include <iostream>

#include "decimalnew.h"

int main( ) {
  DecimalNew dm( 10 );
  std::cout << dm << std::endl;
  DecimalNew dm2( 123456789, true );
  std::cout << dm2 << std::endl;
  DecimalNew dm3( "12345678" );
  std::cout << dm3 << std::endl;
}
