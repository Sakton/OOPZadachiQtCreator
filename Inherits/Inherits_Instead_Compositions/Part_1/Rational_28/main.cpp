#include <iostream>

//#include "rationalpublic.h"
#include "rationalprivate.h"

int main( ) {
  //    std::cout << "******* PROGRAMMA Rational 28 PUBLIC ********" <<
  //    std::endl;

  //    RationalPublic rt( 5, 3 );
  //    Display( rt );

  //    RationalPublic rt1( 2, 4 );
  //    Display( rt1 );

  //    Display( rt + rt1 );
  //    Display( rt - rt1 );
  //    Display( rt * rt1 );
  //    Display( rt / rt1 );

  //    std::cout << std::boolalpha << ( rt == rt1 ) << std::endl;
  //    std::cout << std::boolalpha << ( rt > rt1 ) << std::endl;
  //    std::cout << std::boolalpha << ( rt < rt1 ) << std::endl;

  std::cout << "******* PROGRAMMA Rational 28 PRIVATE ********" << std::endl;

  RationalPrivate rt( 5, 3 );
  Display( rt );

  RationalPrivate rt1( 2, 4 );
  Display( rt1 );

  Display( rt + rt1 );
  Display( rt - rt1 );
  Display( rt * rt1 );
  Display( rt / rt1 );

  std::cout << std::boolalpha << ( rt == rt1 ) << std::endl;
  std::cout << std::boolalpha << ( rt > rt1 ) << std::endl;
  std::cout << std::boolalpha << ( rt < rt1 ) << std::endl;
}
