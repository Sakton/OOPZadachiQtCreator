#include "vector3da.h"
#include <sstream>

void Init( Vector3Da & vct, int32_t vX, int32_t vY, int32_t vZ )
{
    //coordinates can be any
    vct.x = vX;
    vct.y = vY;
    vct.z = vZ;
}

void Display( const Vector3Da & vct )
{
    std::cout << ToString( vct ) << std::endl;
}

void Read( Vector3Da & vct )
{
    int32_t a, b, c;
    std::cout << "Enter x y z" << std::endl;
    std::cin >> a >> b >> c;
    Init( vct, a, b, c );
}

std::string ToString( const Vector3Da & vct )
{
    std::stringstream ss;
    ss << "( " << vct.x << " : " << vct.y << " : " << vct.z << " )";
    return ss.str( );
}

Vector3Da Add( const Vector3Da & a, const Vector3Da & b )
{
    Vector3Da res;
    res.x = a.x + b.x;
    res.y = a.y + b.y;
    res.z = a.z + b.z;
    return res;
}

Vector3Da Sub( const Vector3Da & a, const Vector3Da & b )
{
    Vector3Da res;
    res.x = a.x - b.x;
    res.y = a.y - b.y;
    res.z = a.z - b.z;
    return res;
}

Vector3Da Mul( const Vector3Da & a, const Vector3Da & b )
{
    Vector3Da res;
    res.x = a.y * b.z - a.z * b.y;
    res.y = a.z * b.x - a.x * b.z;
    res.z = a.x * b.y - a.y * b.x;
    return res;
}

Vector3Da Mul( const Vector3Da & a, int32_t scalar )
{
    Vector3Da res;
    res.x = a.x * scalar;
    res.y = a.y * scalar;
    res.z = a.z * scalar;
    return res;
}

bool Equ( const Vector3Da & a, const Vector3Da & b )
{
    return ( a.x == b.x ) && ( a.y == b.y ) && ( a.z == b.z );
}

double Lenth( const Vector3Da & vct )
{
    return std::sqrt( vct.x * vct.x + vct.y * vct.y + vct.z * vct.z );
}

int VecLen( const Vector3Da & a, const Vector3Da & b )
{
    double res = ( Lenth( a ) - Lenth( b ) );
    if ( std::fabs( res ) <= 1e-6 ) {
	return 0;
    }
    else {
	return res;
    }
}

int32_t Scalar( const Vector3Da & a, const Vector3Da & b )
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
