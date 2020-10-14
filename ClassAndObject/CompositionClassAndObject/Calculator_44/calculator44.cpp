#include "calculator44.h"

void Calculator44::Init( double a, double b )
{
    a_.Init( a, ( a - static_cast< int >( a ) ) * 10000 );
    b_.Init( b, ( b - static_cast< int >( b ) ) * 10000 );
}

void Calculator44::Add( )
{
    return a_.Add( b_ ).Display( );
}

void Calculator44::Sub( )
{
    return a_.Sub( b_ ).Display( );
}

void Calculator44::Mul( )
{
    return a_.Mul( b_ ).Display( );
}

void Calculator44::Div( )
{
    return a_.Div( b_ ).Display( );
}
