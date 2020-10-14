#ifndef ANGLE26A_H
#define ANGLE26A_H
#include <string>

struct Angle26A {
    int16_t grad;
    int16_t min;
};

void Init( Angle26A & an, int16_t g, int16_t m );
void Read( Angle26A & an );
void Display( const Angle26A & an );
std::string ToString( const Angle26A & an );

double ToRadian( const Angle26A & an );
Angle26A Normalise( const Angle26A & an );
void Normalise( Angle26A & an );
Angle26A Adding( const Angle26A & an, int16_t g, int16_t m );
Angle26A Substr( const Angle26A & an, int16_t g, int16_t m );
double Sinus( const Angle26A & an );

bool Eq( const Angle26A & an1, const Angle26A & an2 );
bool NotEq( const Angle26A & an1, const Angle26A & an2 );
bool Less( const Angle26A & an1, const Angle26A & an2 );
bool LessEq( const Angle26A & an1, const Angle26A & an2 );
bool Greater( const Angle26A & an1, const Angle26A & an2 );
bool GreaterEq( const Angle26A & an1, const Angle26A & an2 );

#endif // ANGLE26A_H
