#include <iostream>

#include "pointprivate.h"
//#include "pointpublic.h"

int main( ) {
  std::cout << "******* PROGRAMMA POINT 27 PUBLIC ********" << std::endl;
  //  PointPublic pt( 0, 4 );
  //  Display( pt );
  //  PointPublic::Polar pol = pt.ToPolar( );
  //  std::cout << " r =  " << pol.radius << " fi = " << pol.angleFi <<
  //  std::endl;
  //  //проверено поштучно

  //  std::cout << "******* PROGRAMMA POINT 27 BBB && CCC ********" <<
  //  std::endl;
  //  // using My = Point27B;
  //  using My = PointPublic;

  //  My ptB( 0, 4 );
  //  Display( ptB );
  //  My::Polar polar = ptB.ToPolar( );
  //  std::cout << " r =  " << polar.radius << " fi = " << polar.angleFi
  //            << std::endl;

  std::cout << "******* PROGRAMMA POINT 27 PRIVATE ********" << std::endl;
  PointPrivate pt( 0, 4 );
  Display( pt );
  PointPrivate::Polar pol = pt.ToPolar( );
  std::cout << " r =  " << pol.radius << " fi = " << pol.angleFi << std::endl;
  //проверено поштучно

  std::cout << "******* PROGRAMMA POINT 27 PRIVATE ********" << std::endl;
  // using My = Point27B;
  using My = PointPrivate;

  My ptB( 0, 4 );
  Display( ptB );
  My::Polar polar = ptB.ToPolar( );
  std::cout << " r =  " << polar.radius << " fi = " << polar.angleFi
            << std::endl;
}
