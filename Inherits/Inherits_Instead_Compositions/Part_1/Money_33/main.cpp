#include <iomanip>
#include <iostream>

#include "moneyprivate.h"
#include "moneypublic.h"

int main( ) {
  std::cout << "********** MONEY33 PUBLIC ***********" << std::endl;
  MoneyPublic a( 1.0 );
  Display( a );

  MoneyPublic b( 2.0 );
  Display( b );

  //  Money33 c( -2.0 );
  //  Display( c );

  Display( b + a );
  Display( b - a );
  Display( b * a );
  Display( b / a );

  std::cout << std::boolalpha << ( b == a ) << std::endl;
  std::cout << std::boolalpha << ( b < a ) << std::endl;

  std::cout << "********** MONEY33 PRIVATE ***********" << std::endl;

  MoneyPrivate pa( 1.0 );
  Display( pa );

  MoneyPrivate pb( 2.0 );
  Display( pb );

  //  Money33 c( -2.0 );
  //  Display( c );

  Display( pb + pa );
  Display( pb - pa );
  Display( pb * pa );
  Display( pb / pa );

  std::cout << std::boolalpha << ( b == a ) << std::endl;
  std::cout << std::boolalpha << ( b < a ) << std::endl;
}
