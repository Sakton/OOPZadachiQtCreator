//#include "time30.h"

//#include <iostream>
//#include <regex>
//#include <sstream>

// Time30::Time30( int16_t h, int16_t m, int16_t s )
//    : h_ { 0 }, m_ { 0 }, s_ { 0 } {
//  if ( !( 0 <= h && h < 24 ) || !( 0 <= m && m < 60 ) ||
//       !( 0 <= s && s < 60 ) ) {
//    std::cout << "ERROR INIT ARG";
//    exit( 1 );
//  }
//  h_ = h;
//  m_ = m;
//  s_ = s;
//}

// Time30::Time30( const std::string& dt ) {
//  std::regex reg( R"("(\d{2}):(\d{2}):(\d{2}))" );
//  std::smatch res;
//  if ( !std::regex_match( dt, res, reg ) ) {
//    std::cout << "ERROR STR INIT ARG";
//    exit( 1 );
//  }
//  *this = Time30( std::stoi( res[ 1 ] ), std::stoi( res[ 2 ] ),
//                  std::stoi( res[ 3 ] ) );
//}

// Time30::Time30( const Time30& dt ) : Time30( dt.h_, dt.m_, dt.s_ ) {}

// void Time30::Display( ) const {
//  std::cout << static_cast< std::string >( *this ) << std::endl;
//}

// Time30::operator std::string( ) const {
//  std::stringstream ss;
//  ss << "\"";
//  if ( h_ < 10 ) ss << '0';
//  ss << h_ << ":";
//  if ( m_ < 10 ) ss << '0';
//  ss << m_ << ":";
//  if ( s_ < 10 ) ss << '0';
//  ss << s_ << "\"";
//  return ss.str( );
//}

// int32_t operator-( const Time30& t1, const Time30& t2 ) {
//  return std::abs( t1.ToMinut( ) - t2.ToMinut( ) );
//}

// Time30 operator+( const Time30& other, int32_t sec ) {
//  if ( other.ToSecond( ) + sec > Time30::SEC_IN_DAY ) {
//    std::cout << "ERROR ADD SEC";
//    exit( 1 );
//  }
//  return Time30( ( other.ToSecond( ) + sec ) );
//}

// Time30 operator+( int32_t sec, const Time30& other ) {
//  if ( other.ToSecond( ) + sec > Time30::SEC_IN_DAY ) {
//    std::cout << "ERROR ADD SEC";
//    exit( 1 );
//  }
//  return Time30( ( other.ToSecond( ) + sec ) );
//}

// Time30 operator-( const Time30& other, int32_t sec ) {
//  if ( other.ToSecond( ) + sec < Time30::SEC_IN_DAY ) {
//    std::cout << "ERROR SUB SEC";
//    exit( 1 );
//  }
//  return Time30( other.ToSecond( ) - sec );
//}

// bool operator==( const Time30& t1, const Time30& t2 ) {
//  return t1.ToSecond( ) == t2.ToSecond( );
//}

// bool operator<( const Time30& t1, const Time30& t2 ) {
//  return t1.ToSecond( ) < t2.ToSecond( );
//}

// bool operator>( const Time30& t1, const Time30& t2 ) { return !( t1 < t2 ); }

// int32_t Time30::ToSecond( ) const { return ( h_ * 60 + m_ ) * 60 + s_; }

// int32_t Time30::ToMinut( ) const {
//  //округлить вверх, кастуем в дабл + 0,5 кастуем обратно в инт
//  return ( s_ > 30 ) ? m_ + 1 : m_;
//}

// Time30 Time30::ToTime( int32_t sec ) const {
//  if ( sec > Time30::SEC_IN_DAY ) {
//    std::cout << "ERROR SEC";
//    exit( 1 );
//  }
//  return Time30( ( sec / 3600 ) % 24, ( sec / 60 ) % 60, sec % 60 );
//}
