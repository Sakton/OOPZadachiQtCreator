#ifndef VECTOR3DINH_H
#define VECTOR3DINH_H
#include "vector3dBase.h"

class Vector3DInh : public Vector3DBase {
public:
  Vector3DInh( int32_t x = 0, int32_t y = 0, int32_t z = 0 );
  Vector3DInh& operator+=( const Vector3DInh& rhs );
  Vector3DInh& operator-=( const Vector3DInh& rhs );
  Vector3DInh& operator*=( const Vector3DInh& rhs );
  Vector3DInh& operator*=( int32_t scalar );

  friend Vector3DInh operator+( const Vector3DInh& lhs,
				const Vector3DInh& rhs );
  friend Vector3DInh operator-( const Vector3DInh& lhs,
				const Vector3DInh& rhs );
  friend Vector3DInh operator*( const Vector3DInh& lhs,
				const Vector3DInh& rhs );
  friend Vector3DInh operator*( const Vector3DInh& lhs, int32_t scalar );
  friend Vector3DInh operator*( int32_t scalar, const Vector3DInh& rhs );

  int64_t Scalar( const Vector3DInh& b ) const;
  double Lenth( ) const;

  friend bool operator==( const Vector3DInh& lhs, const Vector3DInh& rhs );
  friend bool operator!=( const Vector3DInh& lhs, const Vector3DInh& rhs );
  friend bool operator>( const Vector3DInh& lhs, const Vector3DInh& rhs );
  friend bool operator>=( const Vector3DInh& lhs, const Vector3DInh& rhs );
  friend bool operator<( const Vector3DInh& lhs, const Vector3DInh& rhs );
  friend bool operator<=( const Vector3DInh& lhs, const Vector3DInh& rhs );
};

#endif // VECTOR3DINH_H
