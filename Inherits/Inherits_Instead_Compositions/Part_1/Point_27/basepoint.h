#ifndef BASEPOINT_H
#define BASEPOINT_H
#include <string>

class BasePoint
{
 public:
  struct Polar {
    int32_t radius;
    double angleFi;
  };

  constexpr static double PI = 3.14159265358979323846;
  constexpr static int ANG_PI_2 = 180;

  BasePoint( int32_t x, int16_t y );
  friend std::string ToString( const BasePoint& pt );
  friend void Display( const BasePoint& pt );

  double DistanceToNullCoordinate( );
  double Distance( const BasePoint& b );
  Polar ToPolar( );

  int32_t X( ) const;
  void setX( const int32_t& x );

  int32_t Y( ) const;
  void setY( const int32_t& y );

 private:
  int32_t x_;
  int32_t y_;
};

#endif // BASEPOINT_H
