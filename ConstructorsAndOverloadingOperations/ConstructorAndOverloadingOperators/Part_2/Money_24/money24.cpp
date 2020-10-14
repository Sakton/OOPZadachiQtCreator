#include "money24.h"

#include <iostream>
#include <sstream>

void Display( const Money24B & b )
{
    std::cout << ToString( b ) << std::endl;
}

void Read( Money24B & b )
{
    int32_t aa = 0;
    int16_t bb = 0;
    std::cout << "Enter rub cop" << std::endl;
    std::cin >> aa >> bb;
    b = Money24B( aa, bb );
}

std::string ToString( const Money24B & b )
{
    std::stringstream ss;
    ss << std::fixed << b.rub << ",";
    int x = static_cast< int >( b.cop );
    if ( x < 10 )
        ss << '0';
    ss << x;
    return ss.str( );
}

Money24B::Money24B( int32_t rb, int16_t cp )
{
    if ( !( 0 <= cp && cp < 100 ) ) {
        std::cout << "ERROR DATA COP < 0";
        exit( 1 );
    }
    rub = rb;
    cop = cp;
}

Money24B & Money24B::operator+=( const Money24B & b )
{
    int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
    int64_t rurB = ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
    int64_t summ = rurA + rurB;
    rub = summ / 100;
    cop = std::abs( summ % 100 );
    return *this;
}

Money24B & Money24B::operator-=( const Money24B & b )
{

    int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
    int64_t rurB = ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
    int64_t divide = rurA - rurB;
    rub = divide / 100;
    cop = std::abs( divide % 100 );
    return *this;
}

Money24B & Money24B::operator*=( double x )
{
    int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
    int64_t mul = rurA * x;
    rub = mul / 100;
    cop = std::abs( mul % 100 );
    return *this;
}

double Money24B::operator/=( const Money24B & b )
{
    int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
    int64_t rurB = ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
    if ( rurB == 0 ) {
        std::cout << "ERROR DIVIDE ZERO!!!";
        exit( 1 );
    }
    return rurA / rurB;
}

Money24B & Money24B::operator/=( double x )
{
    if ( x == 0 ) {
        std::cout << "ERROR DIVIDE ZERO!!!";
        exit( 1 );
    }
    int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
    int64_t div = rurA / x;

    rub = div / 100;
    cop = std::abs( div % 100 );
    return *this;
}

Money24B operator+( const Money24B & a, const Money24B & b )
{
    Money24B loc = a;
    loc += b;
    return loc;
}

Money24B operator-( const Money24B & a, const Money24B & b )
{
    Money24B loc = a;
    loc -= b;
    return loc;
}

Money24B operator*( const Money24B & a, double x )
{
    Money24B loc = a;
    loc *= x;
    return loc;
}

double operator/( const Money24B & a, const Money24B & b )
{
    Money24B loc = a;
    return loc /= b;
}

Money24B operator/( const Money24B & a, double x )
{
    Money24B loc = a;
    loc /= x;
    return loc;
}

bool operator==( const Money24B & a, const Money24B & b )
{
    return ( a.rub == b.rub && a.cop == b.cop );
}
bool operator!=( const Money24B & a, const Money24B & b )
{
    return !( a == b );
}
bool operator<=( const Money24B & a, const Money24B & b )
{
    return ( a == b ) || ( a < b );
}
bool operator>=( const Money24B & a, const Money24B & b )
{
    return a > b || a == b;
}
bool operator<( const Money24B & a, const Money24B & b )
{
    return ( ( a.rub < b.rub ) || ( ( a.rub == b.rub ) && ( a.cop < b.cop ) ) );
}

bool operator>( const Money24B & a, const Money24B & b )
{
    return !( a <= b );
}

int32_t Money24B::GetRub( ) const
{
    return rub;
}

uint8_t Money24B::GetCop( ) const
{
    return cop;
}
