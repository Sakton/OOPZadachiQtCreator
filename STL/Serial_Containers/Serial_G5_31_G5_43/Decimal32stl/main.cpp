#include <decimal32.h>

#include <iostream>

int main( ) {
  Decimal32 dcm( "999" );
  std::cout << dcm << std::endl;
  Decimal32 dcm1( "999" );
  std::cout << dcm1 << std::endl;
  //  dcm1.printDebugTryth( );
  std::cout << std::endl;
  dcm *= dcm1;
  std::cout << dcm << std::endl;
}
