#ifndef POINT27C_H
#define POINT27C_H
#include <string>

struct DataPoint {
    int32_t x;
    int32_t y;

    void Init( int32_t x_, int16_t y_ );
    void Display( ) const;
    void Read( );
    std::string ToString( ) const;
};

class Point27C {
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
    double Distance( const Point27C & b ) const;
    Polar ToPolar( ) const;
    bool Eq( const Point27C & b ) const;
    bool NotEq( const Point27C & b ) const;

private:
    DataPoint data_;
};

#endif // POINT27C_H
