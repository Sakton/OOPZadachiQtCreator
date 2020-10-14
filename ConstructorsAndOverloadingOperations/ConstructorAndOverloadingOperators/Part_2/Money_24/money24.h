#ifndef MONEY24_H
#define MONEY24_H
#include <string>

class Money24B {
public:
    Money24B( int32_t rb = 0, int16_t cp = 0 );

    Money24B & operator+=( const Money24B & b );
    Money24B & operator-=( const Money24B & b );
    Money24B & operator*=( double x );
    Money24B & operator/=( double x );
    double operator/=( const Money24B & b );

    friend void Display( const Money24B & b );
    friend void Read( Money24B & b );
    friend std::string ToString( const Money24B & b );

    friend Money24B operator+( const Money24B & a, const Money24B & b );
    friend Money24B operator-( const Money24B & a, const Money24B & b );
    friend Money24B operator*( const Money24B & a, double x );
    friend double operator/( const Money24B & a, const Money24B & b );
    friend Money24B operator/( const Money24B & a, double x );

    friend bool operator==( const Money24B & a, const Money24B & b );
    friend bool operator!=( const Money24B & a, const Money24B & b );
    friend bool operator<=( const Money24B & a, const Money24B & b );
    friend bool operator>=( const Money24B & a, const Money24B & b );
    friend bool operator<( const Money24B & a, const Money24B & b );
    friend bool operator>( const Money24B & a, const Money24B & b );

    int32_t GetRub( ) const;
    uint8_t GetCop( ) const;

private:
    int32_t rub { 0 };
    uint8_t cop { 0 };
};

#endif // MONEY24_H
