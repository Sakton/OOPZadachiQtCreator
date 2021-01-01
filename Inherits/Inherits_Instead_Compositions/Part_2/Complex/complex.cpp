#include "complex.h"
#include <iostream>

Pair::Pair( double a, double b )
    : first { a }
    , second { b }
{
}

Pair::operator std::string( ) const
{
    return std::to_string( first ) + " + i" + std::to_string( second );
}

void Display( const Pair & a )
{
    std::cout << static_cast< std::string >( a ) << std::endl;
}

double Pair::getFirst( ) const
{
    return first;
}

void Pair::setFirst( double value )
{
    first = value;
}

double Pair::getSecond( ) const
{
    return second;
}

void Pair::setSecond( double value )
{
    second = value;
}

bool operator<( const Pair & a, const Pair & b )
{
    return ( a.first < b.first ) || ( a.first == b.first && a.second < b.second );
}

bool operator<=( const Pair & a, const Pair & b )
{
    return ( a < b ) || ( a == b );
}

bool operator>( const Pair & a, const Pair & b )
{
    return !( a <= b );
}

bool operator>=( const Pair & a, const Pair & b )
{
    return ( a > b ) || ( a == b );
}

bool operator==( const Pair & a, const Pair & b )
{
    return ( a.first == b.first && a.second == b.second );
}

bool operator!=( const Pair & a, const Pair & b )
{
    return !( a == b );
}

Complex::Complex( double a, double b )
    : Pair( a, b )
{
}

Complex & Complex::operator+=( const Complex & oth )
{
    setFirst( getFirst( ) + oth.getFirst( ) );
    setSecond( getSecond( ) + oth.getSecond( ) );
    return *this;
}

Complex & Complex::operator-=( const Complex & oth )
{
    setFirst( getFirst( ) - oth.getFirst( ) );
    setSecond( getSecond( ) - oth.getSecond( ) );
    return *this;
}

Complex & Complex::operator*=( const Complex & oth )
{
    setFirst( getFirst( ) * oth.getFirst( ) - getSecond( ) * oth.getSecond( ) );
    setSecond( getFirst( ) * oth.getSecond( ) + getSecond( ) * oth.getFirst( ) );
    return *this;
}

Complex & Complex::operator/=( const Complex & oth )
{
    setFirst( ( getFirst( ) * oth.getFirst( ) + getSecond( ) * oth.getSecond( ) ) / ( oth.getFirst( ) * oth.getFirst( ) + oth.getSecond( ) * oth.getSecond( ) ) );
    setSecond( ( getSecond( ) * oth.getFirst( ) - getSecond( ) * oth.getSecond( ) ) / ( oth.getFirst( ) * oth.getFirst( ) + oth.getSecond( ) * oth.getSecond( ) ) );
    return *this;
}

Complex & Complex::operator-( )
{
    setSecond( -getSecond( ) );
    return *this;
}
