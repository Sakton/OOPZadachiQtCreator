#include <decimal32.h>

#include <iostream>

int main( ) {
  Decimal32 dcm( "123123" );
  // std::cout << dcm << std::endl;
  Decimal32 dcm1( "1123" );
  // std::cout << dcm1 << std::endl;
  //  dcm1.printDebugTryth( );
  // std::cout << std::endl;
  dcm /= dcm1;
  //  std::cout << dcm << std::endl;
  //  std::cout << "str = " << static_cast< std::string >( dcm ) << std::endl;
}
