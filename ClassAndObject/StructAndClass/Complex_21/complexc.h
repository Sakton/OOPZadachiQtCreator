#ifndef COMPLEXC_H
#define COMPLEXC_H
#include <string>

struct PairComplex {
    void Init( double a, double b );
    void Read( );
    void Display( ) const;
    std::string ToString( ) const;
    //**
    double first;
    double second;
};

class ComplexC
{
public:
    void Init( double a, double b );
    void Read( );
    void Display( ) const;
    std::string ToString( ) const;
    ComplexC Add( const ComplexC& a ) const;
    ComplexC Sub( const ComplexC& a ) const;
    ComplexC Mul( const ComplexC& a ) const;
    ComplexC Div( const ComplexC& a ) const;
    bool Equ( const ComplexC& a ) const;
    ComplexC Conj( ) const;

private:
    PairComplex data_;
};

#endif // COMPLEXC_H
