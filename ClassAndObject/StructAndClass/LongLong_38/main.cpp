#include <iostream>
#include <longlong38b.h>

int main( )
{
    LongLong38B lng;
    lng.Init( -9039381371528950324 );
    lng.Display( );

    LongLong38B lng2;
    lng2.Init( 147961868306861516 );

    lng.Add( lng2 ).Display( );

    LongLong38B lng3;
    lng2.Init( 50000000000 );
    lng.Div( lng2 ).Display( );

    lng.Sub( lng ).Display( );
}
