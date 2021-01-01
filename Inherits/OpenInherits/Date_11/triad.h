#ifndef TRIAD_H
#define TRIAD_H
#include <string>

class Triad {
public:
    int a( ) const;
    void setA( int a );
    int b( ) const;
    void setB( int b );
    int c( ) const;
    void setC( int c );

    friend bool operator==( const Triad & a, const Triad & b );
    friend bool operator<( const Triad & a, const Triad & b );

    explicit operator std::string( ) const;
    void Display( ) const;

private:
    int a_ { 0 };
    int b_ { 0 };
    int c_ { 0 };
};

#endif // TRIAD_H
