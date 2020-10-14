#ifndef REAL_H
#define REAL_H
#include "number.h"

class Real : public Number {
public:
    Real( float f = 0 );

    Real pow( double n );
    Real log( );
};

#endif // REAL_H
