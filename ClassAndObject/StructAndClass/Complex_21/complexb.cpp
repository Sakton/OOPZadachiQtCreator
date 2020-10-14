#include "complexb.h"
#include <iomanip>
#include <iostream>
#include <sstream>

void ComplexB::Init( double a, double b )
{
    //a, b - all numeric line
    first_ = a;
    second_ = b;
}

void ComplexB::Read( )
{
    //a, b - read all at once
    std::cout << "Enter a b" << std::endl;
    std::cin >> first_ >> second_;
}

void ComplexB::Display( ) const
{
    std::cout << ToString( );
}

std::string ComplexB::ToString( ) const
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision( 2 ) << "( " << first_ << " + " << second_ << "i )";
    return ss.str( );
}

ComplexB ComplexB::Add( const ComplexB &a ) const
{
    ComplexB res;
    res.first_ = first_ + a.first_;
    res.second_ = second_ + a.second_;
    return res;
}

ComplexB ComplexB::Sub( const ComplexB &a ) const
{
    ComplexB res;
    res.first_ = first_ - a.first_;
    res.second_ = second_ - a.second_;
    return res;
}

ComplexB ComplexB::Mul( const ComplexB &a ) const
{
    ComplexB res;
    res.first_ = first_ * a.first_ - second_ * a.second_;
    res.second_ = first_ * a.second_ + second_ * a.first_;
    return res;
}

ComplexB ComplexB::Div( const ComplexB &a ) const
{
    ComplexB res;
    res.first_ = ( first_ * a.first_ + second_ * a.second_ ) / ( a.first_ * a.first_ + a.second_ * a.second_ );
    res.second_ = ( second_ * a.first_ - first_ * a.second_ ) / ( a.first_ * a.first_ + a.second_ * a.second_ );
    return res;
}

bool ComplexB::Equ( const ComplexB &a ) const
{
    return ( first_ == a.first_ ) && ( second_ == a.second_ );
}

ComplexB ComplexB::Conj( ) const
{
    ComplexB res = *this;
    res.second_ *= -1;
    return res;
}
