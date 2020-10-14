#include <iostream>

using namespace std;

#include "bitstring37b.h"
#include <iostream>

int main()
{

    //    uint32_t x = 1;
    //    uint32_t mask = 1;
    //    mask <<= 31;

    //    for ( int i = 0; i <= 31; ++i ) {
    //	std::cout << ( ( x & mask ) ? '1' : '0' );
    //	mask >>= 1;
    //    }
    //    std::cout << std::endl;
    //    uint32_t y = 1;
    //    y <<= 4;
    //    x |= y;
    //    mask <<= 30;

    //    for ( int i = 0; i < 30; ++i ) {
    //	std::cout << ( ( x & mask ) ? '1' : '0' );
    //	mask >>= 1;
    //    }
    //    std::cout << std::endl;

    //    Bitstring37B bts;
    //    bts.Init( 1, 1 );
    //    bts.Display( );

    //    Bitstring37B bts1;
    //    bts1.Init( 1, 2 );
    //    bts1.Display( );

    //    bts.And( bts1 ).Display( );
    //    bts.Or( bts1 ).Display( );
    //    bts.Xor( bts1 ).Display( );
    //    bts.Not( ).Display( );

    Bitstring37B bts3;
    bts3.Init( 0, 1 );
    bts3.Display( );
    bts3.ShiftLeft( 60 ).Display( );

    Bitstring37B bts4;
    bts4.Init( 2147483648, 0 );
    bts4.Display( );
    bts4.ShiftRight( 60 ).Display( );

    //    uint32_t x = 2147483648;
    //    uint32_t y = 536870912;
    //    //std::cout << ( x | y );

    //    for ( int i = 0; i < 10; ++i ) {
    //	if ( x & y )
    //	    std::cout << x;
    //	y <<= 1;
    //    }

    return 0;
}
