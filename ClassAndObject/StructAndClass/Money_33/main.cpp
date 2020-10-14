#include "money33b.h"
#include <iomanip>
#include <iostream>

int main( )
{
    Money33B a;
    a.Init( 1.0 );
    a.Display( );

    Money33B b;
    b.Init( 2.0 );
    b.Display( );

    Money33B c;
    c.Init( -2.0 );
    c.Display( );

    b.Add( a ).Display( );
    b.Sub( a ).Display( );
    b.Mul( 3 ).Display( );
    b.Div( 3 ).Display( );

    std::cout << std::boolalpha << b.Eq( b ) << std::endl;
    std::cout << std::boolalpha << a.Less( b ) << std::endl;
}
