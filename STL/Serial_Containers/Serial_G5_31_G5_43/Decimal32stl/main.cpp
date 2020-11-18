//#include <decimal32.h>
#include <iostream>

#include "decimal32list.h"

int main( ) {
  try {
    using namespace sktn;
    //  Decimal32 dcm( "908" );
    //  Decimal32 dcm1( "3" );
    //  dcm %= dcm1;
    //  std::cout << dcm << std::endl;

    // list
    Decimal32List dcm( "908" );
    Decimal32List dcm1( "3" );
    dcm %= dcm1;
    std::cout << dcm << std::endl;

  } catch ( std::out_of_range &e ) {
    std::cerr << e.what( ) << std::endl;
  } catch ( std::exception &e ) {
    std::cerr << e.what( ) << std::endl;
  }
}
