#include "pointprivate.h"

PointPrivate::PointPrivate( int32_t x, int16_t y ) : BasePoint( x, y ) {}

void PointPrivate::MoveX( int32_t dx ) { setX( X( ) + dx ); }

void PointPrivate::MoveY( int32_t dy ) { setY( Y( ) + dy ); }

bool operator==( const PointPrivate& a, const PointPrivate& b ) {
  return a.X( ) == b.X( ) && a.Y( ) == b.Y( );
}

bool operator!=( const PointPrivate& a, const PointPrivate& b ) {
  return !( a == b );
}

//ругается но работает
std::string ToString( const PointPrivate& pt ) {
  return ::ToString( static_cast< const BasePoint& >( pt ) );
}
void Display( const PointPrivate& pt ) {
  return ::Display( static_cast< const BasePoint& >( pt ) );
}
