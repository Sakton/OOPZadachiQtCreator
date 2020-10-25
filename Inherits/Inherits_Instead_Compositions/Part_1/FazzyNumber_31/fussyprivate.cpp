#include "fussyprivate.h"

#include <iostream>
#include <sstream>

FussyPrivate::FussyPrivate( double e1, double x, double e2 )
    : BaseFuzzy( e1, x, e2 ) {}

FussyPrivate& FussyPrivate::operator+=( const FussyPrivate& fn ) {
  e1_ = x_ + fn.x_ - e1_ - fn.e1_;
  x_ = x_ + fn.x_;
  e2_ = x_ + fn.x_ - e2_ - fn.e2_;
  return *this;
}

FussyPrivate& FussyPrivate::operator-=( const FussyPrivate& fn ) {
  e1_ = x_ - fn.x_ - e1_ - fn.e1_;
  x_ = x_ - fn.x_;
  e2_ = x_ + fn.x_ + e2_ + fn.e2_;
  return *this;
}

FussyPrivate& FussyPrivate::operator*=( const FussyPrivate& fn ) {
  e1_ = x_ * fn.x_ - fn.x_ * e1_ - x_ * fn.e1_ + e1_ * fn.e1_;
  x_ *= fn.x_;
  e2_ = x_ * fn.x_ + fn.x_ * e2_ + x_ * fn.e2_ + e2_ * fn.e2_;
  return *this;
}

FussyPrivate& FussyPrivate::operator/=( const FussyPrivate& fn ) {
  e1_ = ( x_ - e1_ ) / ( fn.x_ + fn.e2_ );
  x_ /= fn.x_;
  e2_ = ( x_ + e2_ ) / ( fn.x_ - fn.e2_ );
  return *this;
}

FussyPrivate operator+( const FussyPrivate& fn1, const FussyPrivate& fn2 ) {
  FussyPrivate loc = fn1;
  loc += fn2;
  return loc;
}
FussyPrivate operator-( const FussyPrivate& fn1, const FussyPrivate& fn2 ) {
  FussyPrivate loc = fn1;
  loc -= fn2;
  return loc;
}
FussyPrivate operator*( const FussyPrivate& fn1, const FussyPrivate& fn2 ) {
  FussyPrivate loc = fn1;
  loc *= fn2;
  return loc;
}
FussyPrivate operator/( const FussyPrivate& fn1, const FussyPrivate& fn2 ) {
  FussyPrivate loc = fn1;
  loc /= fn2;
  return loc;
}

void Display( const FussyPrivate& fn ) {
  return ::Display( static_cast< const BaseFuzzy& >( fn ) );
}

std::string ToString( const FussyPrivate& fn ) {
  return ::ToString( static_cast< const BaseFuzzy& >( fn ) );
}
