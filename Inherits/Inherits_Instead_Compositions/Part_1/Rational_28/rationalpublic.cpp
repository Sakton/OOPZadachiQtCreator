#include "rationalpublic.h"

RationalPublic::RationalPublic(int32_t x, int16_t y):BaseRational(x, y)
{}

RationalPublic& RationalPublic::operator+=( const RationalPublic& rt ) {
  setChis( chis( ) * rt.znam( ) + znam( ) * rt.chis( ) );
  setZnam( znam( ) * rt.znam( ) );
  reduce( );
  return *this;
}

RationalPublic& RationalPublic::operator-=( const RationalPublic& rt ) {
  setChis( chis( ) * rt.znam( ) - znam( ) * rt.chis( ) );
  setZnam( znam( ) * rt.znam( ) );
  reduce( );
  return *this;
}

RationalPublic& RationalPublic::operator*=( const RationalPublic& rt ) {
  setChis( chis( ) * rt.chis( ) );
  setZnam( znam( ) * rt.znam( ) );
  reduce( );
  return *this;
}

RationalPublic& RationalPublic::operator/=( const RationalPublic& rt ) {
  setChis( chis( ) * rt.znam( ) );
  setZnam( znam( ) * rt.chis( ) );
  reduce( );
  return *this;
}

RationalPublic operator+( const RationalPublic& rt1,
                          const RationalPublic& rt2 ) {
  RationalPublic loc = rt1;
  loc += rt2;
  return loc;
}
RationalPublic operator-( const RationalPublic& rt1,
                          const RationalPublic& rt2 ) {
  RationalPublic loc = rt1;
  loc -= rt2;
  return loc;
}
RationalPublic operator*( const RationalPublic& rt1,
                          const RationalPublic& rt2 ) {
  RationalPublic loc = rt1;
  loc *= rt2;
  return loc;
}
RationalPublic operator/( const RationalPublic& rt1,
                          const RationalPublic& rt2 ) {
  RationalPublic loc = rt1;
  loc /= rt2;
  return loc;
}

bool operator<( const RationalPublic& rt1, const RationalPublic& rt2 ) {
  return ( rt1.chis( ) * rt2.znam( ) < rt1.znam( ) * rt2.chis( ) );
}

bool operator<=( const RationalPublic& rt1, const RationalPublic& rt2 ) {
  return rt1 == rt2 || rt1 < rt2;
}

bool operator>( const RationalPublic& rt1, const RationalPublic& rt2 ) {
  return !( rt1 <= rt2 );
}

bool operator>=( const RationalPublic& rt1, const RationalPublic& rt2 ) {
  return rt1 > rt2 || rt1 == rt2;
}

bool operator==( const RationalPublic& rt1, const RationalPublic& rt2 ) {
  return ( rt1.chis( ) * rt2.znam( ) == rt1.znam( ) * rt2.chis( ) );
}

bool operator!=( const RationalPublic& rt1, const RationalPublic& rt2 ) {
  return !( rt1 == rt2 );
}
