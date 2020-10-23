#include "money24.h"

#include <iostream>
#include <sstream>

void Money24::Display( ) {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

Money24::operator double( ) const {
  return int64_t( rub ) + double( cop ) / 100.0;
}

void Read( Money24& b ) {
  int32_t aa = 0;
  int16_t bb = 0;
  std::cout << "Enter rub cop" << std::endl;
  std::cin >> aa >> bb;
  b = Money24( aa, bb );
}

Money24::operator std::string( ) const {
  std::stringstream ss;
  ss << std::fixed << static_cast< std::string >( rub ) << ",";
  int x = static_cast< int >( cop );
  if ( x < 10 ) ss << '0';
  ss << x;
  return ss.str( );
}

Money24::Money24( int32_t rb, int16_t cp ) {
  if ( !( 0 <= cp && cp < 100 ) ) {
    std::cout << "ERROR DATA COP < 0";
    exit( 1 );
  }
  rub = LongLong38B( rb );
  cop = cp;
}

Money24::Money24( double sum )
    : Money24( sum, ( sum - static_cast< int16_t >( sum ) ) * 100 ) {}

Money24& Money24::operator+=( const Money24& b ) {
  LongLong38B rurA =
      ( rub < LongLong38B( 0 ) ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
  LongLong38B rurB = ( b.rub < LongLong38B( 0 ) ) ? ( b.rub * 100 - b.cop )
                                                  : ( b.rub * 100 + b.cop );
  LongLong38B summ = rurA + rurB;
  rub = summ / 100;
  cop = std::abs( static_cast< int64_t >( summ ) % 100 );
  return *this;
}

Money24& Money24::operator-=( const Money24& b ) {
  LongLong38B rurA =
      ( rub < LongLong38B( 0 ) ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
  LongLong38B rurB = ( b.rub < LongLong38B( 0 ) ) ? ( b.rub * 100 - b.cop )
                                                  : ( b.rub * 100 + b.cop );
  LongLong38B divide = rurA - rurB;
  rub = divide / 100;
  cop = std::abs( static_cast< int64_t >( divide ) % 100 );
  return *this;
}

Money24& Money24::operator*=( double x ) {
  LongLong38B rurA =
      ( rub < LongLong38B( 0 ) ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
  LongLong38B mul = rurA * x;
  rub = mul / 100;
  cop = std::abs( static_cast< int64_t >( mul ) % 100 );
  return *this;
}

double Money24::operator/=( const Money24& b ) {
  LongLong38B rurA =
      ( rub < LongLong38B( 0 ) ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
  LongLong38B rurB = ( b.rub < LongLong38B( 0 ) ) ? ( b.rub * 100 - b.cop )
                                                  : ( b.rub * 100 + b.cop );
  if ( rurB == LongLong38B( 0 ) ) {
    std::cout << "ERROR DIVIDE ZERO!!!";
    exit( 1 );
  }
  return double( static_cast< int64_t >( rurA ) ) /
         double( static_cast< int64_t >( rurB ) );
}

Money24& Money24::operator/=( double x ) {
  if ( x == 0 ) {
    std::cout << "ERROR DIVIDE ZERO!!!";
    exit( 1 );
  }
  LongLong38B rurA =
      ( rub < LongLong38B( 0 ) ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
  LongLong38B div = rurA / x;

  rub = div / 100;
  cop = std::abs( static_cast< int64_t >( div ) % 100 );
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
  return ( a.rub == b.rub && a.cop == b.cop );
}
bool operator!=( const Money24& a, const Money24& b ) { return !( a == b ); }
bool operator<=( const Money24& a, const Money24& b ) {
  return ( a == b ) || ( a < b );
}
bool operator>=( const Money24& a, const Money24& b ) {
  return a > b || a == b;
}
bool operator<( const Money24& a, const Money24& b ) {
  return ( ( a.rub < b.rub ) || ( ( a.rub == b.rub ) && ( a.cop < b.cop ) ) );
}

bool operator>( const Money24& a, const Money24& b ) { return !( a <= b ); }

LongLong38B Money24::GetRub( ) const { return rub; }

uint8_t Money24::GetCop( ) const { return cop; }
