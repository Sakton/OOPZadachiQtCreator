#ifndef VECTOR3DA_H
#define VECTOR3DA_H
#include <cstdint>
#include <iostream>
#include <string>

struct Vector3Da {
    int32_t x;
    int32_t y;
    int32_t z;
};

#pragma pack( push, 1 )
struct Vector3Da_Test {
    int32_t x;
    int32_t y;
    int32_t z;
};
#pragma pack( pop )

void Init( Vector3Da & vct, int32_t vX, int32_t vY, int32_t vZ );
void Display( const Vector3Da & vct );
void Read( Vector3Da & vct );
std::string ToString( const Vector3Da & vct );

Vector3Da Add( const Vector3Da & a, const Vector3Da & b );
Vector3Da Sub( const Vector3Da & a, const Vector3Da & b );
Vector3Da Mul( const Vector3Da & a, const Vector3Da & b );
Vector3Da Mul( const Vector3Da & a, int32_t scalar );
int32_t Scalar( const Vector3Da & a, const Vector3Da & b );
bool Equ( const Vector3Da & a, const Vector3Da & b );
double Lenth( const Vector3Da & vct );
int VecLen( const Vector3Da & a, const Vector3Da & b );

#endif // VECTOR3DA_H
