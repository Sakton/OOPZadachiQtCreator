#include <iostream>

#include "angle26.h"

int main( )
{
    std::cout << "******* PROGRAMMA ANGLE 26 A-A-A ********" << std::endl;
    //Методы проверены поштучно
    // TODO с этого класса демонстрация методов урезана для экономии времени
    // Methods demonstration ()

    Angle26 Ang1( -10, -59 );
    Ang1.Display( );

    Angle26 Ang2 = Angle26( 10, 59 );
    Ang2.Display( );

    Angle26 Ang3 = Ang1 - Ang2;
    Ang3.Display( );

    //    Ang3 = Ang1 - 10;
    //    Ang3.Display( );

    //    Ang3 = 10 - Ang1;
    //    Ang3.Display( );

    std::cout << std::boolalpha << ( Ang2 < Ang3 ) << std::endl;
    Angle26 Ang5( 30, 0 );
    std::cout << Ang5.Sinus( ) << std::endl;

    Angle26 Ang6( 360, 0 );
    Ang6.Display( );
    Ang6.Normalise( );
    Ang6.Display( );
}
