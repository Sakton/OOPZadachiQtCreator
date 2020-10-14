#ifndef ANGLE26C_H
#define ANGLE26C_H
#include <string>

struct DataAngle {
    int16_t grad;
    int16_t min;

    void Init( int16_t g, int16_t m );
    void Read( );
    void Display( ) const;
    std::string ToString( ) const;
};

class Angle26C
{
public:
    void Init( int16_t g, int16_t m );
    void Read( );
    void Display( ) const;
    std::string ToString( ) const;

    double ToRadian( ) const;
    Angle26C Normalise( ) const;
    void Normalise( );
    Angle26C Adding( int16_t g, int16_t m ) const;
    Angle26C Substr( int16_t g, int16_t m ) const;
    double Sinus( ) const;

    bool Eq( const Angle26C & an2 );
    bool NotEq( const Angle26C & an2 );
    bool Less( const Angle26C & an2 );
    bool LessEq( const Angle26C & an2 );
    bool Greater( const Angle26C & an2 );
    bool GreaterEq( const Angle26C & an2 );

private:
    DataAngle data_;
};

#endif // ANGLE26C_H
