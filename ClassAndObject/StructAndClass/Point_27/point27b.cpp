#include "point27b.h"
#include <iostream>
#include <sstream>

const double PI = 3.14159265358979323846;
const int ANG_PI_2 = 180;

void Point27B::Init( int32_t x_, int16_t y_ )
{
    //point may have any coordinats
    x = x_;
    y = y_;
}

void Point27B::Display( ) const
{
    std::cout << ToString( ) << std::endl;
}

void Point27B::Read( )
{
    int16_t a, b;
    std::cout << "Enter a b" << std::endl;
    std::cin >> a >> b;
    Init( a, b );
}

std::string Point27B::ToString( ) const
{
    std::stringstream ss;
    ss << "( " << x << " : " << y << " )";
    return ss.str( );
}

void Point27B::MoveX( int32_t dx )
{
    x += dx;
}

void Point27B::MoveY( int32_t dy )
{
    y += dy;
}

double Point27B::DistanceToNullCoordinate( ) const
{
    return std::sqrt( x * x + y * y );
}

double Point27B::Distance( const Point27B & b ) const
{
    int32_t dx = x - b.x;
    int32_t dy = y - b.y;
    return std::sqrt( dx * dx + dy * dy );
}

Point27B::Polar Point27B::ToPolar( ) const
{
    Polar p;
    p.radius = DistanceToNullCoordinate( );

    if ( x > 0 && y >= 0 ) {
	p.angleFi = std::atan( y / x ) * ANG_PI_2 / PI;
    }
    else if ( x > 0 && y < 0 ) {
	p.angleFi = ( std::atan( y / x ) + 2 * PI ) * ANG_PI_2 / PI;
    }
    else if ( x < 0 ) {
	p.angleFi = ( std::atan( y / x ) + PI ) * ANG_PI_2 / PI;
    }
    else if ( x == 0 && y > 0 ) {
	p.angleFi = 90;
    }
    else if ( x == 0 && y < 0 ) {
	p.angleFi = 270;
    }
    else {
	std::cout << "ERROR ANGLE" << std::endl;
	exit( 1 );
    }
    return p;
}

bool Point27B::Eq( const Point27B & b ) const
{
    return x == b.x && y == b.y;
}

bool Point27B::NotEq( const Point27B & b ) const
{
    return !Eq( b );
}
