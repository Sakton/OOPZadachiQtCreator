#include "pair3.h"

Pair3::Pair3( int32_t a, int32_t b )
{
    first = a;
    second = b;
}

int32_t Pair3::getFirst( ) const
{
    return first;
}

void Pair3::setFirst( const int32_t & value )
{
    first = value;
}

int32_t Pair3::getSecond( ) const
{
    return second;
}

void Pair3::setSecond( const int32_t & value )
{
    second = value;
}

Pair3::operator std::string( )
{
    return std::to_string( first ) + ", " + std::to_string( second );
}

bool operator<( const Pair3 & lhs, const Pair3 & rhs )
{
    return ( lhs.first < rhs.first ) || ( ( lhs.first == rhs.first ) && ( lhs.second < rhs.second ) );
}

bool operator==( const Pair3 & lhs, const Pair3 & rhs )
{
    return lhs.first == rhs.first && lhs.second == rhs.second;
}
