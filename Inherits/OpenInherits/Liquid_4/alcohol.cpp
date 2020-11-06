#include "alcohol.h"
#include <iostream>

Alcohol::Alcohol( const std::string& name, double ro, double krep )
    : Liquid4( name, ro ) {
  setKrep( krep );
}

void Alcohol::Display( ) const {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

Alcohol& Alcohol::operator=( const Liquid4& li ) {
  this->Liquid4::operator=( li );
  return *this;
}

double Alcohol::krep( ) const { return krep_; }

void Alcohol::setKrep( double krep ) {
  if ( krep < 0 ) {
    std::cout << "ERROR KREP";
    exit( 1 );
  }
  krep_ = krep;
}

Alcohol::operator std::string( ) const {
  return Liquid4::operator std::string( ) +
         " :crep = " + std::to_string( krep_ );
}
