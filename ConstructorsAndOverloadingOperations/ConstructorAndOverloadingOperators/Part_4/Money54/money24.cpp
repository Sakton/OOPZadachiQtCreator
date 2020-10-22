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
  //  std::stringstream ss;
  //  ss << std::fixed << rub << ",";
  //  int x = static_cast< int >( cop );
  //  if ( x < 10 ) ss << '0';
  //  ss << x;
  //  return ss.str( );
  return static_cast< std::string >( dengi_ );
}

Money24::Money24( int32_t rb, int16_t cp )
    : dengi_( LongLong38B( rb ), cp / 100.0 ) {
  if ( !( 0 <= cp && cp < 100 ) ) {
    std::cout << "ERROR DATA COP < 0";
    exit( 1 );
  }
  //  rub = rb;
  //  cop = cp;
}

Money24::Money24( double sum )
    : Money24( sum, ( sum - static_cast< int16_t >( sum ) ) * 100 ) {}

Money24& Money24::operator+=( const Money24& b ) {
  //  int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
  //  int64_t rurB =
  //      ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
  //  int64_t summ = rurA + rurB;
  //  rub = summ / 100;
  //  cop = std::abs( summ % 100 );
  //  return *this;
  dengi_ += b.dengi_;
  return *this;
}

Money24& Money24::operator-=( const Money24& b ) {
  //  int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
  //  int64_t rurB =
  //      ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
  //  int64_t divide = rurA - rurB;
  //  rub = divide / 100;
  //  cop = std::abs( divide % 100 );
  //  return *this;
  dengi_ -= b.dengi_;
  return *this;
}

Money24& Money24::operator*=( double x ) {
  //  int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
  //  int64_t mul = rurA * x;
  //  rub = mul / 100;
  //  cop = std::abs( mul % 100 );
  dengi_ *= Fraction35B( LongLong38B( x ),
                         ( x - static_cast< int16_t >( x ) ) * 10000 );
  return *this;
}

double Money24::operator/=( const Money24& b ) {
  //  int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
  //  int64_t rurB =
  //      ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
  //  if ( rurB == 0 ) {
  //    std::cout << "ERROR DIVIDE ZERO!!!";
  //    exit( 1 );
  //  }

  return double( rurA ) / double( rurB );
}

Money24& Money24::operator/=( double x ) {
  if ( x == 0 ) {
    std::cout << "ERROR DIVIDE ZERO!!!";
    exit( 1 );
  }
  int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
  int64_t div = rurA / x;

  rub = div / 100;
  cop = std::abs( div % 100 );
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

int32_t Money24::GetRub( ) const { return rub; }

uint8_t Money24::GetCop( ) const { return cop; }
