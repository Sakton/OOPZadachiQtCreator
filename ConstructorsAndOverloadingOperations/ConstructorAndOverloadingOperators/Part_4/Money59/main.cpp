#include "money24.h"
#include <iostream>

int main()
{
    //Methods demonstration
    Money24 valB1( 10, 50 );

    valB1.Display( );
    Money24 valB2( 21, 0 );
    valB2.Display( );
    Money24 valB4 = valB1 + valB2;
    valB4.Display( );
    valB4 = valB2 - valB1;
    valB4.Display( );
    valB4 = valB1 - valB2;
    valB4.Display( );
    valB4 = valB1 * 2;
    valB4.Display( );
    std::cout << "Div = " << ( valB4 / valB2 ) << std::endl;
    valB4 = valB1 / 2;
    valB4.Display( );

    //    std::cout << std::boolalpha << valB1.Eq( valB2 ) << std::endl;
    //    std::cout << std::boolalpha << valB1.NotEqu( valB2 ) << std::endl;
    //    std::cout << std::boolalpha << valB1.Less( valB2 ) << std::endl;
    //    std::cout << std::boolalpha << valB1.LessOrEq( valB2 ) << std::endl;
    //    std::cout << std::boolalpha << valB1.Greater( valB2 ) << std::endl;
    //    std::cout << std::boolalpha << valB1.GreaterOrEq( valB2 ) << std::endl;
    //    std::cout << std::endl;

    //    valB1 = valB2;
    //    valB1.Display( );
    //    valB2.Display( );

    //    std::cout << std::boolalpha << valB1.Eq( valB2 ) << std::endl;
    //    std::cout << std::boolalpha << valB1.NotEqu( valB2 ) << std::endl;
    //    std::cout << std::boolalpha << valB1.Less( valB2 ) << std::endl;
    //    std::cout << std::boolalpha << valB1.LessOrEq( valB2 ) << std::endl;
    //    std::cout << std::boolalpha << valB1.Greater( valB2 ) << std::endl;
    //    std::cout << std::boolalpha << valB1.GreaterOrEq( valB2 ) << std::endl;
    //    std::cout << std::endl;

    //    valB2 = valB4;
    //    valB1.Display( );
    //    valB2.Display( );

    //    std::cout << std::boolalpha << valB1.Eq( valB2 ) << std::endl;
    //    std::cout << std::boolalpha << valB1.NotEqu( valB2 ) << std::endl;
    //    std::cout << std::boolalpha << valB1.Less( valB2 ) << std::endl;
    //    std::cout << std::boolalpha << valB1.LessOrEq( valB2 ) << std::endl;
    //    std::cout << std::boolalpha << valB1.Greater( valB2 ) << std::endl;
    //    std::cout << std::boolalpha << valB1.GreaterOrEq( valB2 ) << std::endl;
    //    std::cout << std::endl;
}
