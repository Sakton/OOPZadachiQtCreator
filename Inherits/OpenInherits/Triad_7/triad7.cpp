#include "triad7.h"
#include <iostream>

Triad7::Triad7( double a, double b, double c )
    : first_ { a }
    , second_ { b }
    , third_ { c }
{
}

void Triad7::Display( ) const
{
    std::cout << std::string( *this ) << std::endl;
}

Triad7::operator std::string( ) const
{
    return std::to_string( first( ) ) + ", " + std::to_string( second( ) ) + ", " + std::to_string( third( ) );
}

double Triad7::first( ) const
{
    return first_;
}

void Triad7::setFirst( double first )
{
    first_ = first;
}

double Triad7::second( ) const
{
    return second_;
}

void Triad7::setSecond( double second )
{
    second_ = second;
}

double Triad7::third( ) const
{
    return third_;
}

void Triad7::setThird( double third )
{
    third_ = third;
}
