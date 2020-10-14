#include "vector3db.h"
#include <sstream>

void Vector3Db::Init( int32_t vX, int32_t vY, int32_t vZ )
{
    //coordinates can be any
    x_ = vX;
    y_ = vY;
    z_ = vZ;
}

void Vector3Db::Display( )
{
    std::cout << ToString( ) << std::endl;
}

void Vector3Db::Read( )
{
    int32_t a, b, c;
    std::cout << "Enter x y z" << std::endl;
    std::cin >> a >> b >> c;
    Init( a, b, c );
}

std::string Vector3Db::ToString( )
{
    std::stringstream ss;
    ss << "( " << x_ << " : " << y_ << " : " << z_ << " )";
    return ss.str( );
}

Vector3Db Vector3Db::Add( const Vector3Db &b ) const
{
    Vector3Db res;
    res.x_ = x_ + b.x_;
    res.y_ = y_ + b.y_;
    res.z_ = z_ + b.z_;
    return res;
}

Vector3Db Vector3Db::Sub( const Vector3Db &b ) const
{
    Vector3Db res;
    res.x_ = x_ - b.x_;
    res.y_ = y_ - b.y_;
    res.z_ = z_ - b.z_;
    return res;
}

Vector3Db Vector3Db::Mul( const Vector3Db &b ) const
{
    Vector3Db res;
    res.x_ = y_ * b.z_ - z_ * b.y_;
    res.y_ = z_ * b.x_ - x_ * b.z_;
    res.z_ = x_ * b.y_ - y_ * b.x_;
    return res;
}

Vector3Db Vector3Db::Mul( int32_t scalar ) const
{
    Vector3Db res;
    res.x_ = x_ * scalar;
    res.y_ = y_ * scalar;
    res.z_ = z_ * scalar;
    return res;
}

int32_t Vector3Db::Scalar( const Vector3Db &b ) const
{
    return x_ * b.x_ + y_ * b.y_ + z_ * b.z_;
}

bool Vector3Db::Equ( const Vector3Db &b )
{
    return ( x_ == b.x_ ) && ( y_ == b.y_ ) && ( z_ == b.z_ );
}

double Vector3Db::Lenth( ) const
{
    return std::sqrt( x_ * x_ + y_ * y_ + z_ * z_ );
}

int Vector3Db::VecLen( const Vector3Db &b )
{
    double res = ( this->Lenth( ) - b.Lenth( ) );
    if ( std::fabs( res ) <= 1e-6 ) {
	return 0;
    } else {
	return res;
    }
}
