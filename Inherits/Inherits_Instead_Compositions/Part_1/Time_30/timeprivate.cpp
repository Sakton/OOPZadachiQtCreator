#include "timeprivate.h"

#include <iostream>

TimePrivate::TimePrivate( int16_t h, int16_t m, int16_t s )
    : BaseTime( h, m, s ) {}

TimePrivate::TimePrivate( const std::string& dt ) : BaseTime( dt ) {}

TimePrivate::TimePrivate( int32_t sec ) : BaseTime( sec ) {}

TimePrivate operator-( const TimePrivate& other, int32_t sec ) {
  if ( other.ToSecond( ) + sec < TimePrivate::SEC_IN_DAY ) {
    std::cout << "ERROR SUB SEC";
    exit( 1 );
  }
  return TimePrivate( other.ToSecond( ) - sec );
}

int32_t operator-( const TimePrivate& t1, const TimePrivate& t2 ) {
  return std::abs( t1.ToMinut( ) - t2.ToMinut( ) );
}
TimePrivate operator+( const TimePrivate& other, int32_t sec ) {
  if ( other.ToSecond( ) + sec > TimePrivate::SEC_IN_DAY ) {
    std::cout << "ERROR ADD SEC";
    exit( 1 );
  }
  return TimePrivate( ( other.ToSecond( ) + sec ) );
}

TimePrivate operator+( int32_t sec, const TimePrivate& other ) {
  if ( other.ToSecond( ) + sec > TimePrivate::SEC_IN_DAY ) {
    std::cout << "ERROR ADD SEC";
    exit( 1 );
  }
  return TimePrivate( ( other.ToSecond( ) + sec ) );
}

bool operator==( const TimePrivate& t1, const TimePrivate& t2 ) {
  return t1.ToSecond( ) == t2.ToSecond( );
}
bool operator<( const TimePrivate& t1, const TimePrivate& t2 ) {
  return t1.ToSecond( ) < t2.ToSecond( );
}
bool operator>( const TimePrivate& t1, const TimePrivate& t2 ) {
  return !( t1 < t2 );
}

// VS ошибок не выдает
std::string ToString( const TimePrivate& tp ) {
  return ::ToString( static_cast< const BaseTime& >( tp ) );
}

void Display( const TimePrivate& tp ) {
  return ::Display( static_cast< const BaseTime& >( tp ) );
}
