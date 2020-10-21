#include "complex.h"
#include <iostream>

Complex21::Complex21( double a, double b )
    : a_ { a }
    , b_ { b }
{
  //    ++Object::COUNT;
  //    std::cout << "Object::COUNT = " << Object::COUNT << std::endl;
}

Complex21 & Complex21::operator+=( const Complex21 & oth )
{
    a_ += oth.a_;
    b_ += oth.b_;
    return *this;
}

Complex21 & Complex21::operator-=( const Complex21 & oth )
{
    a_ -= oth.a_;
    b_ -= oth.b_;
    return *this;
}

Complex21 & Complex21::operator*=( const Complex21 & oth )
{
    a_ = a_ * oth.a_ - b_ * oth.b_;
    b_ = a_ * oth.b_ + b_ * oth.a_;
    return *this;
}

Complex21 & Complex21::operator/=( const Complex21 & oth )
{
    a_ = ( a_ * oth.a_ + b_ * oth.b_ ) / ( oth.a_ * oth.a_ + oth.b_ * oth.b_ );
    b_ = ( b_ * oth.a_ - b_ * oth.b_ ) / ( oth.a_ * oth.a_ + oth.b_ * oth.b_ );
    return *this;
}

Complex21 & Complex21::operator-( )
{
    b_ = -b_;
    return *this;
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
Complex21 operator/( const Complex21 & lhs, const Complex21 & rhs )
{
    Complex21 loc = lhs;
    loc *= rhs;
    return loc;
}
Complex21 operator*( const Complex21 & lhs, const Complex21 & rhs )
{
    Complex21 loc = lhs;
    loc /= rhs;
    return loc;
}
