#include "lorry.h"
#include <iostream>

Lorry::Lorry( const std::string& name, int16_t cyl, int16_t pow, int16_t mass )
    : Car( name, cyl, pow ), mass_ { mass } {}

Lorry::operator std::string( ) const {
  return Car::operator std::string( ) + ", mass = " + std::to_string( mass_ );
}

void Lorry::Display( ) {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

int16_t Lorry::mass( ) const
{
    return mass_;
}

void Lorry::setMass( const int16_t & mass )
{
    mass_ = mass;
}
