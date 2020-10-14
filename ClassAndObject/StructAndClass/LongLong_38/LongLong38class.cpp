#include "LongLong38class.h"
#include <cmath>

LongLong38::LongLong38( int64_t x )
    : m_juniorRart { 0 }
    , m_seniorPart { 0 }
    , m_negative { false }
{
    if ( x < 0 )
	m_negative = true;
    if ( m_negative ) {
	x = invertNegative64int( x );
    }
    std::pair< int32_t, uint32_t > t = toPair32bit( x );
    m_seniorPart = t.first;
    m_juniorRart = t.second;
}

LongLong38::LongLong38( const LongLong38 & other )
    : m_seniorPart { other.m_seniorPart }
    , m_juniorRart { other.m_juniorRart }
    , m_negative { other.m_negative }
{
}

LongLong38 & LongLong38::operator=( const LongLong38 & other )
{
    if ( this == &other )
	return *this;
    m_seniorPart = other.m_seniorPart;
    m_juniorRart = other.m_juniorRart;
    m_negative = other.m_negative;
    return *this;
}

LongLong38 & LongLong38::operator+=( const LongLong38 & ll )
{
    return ( *this = LongLong38( toInt64( ) + ll.toInt64( ) ) );
}

LongLong38 & LongLong38::operator-=( const LongLong38 & ll )
{
    return ( *this = LongLong38( toInt64( ) - ll.toInt64( ) ) );
}

LongLong38 & LongLong38::operator*=( const LongLong38 & ll )
{
    return ( *this = LongLong38( toInt64( ) * ll.toInt64( ) ) );
}

LongLong38 & LongLong38::operator/=( const LongLong38 & ll )
{
    return ( *this = LongLong38( toInt64( ) / ll.toInt64( ) ) );
}

int64_t LongLong38::toInt64( ) const
{
    return toInt64( m_seniorPart, m_juniorRart );
}

std::string LongLong38::ToString( ) const
{
    return std::to_string( toInt64( ) );
}

std::string LongLong38::printBinary64bit( int64_t num ) const
{
    uint64_t mask = std::pow( 2, 64 );
    std::string res;
    for ( int i = 0; i < 64; ++i ) {
	if ( num & mask ) {
	    res.push_back( '1' );
	} else {
	    res.push_back( '0' );
	}
	mask >>= 1;
    }
    return res;
}

std::string LongLong38::printBinary32bit( int32_t num ) const
{
    uint32_t mask = std::pow( 2, 32 );
    std::string res;
    for ( int i = 0; i < 32; ++i ) {
	if ( num & mask ) {
	    res.push_back( '1' );
	} else {
	    res.push_back( '0' );
	}
	mask >>= 1;
    }
    return res;
}

std::pair< int32_t, uint32_t > LongLong38::toPair32bit( int64_t x ) const
{
    std::pair< int32_t, int32_t > res;
    res.second = ( x & MASK_JUNIOR );
    x >>= 32;
    res.first = x;
    return res;
}

int64_t LongLong38::toInt64( std::pair< int32_t, uint32_t > num ) const
{
    return toInt64( num.first, num.second );
}

int64_t LongLong38::toInt64( int32_t senjorPart, int32_t junuiorPart ) const
{
    int64_t r = 0;
    r = senjorPart;
    r = ( r << 32 );
    r += junuiorPart;
    if ( m_negative ) {
	r = invertNegative64int( r );
    }
    return r;
}

int64_t LongLong38::invertNegative64int( int64_t negX ) const
{
    negX = ~negX;
    negX += 1;
    return negX;
}

LongLong38 operator+( const LongLong38 & lhs, const LongLong38 & rhs )
{
    LongLong38 loc = lhs;
    loc += rhs;
    return loc;
}

LongLong38 operator-( const LongLong38 & lhs, const LongLong38 & rhs )
{
    LongLong38 loc = lhs;
    loc -= rhs;
    return loc;
}

LongLong38 operator*( const LongLong38 & lhs, const LongLong38 & rhs )
{
    LongLong38 loc = lhs;
    loc *= rhs;
    return loc;
}

LongLong38 operator/( const LongLong38 & lhs, const LongLong38 & rhs )
{
    LongLong38 loc = lhs;
    loc /= rhs;
    return loc;
}

std::ostream & operator<<( std::ostream & out, const LongLong38 & rhs )
{
    out << rhs.toInt64( );
    return out;
}
