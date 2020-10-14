#include "money24.h"
#include <iostream>

int main()
{
    //Methods demonstration
    Money24B valB1( 10, 50 );

    Display( valB1 );
    Money24B valB2( 21, 0 );
    Display( valB2 );
    Money24B valB3;
    Read( valB3 );
    Display( valB3 );
    Money24B valB4 = valB1 + valB2;
    Display( valB4 );
    valB4 = valB2 - valB1;
    Display( valB4 );
    valB4 = valB1 - valB2;
    Display( valB4 );
    valB4 = valB1 * 2;
    Display( valB4 );
    std::cout << "Div = " << ( valB4 / valB2 ) << std::endl;
    valB4 = valB1 / 2;
    Display( valB4 );

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
