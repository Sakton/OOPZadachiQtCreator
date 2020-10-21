#ifndef POINT27_H
#define POINT27_H
#include <string>

class Point27 {
 public:
  struct Polar {
    int32_t radius;
    double angleFi;
  };

  explicit Point27( int32_t x = 0, int16_t y = 0 );
  explicit operator std::string( ) const;

  void Display( ) const;

  void MoveX( int32_t dx );
  void MoveY( int32_t dy );
  double DistanceToNullCoordinate( ) const;
  double Distance( const Point27& b ) const;
  Polar ToPolar( ) const;

  friend bool operator==( const Point27& a, const Point27& b );
  friend bool operator!=( const Point27& a, const Point27& b );

 private:
  int32_t x_;
  int32_t y_;
};

#endif // POINT27_H
