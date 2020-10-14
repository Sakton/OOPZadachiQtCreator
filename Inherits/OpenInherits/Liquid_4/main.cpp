#include "alcohol.h"
#include <iostream>

Liquid4 & foo( Liquid4 & obj )
{
    obj.Display( );
    return obj;
}

int main( )
{
    Liquid4 l = Alcohol( "Alc", 100.0, 40 );
    foo( l ).Display( );
    Alcohol al = Alcohol( "Alc1", 200.0, 20 );
    al.Display( );
    foo( al ).Display( );

    al = foo( l );
    al.Display( );

    l.setName( "BBbb" );
    l.setRo( 234.0 );
    l.Display( );

    al.setKrep( 98 );
    al.setName( "988" );
    al.setRo( 98.0 );
    al.Display( );
}
