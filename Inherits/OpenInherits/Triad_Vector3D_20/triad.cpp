#include "triad.h"

#include <iostream>

Triad::Triad( int f, int s, int t )
    : first_ { f }, second_ { s }, third_ { t } {}

Triad &Triad::operator+=( int x ) {
  std::cout << "this = " << this << std::endl;
  first_ += x;
  second_ += x;
  third_ += x;
  return *this;
}

Triad &Triad::operator*=( int x ) {
  first_ *= x;
  second_ *= x;
  third_ *= x;
  return *this;
}

Triad::operator std::string( ) const {
  return std::to_string( first_ ) + ", " + std::to_string( second_ ) + ", " +
         std::to_string( third_ );
}

void Triad::Display( ) const {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

int Triad::first( ) const { return first_; }

void Triad::setFirst( int first ) { first_ = first; }

int Triad::second( ) const { return second_; }

void Triad::setSecond( int second ) { second_ = second; }

int Triad::third( ) const { return third_; }

void Triad::setThird( int third ) { third_ = third; }

Triad operator+( const Triad &t1, int x ) {
  Triad loc = t1;
  loc += x;
  return loc;
}

Triad operator+( int x, const Triad &t1 ) {
  Triad loc = t1;
  loc += x;
  return loc;
}

Triad operator*( int x, const Triad &t1 ) {
  Triad loc = t1;
  loc *= x;
  return loc;
}

bool operator==( const Triad &t1, const Triad &t2 ) {
  return t1.first_ == t2.first_ && t1.second_ == t2.second_ &&
         t1.third_ == t2.third_;
}
