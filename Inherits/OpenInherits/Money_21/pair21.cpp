#include "pair21.h"

#include <iostream>

Pair21::Pair21( int a, int b ) : a_ { a }, b_ { b } {}

std::string Pair21::toString( ) {
  return std::to_string( a_ ) + ":" + std::to_string( b_ );
}

void Pair21::display( ) { std::cout << toString( ) << std::endl; }

Pair21& Pair21::operator*=( int n ) {
  a_ *= n;
  b_ *= n;
  return *this;
}

Pair21& Pair21::operator+=( const Pair21& p ) {
  a_ += p.a_;
  b_ += p.b_;
  return *this;
}

int Pair21::getA( ) const { return a_; }

void Pair21::setA( int a ) { a_ = a; }

int Pair21::getB( ) const { return b_; }

void Pair21::setB( int b ) { b_ = b; }

Pair21 operator*( int n, const Pair21& p ) {
  Pair21 loc = p;
  loc *= n;
  return loc;
}

Pair21 operator*( const Pair21& p, int n ) { return operator*( n, p ); }

Pair21 operator+( const Pair21& p1, const Pair21& p2 ) {
  Pair21 loc = p1;
  loc += p2;
  return loc;
}
