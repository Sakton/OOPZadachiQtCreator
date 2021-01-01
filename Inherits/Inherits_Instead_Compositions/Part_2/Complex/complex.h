#ifndef COMPLEX_H
#define COMPLEX_H
#include <string>

class Pair {
public:
    Pair( double a = 0, double b = 0 );

    friend bool operator<( const Pair & a, const Pair & b );
    friend bool operator<=( const Pair & a, const Pair & b );
    friend bool operator>( const Pair & a, const Pair & b );
    friend bool operator>=( const Pair & a, const Pair & b );
    friend bool operator==( const Pair & a, const Pair & b );
    friend bool operator!=( const Pair & a, const Pair & b );

    friend void Display( const Pair & a );
    explicit operator std::string( ) const;

    double getFirst( ) const;
    void setFirst( double value );
    double getSecond( ) const;
    void setSecond( double value );

private:
    double first;
    double second;
};

class Complex : public Pair {
public:
    Complex( double a = 0, double b = 0 );
    Complex & operator+=( const Complex & oth );
    Complex & operator-=( const Complex & oth );
    Complex & operator*=( const Complex & oth );
    Complex & operator/=( const Complex & oth );
    Complex & operator-( );
};

#endif // COMPLEX_H
