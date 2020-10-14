#ifndef VECTOR3DC_H
#define VECTOR3DC_H
#include <iostream>
#include <string>

struct DataVector {
    void Init( int32_t vX, int32_t vY, int32_t vZ );
    void Display( );
    void Read( );
    std::string ToString( );

    int32_t x;
    int32_t y;
    int32_t z;
};

class Vector3Dc {
    void Init( int32_t vX, int32_t vY, int32_t vZ );
    void Display( );
    void Read( );
    std::string ToString( );

    Vector3Dc Add( const Vector3Dc& b ) const;
    Vector3Dc Sub( const Vector3Dc& b ) const;
    Vector3Dc Mul( const Vector3Dc& b ) const;
    Vector3Dc Mul( int32_t scalar ) const;
    int32_t Scalar( const Vector3Dc& b ) const;
    bool Equ( const Vector3Dc& b );
    double Lenth( ) const;
    int VecLen( const Vector3Dc& b );

public:
    DataVector data_;
};

#endif // VECTOR3DC_H
