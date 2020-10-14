#include "integer.h"

Integer::Integer( int x ) : x_ { x } {}

Integer &Integer::operator+=( const Number &oth ) {
  x_ += static_cast< const Integer & >( oth ).x_;
  return *this;
}

Integer &Integer::operator-=( const Number &oth ) {
  x_ -= static_cast< const Integer & >( oth ).x_;
  return *this;
}

Integer &Integer::operator*=( const Number &oth ) {
  x_ *= static_cast< const Integer & >( oth ).x_;
  return *this;
}

Integer &Integer::operator/=( const Number &oth ) {
  x_ /= static_cast< const Integer & >( oth ).x_;
  return *this;
}

std::ostream &operator<<( std::ostream &out, const Integer &val ) {
  out << val.x_;
  return out;
}
