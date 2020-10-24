#include "pointpublic.h"

PointPublic::PointPublic( int32_t x, int16_t y ) : BasePoint( x, y ) {}

void PointPublic::MoveX( int32_t dx ) { setX( X( ) + dx ); }

void PointPublic::MoveY( int32_t dy ) { setY( Y( ) + dy ); }

bool operator==( const PointPublic& a, const PointPublic& b ) {
  return a.X( ) == b.X( ) && a.Y( ) == b.Y( );
}

bool operator!=( const PointPublic& a, const PointPublic& b ) {
  return !( a == b );
}
