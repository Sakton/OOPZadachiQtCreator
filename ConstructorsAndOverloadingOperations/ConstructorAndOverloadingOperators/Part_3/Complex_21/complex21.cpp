#include "complex21.h"

#include <iomanip>
#include <sstream>

Complex21::Complex21( double a, double b ) : data_( a, b ) {}

Complex21& Complex21::operator+=( const Complex21& oth ) {
  data_.setA( data_.a( ) + oth.data_.a( ) );
  data_.setB( data_.b( ) + oth.data_.b( ) );
  return *this;
}

Complex21& Complex21::operator-=( const Complex21& oth ) {
  data_.setA( data_.a( ) - oth.data_.a( ) );
  data_.setB( data_.b( ) - oth.data_.b( ) );
  return *this;
}

Complex21& Complex21::operator*=( const Complex21& oth ) {
  a_ = a_ * oth.a_ - b_ * oth.b_;
  b_ = a_ * oth.b_ + b_ * oth.a_;
  return *this;
}

Complex21& Complex21::operator/=( const Complex21& oth ) {
  a_ = ( a_ * oth.a_ + b_ * oth.b_ ) / ( oth.a_ * oth.a_ + oth.b_ * oth.b_ );
  b_ = ( b_ * oth.a_ - b_ * oth.b_ ) / ( oth.a_ * oth.a_ + oth.b_ * oth.b_ );
  return *this;
}

Complex21& Complex21::operator-( ) {
  b_ = -b_;
  return *this;
}

Complex21 operator+( const Complex21& lhs, const Complex21& rhs ) {
  Complex21 loc = lhs;
  loc += rhs;
  return loc;
}
Complex21 operator-( const Complex21& lhs, const Complex21& rhs ) {
  Complex21 loc = lhs;
  loc -= rhs;
  return loc;
}
Complex21 operator/( const Complex21& lhs, const Complex21& rhs ) {
  Complex21 loc = lhs;
  loc *= rhs;
  return loc;
}
Complex21 operator*( const Complex21& lhs, const Complex21& rhs ) {
  Complex21 loc = lhs;
  loc /= rhs;
  return loc;
}

PairCmplx::PairCmplx( double a, double b ) : a_ { a }, b_ { b } {}

double PairCmplx::a( ) const { return a_; }

void PairCmplx::setA( double a ) { a_ = a; }

double PairCmplx::b( ) const { return b_; }

void PairCmplx::setB( double b ) { b_ = b; }

PairCmplx::operator std::string( ) {
  std::stringstream ss;
  ss << std::fixed << std::setprecision( 2 );
  ss << a_ << " + " << b_ << "i";
  return ss.str( );
}
