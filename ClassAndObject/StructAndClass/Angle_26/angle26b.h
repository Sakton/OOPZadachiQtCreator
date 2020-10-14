#ifndef ANGLE26B_H
#define ANGLE26B_H
#include <string>

class Angle26B
{
public:
    void Init( int16_t g, int16_t m );
    void Init( double angl );
    void Read( );
    void Display( ) const;
    std::string ToString( ) const;

    double ToRadian( ) const;
    Angle26B Normalise( ) const;
    void Normalise( );
    Angle26B Adding( int16_t g, int16_t m ) const;
    Angle26B Adding( const Angle26B & other ) const;
    Angle26B Substr( int16_t g, int16_t m ) const;
    Angle26B Substr( const Angle26B & other ) const;
    double Sinus( ) const;
    double Angle( ) const;

    bool Eq( const Angle26B & an2 );
    bool NotEq( const Angle26B & an2 );
    bool Less( const Angle26B & an2 );
    bool LessEq( const Angle26B & an2 );
    bool Greater( const Angle26B & an2 );
    bool GreaterEq( const Angle26B & an2 );

private:
    int16_t grad;
    int16_t min;
};

#endif // ANGLE26B_H
