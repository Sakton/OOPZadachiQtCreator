#include <iostream>

#include "decimalnew.h"

int main( ) {
  DecimalNew dm( 10 );
  std::cout << dm << std::endl;
  DecimalNew dm2( 123, true );
  std::cout << dm2 << std::endl;
  DecimalNew dm3( "123" );
  std::cout << dm3 << std::endl;
  dm2 *= dm3;
  std::cout << dm2 << std::endl;
}
