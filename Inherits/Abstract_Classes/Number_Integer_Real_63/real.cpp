#include "real.h"

Real::Real( double x ) : x_ { x } {}

Real &Real::operator+=( const Number &oth ) {
  x_ += static_cast< const Real & >( oth ).x_;
  return *this;
}

Real &Real::operator-=( const Number &oth ) {
  x_ -= static_cast< const Real & >( oth ).x_;
  return *this;
}

Real &Real::operator*=( const Number &oth ) {
  x_ *= static_cast< const Real & >( oth ).x_;
  return *this;
}

Real &Real::operator/=( const Number &oth ) {
  x_ /= static_cast< const Real & >( oth ).x_;
  return *this;
}

std::ostream &operator<<( std::ostream &out, const Real &val ) {
  out << val.x_;
  return out;
}
