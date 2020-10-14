#include "point27a.h"
#include <iostream>
#include <sstream>

const double PI = 3.14159265358979323846;
const int ANG_PI_2 = 180;

void Init( Point27A & pt, int32_t x_, int16_t y_ )
{
    //point may have any coordinats
    pt.x = x_;
    pt.y = y_;
}

void Display( const Point27A & pt )
{
    std::cout << ToString( pt ) << std::endl;
}

void Read( Point27A & pt )
{
    int16_t a, b;
    std::cout << "Enter a b" << std::endl;
    std::cin >> a >> b;
    Init( pt, a, b );
}

std::string ToString( const Point27A & pt )
{
    std::stringstream ss;
    ss << "( " << pt.x << " : " << pt.y << " )";
    return ss.str( );
}

void MoveX( Point27A & pt, int32_t dx )
{
    pt.x += dx;
}

void MoveY( Point27A & pt, int32_t dy )
{
    pt.y += dy;
}

double DistanceToNullCoordinate( const Point27A & pt )
{
    return std::sqrt( pt.x * pt.x + pt.y * pt.y );
}

double Distance( const Point27A & a, const Point27A & b )
{
    int32_t dx = a.x - b.x;
    int32_t dy = a.y - b.y;
    return std::sqrt( dx * dx + dy * dy );
}

Polar ToPolar( const Point27A & a )
{
    Polar p;
    p.radius = DistanceToNullCoordinate( a );

    if ( a.x > 0 && a.y >= 0 ) {
	p.angleFi = std::atan( a.y / a.x ) * ANG_PI_2 / PI;
    }
    else if ( a.x > 0 && a.y < 0 ) {
	p.angleFi = ( std::atan( a.y / a.x ) + 2 * PI ) * ANG_PI_2 / PI;
    }
    else if ( a.x < 0 ) {
	p.angleFi = ( std::atan( a.y / a.x ) + PI ) * ANG_PI_2 / PI;
    }
    else if ( a.x == 0 && a.y > 0 ) {
	p.angleFi = 90;
    }
    else if ( a.x == 0 && a.y < 0 ) {
	p.angleFi = 270;
    }
    else {
	std::cout << "ERROR ANGLE" << std::endl;
	exit( 1 );
    }
    return p;
}

bool Eq( const Point27A & a, const Point27A & b )
{
    return a.x == b.x && a.y == b.y;
}

bool NotEq( const Point27A & a, const Point27A & b )
{
    return !Eq( a, b );
}
