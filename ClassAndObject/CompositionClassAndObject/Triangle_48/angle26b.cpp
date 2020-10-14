#include "angle26b.h"
#include <iostream>
#include <sstream>

const double PI = 3.14159265358979323846;
const int ANG_PI_2 = 180;

void Angle26B::Init( int16_t g, int16_t m )
{
    //знаки должны быть одинаковы раз передается 2 параметрами
    if ( ( g < 0 && m > 0 ) || ( 0 < g && m < 0 ) || !( 0 <= std::abs( m ) && std::abs( m ) < 60 ) ) {
	std::cout << "ERROR DATA";
	exit( 1 );
    }
    grad = g;
    min = m;
}

void Angle26B::Init( double angl )
{
    grad = static_cast< int16_t >( angl );
    min = static_cast< int16_t >( ( angl - grad ) * 60 );
}

void Angle26B::Read( )
{
    int16_t a, b;
    std::cout << "Enter a, b" << std::endl;
    std::cin >> a >> b;
    Init( a, b );
}

void Angle26B::Display( ) const
{
    std::cout << ToString( ) << std::endl;
}

std::string Angle26B::ToString( ) const
{
    std::stringstream ss;
    ss << grad << static_cast< char >( 248 ) << std::abs( min ) << "\'";
    return ss.str( );
}

double Angle26B::ToRadian( ) const
{
    double grad = static_cast< double >( this->grad ) + static_cast< double >( min ) * 60 / 100;
    return grad * PI / ANG_PI_2;
}

Angle26B Angle26B::Normalise( ) const
{
    Angle26B t = *this;
    t.grad %= 360;
    return t;
}

void Angle26B::Normalise( )
{
    grad %= 360;
}

Angle26B Angle26B::Adding( int16_t g, int16_t m ) const
{
    Angle26B t = *this;
    t.grad += g;
    t.min += m;
    if ( std::abs( t.min ) >= 60 ) {
	t.grad = ( t.grad < 0 ) ? --t.grad : ++t.grad;
	t.min = ( t.min < 0 ) ? t.min + 60 : t.min - 60;
    }
    return t;
}

Angle26B Angle26B::Adding( const Angle26B & other ) const
{
    Angle26B t = *this;
    t.grad += other.grad;
    t.min += other.min;
    if ( std::abs( t.min ) >= 60 ) {
	t.grad = ( t.grad < 0 ) ? --t.grad : ++t.grad;
	t.min = ( t.min < 0 ) ? t.min + 60 : t.min - 60;
    }
    return t;
}

Angle26B Angle26B::Substr( int16_t g, int16_t m ) const
{
    Angle26B t = *this;
    t.grad -= g;
    t.min -= m;
    if ( std::abs( t.min ) >= 60 ) {
	t.grad = ( t.grad < 0 ) ? --t.grad : ++t.grad;
	t.min = ( t.min < 0 ) ? t.min + 60 : t.min - 60;
    }
    return t;
}

Angle26B Angle26B::Substr( const Angle26B & other ) const
{
    Angle26B t = *this;
    t.grad -= other.grad;
    t.min -= other.min;
    if ( std::abs( t.min ) >= 60 ) {
	t.grad = ( t.grad < 0 ) ? --t.grad : ++t.grad;
	t.min = ( t.min < 0 ) ? t.min + 60 : t.min - 60;
    }
    return t;
}

double Angle26B::Sinus( ) const
{
    return std::sin( ToRadian( ) );
}

double Angle26B::Angle( ) const
{
    return ( double( grad ) + double( min ) / 60 );
}

bool Angle26B::Eq( const Angle26B & an2 )
{
    return ( grad == an2.grad ) && ( min == an2.min );
}

bool Angle26B::NotEq( const Angle26B & an2 )
{
    return !Eq( an2 );
}

bool Angle26B::Less( const Angle26B & an2 )
{
    return ( grad < an2.grad ) || ( ( grad == an2.grad ) && ( min < an2.min ) );
}

bool Angle26B::LessEq( const Angle26B & an2 )
{
    return Less( an2 ) || Eq( an2 );
}

bool Angle26B::Greater( const Angle26B & an2 )
{
    return !LessEq( an2 );
}

bool Angle26B::GreaterEq( const Angle26B & an2 )
{
    return Greater( an2 ) || Eq( an2 );
}
