#ifndef POINTPRIVATE_H
#define POINTPRIVATE_H
#include "basepoint.h"

class PointPrivate : BasePoint {
 public:
  // opening interface from private base class
  using BasePoint::Polar;
  using BasePoint::ToPolar;
  //**

  PointPrivate( int32_t x = 0, int16_t y = 0 );

  friend std::string ToString( const PointPrivate& pt );
  friend void Display( const PointPrivate& pt );

  void MoveX( int32_t dx );
  void MoveY( int32_t dy );

  friend bool operator==( const PointPrivate& a, const PointPrivate& b );
  friend bool operator!=( const PointPrivate& a, const PointPrivate& b );
};

#endif // POINTPRIVATE_H
