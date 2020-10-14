#include "vector3dc.h"
#include <sstream>

void DataVector::Init( int32_t vX, int32_t vY, int32_t vZ )
{
    //coordinates can be any
    x = vX;
    y = vY;
    z = vZ;
}

void DataVector::Display( )
{
    std::cout << ToString( ) << std::endl;
}

void DataVector::Read( )
{
    int32_t a, b, c;
    std::cout << "Enter x y z" << std::endl;
    std::cin >> a >> b >> c;
    Init( a, b, c );
}

std::string DataVector::ToString( )
{
    std::stringstream ss;
    ss << "( " << x << " : " << y << " : " << z << " )";
    return ss.str( );
}

void Vector3Dc::Init( int32_t vX, int32_t vY, int32_t vZ )
{
    data_.Init( vX, vY, vZ );
}

void Vector3Dc::Display( )
{
    data_.Display( );
}

void Vector3Dc::Read( )
{
    data_.Read( );
}

std::string Vector3Dc::ToString( )
{
    return data_.ToString( );
}

Vector3Dc Vector3Dc::Add( const Vector3Dc &b ) const
{
    Vector3Dc res;
    res.data_.x = data_.x + b.data_.x;
    res.data_.y = data_.y + b.data_.y;
    res.data_.z = data_.z + b.data_.z;
    return res;
}

Vector3Dc Vector3Dc::Sub( const Vector3Dc &b ) const
{
    Vector3Dc res;
    res.data_.x = data_.x - b.data_.x;
    res.data_.y = data_.y - b.data_.y;
    res.data_.z = data_.z - b.data_.z;
    return res;
}

Vector3Dc Vector3Dc::Mul( const Vector3Dc &b ) const
{
    Vector3Dc res;
    res.data_.x = data_.y * b.data_.z - data_.z * b.data_.y;
    res.data_.y = data_.z * b.data_.x - data_.x * b.data_.z;
    res.data_.z = data_.x * b.data_.y - data_.y * b.data_.x;
    return res;
}

Vector3Dc Vector3Dc::Mul( int32_t scalar ) const
{
    Vector3Dc res;
    res.data_.x = data_.x * scalar;
    res.data_.y = data_.y * scalar;
    res.data_.z = data_.z * scalar;
    return res;
}

int32_t Vector3Dc::Scalar( const Vector3Dc &b ) const
{
    return data_.x * b.data_.x + data_.y * b.data_.y + data_.z * b.data_.z;
}

bool Vector3Dc::Equ( const Vector3Dc &b )
{
    return ( data_.x == b.data_.x ) && ( data_.y == b.data_.y ) && ( data_.z == b.data_.z );
}

double Vector3Dc::Lenth( ) const
{
    return std::sqrt( data_.x * data_.x + data_.y * data_.y + data_.z * data_.z );
}

int Vector3Dc::VecLen( const Vector3Dc &b )
{
    double res = ( this->Lenth( ) - b.Lenth( ) );
    if ( std::fabs( res ) <= 1e-6 ) {
	return 0;
    } else {
	return res;
    }
}
