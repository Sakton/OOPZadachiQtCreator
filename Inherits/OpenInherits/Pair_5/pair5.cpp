#include "pair5.h"
#include <iostream>

Pair5::Pair5( int32_t a, int32_t b )
    : first_ { a }
    , second_ { b }
{
}

Pair5::operator std::string( ) const
{
    return ( std::to_string( first( ) ) + ", " + std::to_string( second( ) ) );
}

int32_t Pair5::Mult( )
{
    return first( ) * second( );
}

void Pair5::Display( ) const
{
    std::cout << std::string( *this ) << std::endl;
}

int32_t Pair5::first( ) const
{
    return first_;
}

void Pair5::setFirst( const int32_t & first )
{
    first_ = first;
}

int32_t Pair5::second( ) const
{
    return second_;
}

void Pair5::setSecond( const int32_t & second )
{
    second_ = second;
}
