#include "point27c.h"
#include <iostream>
#include <sstream>

const double PI = 3.14159265358979323846;
const int ANG_PI_2 = 180;

void DataPoint::Init( int32_t x_, int16_t y_ )
{
    //point may have any coordinats
    x = x_;
    y = y_;
}

void DataPoint::Display( ) const
{
    std::cout << ToString( ) << std::endl;
}

void DataPoint::Read( )
{
    int16_t a, b;
    std::cout << "Enter a b" << std::endl;
    std::cin >> a >> b;
    Init( a, b );
}

std::string DataPoint::ToString( ) const
{
    std::stringstream ss;
    ss << "( " << x << " : " << y << " )";
    return ss.str( );
}

void Point27C::Init( int32_t x_, int16_t y_ )
{
    data_.Init( x_, y_ );
}

void Point27C::Display( ) const
{
    data_.Display( );
}

void Point27C::Read( )
{
    data_.Read( );
}

std::string Point27C::ToString( ) const
{
    return data_.ToString( );
}

void Point27C::MoveX( int32_t dx )
{
    data_.x += dx;
}

void Point27C::MoveY( int32_t dy )
{
    data_.y += dy;
}

double Point27C::DistanceToNullCoordinate( ) const
{
    return std::sqrt( data_.x * data_.x + data_.y * data_.y );
}

double Point27C::Distance( const Point27C & b ) const
{
    int32_t dx = data_.x - b.data_.x;
    int32_t dy = data_.y - b.data_.y;
    return std::sqrt( dx * dx + dy * dy );
}

Point27C::Polar Point27C::ToPolar( ) const
{
    Polar p;
    p.radius = DistanceToNullCoordinate( );

    if ( data_.x > 0 && data_.y >= 0 ) {
	p.angleFi = std::atan( data_.y / data_.x ) * ANG_PI_2 / PI;
    }
    else if ( data_.x > 0 && data_.y < 0 ) {
	p.angleFi = ( std::atan( data_.y / data_.x ) + 2 * PI ) * ANG_PI_2 / PI;
    }
    else if ( data_.x < 0 ) {
	p.angleFi = ( std::atan( data_.y / data_.x ) + PI ) * ANG_PI_2 / PI;
    }
    else if ( data_.x == 0 && data_.y > 0 ) {
	p.angleFi = 90;
    }
    else if ( data_.x == 0 && data_.y < 0 ) {
	p.angleFi = 270;
    }
    else {
	std::cout << "ERROR ANGLE" << std::endl;
	exit( 1 );
    }
    return p;
}

bool Point27C::Eq( const Point27C & b ) const
{
    return data_.x == b.data_.x && data_.y == b.data_.y;
}

bool Point27C::NotEq( const Point27C & b ) const
{
    return !Eq( b );
}
