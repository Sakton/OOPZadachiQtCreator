#include "real.h"
#include <cmath>

Real::Real( float f )
    : Number( f )
{
}

Real Real::pow( double n )
{
    //    if ( n == 1 )
    //        return num;
    //    else {
    //        Number t;
    //        for ( int i = 0; i < num.f( ); ++i ) {
    //            t += pow( num, n - 1 );
    //        }
    //        return t;
    //    }

    return Real( std::pow( f( ), n ) );
}

Real Real::log( )
{
    return Real( std::log( f( ) ) );
}
