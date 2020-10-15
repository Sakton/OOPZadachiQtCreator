#include "pair.h"

#include <iomanip>
#include <iostream>
#include <sstream>

Pair::Pair( double f, double s ) : first_ { f }, second_ { s } {}

Pair& Pair::operator+=( const Pair& pr ) {
  setFirst( first_ + second_ );
  setSecond( pr.first_ + pr.second_ );
  return *this;
}

Pair operator+( const Pair& pr1, const Pair& pr2 ) {
  Pair loc = pr1;
  loc += pr2;
  return loc;
}

double Pair::MultPole( ) const { return first_ * second_; }

double Pair::first( ) const { return first_; }

void Pair::setFirst( double first ) { first_ = first; }

double Pair::second( ) const { return second_; }

void Pair::setSecond( double second ) { second_ = second; }

Pair::operator std::string( ) const {
  std::stringstream ss;
  ss << std::fixed << std::setprecision( 2 );
  ss << "pair: " << first( ) << " : " << second( );
  return ss.str( );
}

void Pair::Display( ) const { std::cout << std::string( *this ) << std::endl; }
