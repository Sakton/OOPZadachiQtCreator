#include "liquid4.h"
#include <iostream>

Liquid4::Liquid4( const std::string& name, double ro ) {
  setName( name );
  setRo( ro );
}

void Liquid4::Display( ) const {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

Liquid4& Liquid4::operator=( const Liquid4& lic ) {
  name_ = lic.name_;
  ro_ = lic.ro_;
  return *this;
}

Liquid4::operator std::string( ) const {
  return name_ + ": ro = " + std::to_string( ro_ );
}

double Liquid4::ro( ) const { return ro_; }

void Liquid4::setRo( double ro ) {
  if ( ro < 0 ) {
    std::cout << "ERROR";
    exit( 1 );
  }
  ro_ = ro;
}

std::string Liquid4::name( ) const { return name_; }

void Liquid4::setName( const std::string& name ) { name_ = name; }
