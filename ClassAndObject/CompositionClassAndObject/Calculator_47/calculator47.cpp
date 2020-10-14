#include "calculator47.h"

Calculator47::Calculator47( long double a, long double b )
{
    a_.Init( a, ( a - static_cast< int64_t >( a ) ) );
    b_.Init( b, ( b - static_cast< int64_t >( b ) ) );
}

Fraction46 Calculator47::Add( )
{
    return a_.Add( b_ );
}

Fraction46 Calculator47::Sub( )
{
    return a_.Sub( b_ );
}

Fraction46 Calculator47::Mul( )
{
    return a_.Mul( b_ );
}

Fraction46 Calculator47::Div( )
{
    return a_.Div( b_ );
}
