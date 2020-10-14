#include "goods36b.h"
#include <iostream>

using namespace std;

int main()
{
    Goods36B gds;
    gds.Init( "Test1", "23.09.2020", 1, 398.00, 2 );
    gds.Display( );

    gds.AddCount( 2 );
    gds.Display( );

    gds.SetPrice( 100 );
    gds.Display( );

    gds.SubCount( 2 );
    gds.Display( );
}
