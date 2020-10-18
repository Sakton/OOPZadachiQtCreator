#include "time30.h"

#include <iostream>
#include <regex>
#include <sstream>

Time30::Time30( int16_t h, int16_t m, int16_t s )
    : h_ { 0 }, m_ { 0 }, s_ { 0 } {
  if ( !( 0 <= h && h < 24 ) || !( 0 <= m && m < 60 ) ||
       !( 0 <= s && s < 60 ) ) {
    std::cout << "ERROR INIT ARG";
    exit( 1 );
  }
  h_ = h;
  m_ = m;
  s_ = s;
}

Time30::Time30( const std::string& dt ) {
  std::regex reg( R"("(\d{2}):(\d{2}):(\d{2}))" );
  std::smatch res;
  if ( !std::regex_match( dt, res, reg ) ) {
    std::cout << "ERROR STR INIT ARG";
    exit( 1 );
  }
  *this = Time30( std::stoi( res[ 1 ] ), std::stoi( res[ 2 ] ),
                  std::stoi( res[ 3 ] ) );
}

Time30::Time30( int32_t sec ) : Time30( ToTime( sec ) ) {}

Time30::Time30( const Time30& dt ) : Time30( dt.h_, dt.m_, dt.s_ ) {}

void Display( const Time30& dt ) {
  std::cout << static_cast< std::string >( dt ) << std::endl;
}

Time30::operator std::string( ) const {
  std::stringstream ss;
  ss << "\"";
  if ( h_ < 10 ) ss << '0';
  ss << h_ << ":";
  if ( m_ < 10 ) ss << '0';
  ss << m_ << ":";
  if ( s_ < 10 ) ss << '0';
  ss << s_ << "\"";
  return ss.str( );
}

int32_t operator-( const Time30& t1, const Time30& t2 ) {
  return std::abs( ToMinut( t1 ) - ToMinut( t2 ) );
}

Time30 operator+( const Time30& other, int32_t sec ) {
  if ( ToSecond( other ) + sec > Time30::SEC_IN_DAY ) {
    std::cout << "ERROR ADD SEC";
    exit( 1 );
  }
  return Time30( ( ToSecond( other ) + sec ) );
}

Time30 operator+( int32_t sec, const Time30& other ) {
  if ( ToSecond( other ) + sec > Time30::SEC_IN_DAY ) {
    std::cout << "ERROR ADD SEC";
    exit( 1 );
  }
  return Time30( ( ToSecond( other ) + sec ) );
}

Time30 operator-( const Time30& other, int32_t sec ) {
  if ( ToSecond( other ) + sec < Time30::SEC_IN_DAY ) {
    std::cout << "ERROR SUB SEC";
    exit( 1 );
  }
  return Time30( ToSecond( other ) - sec );
}

bool operator==( const Time30& t1, const Time30& t2 ) {
  return ToSecond( t1 ) == ToSecond( t2 );
}

bool operator<( const Time30& t1, const Time30& t2 ) {
  return ToSecond( t1 ) < ToSecond( t2 );
}

bool operator>( const Time30& t1, const Time30& t2 ) { return !( t1 < t2 ); }

int32_t ToSecond( const Time30& t1 ) {
  return ( t1.h_ * 60 + t1.m_ ) * 60 + t1.s_;
}

int32_t ToMinut( const Time30& t1 ) {
  //округлить вверх, кастуем в дабл + 0,5 кастуем обратно в инт
  return ( t1.s_ > 30 ) ? t1.m_ + 1 : t1.m_;
}

Time30 Time30::ToTime( int32_t sec ) {
  if ( sec > Time30::SEC_IN_DAY ) {
    std::cout << "ERROR SEC";
    exit( 1 );
  }
  return Time30( ( sec / 3600 ) % 24, ( sec / 60 ) % 60, sec % 60 );
}
