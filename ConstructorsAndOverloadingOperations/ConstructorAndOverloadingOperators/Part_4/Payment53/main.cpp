#include <iostream>

#include "payment39b.h"

int main( ) {
  std::cout << "XXXXXXXXX  PAYMENTS_53  XXXXXXXXX" << std::endl;
  Payment39B pay( "name", Money24( 50000.0 ), "20.02.2013", 1.3, 22, 31 );
  pay.Display( );
}
