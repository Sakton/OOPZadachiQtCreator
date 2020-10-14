#include "number.h"

Number1::Number1( double x ) : x_ { x } {}

Number1 &Number1::operator*=( const Number1 &num ) {
  x_ *= num.x_;
  return *this;
}

std::ostream &Number1::Show( std::ostream &out ) const {
  out << x_;
  return out;
}

double Number1::X( ) const { return x_; }

Number1 &Number1::operator-=( const Number1 &num ) {
  x_ -= num.x_;
  return *this;
}
