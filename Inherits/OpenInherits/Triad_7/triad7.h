#ifndef TRIAD7_H
#define TRIAD7_H
#include <string>

class Triad7
{
public:
    Triad7( double a = 0, double b = 0, double c = 0 );
    void Display( ) const;
    operator std::string( ) const;

    double first( ) const;
    void setFirst( double first );
    double second( ) const;
    void setSecond( double second );
    double third( ) const;
    void setThird( double third );

private:
    double first_;
    double second_;
    double third_;
};

#endif // TRIAD7_H
