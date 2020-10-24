#include <iostream>

#include "angle26private.h"

int main( ) {
  std::cout << "******* PROGRAMMA ANGLE 26 PUBLIC ********" << std::endl;
  //Методы проверены поштучно
  // TODO с этого класса демонстрация методов урезана для экономии времени
  // Methods demonstration ()

  //  Angle26public Ang1( -10, -59 );
  //  Display( Ang1 );

  //  Angle26public Ang2 = Angle26public( 10, 59 );
  //  Display( Ang2 );

  //  Angle26public Ang3 = Ang1 - Ang2;
  //  Display( Ang3 );

  //  //    Ang3 = Ang1 - 10;
  //  //    Ang3.Display( );

  //  //    Ang3 = 10 - Ang1;
  //  //    Ang3.Display( );

  //  std::cout << std::boolalpha << ( Ang2 < Ang3 ) << std::endl;
  //  Angle26public Ang5( 30, 0 );
  //  std::cout << Ang5.Sinus( ) << std::endl;

  //  Angle26public Ang6( 360, 0 );
  //  Display( Ang6 );
  //  Ang6.Normalise( );
  //  Display( Ang6 );

  std::cout << "******* PROGRAMMA ANGLE 26 PRIVATE ********" << std::endl;
  //Методы проверены поштучно
  // TODO с этого класса демонстрация методов урезана для экономии времени
  // Methods demonstration ()

  Angle26private pAng1( -10, -59 );
  Display( pAng1 );

  Angle26private pAng2 = Angle26private( 10, 59 );
  Display( pAng2 );

  Angle26private pAng3 = pAng1 - pAng2;
  Display( pAng3 );

  //    Ang3 = Ang1 - 10;
  //    Ang3.Display( );

  //    Ang3 = 10 - Ang1;
  //    Ang3.Display( );

  std::cout << std::boolalpha << ( pAng2 < pAng3 ) << std::endl;
  Angle26private pAng5( 30, 0 );
  std::cout << pAng5.Sinus( ) << std::endl;

  Angle26private pAng6( 360, 0 );
  Display( pAng6 );
  pAng6.Normalise( );
  Display( pAng6 );
}
