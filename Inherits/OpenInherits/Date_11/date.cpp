#include "date.h"

Date::Date( int day, int mon, int year ) {
  setA( day );
  setB( mon );
  setC( year );
}

bool operator<( const Date& d_a, const Date& d_b ) {
  return ( static_cast< const Triad& >( d_a ) <
           static_cast< const Triad& >( d_b ) );
}

bool operator<=( const Date& d_a, const Date& d_b ) {
  return d_a < d_b || d_a == d_b;
}

bool operator>=( const Date& d_a, const Date& d_b ) {
  return d_a > d_b || d_a == d_b;
}

bool operator>( const Date& d_a, const Date& d_b ) { return !( d_a <= d_b ); }

bool operator==( const Date& d_a, const Date& d_b ) {
  return ( static_cast< const Triad& >( d_a ) ==
           static_cast< const Triad& >( d_b ) );
}

bool operator!=( const Date& d_a, const Date& d_b ) { return !( d_a == d_b ); }
