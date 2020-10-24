#ifndef POINTPUBLIC_H
#define POINTPUBLIC_H
#include "basepoint.h"

class PointPublic : public BasePoint {
 public:
  PointPublic( int32_t x = 0, int16_t y = 0 );

  void MoveX( int32_t dx );
  void MoveY( int32_t dy );

  friend bool operator==( const PointPublic& a, const PointPublic& b );
  friend bool operator!=( const PointPublic& a, const PointPublic& b );
};

#endif // POINTPUBLIC_H
