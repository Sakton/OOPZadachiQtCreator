#include "time30b.h"
#include <iostream>
#include <regex>
#include <sstream>

void Time30B::Init( int16_t h, int16_t m, int16_t s )
{
    if ( !( 0 <= h && h < 24 ) || !( 0 <= m && m < 60 ) || !( 0 <= s && s < 60 ) ) {
	std::cout << "ERROR INIT ARG";
	exit( 1 );
    }
    h_ = h;
    m_ = m;
    s_ = s;
}

void Time30B::Init( const std::string & dt )
{
    std::regex reg( R"("(\d{2}):(\d{2}):(\d{2}))" );
    std::smatch res;
    if ( !std::regex_match( dt, res, reg ) ) {
	std::cout << "ERROR STR INIT ARG";
	exit( 1 );
    }
    Init( std::stoi( res[ 1 ] ), std::stoi( res[ 2 ] ), std::stoi( res[ 3 ] ) );
}

void Time30B::Init( int32_t sec )
{
    Init( ToTime( sec ) );
}

void Time30B::Init( const Time30B & dt )
{
    Init( dt.h_, dt.m_, dt.s_ );
}

void Time30B::Display( ) const
{
    std::cout << ToString( );
}

std::string Time30B::ToString( ) const
{
    std::stringstream ss;
    ss << "\"";
    if ( h_ < 10 )
	ss << '0';
    ss << h_ << ":";
    if ( m_ < 10 )
	ss << '0';
    ss << m_ << ":";
    if ( s_ < 10 )
	ss << '0';
    ss << s_ << "\"";
    return ss.str( );
}

int32_t Time30B::DeltaMoment( const Time30B & other ) const
{
    return std::abs( ToMinut( ) - other.ToMinut( ) );
}

Time30B Time30B::AddSec( int32_t sec ) const
{
    if ( ToSecond( ) + sec > SEC_IN_DAY ) {
	std::cout << "ERROR ADD SEC";
	exit( 1 );
    }
    return ToTime( ToSecond( ) + sec );
}

Time30B Time30B::SubSec( int32_t sec ) const
{
    if ( ToSecond( ) + sec < SEC_IN_DAY ) {
	std::cout << "ERROR SUB SEC";
	exit( 1 );
    }
    return ToTime( ToSecond( ) - sec );
}

bool Time30B::Eq( const Time30B & other )
{
    return ToSecond( ) == other.ToSecond( );
}

bool Time30B::Less( const Time30B & other )
{
    return ToSecond( ) < other.ToSecond( );
}

bool Time30B::Great( const Time30B & other )
{
    return !Less( other );
}

int32_t Time30B::ToSecond( ) const
{
    return ( h_ * 60 + m_ ) * 60 + s_;
}

int32_t Time30B::ToMinut( ) const
{
    //округлить вверх, кастуем в дабл + 0,5 кастуем обратно в инт
    return ( s_ > 30 ) ? m_ + 1 : m_;
}

Time30B Time30B::ToTime( int32_t sec ) const
{
    Time30B loc;
    if ( sec > SEC_IN_DAY ) {
	std::cout << "ERROR SEC";
	exit( 1 );
    }
    loc.Init( ( sec / 3600 ) % 24, ( sec / 60 ) % 60, sec % 60 );
    return loc;
}
