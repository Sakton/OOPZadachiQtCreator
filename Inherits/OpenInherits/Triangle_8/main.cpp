#include "equilateral.h"
#include <iostream>

Triangle8 & foo( Triangle8 & tr )
{
    tr.Display( );
    return tr;
}

int main()
{
    Triangle8 * t1;
    t1 = new Equilateral( 5, 4, 3 );
    t1->Display( );
    static_cast< Equilateral * >( t1 )->Display( );

    Equilateral eq( 6, 7, 8 );
    eq.Display( );

    foo( eq );

    eq = *t1;
    t1->Display( );
}
