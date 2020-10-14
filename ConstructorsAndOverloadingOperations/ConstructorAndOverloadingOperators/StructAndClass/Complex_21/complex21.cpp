#include "complex21.h"
#include <iomanip>
#include <iostream>
#include <sstream>

Complex21::Complex21( double a, double b )
{
    //a, b - all numeric line
    first_ = a;
    second_ = b;
}

Complex21::Complex21( const Complex21 & oth )
{
    first_ = oth.first_;
    second_ = oth.second_;
}

std::string Complex21::ToString( ) const
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision( 2 ) << "( " << first_ << " + " << second_ << "i )";
    return ss.str( );
}

Complex21 & Complex21::operator+=( const Complex21 & oth )
{
    first_ += oth.first_;
    second_ += oth.second_;
    return *this;
}

Complex21 & Complex21::operator-=( const Complex21 & oth )
{
    first_ -= oth.first_;
    second_ -= oth.second_;
    return *this;
}

Complex21 & Complex21::operator*=( const Complex21 & oth )
{
    first_ = first_ * oth.first_ - second_ * oth.second_;
    second_ = first_ * oth.second_ + second_ * oth.first_;
    return *this;
}

Complex21 & Complex21::operator/=( const Complex21 & oth )
{
    first_ = ( first_ * oth.first_ + second_ * oth.second_ ) / ( oth.first_ * oth.first_ + oth.second_ * oth.second_ );
    second_ = ( second_ * oth.first_ - first_ * oth.second_ ) / ( oth.first_ * oth.first_ + oth.second_ * oth.second_ );
    return *this;
}

Complex21 & Complex21::operator-( )
{
    second_ = -second_;
    return *this;
}

void Read( Complex21 & oth )
{
    //a, b - read all at once
    double a = 0, b = 0;
    std::cout << "Enter a b" << std::endl;
    std::cin >> a >> b;
    oth = Complex21( a, b );
}

void Display( const Complex21 & oth )
{
    std::cout << oth.ToString( );
}

Complex21 operator+( const Complex21 & lhs, const Complex21 & rhs )
{
    Complex21 loc = lhs;
    loc += rhs;
    return loc;
}

Complex21 operator-( const Complex21 & lhs, const Complex21 & rhs )
{
    Complex21 loc = lhs;
    loc -= rhs;
    return loc;
}

Complex21 operator*( const Complex21 & lhs, const Complex21 & rhs )
{
    Complex21 loc = lhs;
    loc *= rhs;
    return loc;
}
Complex21 operator/( const Complex21 & lhs, const Complex21 & rhs )
{
    Complex21 loc = lhs;
    loc /= rhs;
    return loc;
}

Complex21 operator-( const Complex21 & rhs )
{
    Complex21 loc = rhs;
    return -loc;
}
