#include "angle26c.h"
#include <iostream>
#include <sstream>

const double PI = 3.14159265358979323846;
const int ANG_PI_2 = 180;

void DataAngle::Init( int16_t g, int16_t m )
{
    //знаки должны быть одинаковы раз передается 2 параметрами
    if ( ( g < 0 && m > 0 ) || ( 0 < g && m < 0 ) || !( 0 <= std::abs( m ) && std::abs( m ) < 60 ) ) {
	std::cout << "ERROR DATA";
	exit( 1 );
    }
    grad = g;
    min = m;
}

void DataAngle::Read( )
{
    int16_t a, b;
    std::cout << "Enter a, b" << std::endl;
    std::cin >> a >> b;
    Init( a, b );
}

void DataAngle::Display( ) const
{
    std::cout << ToString( ) << std::endl;
}

std::string DataAngle::ToString( ) const
{
    std::stringstream ss;
    ss << grad << static_cast< char >( 248 ) << std::abs( min ) << "\'";
    return ss.str( );
}

void Angle26C::Init( int16_t g, int16_t m )
{
    data_.Init( g, m );
}

void Angle26C::Read( )
{
    data_.Read( );
}

void Angle26C::Display( ) const
{
    data_.Display( );
}

std::string Angle26C::ToString( ) const
{
    return data_.ToString( );
}

double Angle26C::ToRadian( ) const
{
    double grad = static_cast< double >( data_.grad ) + static_cast< double >( data_.min ) * 60 / 100;
    return grad * PI / ANG_PI_2;
}

Angle26C Angle26C::Normalise( ) const
{
    Angle26C t = *this;
    t.data_.grad %= 360;
    return t;
}

void Angle26C::Normalise( )
{
    data_.grad %= 360;
}

Angle26C Angle26C::Adding( int16_t g, int16_t m ) const
{
    Angle26C t = *this;
    t.data_.grad += g;
    t.data_.min += m;
    if ( std::abs( t.data_.min ) >= 60 ) {
	t.data_.grad = ( t.data_.grad < 0 ) ? --t.data_.grad : ++t.data_.grad;
	t.data_.min = ( t.data_.min < 0 ) ? t.data_.min + 60 : t.data_.min - 60;
    }
    return t;
}

Angle26C Angle26C::Substr( int16_t g, int16_t m ) const
{
    Angle26C t = *this;
    t.data_.grad -= g;
    t.data_.min -= m;
    if ( std::abs( t.data_.min ) >= 60 ) {
	t.data_.grad = ( t.data_.grad < 0 ) ? --t.data_.grad : ++t.data_.grad;
	t.data_.min = ( t.data_.min < 0 ) ? t.data_.min + 60 : t.data_.min - 60;
    }
    return t;
}

double Angle26C::Sinus( ) const
{
    return std::sin( ToRadian( ) );
}

bool Angle26C::Eq( const Angle26C & an2 )
{
    return ( data_.grad == an2.data_.grad ) && ( data_.min == an2.data_.min );
}

bool Angle26C::NotEq( const Angle26C & an2 )
{
    return !Eq( an2 );
}

bool Angle26C::Less( const Angle26C & an2 )
{
    return ( data_.grad < an2.data_.grad ) || ( ( data_.grad == an2.data_.grad ) && ( data_.min < an2.data_.min ) );
}

bool Angle26C::LessEq( const Angle26C & an2 )
{
    return Less( an2 ) || Eq( an2 );
}

bool Angle26C::Greater( const Angle26C & an2 )
{
    return !LessEq( an2 );
}

bool Angle26C::GreaterEq( const Angle26C & an2 )
{
    return Greater( an2 ) || Eq( an2 );
}
