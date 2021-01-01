#include "complex.h"
#include <iostream>

int main()
{
    Complex a( 10, 20 );
    Display( a );
    std::cout << std::boolalpha << ( a == a ) << std::endl;

    Complex b( 5, 10 );
    Display( b );
    Display( a += b );
}
