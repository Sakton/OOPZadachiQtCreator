//#include "longlong38b.h"

//#include <iostream>

// LongLong38B::LongLong38B( int64_t bits_64_num ) {
//  junior_ = bits_64_num & MASK_;
//  bits_64_num >>= 32;
//  senior_ = bits_64_num & MASK_;
//}

// void LongLong38B::Display( ) const {
//  std::cout << static_cast< std::string >( *this ) << std::endl;
//}

// LongLong38B::operator std::string( ) const {
//  return std::to_string( static_cast< int64_t >( *this ) );
//}

// LongLong38B::operator int64_t( ) const {
//  int64_t t = senior_;
//  t <<= 32;
//  t += junior_;
//  return t;
//}

// LongLong38B &LongLong38B::operator+=( const LongLong38B &b ) {
//  return *this = LongLong38B( static_cast< int64_t >( *this ) +
//                              static_cast< int64_t >( b ) );
//}

// LongLong38B &LongLong38B::operator+=( int32_t b ) {
//  return *this = LongLong38B( static_cast< int64_t >( *this ) + b );
//}

// LongLong38B &LongLong38B::operator-=( const LongLong38B &b ) {
//  return *this = LongLong38B( static_cast< int64_t >( *this ) -
//                              static_cast< int64_t >( b ) );
//}

// LongLong38B &LongLong38B::operator-=( int32_t b ) {
//  return *this = LongLong38B( static_cast< int64_t >( *this ) - b );
//}

// LongLong38B &LongLong38B::operator*=( const LongLong38B &b ) {
//  return *this = LongLong38B( static_cast< int64_t >( *this ) *
//                              static_cast< int64_t >( b ) );
//}

// LongLong38B &LongLong38B::operator*=( int32_t b ) {
//  return *this = LongLong38B( static_cast< int64_t >( *this ) * b );
//}

// LongLong38B &LongLong38B::operator/=( const LongLong38B &b ) {
//  if ( static_cast< int64_t >( b ) == 0 ) {
//    std::cout << "ERROR DIV ZERO";
//    exit( 1 );
//  }
//  return *this = LongLong38B( static_cast< int64_t >( *this ) /
//                              static_cast< int64_t >( b ) );
//}

// LongLong38B &LongLong38B::operator/=( int32_t b ) {
//  if ( b == 0 ) {
//    std::cout << "ERROR DIV ZERO";
//    exit( 1 );
//  }
//  return *this = LongLong38B( static_cast< int64_t >( *this ) / b );
//}

// LongLong38B LongLong38B::Modul( ) const {
//  LongLong38B loc = *this;
//  loc.senior_ = std::abs( loc.senior_ );
//  return loc;
//}

// LongLong38B operator+( const LongLong38B &b1, const LongLong38B &b2 ) {
//  LongLong38B loc = b1;
//  loc += b2;
//  return loc;
//}

// LongLong38B operator+( const LongLong38B &b1, int64_t x ) {
//  LongLong38B loc = b1;
//  loc += x;
//  return loc;
//}

// LongLong38B operator+( int64_t x, const LongLong38B &b1 ) {
//  LongLong38B loc = b1;
//  loc += x;
//  return loc;
//}

// LongLong38B operator-( const LongLong38B &b1, const LongLong38B &b2 ) {
//  LongLong38B loc = b1;
//  loc -= b2;
//  return loc;
//}

// LongLong38B operator-( const LongLong38B &b1, int64_t x ) {
//  LongLong38B loc = b1;
//  loc -= x;
//  return loc;
//}

// LongLong38B operator-( int64_t x, const LongLong38B &b1 ) {
//  LongLong38B loc = b1;
//  loc -= x;
//  return loc;
//}

// LongLong38B operator*( const LongLong38B &b1, const LongLong38B &b2 ) {
//  LongLong38B loc = b1;
//  loc *= b2;
//  return loc;
//}

// LongLong38B operator*( const LongLong38B &b1, int64_t x ) {
//  LongLong38B loc = b1;
//  loc *= x;
//  return loc;
//}

// LongLong38B operator*( int64_t x, const LongLong38B &b1 ) {
//  LongLong38B loc = b1;
//  loc *= x;
//  return loc;
//}

// LongLong38B operator/( const LongLong38B &b1, const LongLong38B &b2 ) {
//  LongLong38B loc = b1;
//  loc /= b2;
//  return loc;
//}

// LongLong38B operator/( const LongLong38B &b1, int64_t x ) {
//  LongLong38B loc = b1;
//  loc /= x;
//  return loc;
//}

// LongLong38B operator/( int64_t x, const LongLong38B &b1 ) {
//  LongLong38B loc = b1;
//  loc /= x;
//  return loc;
//}

// bool operator<( const LongLong38B &b1, const LongLong38B &b2 ) {
//  return static_cast< int64_t >( b1 ) < static_cast< int64_t >( b2 );
//}

// bool operator<=( const LongLong38B &b1, const LongLong38B &b2 ) {
//  return b1 < b2 || b1 == b2;
//}

// bool operator>=( const LongLong38B &b1, const LongLong38B &b2 ) {
//  return b1 > b2 || b1 == b2;
//}

// bool operator>( const LongLong38B &b1, const LongLong38B &b2 ) {
//  return !( b1 <= b2 );
//}

// bool operator==( const LongLong38B &b1, const LongLong38B &b2 ) {
//  return static_cast< int64_t >( b1 ) == static_cast< int64_t >( b2 );
//}

// bool operator!=( const LongLong38B &b1, const LongLong38B &b2 ) {
//  return !( b1 == b2 );
//}
