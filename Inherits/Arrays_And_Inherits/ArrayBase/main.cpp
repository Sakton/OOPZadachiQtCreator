#include "array.h"
#include <iostream>

int main()
{
    Array< int > ar( 5 );
    for ( int i = 0; i < 5; ++i ) {
        std::cout << ar[ i ] << " ";
    }
    ar[ 1 ] = 1;
    ar[ 2 ] = 1;
    std::cout << std::endl;
    for ( int i = 0; i < 5; ++i ) {
        std::cout << ar[ i ] << " ";
    }
}
