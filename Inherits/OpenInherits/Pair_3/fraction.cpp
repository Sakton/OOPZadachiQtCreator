#include "fraction.h"

Fraction::Fraction( int32_t a, int32_t b )
    : Pair3( a, b )
{
}
bool operator<( const Fraction & a, const Fraction & b )
{
    return static_cast< Pair3 >( a ) < static_cast< Pair3 >( b );
}
bool operator<=( const Fraction & a, const Fraction & b )
{
    return a < b || a == b;
}
bool operator>( const Fraction & a, const Fraction & b )
{
    return !( a <= b );
}
bool operator>=( const Fraction & a, const Fraction & b )
{
    return a > b || a == b;
}
bool operator==( const Fraction & a, const Fraction & b )
{
    return static_cast< Pair3 >( a ) == static_cast< Pair3 >( b );
}
bool operator!=( const Fraction & a, const Fraction & b )
{
    return !( a == b );
}
