#include "triangle.h"

Triad7 & foo( Triad7 & t )
{
    t.Display( );
    return t;
}

int main()
{
    Triangle tr( 3, 4, 5 );
    tr.Display( );
    foo( tr );
}
