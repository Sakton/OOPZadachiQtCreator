#ifndef RATIONAL28A_H
#define RATIONAL28A_H
#include <string>

struct Rational28A {
    int32_t a;
    int32_t b;
    void Sokratit( );

private:
    void reduce( );
    int reduce( int aa, int bb );
};

void Init( Rational28A & pt, int32_t x, int16_t y );
void Display( const Rational28A & pt );
void Read( Rational28A & pt );
std::string ToString( const Rational28A & pt );

Rational28A Add( const Rational28A & a, const Rational28A & b );
Rational28A Sub( const Rational28A & a, const Rational28A & b );
Rational28A Mul( const Rational28A & a, const Rational28A & b );
Rational28A Div( const Rational28A & a, const Rational28A & b );

bool Eq( const Rational28A & a, const Rational28A & b );
bool Great( const Rational28A & a, const Rational28A & b );
bool Less( const Rational28A & a, const Rational28A & b );

#endif // RATIONAL28A_H
