#ifndef POINT27B_H
#define POINT27B_H
#include <string>

class Point27B
{
public:
    struct Polar {
	int32_t radius;
	double angleFi;
    };

    void Init( int32_t x_, int16_t y_ );
    void Display( ) const;
    void Read( );
    std::string ToString( ) const;

    void MoveX( int32_t dx );
    void MoveY( int32_t dy );
    double DistanceToNullCoordinate( ) const;
    double Distance( const Point27B & b ) const;
    Polar ToPolar( ) const;
    bool Eq( const Point27B & b ) const;
    bool NotEq( const Point27B & b ) const;

private:
    int32_t x;
    int32_t y;
};

#endif // POINT27B_H
