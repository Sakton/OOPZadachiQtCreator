#include "triad.h"

#include <string>

Triad::Triad( int f, int s, int t )
    : first_ { f }, second_ { s }, third_ { t } {}

int Triad::First( ) const { return first_; }
int Triad::Second( ) const { return second_; }
int Triad::Third( ) const { return third_; }

std::ostream &Triad::show( std::ostream &out ) {
  out << static_cast< std::string >( *this );
  return out;
}

Triad::operator std::string( ) {
  return "triad str " + std::to_string( first_ ) + ":" +
         std::to_string( second_ ) + ":" + std::to_string( third_ );
}

void Triad::setFirst(int first)
{
    first_ = first;
}

void Triad::setSecond(int second)
{
    second_ = second;
}

void Triad::setThird(int third)
{
    third_ = third;
}

int Triad::FirstNext( ) { return ++first_; }
int Triad::SecondNext( ) { return ++second_; }
int Triad::ThirdNext( ) { return ++third_; }
