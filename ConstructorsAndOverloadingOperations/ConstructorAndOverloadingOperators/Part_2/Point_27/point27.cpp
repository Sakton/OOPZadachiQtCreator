#include "point27.h"

#include <cmath>
#include <iostream>

const double PI = 3.14159265358979323846;
const int ANG_PI_2 = 180;

Point27::Point27( int32_t x, int16_t y ) : x_ { x }, y_ { y } {}

Point27::operator std::string( ) const {
  return "( " + std::to_string( x_ ) + " : " + std::to_string( y_ ) + " )";
}

void Display( const Point27& pt ) {
  std::cout << static_cast< std::string >( pt ) << std::endl;
}

void MoveX( Point27& pt, int32_t dx ) { pt.x_ += dx; }

void MoveY( Point27& pt, int32_t dy ) { pt.y_ += dy; }
double DistanceToNullCoordinate( const Point27& pt ) {
  return std::sqrt( pt.x_ * pt.x_ + pt.y_ * pt.y_ );
}
double Distance( const Point27& a, const Point27& b ) {
  int32_t dx = a.x_ - b.x_;
  int32_t dy = a.y_ - b.y_;
  return std::sqrt( dx * dx + dy * dy );
}

Point27::Polar ToPolar( const Point27& a ) {
  Point27::Polar p;
  p.radius = DistanceToNullCoordinate( a );

  if ( a.x_ > 0 && a.y_ >= 0 ) {
    p.angleFi = std::atan( a.y_ / a.x_ ) * ANG_PI_2 / PI;
  } else if ( a.x_ > 0 && a.y_ < 0 ) {
    p.angleFi = ( std::atan( a.y_ / a.x_ ) + 2 * PI ) * ANG_PI_2 / PI;
  } else if ( a.x_ < 0 ) {
    p.angleFi = ( std::atan( a.y_ / a.x_ ) + PI ) * ANG_PI_2 / PI;
  } else if ( a.x_ == 0 && a.y_ > 0 ) {
    p.angleFi = 90;
  } else if ( a.x_ == 0 && a.y_ < 0 ) {
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
