#include "rationalprivate.h"

RationalPrivate::RationalPrivate( int32_t x, int16_t y )
    : BaseRational( x, y ) {}

RationalPrivate& RationalPrivate::operator+=( const RationalPrivate& rt ) {
  setChis( chis( ) * rt.znam( ) + znam( ) * rt.chis( ) );
  setZnam( znam( ) * rt.znam( ) );
  reduce( );
  return *this;
}

RationalPrivate& RationalPrivate::operator-=( const RationalPrivate& rt ) {
  setChis( chis( ) * rt.znam( ) - znam( ) * rt.chis( ) );
  setZnam( znam( ) * rt.znam( ) );
  reduce( );
  return *this;
}

RationalPrivate& RationalPrivate::operator*=( const RationalPrivate& rt ) {
  setChis( chis( ) * rt.chis( ) );
  setZnam( znam( ) * rt.znam( ) );
  reduce( );
  return *this;
}

RationalPrivate& RationalPrivate::operator/=( const RationalPrivate& rt ) {
  setChis( chis( ) * rt.znam( ) );
  setZnam( znam( ) * rt.chis( ) );
  reduce( );
  return *this;
}

RationalPrivate operator+( const RationalPrivate& rt1,
                           const RationalPrivate& rt2 ) {
  RationalPrivate loc = rt1;
  loc += rt2;
  return loc;
}
RationalPrivate operator-( const RationalPrivate& rt1,
                           const RationalPrivate& rt2 ) {
  RationalPrivate loc = rt1;
  loc -= rt2;
  return loc;
}
RationalPrivate operator*( const RationalPrivate& rt1,
                           const RationalPrivate& rt2 ) {
  RationalPrivate loc = rt1;
  loc *= rt2;
  return loc;
}
RationalPrivate operator/( const RationalPrivate& rt1,
                           const RationalPrivate& rt2 ) {
  RationalPrivate loc = rt1;
  loc /= rt2;
  return loc;
}

bool operator<( const RationalPrivate& rt1, const RationalPrivate& rt2 ) {
  return ( rt1.chis( ) * rt2.znam( ) < rt1.znam( ) * rt2.chis( ) );
}

bool operator<=( const RationalPrivate& rt1, const RationalPrivate& rt2 ) {
  return rt1 == rt2 || rt1 < rt2;
}

bool operator>( const RationalPrivate& rt1, const RationalPrivate& rt2 ) {
  return !( rt1 <= rt2 );
}

bool operator>=( const RationalPrivate& rt1, const RationalPrivate& rt2 ) {
  return rt1 > rt2 || rt1 == rt2;
}

bool operator==( const RationalPrivate& rt1, const RationalPrivate& rt2 ) {
  return ( rt1.chis( ) * rt2.znam( ) == rt1.znam( ) * rt2.chis( ) );
}

bool operator!=( const RationalPrivate& rt1, const RationalPrivate& rt2 ) {
  return !( rt1 == rt2 );
}

void Display( const RationalPrivate& rp ) {
  return ::Display( static_cast< const BaseRational& >( rp ) );
}

std::string ToString( const RationalPrivate& rp ) {
  return ::ToString( static_cast< const BaseRational& >( rp ) );
}
