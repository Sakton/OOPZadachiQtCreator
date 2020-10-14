#ifndef COMPLEXB_H
#define COMPLEXB_H
#include <string>

class ComplexB {
public:
    void Init( double a, double b );
    void Read( );
    void Display( ) const;
    std::string ToString( ) const;
    ComplexB Add( const ComplexB& a ) const;
    ComplexB Sub( const ComplexB& a ) const;
    ComplexB Mul( const ComplexB& a ) const;
    ComplexB Div( const ComplexB& a ) const;
    bool Equ( const ComplexB& a ) const;
    ComplexB Conj( ) const;

private:
    double first_ { 0 };
    double second_ { 0 };
};

#endif	      // COMPLEXB_H
