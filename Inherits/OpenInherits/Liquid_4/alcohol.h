#ifndef ALCOHOL_H
#define ALCOHOL_H
#include "liquid4.h"

class Alcohol : public Liquid4 {
public:
    Alcohol( const std::string & name = { }, double ro = 0.0, double krep = 0.0 );
    void Display( ) const;

    Alcohol & operator=( const Liquid4 & li );
    Alcohol & operator=( const Alcohol & li );

    double krep( ) const;
    void setKrep( double krep );

    operator std::string( ) const;

private:
    double krep_;
};

#endif // ALCOHOL_H
