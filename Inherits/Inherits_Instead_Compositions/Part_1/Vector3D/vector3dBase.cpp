#include "vector3dBase.h"

#include <iostream>
#include <sstream>

Vector3DBase::Vector3DBase( int32_t x, int32_t y, int32_t z )
    : x_ { x }, y_ { y }, z_ { z } {}

std::string Vector3DBase::ToString( ) const {
  std::stringstream ss;
  ss << "( " << x_ << " : " << y_ << " : " << z_ << " )";
  return ss.str( );
}

int32_t Vector3DBase::x( ) const { return x_; }

void Vector3DBase::setX( const int32_t &x ) { x_ = x; }

int32_t Vector3DBase::y( ) const { return y_; }

void Vector3DBase::setY( const int32_t &y ) { y_ = y; }

int32_t Vector3DBase::z( ) const { return z_; }

void Vector3DBase::setZ( const int32_t &z ) { z_ = z; }

void Display( const Vector3DBase &vc ) {
  std::cout << vc.ToString( ) << std::endl;
}
