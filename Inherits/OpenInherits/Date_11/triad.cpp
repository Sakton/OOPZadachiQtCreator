#include "triad.h"
#include <iostream>

bool operator==( const Triad & a, const Triad & b )
{
    return a.a_ == b.a_ && a.b_ == b.b_ && a.c_ == b.c_;
}

bool operator<( const Triad & a, const Triad & b )
{
    return ( a.a_ < b.a_ ) || ( a.a_ == b.a_ && a.b_ < b.b_ ) || ( a.a_ == b.a_ && a.b_ == b.b_ && a.c_ < b.c_ );
}

int Triad::a( ) const
{
    return a_;
}

void Triad::setA( int a )
{
    a_ = a;
}

int Triad::b( ) const
{
    return b_;
}

void Triad::setB( int b )
{
    b_ = b;
}

int Triad::c( ) const
{
    return c_;
}

void Triad::setC( int c )
{
    c_ = c;
}

void Triad::Display( ) const
{
    //std::cout << static_cast< std::string >( *this ) << std::endl;
    std::cout << ( std::string )( *this ) << std::endl;
}

Triad::operator std::string( ) const
{
    return std::to_string( a_ ) + ":" + std::to_string( b_ ) + ":" + std::to_string( c_ );
}
