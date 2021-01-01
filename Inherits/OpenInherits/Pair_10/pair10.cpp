#include "pair10.h"

#include <iostream>

Pair10::Pair10( double f, double s ) : first_ { 0 }, second_ { 0 } {
  setFirst( f );
  setSecond( s );
}

double Pair10::Mult( ) const { return first_ * second_; }

void Pair10::Display( ) {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

Pair10::operator std::string( ) const {
  return std::to_string( first_ ) + ", " + std::to_string( second_ );
}

double Pair10::first( ) const { return first_; }

void Pair10::setFirst( double first ) {
  if ( first < 0 ) {
    std::cout << "ERROR FIRST";
    exit( 1 );
  }
  first_ = first;
}

double Pair10::second( ) const { return second_; }

void Pair10::setSecond( double second ) {
  if ( second < 0 ) {
    std::cout << "ERROR SECOND";
    exit( 1 );
  }
  second_ = second;
}
