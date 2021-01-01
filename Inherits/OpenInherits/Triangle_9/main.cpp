#include "rightangled.h"
#include <iostream>

Triangle9 & foo( Triangle9 & tr )
{
    tr.Display( );
    return tr;
}

int main()
{
    //TODO тут
    Triangle9 tr( 4, 5, 3 );
    tr.Display( );

    RightAngled ra( 4, 5, 3 );
    ra.Display( );

    foo( ra );

    Triangle9 * pB;
    pB = new RightAngled( 4, 5, 3 );
    foo( *pB );

    Triangle9 lhs = ra;
    lhs = ra;
    lhs.Display( );
    lhs.setAb( 5 );
    lhs.setAc( 6 );
    lhs.setBc( 4 );
    lhs.Display( );
    //    std::cout << "area = " << static_cast< RightAngled * >( &lhs )->Area( );

    RightAngled rhs;
    rhs = lhs;
    rhs.Display( );
}
