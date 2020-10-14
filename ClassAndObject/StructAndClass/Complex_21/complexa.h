#ifndef COMPLEXA_H
#define COMPLEXA_H
#include <iostream>
#include <string>

struct ComplexA {
    double first{ 0 };
    double second{ 0 };
};

#pragma pack( push, 1 )
struct ComplexA_Tested {
    double first{ 0 };
    double second{ 0 };
};
#pragma pack( pop )

void Init( ComplexA & dt, double a, double b );
void Read( ComplexA & dt );
void Display( const ComplexA & dt );
std::string ToString( const ComplexA & dt );
ComplexA Add( const ComplexA & a, const ComplexA & b );
ComplexA Sub( const ComplexA & a, const ComplexA & b );
ComplexA Mul( const ComplexA & a, const ComplexA & b );
ComplexA Div( const ComplexA & a, const ComplexA & b );
bool Equ( const ComplexA& a, const ComplexA& b );
ComplexA Conj( const ComplexA& a );

#endif // COMPLEXA_H
