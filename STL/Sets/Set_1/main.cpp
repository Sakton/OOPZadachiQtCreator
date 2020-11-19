#include <ctime>
#include <iostream>

#include "ozero.h"
#include "rybak.h"

int main()
{
  std::srand( std::time( nullptr ) );
  Ozero oz;
  Rybak r1;
  Rybak r2;
  Rybak r3;
  r1.getFishOut_n( &oz, 5 );
  r2.getFishOut_n( &oz, 5 );
  r3.getFishOut_n( &oz, 5 );
  std::cout << r1 << std::endl << std::endl;
  std::cout << r2 << std::endl << std::endl;
  std::cout << r3 << std::endl << std::endl;
  //******
  std::cout << "all.uloves = " << ( r1.getUlov( ) + r2.getUlov( ) ) << std::endl << std::endl;
}
