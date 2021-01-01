#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle( int32_t a, int32_t b )
    : Pair5( a, b )
{
}

void Rectangle::Display( )
{
    std::cout << std::string( *this ) << std::endl;
}

Rectangle::operator std::string( )
{
    return this->Pair5::operator std::string( ) + " perimeter: " + std::to_string( Perimeter( ) ) + " Area: " + std::to_string( Area( ) );
}

int32_t Rectangle::Perimeter( )
{
    return ( first( ) + second( ) ) * 2;
}

int32_t Rectangle::Area( )
{
    return first( ) * second( );
}
