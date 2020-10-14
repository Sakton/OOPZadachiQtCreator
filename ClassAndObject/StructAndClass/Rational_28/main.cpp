#include "rational28a.h"
#include "rational28b.h"
#include "rational28c.h"
#include <iostream>

int main()
{
    std::cout << "******* PROGRAMMA Rational 28 AAA ********" << std::endl;

    Rational28A rt;
    Init( rt, 5, 3 );
    Display( rt );

    Rational28A rt1;
    Init( rt1, 2, 4 );
    Display( rt1 );

    Display( Add( rt, rt1 ) );
    Display( Sub( rt, rt1 ) );
    Display( Mul( rt, rt1 ) );
    Display( Div( rt, rt1 ) );

    std::cout << std::boolalpha << Eq( rt, rt1 ) << std::endl;
    std::cout << std::boolalpha << Great( rt, rt1 ) << std::endl;
    std::cout << std::boolalpha << Less( rt, rt1 ) << std::endl;

    std::cout << "******* PROGRAMMA Rational 28 BBB && CCC ********" << std::endl;
    using My = Rational28B;
    //using My = Rational28C;

    My rtt;
    rtt.Init( 5, 3 );
    rtt.Display( );

    Rational28B rtt1;
    rtt1.Init( 2, 4 );
    rtt1.Display( );

    rtt.Add( rtt1 ).Display( );
    rtt.Sub( rtt1 ).Display( );
    rtt.Mul( rtt1 ).Display( );
    rtt.Div( rtt1 ).Display( );

    std::cout << std::boolalpha << rtt.Eq( rtt1 ) << std::endl;
    std::cout << std::boolalpha << rtt.Great( rtt1 ) << std::endl;
    std::cout << std::boolalpha << rtt.Less( rtt1 ) << std::endl;
}
