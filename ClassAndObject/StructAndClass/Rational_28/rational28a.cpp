#include "rational28a.h"
#include <iostream>
#include <sstream>

void Rational28A::Sokratit( )
{
    reduce( );
}

void Rational28A::reduce( )
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

int Rational28A::reduce( int aa, int bb )
{
    while ( bb ) {
	int t = aa % bb;
	aa = bb;
	bb = t;
    }
    return aa;
}

void Init( Rational28A & pt, int32_t x, int16_t y )
{
    if ( y == 0 ) {
	std::cout << "ERROR DIV ZERO" << std::endl;
	exit( 1 );
    }
    if ( x < 0 && y < 0 ) {
	x = -x;
	y = -y;
    }
    pt.a = x;
    pt.b = y;
    pt.Sokratit( );
}

void Display( const Rational28A & pt )
{
    std::cout << ToString( pt ) << std::endl;
}

void Read( Rational28A & pt )
{
    int16_t a, b;
    std::cout << "Enter a b" << std::endl;
    std::cin >> a >> b;
    Init( pt, a, b );
}

std::string ToString( const Rational28A & pt )
{
    std::stringstream ss;
    ss << pt.a << "/" << pt.b;
    return ss.str( );
}

Rational28A Add( const Rational28A & a, const Rational28A & b )
{
    Rational28A t;
    t.a = a.a * b.b + a.b * b.a;
    t.b = a.b * b.b;
    t.Sokratit( );
    return t;
}

Rational28A Sub( const Rational28A & a, const Rational28A & b )
{
    Rational28A t;
    t.a = a.a * b.b - a.b * b.a;
    t.b = a.b * b.b;
    t.Sokratit( );
    return t;
}

Rational28A Mul( const Rational28A & a, const Rational28A & b )
{
    Rational28A t;
    t.a = a.a * b.a;
    t.b = a.b * b.b;
    t.Sokratit( );
    return t;
}

Rational28A Div( const Rational28A & a, const Rational28A & b )
{
    Rational28A t;
    t.a = a.a * b.b;
    t.b = a.b * b.a;
    t.Sokratit( );
    return t;
}

bool Eq( const Rational28A & a, const Rational28A & b )
{
    return ( a.a * b.b == a.b * b.a );
}

bool Great( const Rational28A & a, const Rational28A & b )
{
    return ( a.a * b.b > a.b * b.a );
}

bool Less( const Rational28A & a, const Rational28A & b )
{
    return ( a.a * b.b < a.b * b.a );
}
