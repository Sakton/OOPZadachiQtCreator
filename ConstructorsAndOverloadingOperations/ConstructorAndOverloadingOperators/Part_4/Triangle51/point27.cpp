#include "point27.h"

#include <cmath>
#include <iostream>

const double PI = 3.14159265358979323846;
const int ANG_PI_2 = 180;

Point27::Point27( int32_t x, int16_t y ) : x_ { x }, y_ { y } {}

Point27::operator std::string( ) const {
  return "( " + std::to_string( x_ ) + " : " + std::to_string( y_ ) + " )";
}

void Point27::Display( ) const {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

void Point27::MoveX( int32_t dx ) { x_ += dx; }

void Point27::MoveY( int32_t dy ) { y_ += dy; }

double Point27::DistanceToNullCoordinate( ) const {
  return std::sqrt( x_ * x_ + y_ * y_ );
}

double Point27::Distance( const Point27& b ) const {
  int32_t dx = x_ - b.x_;
  int32_t dy = y_ - b.y_;
  return std::sqrt( dx * dx + dy * dy );
}

Point27::Polar Point27::ToPolar( ) const {
  Point27::Polar p;
  p.radius = DistanceToNullCoordinate( );

  if ( x_ > 0 && y_ >= 0 ) {
    p.angleFi = std::atan( y_ / x_ ) * ANG_PI_2 / PI;
  } else if ( x_ > 0 && y_ < 0 ) {
    p.angleFi = ( std::atan( y_ / x_ ) + 2 * PI ) * ANG_PI_2 / PI;
  } else if ( x_ < 0 ) {
    p.angleFi = ( std::atan( y_ / x_ ) + PI ) * ANG_PI_2 / PI;
  } else if ( x_ == 0 && y_ > 0 ) {
    p.angleFi = 90;
  } else if ( x_ == 0 && y_ < 0 ) {
    p.angleFi = 270;
  } else {
    std::cout << "ERROR ANGLE" << std::endl;
    exit( 1 );
  }
  return p;
}

bool operator==( const Point27& a, const Point27& b ) {
  return a.x_ == b.x_ && a.y_ == b.y_;
}
bool operator!=( const Point27& a, const Point27& b ) { return !( a == b ); }
