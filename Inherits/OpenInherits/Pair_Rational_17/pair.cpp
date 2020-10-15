#include "pair.h"

#include <iostream>

Pair::Pair( int f, int s ) : first_ { f }, second_ { s } {}

Pair &Pair::operator-=( const Pair &oth ) {
  first_ -= second_;
  second_ = oth.first_ - oth.second_;
  return *this;
}

void Pair::Display( ) const {
  // std::cout << static_cast< std::string >( *this );
  // std::cout << ( std::string )( *this );
  std::cout << std::string( *this ) << std::endl;
}

int Pair::first( ) const { return first_; }

void Pair::setFirst( int first ) { first_ = first; }

int Pair::second( ) const { return second_; }

void Pair::setSecond( int second ) { second_ = second; }

Pair::operator std::string( ) const {
  return "pair = " + std::to_string( first_ ) + "^(..)^" +
         std::to_string( second_ );
}

Pair operator-( const Pair &p1, const Pair &p2 ) {
  Pair loc = p1;
  loc -= p2;
  return loc;
}

bool operator==( const Pair &p1, const Pair &p2 ) {
  return p1.first_ == p2.first_ && p1.second_ == p2.second_;
}
