#include "rightangled.h"
#include <cmath>
#include <iostream>

RightAngled::RightAngled( int32_t a, int32_t b, int32_t c )
    : Triangle9( a, b, c )
    , area_ { 0 }
{
    double p = Perimetr( ) / 2;
    area_ = std::sqrt( p * ( p - ab( ) ) * ( p - bc( ) ) * ( p - ac( ) ) );
}

RightAngled & RightAngled::operator=( const Triangle9 & rhs )
{
    setAb( rhs.ab( ) );
    setBc( rhs.bc( ) );
    setAc( rhs.ac( ) );
    area_ = AreaR( );
    return *this;
}

void RightAngled::Display( ) const
{
    std::cout << static_cast< std::string >( *this );
}

double RightAngled::AreaR( )
{
    double p = Perimetr( ) / 2;
    return std::sqrt( p * ( p - ab( ) ) * ( p - bc( ) ) * ( p - ac( ) ) );
}

RightAngled::operator std::string( ) const
{
    return Triangle9::operator std::string( ) + ", area = " + std::to_string( Area( ) );
}

double RightAngled::Area( ) const
{
    return area_;
}
