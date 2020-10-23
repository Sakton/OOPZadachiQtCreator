#include "rational28.h"

#include <iostream>

Rational28::Rational28( int32_t x, int16_t y ) : chis_ { 1 }, znam_ { 1 } {
  if ( y == 0 ) {
    std::cout << "ERROR DIV ZERO" << std::endl;
    exit( 1 );
  }
  if ( x < 0 && y < 0 ) {
    x = -x;
    y = -y;
  }
  chis_ = LongLong38B( x );
  znam_ = LongLong38B( y );
  reduce( *this );
}

Rational28& Rational28::operator+=( const Rational28& rt ) {
  chis_ = chis_ * rt.znam_ + znam_ * rt.chis_;
  znam_ = znam_ * rt.znam_;
  reduce( *this );
  return *this;
}

Rational28& Rational28::operator-=( const Rational28& rt ) {
  chis_ = chis_ * rt.znam_ - znam_ * rt.chis_;
  znam_ = znam_ * rt.znam_;
  reduce( *this );
  return *this;
}

Rational28& Rational28::operator*=( const Rational28& rt ) {
  chis_ = chis_ * rt.chis_;
  znam_ = znam_ * rt.znam_;
  reduce( *this );
  return *this;
}

Rational28& Rational28::operator/=( const Rational28& rt ) {
  chis_ = chis_ * rt.znam_;
  znam_ = znam_ * rt.chis_;
  reduce( *this );
  return *this;
}

void reduce( Rational28& rt ) {
  LongLong38B aa = rt.chis_.Modul( );
  LongLong38B bb = rt.znam_;

  while ( bb != LongLong38B( 0 ) ) {
    LongLong38B t = aa % bb;
    aa = bb;
    bb = t;
  }
  // NOD - in aa;
  rt.chis_ /= aa;
  rt.znam_ /= aa;
}

Rational28::operator std::string( ) const {
  return static_cast< std::string >( chis_ ) + "/" +
         static_cast< std::string >( znam_ );
}

void Display( const Rational28& rt ) {
  std::cout << static_cast< std::string >( rt ) << std::endl;
}

Rational28 operator+( const Rational28& rt1, const Rational28& rt2 ) {
  Rational28 loc = rt1;
  loc += rt2;
  return loc;
}
Rational28 operator-( const Rational28& rt1, const Rational28& rt2 ) {
  Rational28 loc = rt1;
  loc -= rt2;
  return loc;
}
Rational28 operator*( const Rational28& rt1, const Rational28& rt2 ) {
  Rational28 loc = rt1;
  loc *= rt2;
  return loc;
}
Rational28 operator/( const Rational28& rt1, const Rational28& rt2 ) {
  Rational28 loc = rt1;
  loc /= rt2;
  return loc;
}

bool operator<( const Rational28& rt1, const Rational28& rt2 ) {
  return ( rt1.chis_ * rt2.znam_ < rt1.znam_ * rt2.chis_ );
}
bool operator<=( const Rational28& rt1, const Rational28& rt2 ) {
  return rt1 == rt2 || rt1 < rt2;
}
bool operator>( const Rational28& rt1, const Rational28& rt2 ) {
  return !( rt1 <= rt2 );
}
bool operator>=( const Rational28& rt1, const Rational28& rt2 ) {
  return rt1 > rt2 || rt1 == rt2;
}
bool operator==( const Rational28& rt1, const Rational28& rt2 ) {
  return ( rt1.chis_ * rt2.znam_ == rt1.znam_ * rt2.chis_ );
}
bool operator!=( const Rational28& rt1, const Rational28& rt2 ) {
  return !( rt1 == rt2 );
}
