#include "fuzzupublic.h"

FuzzuPublic::FuzzuPublic( double e1, double x, double e2 )
    : BaseFuzzy( e1, x, e2 ) {}

FuzzuPublic& FuzzuPublic::operator+=( const FuzzuPublic& fn ) {
  e1_ = x_ + fn.x_ - e1_ - fn.e1_;
  x_ = x_ + fn.x_;
  e2_ = x_ + fn.x_ - e2_ - fn.e2_;
  return *this;
}

FuzzuPublic& FuzzuPublic::operator-=( const FuzzuPublic& fn ) {
  e1_ = x_ - fn.x_ - e1_ - fn.e1_;
  x_ = x_ - fn.x_;
  e2_ = x_ + fn.x_ + e2_ + fn.e2_;
  return *this;
}

FuzzuPublic& FuzzuPublic::operator*=( const FuzzuPublic& fn ) {
  e1_ = x_ * fn.x_ - fn.x_ * e1_ - x_ * fn.e1_ + e1_ * fn.e1_;
  x_ *= fn.x_;
  e2_ = x_ * fn.x_ + fn.x_ * e2_ + x_ * fn.e2_ + e2_ * fn.e2_;
  return *this;
}

FuzzuPublic& FuzzuPublic::operator/=( const FuzzuPublic& fn ) {
  e1_ = ( x_ - e1_ ) / ( fn.x_ + fn.e2_ );
  x_ /= fn.x_;
  e2_ = ( x_ + e2_ ) / ( fn.x_ - fn.e2_ );
  return *this;
}

FuzzuPublic operator+( const FuzzuPublic& fn1, const FuzzuPublic& fn2 ) {
  FuzzuPublic loc = fn1;
  loc += fn2;
  return loc;
}
FuzzuPublic operator-( const FuzzuPublic& fn1, const FuzzuPublic& fn2 ) {
  FuzzuPublic loc = fn1;
  loc -= fn2;
  return loc;
}
FuzzuPublic operator*( const FuzzuPublic& fn1, const FuzzuPublic& fn2 ) {
  FuzzuPublic loc = fn1;
  loc *= fn2;
  return loc;
}
FuzzuPublic operator/( const FuzzuPublic& fn1, const FuzzuPublic& fn2 ) {
  FuzzuPublic loc = fn1;
  loc /= fn2;
  return loc;
}
