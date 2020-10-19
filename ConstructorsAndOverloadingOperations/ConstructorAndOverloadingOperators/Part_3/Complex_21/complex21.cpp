#include "complex21.h"

#include <iomanip>
#include <iostream>
#include <sstream>

Complex21::Complex21( double a, double b ) : data_( a, b ) {}

void Complex21::Display( ) const { ::Display( data_ ); }

Complex21::operator std::string( ) {
  return static_cast< std::string >( data_ );
}

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
  data_.setA( data_.a( ) * oth.data_.a( ) - data_.b( ) * oth.data_.b( ) );
  data_.setB( data_.a( ) * oth.data_.b( ) + data_.b( ) * oth.data_.a( ) );
  return *this;
}

Complex21& Complex21::operator/=( const Complex21& oth ) {
  data_.setA(
      ( data_.a( ) * oth.data_.a( ) + data_.b( ) * oth.data_.b( ) ) /
      ( oth.data_.a( ) * oth.data_.a( ) + oth.data_.b( ) * oth.data_.b( ) ) );
  data_.setB(
      ( data_.b( ) * oth.data_.a( ) - data_.b( ) * oth.data_.b( ) ) /
      ( oth.data_.a( ) * oth.data_.a( ) + oth.data_.b( ) * oth.data_.b( ) ) );
  return *this;
}

Complex21& Complex21::operator-( ) {
  data_.setB( -data_.b( ) );
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

PairCmplx::operator std::string( ) const {
  std::stringstream ss;
  ss << std::fixed << std::setprecision( 2 );
  ss << a_ << " + " << b_ << "i";
  return ss.str( );
}

void Display( const PairCmplx& pc ) {
  std::cout << static_cast< std::string >( pc ) << std::endl;
}
