#include "complex.h"

#include <iomanip>
#include <iostream>
#include <sstream>

Complex::Complex( double f, double s ) : Pair( f, s ) {}

Complex &Complex::operator-=( const Complex &oth ) {
  setFirst( first( ) - second( ) );
  setSecond( oth.first( ) - oth.second( ) );
  return *this;
}

Complex &Complex::operator*=( const Complex &oth ) {
  setFirst( first( ) * oth.first( ) - second( ) * oth.second( ) );
  setSecond( first( ) * oth.second( ) + second( ) * oth.first( ) );
  return *this;
}

void Complex::Display( ) const {
  std::cout << std::string( *this ) << std::endl;
}

Complex::operator std::string( ) const {
  std::stringstream ss;
  ss << std::fixed << std::setprecision( 2 );
  ss << "complex = " << first( ) << " + " << second( ) << "i";
  return ss.str( );
}
