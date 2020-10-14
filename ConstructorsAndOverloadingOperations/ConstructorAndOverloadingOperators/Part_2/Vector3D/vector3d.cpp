#include "vector3d.h"

#include <iostream>
#include <sstream>

Vector3D::Vector3D( int32_t x, int32_t y, int32_t z )
    : x_ { x }, y_ { y }, z_ { z } {}

void Vector3D::Display( ) const { std::cout << ToString( ) << std::endl; }

std::string Vector3D::ToString( ) const {
  std::stringstream ss;
  ss << "( " << x_ << " : " << y_ << " : " << z_ << " )";
  return ss.str( );
}

Vector3D& Vector3D::operator+=( const Vector3D& rhs ) {
  x_ += rhs.x_;
  y_ += rhs.y_;
  z_ += rhs.z_;
  return *this;
}

Vector3D& Vector3D::operator-=( const Vector3D& rhs ) {
  x_ -= rhs.x_;
  y_ -= rhs.y_;
  z_ -= rhs.z_;
  return *this;
}

Vector3D& Vector3D::operator*=( const Vector3D& rhs ) {
  x_ = y_ * rhs.z_ - z_ * rhs.y_;
  y_ = z_ * rhs.x_ - x_ * rhs.z_;
  z_ = x_ * rhs.y_ - y_ * rhs.x_;
  return *this;
}

Vector3D& Vector3D::operator*=( int32_t scalar ) {
  x_ *= scalar;
  y_ *= scalar;
  z_ *= scalar;
  return *this;
}

int64_t Vector3D::Scalar( const Vector3D& b ) const {
  return x_ * b.x_ + y_ * b.y_ + z_ * b.z_;
}

double Vector3D::Lenth( ) const {
  return std::sqrt( x_ * x_ + y_ * y_ + z_ * z_ );
}

Vector3D operator+( const Vector3D& lhs, const Vector3D& rhs ) {
  Vector3D loc = lhs;
  loc += rhs;
  return loc;
}
Vector3D operator-( const Vector3D& lhs, const Vector3D& rhs ) {
  Vector3D loc = lhs;
  loc -= rhs;
  return loc;
}
Vector3D operator*( const Vector3D& lhs, const Vector3D& rhs ) {
  Vector3D loc = lhs;
  loc *= rhs;
  return loc;
}
Vector3D operator*( const Vector3D& lhs, int32_t scalar ) {
  Vector3D loc = lhs;
  loc *= scalar;
  return loc;
}
Vector3D operator*( int32_t scalar, const Vector3D& rhs ) {
  Vector3D loc = rhs;
  loc *= scalar;
  return loc;
}

bool operator==( const Vector3D& lhs, const Vector3D& rhs ) {
  return ( lhs.x_ == rhs.x_ ) && ( lhs.y_ == rhs.y_ ) && ( lhs.z_ == rhs.z_ );
}
bool operator!=( const Vector3D& lhs, const Vector3D& rhs ) {
  return !( lhs == rhs );
}
bool operator>( const Vector3D& lhs, const Vector3D& rhs ) {
  return !( lhs <= rhs );
}
bool operator>=( const Vector3D& lhs, const Vector3D& rhs ) {
  return lhs > rhs || lhs == rhs;
}
bool operator<( const Vector3D& lhs, const Vector3D& rhs ) {
  return lhs.Lenth( ) < rhs.Lenth( );
}
bool operator<=( const Vector3D& lhs, const Vector3D& rhs ) {
  return lhs < rhs || lhs == rhs;
}
