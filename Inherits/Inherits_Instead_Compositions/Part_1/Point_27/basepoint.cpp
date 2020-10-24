#include "basepoint.h"

#include <cmath>
#include <iostream>

BasePoint::BasePoint( int32_t x, int16_t y ) : x_ { x }, y_ { y } {}

double BasePoint::DistanceToNullCoordinate( ) {
  return std::sqrt( x_ * x_ + y_ * y_ );
}

double BasePoint::Distance( const BasePoint& b ) {
  int32_t dx = x_ - b.x_;
  int32_t dy = y_ - b.y_;
  return std::sqrt( dx * dx + dy * dy );
}

BasePoint::Polar BasePoint::ToPolar( ) {
  BasePoint::Polar p;
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

int32_t BasePoint::X( ) const { return x_; }

void BasePoint::setX( const int32_t& x ) { x_ = x; }

int32_t BasePoint::Y( ) const { return y_; }

void BasePoint::setY( const int32_t& y ) { y_ = y; }

std::string ToString( const BasePoint& pt ) {
  return "( " + std::to_string( pt.x_ ) + " : " + std::to_string( pt.y_ ) +
         " )";
}

void Display( const BasePoint& pt ) {
  std::cout << ToString( pt ) << std::endl;
}
