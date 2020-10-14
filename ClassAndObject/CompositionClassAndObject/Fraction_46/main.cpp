#include <fraction46.h>
#include <iostream>

int main( )
{
    Fraction46 fr1;
    fr1.Init( 9, 0.0009 );
    fr1.Display( );

    Fraction46 fr2;
    fr2.Init( 3, 0.0003 );
    fr2.Display( );

    fr1.Div( fr2 ).Display( );
}
