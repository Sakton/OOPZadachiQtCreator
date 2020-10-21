#ifndef POINT27_H
#define POINT27_H
#include <string>

class Point27 {
 public:
  struct Polar {
    int32_t radius;
    double angleFi;
  };

  Point27( int32_t x, int16_t y );
  operator std::string( ) const;

  friend void Display( const Point27& pt );

  friend void MoveX( Point27& pt, int32_t dx );
  friend void MoveY( Point27& pt, int32_t dy );
  friend double DistanceToNullCoordinate( const Point27& pt );
  friend double Distance( const Point27& a, const Point27& b );
  friend Polar ToPolar( const Point27& a );

  friend bool operator==( const Point27& a, const Point27& b );
  friend bool operator!=( const Point27& a, const Point27& b );

 private:
  int32_t x_;
  int32_t y_;
};

#endif // POINT27_H
