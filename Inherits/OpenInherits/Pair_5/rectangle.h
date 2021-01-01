#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "pair5.h"

class Rectangle : public Pair5
{
public:
    Rectangle( int32_t a = 0, int32_t b = 0 );

    operator std::string( );
    void Display( );

    int32_t Perimeter( );
    int32_t Area( );
};

#endif // RECTANGLE_H
