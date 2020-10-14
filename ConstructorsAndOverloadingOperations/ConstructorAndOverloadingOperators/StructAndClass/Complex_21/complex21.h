#ifndef COMPLEX21_H
#define COMPLEX21_H
#include <string>

class Complex21 {
public:
    Complex21( double a = 0, double b = 0 );
    Complex21( const Complex21 & oth );

    friend void Read( Complex21 & oth );
    friend void Display( const Complex21 & oth );
    std::string ToString( ) const;

    Complex21 & operator+=( const Complex21 & oth );
    Complex21 & operator-=( const Complex21 & oth );
    Complex21 & operator*=( const Complex21 & oth );
    Complex21 & operator/=( const Complex21 & oth );
    Complex21 & operator-( );

    friend Complex21 operator+( const Complex21 & lhs, const Complex21 & rhs );
    friend Complex21 operator-( const Complex21 & lhs, const Complex21 & rhs );
    friend Complex21 operator*( const Complex21 & lhs, const Complex21 & rhs );
    friend Complex21 operator/( const Complex21 & lhs, const Complex21 & rhs );
    friend Complex21 operator-( const Complex21 & rhs );

    friend bool operator==( const Complex21 & lhs, const Complex21 & rhs );

    //    ComplexB Add( const ComplexB & a ) const;
    //    ComplexB Sub( const ComplexB & a ) const;
    //    ComplexB Mul( const ComplexB & a ) const;
    //    ComplexB Div( const ComplexB & a ) const;
    //    bool Equ( const ComplexB & a ) const;
    //    ComplexB Conj( ) const;

private:
    double first_ { 0 };
    double second_ { 0 };
};

#endif // COMPLEX21_H
