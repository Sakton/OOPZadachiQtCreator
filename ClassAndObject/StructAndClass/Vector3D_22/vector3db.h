#ifndef VECTOR3DB_H
#define VECTOR3DB_H
#include <iostream>
#include <string>

class Vector3Db {
public:
    void Init( int32_t vX, int32_t vY, int32_t vZ );
    void Display( );
    void Read( );
    std::string ToString( );

    Vector3Db Add( const Vector3Db& b ) const;
    Vector3Db Sub( const Vector3Db& b ) const;
    Vector3Db Mul( const Vector3Db& b ) const;
    Vector3Db Mul( int32_t scalar ) const;
    int32_t Scalar( const Vector3Db& b ) const;
    bool Equ( const Vector3Db& b );
    double Lenth( ) const;
    int VecLen( const Vector3Db& b );

private:
    int32_t x_;
    int32_t y_;
    int32_t z_;
};

#endif // VECTOR3DB_H
