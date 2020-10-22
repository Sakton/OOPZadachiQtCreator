#include <iostream>

#include "triangle25.h"

int main( ) {
  // Methods demonstration
  // inits
  std::cout << "******* PROGRAMMA TRIANGLE 51 ********" << std::endl;
  Triangle25 trA1( Point27( 1, 1 ), Point27( 1, 8 ), Point27( 4, 1 ) );
  trA1.Display( );
  trA1.setC( Point27( 5, 1 ) );
  trA1.Display( );
  trA1.setB( Point27( 1, 5 ) );
  trA1.Display( );

  std::cout << "H AB = " << trA1.HeightToA( ) << std::endl;
  std::cout << "H BC = " << trA1.HeightToB( ) << std::endl;
  std::cout << "H AC = " << trA1.HeightToC( ) << std::endl;
  std::cout << "S Tringle = " << trA1.Area( ) << std::endl;
  std::cout << "S Perimeter = " << trA1.Perimeter( ) << std::endl;

  return 0;
}
