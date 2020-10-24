#include "angle26base.h"

#include <iostream>
#include <sstream>

Angle26Base::Angle26Base( int16_t g, int16_t m ) : grad { g }, min { m } {
  if ( ( g < 0 && m > 0 ) || ( 0 < g && m < 0 ) ||
       !( 0 <= std::abs( m ) && std::abs( m ) < 60 ) ) {
    std::cout << "ERROR DATA";
    exit( 1 );
  }
  grad = g;
  min = m;
}

Angle26Base::Angle26Base( double angl ) {
  grad = static_cast< int16_t >( angl );
  min = static_cast< int16_t >( ( angl - grad ) * 60 );
}

double Angle26Base::ToRadian( ) const {
  double grad = static_cast< double >( this->grad ) +
                static_cast< double >( min ) * 60 / 100;
  return grad * PI / ANG_PI_2;
}

Angle26Base Angle26Base::Normalise( ) const {
  Angle26Base t = *this;
  t.grad %= 360;
  return t;
}

void Angle26Base::Normalise( ) { grad %= 360; }

double Angle26Base::Sinus( ) const { return std::sin( ToRadian( ) ); }

double Angle26Base::Angle( ) const {
  return ( double( grad ) + double( min ) / 60 );
}

int16_t Angle26Base::getGrad( ) const { return grad; }

void Angle26Base::setGrad( const int16_t& value ) { grad = value; }

int16_t Angle26Base::getMin( ) const { return min; }

void Angle26Base::setMin( const int16_t& value ) { min = value; }

void Display( const Angle26Base& ang ) {
  std::cout << ToString( ang ) << std::endl;
}

std::string ToString( const Angle26Base& ang ) {
  std::stringstream ss;
  ss << ang.grad << static_cast< char >( 248 ) << std::abs( ang.min ) << "\'";
  return ss.str( );
}
