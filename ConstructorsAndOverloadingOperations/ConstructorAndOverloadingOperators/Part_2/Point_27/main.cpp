#include <point27.h>

#include <iostream>

int main( ) {
  std::cout << "******* PROGRAMMA POINT 27 AAA ********" << std::endl;
  Point27 pt( 0, 4 );
  Display( pt );
  Point27::Polar pol = ToPolar( pt );
  std::cout << " r =  " << pol.radius << " fi = " << pol.angleFi << std::endl;
  //проверено поштучно

  std::cout << "******* PROGRAMMA POINT 27 BBB && CCC ********" << std::endl;
  // using My = Point27B;
  using My = Point27;

  My ptB( 0, 4 );
  Display( ptB );
  My::Polar polar = ToPolar( ptB );
  std::cout << " r =  " << polar.radius << " fi = " << polar.angleFi
            << std::endl;
}
