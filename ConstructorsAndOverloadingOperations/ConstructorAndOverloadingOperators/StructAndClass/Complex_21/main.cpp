#include "complex21.h"
#include <iostream>

int main()
{
    std::cout << "******* PROGRAMMA COMPLEX 21 B-B-B ********" << std::endl;

    //Methods demonstration
    Complex21 aB( 1.1, 2.2 ), bB( 3.3, 4.4 );
    Display( aB );
    std::cout << std::endl;
    Display( bB );
    std::cout << std::endl;

    Complex21 cB = aB + bB;
    Complex21 dB = aB - bB;
    Complex21 eB = aB / bB;
    Complex21 fB = aB * bB;

    Display( cB );
    std::cout << std::endl;
    Display( dB );
    std::cout << std::endl;
    Display( eB );
    std::cout << std::endl;
    Display( fB );
    std::cout << std::endl;

    Complex21 lB = -aB;
    Complex21 mB = -bB;

    Display( lB );
    std::cout << std::endl;
    Display( mB );
    std::cout << std::endl;

    Complex21 aaB;
    Read( aaB );
    Display( aaB );
    std::cout << std::endl;

    //arrays
    Complex21 arrB[ 10 ];
    for ( int i = 0; i < 10; ++i ) {
	arrB[ i ] = Complex21( i + 1, -i - 1 );
    }
    for ( int i = 0; i < 10; ++i ) {
	Display( arrB[ i ] );
	std::cout << std::endl;
    }
}
