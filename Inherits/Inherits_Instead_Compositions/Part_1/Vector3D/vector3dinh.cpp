#include "vector3dinh.h"

#include <cmath>
Vector3DInh::Vector3DInh( int32_t x, int32_t y, int32_t z )
    : Vector3DBase( x, y, z ) {}

Vector3DInh& Vector3DInh::operator+=( const Vector3DInh& rhs ) {
  setX( x( ) + rhs.x( ) );
  setY( y( ) + rhs.y( ) );
  setZ( z( ) + rhs.z( ) );
  return *this;
}

Vector3DInh& Vector3DInh::operator-=( const Vector3DInh& rhs ) {
  setX( x( ) - rhs.x( ) );
  setY( y( ) - rhs.y( ) );
  setZ( z( ) - rhs.z( ) );
  return *this;
}

Vector3DInh& Vector3DInh::operator*=( const Vector3DInh& rhs ) {
  setX( x( ) * rhs.x( ) );
  setY( y( ) * rhs.y( ) );
  setZ( z( ) * rhs.z( ) );
  return *this;
}

Vector3DInh& Vector3DInh::operator*=( int32_t scalar ) {
  setX( x( ) * scalar );
  setY( y( ) * scalar );
  setZ( z( ) * scalar );
  return *this;
}

int64_t Vector3DInh::Scalar( const Vector3DInh& b ) const {
  return x( ) * b.x( ) + y( ) * b.y( ) + z( ) * b.z( );
}

double Vector3DInh::Lenth( ) const {
  return std::sqrt( x( ) * x( ) + y( ) * y( ) + z( ) * z( ) );
}

bool operator==( const Vector3DInh& lhs, const Vector3DInh& rhs ) {
  return ( lhs.Lenth( ) - rhs.Lenth( ) ) <= 1e-3;
}

//остальные аналогично

// bool operator!=( const Vector3DInh& lhs, const Vector3DInh& rhs ) {}
// bool operator>( const Vector3DInh& lhs, const Vector3DInh& rhs ) {}
// bool operator>=( const Vector3DInh& lhs, const Vector3DInh& rhs ) {}
// bool operator<( const Vector3DInh& lhs, const Vector3DInh& rhs ) {}
// bool operator<=( const Vector3DInh& lhs, const Vector3DInh& rhs ) {}
