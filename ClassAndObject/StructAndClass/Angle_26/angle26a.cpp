#include "angle26a.h"
#include <iostream>
#include <sstream>

const double PI = 3.14159265358979323846;
const int ANG_PI_2 = 180;

void Init( Angle26A & an, int16_t g, int16_t m )
{
    //знаки должны быть одинаковы раз передается 2 параметрами
    if ( ( g < 0 && m > 0 ) || ( 0 < g && m < 0 ) || !( 0 <= std::abs( m ) && std::abs( m ) < 60 ) ) {
	std::cout << "ERROR DATA";
	exit( 1 );
    }
    an.grad = g;
    an.min = m;
}

void Read( Angle26A & an )
{
    int16_t a, b;
    std::cout << "Enter a, b" << std::endl;
    std::cin >> a >> b;
    Init( an, a, b );
}

void Display( const Angle26A & an )
{
    std::cout << ToString( an ) << std::endl;
}

std::string ToString( const Angle26A & an )
{
    std::stringstream ss;
    ss << an.grad << static_cast< char >( 248 ) << std::abs( an.min ) << "\'";
    return ss.str( );
}

double ToRadian( const Angle26A & an )
{
    double grad = static_cast< double >( an.grad ) + static_cast< double >( an.min ) * 60 / 100;
    return grad * PI / ANG_PI_2;
}

Angle26A Normalise( const Angle26A & an )
{
    Angle26A t = an;
    t.grad %= 360;
    return t;
}

void Normalise( Angle26A & an )
{
    an.grad %= 360;
}

Angle26A Adding( const Angle26A & an, int16_t g, int16_t m )
{
    Angle26A t = an;
    t.grad += g;
    t.min += m;
    if ( std::abs( t.min ) >= 60 ) {
	t.grad = ( t.grad < 0 ) ? --t.grad : ++t.grad;
	t.min = ( t.min < 0 ) ? t.min + 60 : t.min - 60;
    }
    return t;
}

Angle26A Substr( const Angle26A & an, int16_t g, int16_t m )
{
    Angle26A t = an;
    t.grad -= g;
    t.min -= m;
    if ( std::abs( t.min ) >= 60 ) {
	t.grad = ( t.grad < 0 ) ? --t.grad : ++t.grad;
	t.min = ( t.min < 0 ) ? t.min + 60 : t.min - 60;
    }
    return t;
}

double Sinus( const Angle26A & an )
{
    return std::sin( ToRadian( an ) );
}

bool Eq( const Angle26A & an1, const Angle26A & an2 )
{
    return ( an1.grad == an2.grad ) && ( an1.min == an2.min );
}

bool NotEq( const Angle26A & an1, const Angle26A & an2 )
{
    return !Eq( an1, an2 );
}

bool Less( const Angle26A & an1, const Angle26A & an2 )
{
    return ( an1.grad < an2.grad ) || ( ( an1.grad == an2.grad ) && ( an1.min < an2.min ) );
}

bool LessEq( const Angle26A & an1, const Angle26A & an2 )
{
    return Less( an1, an2 ) || Eq( an1, an2 );
}

bool Greater( const Angle26A & an1, const Angle26A & an2 )
{
    return !LessEq( an1, an2 );
}

bool GreaterEq( const Angle26A & an1, const Angle26A & an2 )
{
    return Greater( an1, an2 ) || Eq( an1, an2 );
}
