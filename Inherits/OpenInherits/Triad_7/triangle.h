#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "triad7.h"

class Triangle : public Triad7 {
public:
    Triangle( double a = 0, double b = 0, double c = 0 );
    void Display( ) const;
    operator std::string( ) const;
    double Area( ) const;
    double angA( ) const;
    double angB( ) const;
    double angC( ) const;
};

#endif // TRIANGLE_H
