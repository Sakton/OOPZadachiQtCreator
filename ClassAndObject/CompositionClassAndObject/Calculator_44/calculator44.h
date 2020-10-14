#ifndef CALCULATOR44_H
#define CALCULATOR44_H
#include <fraction35b.h>

class Calculator44
{
public:
    void Init( double a, double b );

    void Add( );
    void Sub( );
    void Mul( );
    void Div( );

private:
    Fraction35B a_;
    Fraction35B b_;
};

#endif // CALCULATOR44_H
