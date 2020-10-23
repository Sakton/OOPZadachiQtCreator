#include "rational7.h"

#include <iostream>

const int Rational7::MAX = 0;

Rational7::Rational7( int n )
    : chislitel_ { nullptr }, znamenatel_ { nullptr } {
  if ( n < 0 || n > MAX ) {
    std::cout << "ERROR";
    exit( 1 );
  }
  chislitel_ = new int[ n ] { 0 };
  znamenatel_ = new int[ n ] { 0 };
}

Rational7::Rational7( const std::string &drob ) {
  int zn = drob.find( '/' );
  if ( zn != std::string::npos ) {
    std::string chisl( drob.substr( 0, zn ) );
    std::string znam( drob.substr( zn + 1, drob.size( ) ) );
    std::cout << chisl << "/////" << znam;
  }
}

// Rational7::Rational7( const Rational7 &rvalue ) {}

Rational7::~Rational7( ) {
  delete[] chislitel_;
  delete[] znamenatel_;
}
