#ifndef RATIONAL28B_H
#define RATIONAL28B_H
#include <string>

class Rational28B
{
public:
    void Init( int32_t x, int16_t y );
    void Display( ) const;
    void Read( );
    std::string ToString( ) const;

    Rational28B Add( const Rational28B & b ) const;
    Rational28B Sub( const Rational28B & b ) const;
    Rational28B Mul( const Rational28B & b ) const;
    Rational28B Div( const Rational28B & b ) const;

    bool Eq( const Rational28B & b ) const;
    bool Great( const Rational28B & b ) const;
    bool Less( const Rational28B & b ) const;

private:
    void reduce( );

public:
    int32_t a;
    int32_t b;
};

#endif // RATIONAL28B_H
