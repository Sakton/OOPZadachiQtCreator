#include <iostream>

#include "rational28.h"

int main()
{
    std::cout << "******* PROGRAMMA Rational 28 AAA ********" << std::endl;

    Rational28 rt( 5, 3 );
    Display( rt );

    Rational28 rt1( 2, 4 );
    Display( rt1 );

    Display( rt + rt1 );
    Display( rt - rt1 );
    Display( rt * rt1 );
    Display( rt / rt1 );

    std::cout << std::boolalpha << ( rt == rt1 ) << std::endl;
    std::cout << std::boolalpha << ( rt > rt1 ) << std::endl;
    std::cout << std::boolalpha << ( rt < rt1 ) << std::endl;
}
