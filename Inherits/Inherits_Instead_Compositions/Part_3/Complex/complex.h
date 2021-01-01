#ifndef COMPLEX_H
#define COMPLEX_H
#include "object.h"

class Complex21 : public Object {
public:
    Complex21( double a = 0, double b = 0 );

    Complex21 & operator+=( const Complex21 & oth );
    Complex21 & operator-=( const Complex21 & oth );
    Complex21 & operator*=( const Complex21 & oth );
    Complex21 & operator/=( const Complex21 & oth );
    Complex21 & operator-( );

    friend Complex21 operator+( const Complex21 & lhs, const Complex21 & rhs );
    friend Complex21 operator-( const Complex21 & lhs, const Complex21 & rhs );
    friend Complex21 operator/( const Complex21 & lhs, const Complex21 & rhs );
    friend Complex21 operator*( const Complex21 & lhs, const Complex21 & rhs );

private:
    double a_;
    double b_;
};

#endif // COMPLEX_H
