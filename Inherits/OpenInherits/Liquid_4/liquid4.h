#ifndef LIQUID4_H
#define LIQUID4_H
#include <string>

class Liquid4
{
public:
    Liquid4( const std::string & name = { }, double ro = 0.0 );

    operator std::string( ) const;
    void Display( ) const;

    Liquid4 & operator=( const Liquid4 & lic );

    double ro( ) const;
    void setRo( double ro );
    std::string name( ) const;
    void setName( const std::string & name );

private:
    std::string name_;
    double ro_;
};

#endif // LIQUID4_H
