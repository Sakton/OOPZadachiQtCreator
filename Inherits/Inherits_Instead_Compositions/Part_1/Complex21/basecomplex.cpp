#include "basecomplex.h"

#include <iostream>

BaseComplex::BaseComplex( double a, double b ) : realn_ { a }, mnim_ { b } {}

BaseComplex::operator std::string( ) const {
  return std::to_string( realn_ ) + " i" + std::to_string( mnim_ );
}

double BaseComplex::realn( ) const { return realn_; }

void BaseComplex::setRealn( double realn ) { realn_ = realn; }

double BaseComplex::mnim( ) const { return mnim_; }

void BaseComplex::setMnim( double mnim ) { mnim_ = mnim; }

void Read( BaseComplex& bc ) {
  //**
  double a, b;
  std::cin >> a >> b;
  //проверки
  bc.realn_ = a;
  bc.mnim_ = b;
}
void Display( const BaseComplex& bc ) {
  std::cout << static_cast< std::string >( bc ) << std::endl;
}
