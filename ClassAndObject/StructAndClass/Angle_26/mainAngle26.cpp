#include "angle26a.h"
#include "angle26b.h"
#include "angle26c.h"
#include <iostream>

int main( )
{
    std::cout << "******* PROGRAMMA ANGLE 26 A-A-A ********" << std::endl;
    //Методы проверены поштучно
    //TODO с этого класса демонстрация методов урезана для экономии времени
    //Methods demonstration ()

    //    Angle26A Ang1;
    //    Init( Ang1, -10, -59 );
    //    Display( Ang1 );

    //    Angle26A Ang2 = Adding( Ang1, 10, 59 );
    //    Display( Ang2 );

    //    Angle26A Ang3 = Substr( Ang1, -10, -59 );
    //    Display( Ang3 );

    //    std::cout << std::boolalpha << Less( Ang2, Ang3 ) << std::endl;
    //    Angle26A Ang5;
    //    Init( Ang5, 30, 0 );
    //    std::cout << Sinus( Ang5 ) << std::endl;

    //    Angle26A Ang6;
    //    Init( Ang6, 360, 0 );
    //    Display( Ang6 );
    //    Normalise( Ang6 );
    //    Display( Ang6 );

    //    std::cout << "******* PROGRAMMA ANGLE 26 BBB && CCC ********" << std::endl;

    //    //typedef Angle26D My;
    //    typedef Angle26C My;

    //    My Bng1;
    //    Bng1.Init( -10, -59 );
    //    Bng1.Display( );

    //    My Bng2 = Bng1.Adding( 10, 59 );
    //    Bng2.Display( );

    //    My Bng3 = Bng1.Substr( -10, -59 );
    //    Bng3.Display( );

    //    std::cout << std::boolalpha << Bng2.Less( Bng3 ) << std::endl;
    //    My Bng5;
    //    Bng5.Init( 30, 0 );
    //    std::cout << Bng5.Sinus( ) << std::endl;

    //    My Bng6;
    //    Bng6.Init( 360, 0 );
    //    Bng6.Display( );
    //    Bng6.Normalise( );
    //    Bng6.Display( );

    Angle26B test;
    test.Init( 30.99 );
    test.Display( );
}
