#include "basetime.h"

#include <iostream>
#include <regex>
#include <sstream>

BaseTime::BaseTime( int16_t h, int16_t m, int16_t s )
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

BaseTime::BaseTime( const std::string& dt ) {
  std::regex reg( R"("(\d{2}):(\d{2}):(\d{2}))" );
  std::smatch res;
  if ( !std::regex_match( dt, res, reg ) ) {
    std::cout << "ERROR STR INIT ARG";
    exit( 1 );
  }
  *this = BaseTime( std::stoi( res[ 1 ] ), std::stoi( res[ 2 ] ),
                    std::stoi( res[ 3 ] ) );
}

BaseTime::BaseTime( int32_t sec ) : BaseTime( ToTime( sec ) ) {}

BaseTime BaseTime::ToTime( int32_t sec ) const {
  if ( sec > BaseTime::SEC_IN_DAY ) {
    std::cout << "ERROR SEC";
    exit( 1 );
  }
  return BaseTime( ( sec / 3600 ) % 24, ( sec / 60 ) % 60, sec % 60 );
}

int32_t BaseTime::ToSecond( ) const { return ( h_ * 60 + m_ ) * 60 + s_; }

int32_t BaseTime::ToMinut( ) const { return ( s_ > 30 ) ? m_ + 1 : m_; }

void Display( const BaseTime& dt ) { std::cout << ToString( dt ) << std::endl; }

std::string ToString( const BaseTime& dt ) {
  std::stringstream ss;
  ss << "\"";
  if ( dt.h_ < 10 ) ss << '0';
  ss << dt.h_ << ":";
  if ( dt.m_ < 10 ) ss << '0';
  ss << dt.m_ << ":";
  if ( dt.s_ < 10 ) ss << '0';
  ss << dt.s_ << "\"";
  return ss.str( );
}
