#include "equilateral.h"
#include <cmath>
#include <iostream>

Equilateral::Equilateral( int32_t a, int32_t b, int32_t c )
    : Triangle8( a, b, c )
    , area_ { Area( ) }
{
}

Equilateral & Equilateral::operator=( const Triangle8 & oth )
{
    setAb( oth.ab( ) );
    setBc( oth.bc( ) );
    setAc( oth.ac( ) );
    area_ = Area( );
    return *this;
}

void Equilateral::Display( ) const
{
    std::cout << static_cast< std::string >( *this ) << std::endl;
}

Equilateral::operator std::string( ) const
{
    return Triangle8::operator std::string( ) + ", area = " + std::to_string( Area( ) );
}

double Equilateral::Area( ) const
{
    double p = Perimetr( ) / 2;
    return std::sqrt( p * ( p - ab( ) ) * ( p - bc( ) ) * ( p - ac( ) ) );
}
