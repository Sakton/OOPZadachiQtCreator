#include "timepublic.h"

#include <iostream>

TimePublic::TimePublic( int16_t h, int16_t m, int16_t s )
    : BaseTime( h, m, s ) {}

TimePublic::TimePublic( const std::string& dt ) : BaseTime( dt ) {}

TimePublic::TimePublic( int32_t sec ) : BaseTime( sec ) {}

TimePublic operator-( const TimePublic& other, int32_t sec ) {
  if ( other.ToSecond( ) + sec < TimePublic::SEC_IN_DAY ) {
    std::cout << "ERROR SUB SEC";
    exit( 1 );
  }
  return TimePublic( other.ToSecond( ) - sec );
}

int32_t operator-( const TimePublic& t1, const TimePublic& t2 ) {
  return std::abs( t1.ToMinut( ) - t2.ToMinut( ) );
}
TimePublic operator+( const TimePublic& other, int32_t sec ) {
  if ( other.ToSecond( ) + sec > TimePublic::SEC_IN_DAY ) {
    std::cout << "ERROR ADD SEC";
    exit( 1 );
  }
  return TimePublic( ( other.ToSecond( ) + sec ) );
}

TimePublic operator+( int32_t sec, const TimePublic& other ) {
  if ( other.ToSecond( ) + sec > TimePublic::SEC_IN_DAY ) {
    std::cout << "ERROR ADD SEC";
    exit( 1 );
  }
  return TimePublic( ( other.ToSecond( ) + sec ) );
}

bool operator==( const TimePublic& t1, const TimePublic& t2 ) {
  return t1.ToSecond( ) == t2.ToSecond( );
}
bool operator<( const TimePublic& t1, const TimePublic& t2 ) {
  return t1.ToSecond( ) < t2.ToSecond( );
}
bool operator>( const TimePublic& t1, const TimePublic& t2 ) {
  return !( t1 < t2 );
}
