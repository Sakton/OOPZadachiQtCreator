#include "pair.h"

#include <iostream>

Pair::Pair( int f, int s ) : first_ { f }, second_ { s } {}

int Pair::first( ) const { return first_; }

void Pair::setFirst( int first ) { first_ = first; }

int Pair::second( ) const { return second_; }

void Pair::setSecond( int second ) { second_ = second; }

Pair &Pair::operator+=( const Pair &p ) {
  first_ += second_;
  second_ = p.first_ + p.second_;
  return *this;
}

Pair::operator std::string( ) const {
  return "pair: " + std::to_string( first_ ) + " : " +
         std::to_string( second_ );
}

void Pair::Display( ) const { std::cout << std::string( *this ) << std::endl; }

Pair operator+( const Pair &p1, const Pair &p2 ) {
  Pair loc = p1;
  loc += p2;
  return loc;
}
