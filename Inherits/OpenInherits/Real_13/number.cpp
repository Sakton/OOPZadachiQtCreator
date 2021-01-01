#include "number.h"
#include <iostream>

Number::Number( float f )
    : f_ { f }
{
}

Number & Number::operator+=( const Number & ot )
{
    f_ += ot.f_;
    return *this;
}

Number & Number::operator/=( const Number & ot )
{
    if ( ot.f_ == 0.0 ) {
        std::cout << "ERROR";
        exit( 1 );
    }
    f_ /= ot.f_;
    return *this;
}

float Number::f() const
{
    return f_;
}
