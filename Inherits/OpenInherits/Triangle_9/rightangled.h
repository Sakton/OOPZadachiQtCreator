#ifndef RIGHTANGLED_H
#define RIGHTANGLED_H
#include "triangle9.h"

class RightAngled : public Triangle9 {
public:
    RightAngled( int32_t a = 0, int32_t b = 0, int32_t c = 0 );
    RightAngled & operator=( const Triangle9 & rhs );

    void Display( ) const;
    operator std::string( ) const;
    double AreaR( );
    double Area( ) const;

private:
    double area_;
};

#endif // RIGHTANGLED_H
