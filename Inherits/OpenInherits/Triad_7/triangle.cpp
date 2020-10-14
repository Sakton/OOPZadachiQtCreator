#include "triangle.h"
#include <iostream>

Triangle::Triangle( double a, double b, double c )
    : Triad7( a, b, c )
{
    if ( a < 0 || b < 0 || c < 0 ) {
	std::cout << "ERROR";
	exit( 1 );
    }
}

void Triangle::Display( ) const
{
    std::cout << static_cast< std::string >( *this ) << std::endl;
}

double Triangle::Area( ) const
{
    double p = ( first( ) + second( ) + third( ) ) / 2;
    return std::sqrt( p * ( p - first( ) ) * ( p - second( ) ) * ( p - third( ) ) );
}

double Triangle::angA( ) const
{
    return std::acos( ( second( ) * second( ) + third( ) * third( ) - first( ) * first( ) ) / ( 2 * second( ) * third( ) ) ) * 180 / 3.14;
}

double Triangle::angB( ) const
{
    return std::acos( ( first( ) * first( ) + third( ) * third( ) - second( ) * second( ) ) / ( 2 * first( ) * third( ) ) ) * 180 / 3.14;
}

double Triangle::angC( ) const
{
    return 180.0 - angA( ) - angB( );
}

Triangle::operator std::string( ) const
{
    return Triad7::operator std::string( ) + ", " + std::to_string( angA( ) ) + ", " + std::to_string( angB( ) ) + ", " + std::to_string( angC( ) ) + " area = " + std::to_string( Area( ) );
}
