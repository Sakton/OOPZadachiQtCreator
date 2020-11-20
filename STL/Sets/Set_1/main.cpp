#include <ctime>
#include <iostream>

#include "megarybak.h"
#include "ozero.h"
#include "rybak.h"

int main()
{
  std::srand( std::time( nullptr ) );
  Ozero oz;
  Rybak r1;
  Rybak r2;
  Rybak r3;
  MegaRybak mr;
  r1.getFishOut_n( &oz, 5 );
  r2.getFishOut_n( &oz, 5 );
  r3.getFishOut_n( &oz, 5 );
  mr.megaUlov( &oz );

  //  std::cout << r1 << std::endl << std::endl;
  //  std::cout << r2 << std::endl << std::endl;
  //  std::cout << r3 << std::endl << std::endl;
  // std::cout << mr << std::endl << std::endl;
  //******

  Ulov t1 = ( r1.getUlov( ) + r2.getUlov( ) + r3.getUlov( ) );
  Ulov t2 = ( mr.getUlov( ) - t1 );
  Ulov t3 = ( mr.getUlov( ) / t1 );

  std::cout << "all.uloves:\n" << t1 << std::endl << std::endl;
  std::cout << "uloves mega - prosto:\n" << t2 << std::endl << std::endl;
  std::cout << "mega uloves: / prosto\n" << t3 << std::endl << std::endl;
}
