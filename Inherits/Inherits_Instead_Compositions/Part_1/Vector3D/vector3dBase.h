#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cstdint>
#include <string>

class Vector3DBase {
public:
  Vector3DBase( int32_t x = 0, int32_t y = 0, int32_t z = 0 );
  friend void Display( const Vector3DBase &vc );
  // friend void Read( );
  std::string ToString( ) const;

  //  Vector3D& operator+=( const Vector3D& rhs );
  //  Vector3D& operator-=( const Vector3D& rhs );
  //  Vector3D& operator*=( const Vector3D& rhs );
  //  Vector3D& operator*=( int32_t scalar );

  //  friend Vector3D operator+( const Vector3D& lhs, const Vector3D& rhs );
  //  friend Vector3D operator-( const Vector3D& lhs, const Vector3D& rhs );
  //  friend Vector3D operator*( const Vector3D& lhs, const Vector3D& rhs );
  //  friend Vector3D operator*( const Vector3D& lhs, int32_t scalar );
  //  friend Vector3D operator*( int32_t scalar, const Vector3D& rhs );

  //  int64_t Scalar( const Vector3D& b ) const;

  //  friend bool operator==( const Vector3D& lhs, const Vector3D& rhs );
  //  friend bool operator!=( const Vector3D& lhs, const Vector3D& rhs );
  //  friend bool operator>( const Vector3D& lhs, const Vector3D& rhs );
  //  friend bool operator>=( const Vector3D& lhs, const Vector3D& rhs );
  //  friend bool operator<( const Vector3D& lhs, const Vector3D& rhs );
  //  friend bool operator<=( const Vector3D& lhs, const Vector3D& rhs );

  //  double Lenth( ) const;

  int32_t x( ) const;
  void setX( const int32_t &x );
  int32_t y( ) const;
  void setY( const int32_t &y );
  int32_t z( ) const;
  void setZ( const int32_t &z );

private:
  int32_t x_;
  int32_t y_;
  int32_t z_;
};

#endif // VECTOR3D_H
