#include "longlong38b.h"
#include <iostream>

void LongLong38B::Init( int64_t bits_64_num )
{
    junior_ = bits_64_num & MASK_;
    bits_64_num >>= 32;
    senior_ = bits_64_num & MASK_;
}

void LongLong38B::Init( const LongLong38B & l )
{
    senior_ = l.senior_;
    junior_ = l.junior_;
}

void LongLong38B::Display( ) const
{
    std::cout << ToString( ) << std::endl;
}

std::string LongLong38B::ToString( ) const
{
    return std::to_string( ToInt64( ) );
}

LongLong38B & LongLong38B::AddSelf( const LongLong38B & b )
{
    Init( ToInt64( ) + b.ToInt64( ) );
    return *this;
}

LongLong38B & LongLong38B::AddSelf( int32_t b )
{
    Init( ToInt64( ) + b );
	return *this;
}

LongLong38B LongLong38B::Add( const LongLong38B & b ) const
{
    LongLong38B loc;
    loc.Init( *this );
    loc.AddSelf( b );
    return loc;
}

LongLong38B LongLong38B::Add( int32_t b ) const
{
    LongLong38B loc;
    loc.Init( *this );
    loc.AddSelf( b );
    return loc;
}

LongLong38B & LongLong38B::SubSelf( const LongLong38B & b )
{
    Init( ToInt64( ) - b.ToInt64( ) );
    return *this;
}

LongLong38B & LongLong38B::SubSelf( int32_t b )
{
    Init( ToInt64( ) - b );
    return *this;
}

LongLong38B LongLong38B::Sub( const LongLong38B & b ) const
{
    LongLong38B loc;
    loc.Init( *this );
    loc.SubSelf( b );
    return loc;
}

LongLong38B LongLong38B::Sub( int32_t b ) const
{
    LongLong38B loc;
    loc.Init( *this );
    loc.SubSelf( b );
    return loc;
}

LongLong38B & LongLong38B::MidSelf( const LongLong38B & b )
{
    Init( ToInt64( ) * b.ToInt64( ) );
    return *this;
}

LongLong38B & LongLong38B::MidSelf( int32_t b )
{
    Init( ToInt64( ) * b );
    return *this;
}

LongLong38B LongLong38B::Mid( const LongLong38B & b ) const
{
    LongLong38B loc;
    loc.Init( *this );
    loc.MidSelf( b );
    return loc;
}

LongLong38B LongLong38B::Mid( int32_t b ) const
{
    LongLong38B loc;
    loc.Init( *this );
    loc.MidSelf( b );
    return loc;
}

LongLong38B & LongLong38B::DivSelf( const LongLong38B & b )
{
    if ( b.ToInt64( ) == 0 ) {
	std::cout << "ERROR DIV ZERO";
	exit( 1 );
    }
    Init( ToInt64( ) / b.ToInt64( ) );
    return *this;
}

LongLong38B & LongLong38B::DivSelf( int32_t b )
{
    if ( b == 0 ) {
	std::cout << "ERROR DIV ZERO";
	exit( 1 );
    }
    Init( ToInt64( ) / b );
    return *this;
}

LongLong38B LongLong38B::Div( const LongLong38B & b ) const
{
    LongLong38B loc;
    loc.Init( *this );
    loc.DivSelf( b );
    return loc;
}

LongLong38B LongLong38B::Div( int32_t b ) const
{
    LongLong38B loc;
    loc.Init( *this );
    loc.DivSelf( b );
    return loc;
}

int64_t LongLong38B::ToInt64( ) const
{
    int64_t t = senior_;
    t <<= 32;
    t += junior_;
    return t;
}

bool LongLong38B::Eq( const LongLong38B & b ) const
{
    return ToInt64( ) == b.ToInt64( );
}

bool LongLong38B::Less( const LongLong38B & b ) const
{
    return ToInt64( ) < b.ToInt64( );
}

bool LongLong38B::Great( const LongLong38B & b ) const
{
    return ToInt64( ) > b.ToInt64( );
}

bool LongLong38B::NotEq( const LongLong38B & b ) const
{
    return !Eq( b );
}

bool LongLong38B::LessEq( const LongLong38B & b ) const
{
    return Less( b ) || Eq( b );
}
bool LongLong38B::GreatEq( const LongLong38B & b ) const
{
    return Great( b ) || Eq( b );
}
