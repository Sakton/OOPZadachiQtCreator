#include <iostream>

#include "timeprivate.h"
#include "timepublic.h"

int main( ) {
  std::cout << "*********** TIME PUBLIC *************" << std::endl;

  TimePublic tm( 1000 );
  Display( tm );
  std::cout << "min up okr = " << tm.ToMinut( ) << std::endl;
  std::cout << "sec = " << tm.ToSecond( ) << std::endl;
  std::cout << std::endl;

  TimePublic tm1( 32000 );
  Display( tm1 );
  std::cout << "sec = " << tm1.ToSecond( ) << std::endl;

  std::cout << std::boolalpha << ( tm == tm1 ) << std::endl;
  std::cout << std::boolalpha << ( tm < tm1 ) << std::endl;
  std::cout << std::boolalpha << ( tm > tm1 ) << std::endl;

  std::cout << "*********** TIME PRIVATE *************" << std::endl;

  TimePrivate ptm( 1000 );
  Display( ptm );
  std::cout << "min up okr = " << ptm.ToMinut( ) << std::endl;
  std::cout << "sec = " << ptm.ToSecond( ) << std::endl;
  std::cout << std::endl;

  TimePrivate ptm1( 32000 );
  Display( ptm1 );
  std::cout << "sec = " << ptm1.ToSecond( ) << std::endl;

  std::cout << std::boolalpha << ( ptm == ptm1 ) << std::endl;
  std::cout << std::boolalpha << ( ptm < ptm1 ) << std::endl;
  std::cout << std::boolalpha << ( ptm > ptm1 ) << std::endl;
}
