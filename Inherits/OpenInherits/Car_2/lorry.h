#ifndef LORRY_H
#define LORRY_H
#include "car.h"

class Lorry : public Car {
public:
    Lorry( const std::string & name = "", int16_t cyl = 0, int16_t pow = 0, int16_t mass = 0 );
    operator std::string( ) const;
    void Display( );

    int16_t mass( ) const;
    void setMass( const int16_t & mass );

private:
    int16_t mass_;
};

#endif // LORRY_H
