#ifndef MONEY24A_H
#define MONEY24A_H
#include <string>

struct Money24A {
    int32_t rub { 0 };
    uint8_t cop { 0 };
};

#pragma pack( push, 1 )
struct Money24A_T {
    int32_t rub;
    uint8_t cop;
};
#pragma pack( pop )

void Init( Money24A & mn, int32_t rb, int16_t cp );
void Display( const Money24A & mn );
void Read( Money24A & mn );
std::string ToString( const Money24A & mn );

Money24A Add( const Money24A & a, const Money24A & b );
Money24A Sub( const Money24A & a, const Money24A & b );
// Money24A Mul( const Money24A & a, const Money24A & b ); бессмысленная операция
Money24A Mul( const Money24A & a, double x );
double Div( const Money24A & a, const Money24A & b );
Money24A Div( const Money24A & a, double x );
bool Eq( const Money24A & a, const Money24A & b );
bool NotEqu( const Money24A & a, const Money24A & b );
bool Less( const Money24A & a, const Money24A & b );
bool LessOrEq( const Money24A & a, const Money24A & b );
bool Greater( const Money24A & a, const Money24A & b );
bool GreaterOrEq( const Money24A & a, const Money24A & b );

#endif	      // MONEY24A_H
