#ifndef CALCULATOR47_H
#define CALCULATOR47_H
#include "fraction46.h"

class Calculator47
{
public:
    Calculator47( long double a, long double b );
    Fraction46 Add( );
    Fraction46 Sub( );
    Fraction46 Mul( );
    Fraction46 Div( );

private:
    Fraction46 a_;
    Fraction46 b_;
};

#endif // CALCULATOR47_H
