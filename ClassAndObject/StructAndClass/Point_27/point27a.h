#ifndef POINT27A_H
#define POINT27A_H
#include <string>

struct Point27A {
    int32_t x;
    int32_t y;
};

struct Polar {
    int32_t radius;
    double angleFi;
};

void Init( Point27A & pt, int32_t x_, int16_t y_ );
void Display( const Point27A & pt );
void Read( Point27A & pt );
std::string ToString( const Point27A & pt );

void MoveX( Point27A & pt, int32_t dx );
void MoveY( Point27A & pt, int32_t dy );
double DistanceToNullCoordinate( const Point27A & pt );
double Distance( const Point27A & a, const Point27A & b );
Polar ToPolar( const Point27A & a );
bool Eq( const Point27A & a, const Point27A & b );
bool NotEq( const Point27A & a, const Point27A & b );

#endif // POINT27A_H
