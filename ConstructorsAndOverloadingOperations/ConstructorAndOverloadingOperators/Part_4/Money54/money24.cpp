#include "money24.h"

#include <iostream>
#include <sstream>

void Money24::Display( ) {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

Money24::operator double( ) const { return static_cast< double >( dengi_ ); }

void Read( Money24& b ) {
  int32_t aa = 0;
  int16_t bb = 0;
  std::cout << "Enter rub cop" << std::endl;
  std::cin >> aa >> bb;
  b = Money24( aa, bb );
}

Money24::operator std::string( ) const {
  return static_cast< std::string >( dengi_ );
}

Money24::Money24( int32_t rb, int16_t cp )
    : dengi_( LongLong38B( rb ), cp * 100 ) {
  if ( !( 0 <= cp && cp < 100 ) ) {
    std::cout << "ERROR DATA COP < 0";
    exit( 1 );
  }
}

Money24::Money24( double sum )
    : Money24( sum, ( sum - static_cast< int16_t >( sum ) ) * 100 ) {}

Money24& Money24::operator+=( const Money24& b ) {
  dengi_ += b.dengi_;
  return *this;
}

Money24& Money24::operator-=( const Money24& b ) {
  dengi_ -= b.dengi_;
  return *this;
}

Money24& Money24::operator*=( double x ) {
  dengi_ *= Fraction35B( LongLong38B( x ),
                         ( x - static_cast< int16_t >( x ) ) * 10000 );
  return *this;
}

double Money24::operator/=( const Money24& b ) {
  return double( dengi_ ) / double( b.dengi_ );
}

Money24& Money24::operator/=( double x ) {
  double t = double( dengi_ ) / x;
  dengi_ = Fraction35B( LongLong38B( t ),
                        ( t - static_cast< int16_t >( t ) ) * 10000 );
  return *this;
}

Money24 operator+( const Money24& a, const Money24& b ) {
  Money24 loc = a;
  loc += b;
  return loc;
}

Money24 operator-( const Money24& a, const Money24& b ) {
  Money24 loc = a;
  loc -= b;
  return loc;
}

Money24 operator*( const Money24& a, double x ) {
  Money24 loc = a;
  loc *= x;
  return loc;
}

double operator/( const Money24& a, const Money24& b ) {
  Money24 loc = a;
  return loc /= b;
}

Money24 operator/( const Money24& a, double x ) {
  Money24 loc = a;
  loc /= x;
  return loc;
}

bool operator==( const Money24& a, const Money24& b ) {
  return ( a.dengi_ == b.dengi_ );
}
bool operator!=( const Money24& a, const Money24& b ) { return !( a == b ); }
bool operator<=( const Money24& a, const Money24& b ) {
  return ( a == b ) || ( a < b );
}
bool operator>=( const Money24& a, const Money24& b ) {
  return a > b || a == b;
}
bool operator<( const Money24& a, const Money24& b ) {
  return ( a.dengi_ < b.dengi_ );
}

bool operator>( const Money24& a, const Money24& b ) { return !( a <= b ); }

int64_t Money24::GetRub( ) const {
  return static_cast< int64_t >( dengi_.Whole( ) );
}

uint8_t Money24::GetCop( ) const { return dengi_.Fractional( ) / 100; }
