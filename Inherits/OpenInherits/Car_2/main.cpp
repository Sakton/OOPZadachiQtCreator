#include "lorry.h"
#include <iostream>
#include <string>

Car & foo( Car & c )
{
    c.Display( );
    return c;
}

//MAIN
int main()
{
    Car a = Car( "Car 1", 4, 117 );
    foo( a ).Display( );
    Lorry b = Lorry( "Lorry 1", 8, 900, 5000 );
    foo( b ).Display( );

    Lorry *p_l = new Lorry( "Lorry 2", 10, 1000, 10000 );

    Car *p_a, *p_b;
    p_a = &a;
    p_b = &b;

    foo( *p_a );
    foo( *p_b );
}
