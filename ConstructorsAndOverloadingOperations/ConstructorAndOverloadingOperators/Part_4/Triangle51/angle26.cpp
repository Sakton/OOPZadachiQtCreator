#include "angle26.h"

#include <iostream>
#include <sstream>

const double PI = 3.14159265358979323846;
const int ANG_PI_2 = 180;

Angle26::Angle26( int16_t g, int16_t m ) : grad { g }, min { m } {
  if ( ( g < 0 && m > 0 ) || ( 0 < g && m < 0 ) ||
       !( 0 <= std::abs( m ) && std::abs( m ) < 60 ) ) {
    std::cout << "ERROR DATA";
    exit( 1 );
  }
  grad = g;
  min = m;
}

Angle26::Angle26( double angl ) : Angle26( 0, 0 ) {
  grad = static_cast< int16_t >( angl );
  min = static_cast< int16_t >( ( angl - grad ) * 60 );
}

void Angle26::Read( ) {
  int16_t a, b;
  std::cout << "Enter a, b" << std::endl;
  std::cin >> a >> b;
  *this = Angle26( a, b );
}

void Angle26::Display( ) const { std::cout << ToString( ) << std::endl; }

std::string Angle26::ToString( ) const {
  std::stringstream ss;
  ss << grad << static_cast< char >( 248 ) << std::abs( min ) << "\'";
  return ss.str( );
}

double Angle26::ToRadian( ) const {
  double grad = static_cast< double >( this->grad ) +
                static_cast< double >( min ) * 60 / 100;
  return grad * PI / ANG_PI_2;
}

Angle26 Angle26::Normalise( ) const {
  Angle26 t = *this;
  t.grad %= 360;
  return t;
}

void Angle26::Normalise( ) { grad %= 360; }

Angle26 operator+( const Angle26& an1, const Angle26& an2 ) {
  Angle26 t = an1;
  t.grad += an2.grad;
  t.min += an2.min;
  if ( std::abs( t.min ) >= 60 ) {
    t.grad = ( t.grad < 0 ) ? --t.grad : ++t.grad;
    t.min = ( t.min < 0 ) ? t.min + 60 : t.min - 60;
  }
  return t;
}

Angle26 operator-( const Angle26& an1, const Angle26& an2 ) {
  Angle26 t = an1;
  t.grad -= an2.grad;
  t.min -= an2.min;
  if ( std::abs( t.min ) >= 60 ) {
    t.grad = ( t.grad < 0 ) ? --t.grad : ++t.grad;
    t.min = ( t.min < 0 ) ? t.min + 60 : t.min - 60;
  }
  return t;
}

double Angle26::Sinus( ) const { return std::sin( ToRadian( ) ); }

double Angle26::Angle( ) const {
  return ( double( grad ) + double( min ) / 60 );
}

bool operator<( const Angle26& an1, const Angle26& an2 ) {
  return ( an1.grad < an2.grad ) ||
         ( ( an1.grad == an2.grad ) && ( an1.min < an2.min ) );
}

bool operator<=( const Angle26& an1, const Angle26& an2 ) {
  return an1 < an2 || an1 == an2;
}

bool operator>( const Angle26& an1, const Angle26& an2 ) {
  return !( an1 <= an2 );
}

bool operator>=( const Angle26& an1, const Angle26& an2 ) {
  return an1 > an2 || an1 == an2;
}
bool operator==( const Angle26& an1, const Angle26& an2 ) {
  return ( an1.grad == an2.grad ) && ( an1.min == an2.min );
}
bool operator!=( const Angle26& an1, const Angle26& an2 ) {
  return !( an1 == an2 );
}

int16_t Angle26::getGrad( ) const { return grad; }

void Angle26::setGrad( const int16_t& value ) { grad = value; }

int16_t Angle26::getMin( ) const { return min; }

void Angle26::setMin( const int16_t& value ) { min = value; }
