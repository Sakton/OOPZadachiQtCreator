#include "fraction.h"
#include <iostream>

int main()
{
    Fraction a( 5, 10 );
    Fraction b( 3, 4 );
    Fraction c( 3, 4 );

    std::cout << std::boolalpha << ( a < b ) << std::endl;
    std::cout << std::boolalpha << ( a > b ) << std::endl;
    std::cout << std::boolalpha << ( a == b ) << std::endl;
    std::cout << std::boolalpha << ( a <= b ) << std::endl;
    std::cout << std::boolalpha << ( a >= b ) << std::endl;
    std::cout << std::boolalpha << ( a != b ) << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << std::boolalpha << ( c < b ) << std::endl;
    std::cout << std::boolalpha << ( c > b ) << std::endl;
    std::cout << std::boolalpha << ( c == b ) << std::endl;
    std::cout << std::boolalpha << ( c <= b ) << std::endl;
    std::cout << std::boolalpha << ( c >= b ) << std::endl;
    std::cout << std::boolalpha << ( c != b ) << std::endl;

    std::string aa = a;

    std::cout << aa;
}
