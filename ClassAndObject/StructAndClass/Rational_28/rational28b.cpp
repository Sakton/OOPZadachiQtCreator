#include "rational28b.h"
#include <iostream>
#include <sstream>

void Rational28B::Init( int32_t x, int16_t y )
{
    if ( y == 0 ) {
	std::cout << "ERROR DIV ZERO" << std::endl;
	exit( 1 );
    }
    if ( x < 0 && y < 0 ) {
	x = -x;
	y = -y;
    }
    a = x;
    b = y;
    reduce( );
}

void Rational28B::Display( ) const
{
    std::cout << ToString( ) << std::endl;
}

void Rational28B::Read( )
{
    int16_t a, b;
    std::cout << "Enter a b" << std::endl;
    std::cin >> a >> b;
    Init( a, b );
}

std::string Rational28B::ToString( ) const
{
    std::stringstream ss;
    ss << a << "/" << b;
    return ss.str( );
}

Rational28B Rational28B::Add( const Rational28B & b ) const
{
    Rational28B t;
    t.a = this->a * b.b + this->b * b.a;
    t.b = this->b * b.b;
    t.reduce( );
    return t;
}

Rational28B Rational28B::Sub( const Rational28B & b ) const
{
    Rational28B t;
    t.a = a * b.b - this->b * b.a;
    t.b = this->b * b.b;
    t.reduce( );
    return t;
}

Rational28B Rational28B::Mul( const Rational28B & b ) const
{
    Rational28B t;
    t.a = a * b.a;
    t.b = this->b * b.b;
    t.reduce( );
    return t;
}

Rational28B Rational28B::Div( const Rational28B & b ) const
{
    Rational28B t;
    t.a = a * b.b;
    t.b = this->b * b.a;
    t.reduce( );
    return t;
}

bool Rational28B::Eq( const Rational28B & b ) const
{
    return ( a * b.b == this->b * b.a );
}

bool Rational28B::Great( const Rational28B & b ) const
{
    return ( a * b.b > this->b * b.a );
}

bool Rational28B::Less( const Rational28B & b ) const
{
    return ( a * b.b < this->b * b.a );
}

void Rational28B::reduce( )
{
    int aa = std::abs( a );
    int bb = std::abs( b );

    while ( bb ) {
	int t = aa % bb;
	aa = bb;
	bb = t;
    }
    //NOD - in aa;
    a /= aa;
    b /= aa;
}
