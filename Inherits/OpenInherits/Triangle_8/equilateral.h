#ifndef EQUILATERAL_H
#define EQUILATERAL_H
#include "triangle8.h"

class Equilateral : public Triangle8 {
public:
    Equilateral( int32_t a = 0, int32_t b = 0, int32_t c = 0 );
    Equilateral & operator=( const Triangle8 & oth );

    void Display( ) const;
    operator std::string( ) const;

    double Area( ) const;

private:
    double area_;
};

#endif // EQUILATERAL_H
