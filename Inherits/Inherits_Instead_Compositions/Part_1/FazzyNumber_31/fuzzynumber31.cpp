#include "fuzzynumber31.h"

#include <iostream>
#include <sstream>

FuzzyNumber31::FuzzyNumber31( double e1, double x, double e2 )
    : e1_ { e1 }, x_ { x }, e2_ { e2 } {}

FuzzyNumber31::operator std::string( ) const {
  std::stringstream ss;
  ss << "( " << x_ << "-" << std::abs( e1_ ) << ", " << x_ << ", " << x_ << "+"
     << std::abs( e1_ ) << " )";
  return ss.str( );
}

FuzzyNumber31 &FuzzyNumber31::operator+=( const FuzzyNumber31 &fn ) {
  e1_ = x_ + fn.x_ - e1_ - fn.e1_;
  x_ = x_ + fn.x_;
  e2_ = x_ + fn.x_ - e2_ - fn.e2_;
  return *this;
}

FuzzyNumber31 &FuzzyNumber31::operator-=( const FuzzyNumber31 &fn ) {
  e1_ = x_ - fn.x_ - e1_ - fn.e1_;
  x_ = x_ - fn.x_;
  e2_ = x_ + fn.x_ + e2_ + fn.e2_;
  return *this;
}

FuzzyNumber31 &FuzzyNumber31::operator*=( const FuzzyNumber31 &fn ) {
  e1_ = x_ * fn.x_ - fn.x_ * e1_ - x_ * fn.e1_ + e1_ * fn.e1_;
  x_ *= fn.x_;
  e2_ = x_ * fn.x_ + fn.x_ * e2_ + x_ * fn.e2_ + e2_ * fn.e2_;
  return *this;
}

FuzzyNumber31 &FuzzyNumber31::operator/=( const FuzzyNumber31 &fn ) {
  e1_ = ( x_ - e1_ ) / ( fn.x_ + fn.e2_ );
  x_ /= fn.x_;
  e2_ = ( x_ + e2_ ) / ( fn.x_ - fn.e2_ );
  return *this;
}

FuzzyNumber31 operator+( const FuzzyNumber31 &fn1, const FuzzyNumber31 &fn2 ) {
  FuzzyNumber31 loc = fn1;
  loc += fn2;
  return loc;
}

FuzzyNumber31 operator-( const FuzzyNumber31 &fn1, const FuzzyNumber31 &fn2 ) {
  FuzzyNumber31 loc = fn1;
  loc -= fn2;
  return loc;
}

FuzzyNumber31 operator*( const FuzzyNumber31 &fn1, const FuzzyNumber31 &fn2 ) {
  FuzzyNumber31 loc = fn1;
  loc *= fn2;
  return loc;
}

FuzzyNumber31 operator/( const FuzzyNumber31 &fn1, const FuzzyNumber31 &fn2 ) {
  FuzzyNumber31 loc = fn1;
  loc /= fn2;
  return loc;
}

void Display( const FuzzyNumber31 &fn ) {
  std::cout << static_cast< std::string >( fn ) << std::endl;
}
