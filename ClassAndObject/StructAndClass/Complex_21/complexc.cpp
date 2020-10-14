#include "complexc.h"
#include <iomanip>
#include <iostream>
#include <sstream>

void PairComplex::Init( double a, double b )
{
    //a, b - all numeric line
    first = a;
    second = b;
}

void PairComplex::Read( )
{
    //a, b - read all at once
    std::cout << "Enter a b" << std::endl;
    std::cin >> first >> second;
}

void PairComplex::Display( ) const
{
    std::cout << ToString( );
}

std::string PairComplex::ToString( ) const
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision( 2 ) << "( " << first << " + " << second << "i )";
    return ss.str( );
}

void ComplexC::Init( double a, double b )
{
    data_.Init( a, b );
}

void ComplexC::Read( )
{
    data_.Read( );
}

void ComplexC::Display( ) const
{
    data_.Display( );
}

std::string ComplexC::ToString( ) const
{
    return data_.ToString( );
}

ComplexC ComplexC::Add( const ComplexC &a ) const
{
    ComplexC res;
    res.data_.first = data_.first + a.data_.first;
    res.data_.second = data_.second + a.data_.second;
    return res;
}

ComplexC ComplexC::Sub( const ComplexC &a ) const
{
    ComplexC res;
    res.data_.first = data_.first - a.data_.first;
    res.data_.second = data_.second - a.data_.second;
    return res;
}

ComplexC ComplexC::Mul( const ComplexC &a ) const
{
    ComplexC res;
    res.data_.first = data_.first * a.data_.first - data_.second * a.data_.second;
    res.data_.second = data_.first * a.data_.second + data_.second * a.data_.first;
    return res;
}

ComplexC ComplexC::Div( const ComplexC &a ) const
{
    ComplexC res;
    res.data_.first = ( data_.first * a.data_.first + data_.second * a.data_.second ) / ( a.data_.first * a.data_.first + a.data_.second * a.data_.second );
    res.data_.second = ( data_.second * a.data_.first - data_.first * a.data_.second ) / ( a.data_.first * a.data_.first + a.data_.second * a.data_.second );
    return res;
}

bool ComplexC::Equ( const ComplexC &a ) const
{
    return ( data_.first == a.data_.first ) && ( data_.second == a.data_.second );
}

ComplexC ComplexC::Conj( ) const
{
    ComplexC res = *this;
    res.data_.second *= -1;
    return res;
}
