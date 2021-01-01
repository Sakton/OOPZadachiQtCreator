#include "rectangle.h"
#include <iostream>

Pair5 & foo( Pair5 & obj )
{
    obj.Display( );
    return obj;
}

int main( )
{
    Pair5 *p1, *p2;
    p1 = new Rectangle( 3, 4 );
    foo( *p1 ).Display( );
    p1->Display( );
    Rectangle * rect = static_cast< Rectangle * >( p1 );
    rect->Display( );
    rect->setFirst( 10 );
    rect->Display( );
    rect->setSecond( 10 );
    rect->Display( );
    foo( *rect );
}
