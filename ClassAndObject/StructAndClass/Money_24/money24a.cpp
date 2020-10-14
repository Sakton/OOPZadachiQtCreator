#include "money24a.h"
#include <iomanip>
#include <iostream>
#include <sstream>

void Init( Money24A & mn, int32_t rb, int16_t cp )
{
    if ( !( 0 <= cp && cp < 100 ) ) {
	std::cout << "ERROR DATA COP < 0";
	exit( 1 );
    }
    mn.rub = rb;
    mn.cop = cp;
}

void Display( const Money24A & mn )
{
    std::cout << ToString( mn ) << std::endl;
}

void Read( Money24A & mn )
{
    int32_t a = 0;
    int16_t b = 0;
    std::cout << "Enter rub cop" << std::endl;
    std::cin >> a >> b;
    Init( mn, a, b );
}

std::string ToString( const Money24A & mn )
{
    std::stringstream ss;
    ss << std::fixed << mn.rub << ",";
    int x = static_cast< int >( mn.cop );
    if ( x < 10 )
	ss << '0';
    ss << x;
    return ss.str( );
}

Money24A Add( const Money24A & a, const Money24A & b )
{
    Money24A res;
    int64_t rurA = ( a.rub < 0 ) ? ( a.rub * 100 - a.cop ) : ( a.rub * 100 + a.cop );
    int64_t rurB = ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
    int64_t summ = rurA + rurB;
    Init( res, summ / 100, std::abs( summ % 100 ) );
    return res;
}

Money24A Sub( const Money24A & a, const Money24A & b )
{
    Money24A res;
    int64_t rurA = ( a.rub < 0 ) ? ( a.rub * 100 - a.cop ) : ( a.rub * 100 + a.cop );
    int64_t rurB = ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
    int64_t divide = rurA - rurB;
    Init( res, divide / 100, std::abs( divide % 100 ) );
    return res;
}

//Money24A Mul( const Money24A & a, const Money24A & b )
//{
//    Money24A res;
//    int64_t rurA = ( a.rub < 0 ) ? ( a.rub * 100 - a.cop ) : ( a.rub * 100 + a.cop );
//    int64_t rurB = ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
//    int64_t mul = rurA * rurB;
//    Init( res, mul / 100, std::abs( mul % 100 ) );
//    return res;
//}

Money24A Mul( const Money24A & a, double x )
{
    Money24A res;
    int64_t rurA = ( a.rub < 0 ) ? ( a.rub * 100 - a.cop ) : ( a.rub * 100 + a.cop );
    int64_t mul = rurA * x;
    Init( res, mul / 100, std::abs( mul % 100 ) );
    return res;
}

double Div( const Money24A & a, const Money24A & b )
{
    //Деньга деленная на деньгу не будет деньга, а будет количество частей
    int64_t rurA = ( a.rub < 0 ) ? ( a.rub * 100 - a.cop ) : ( a.rub * 100 + a.cop );
    int64_t rurB = ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
    if ( rurB == 0 ) {
	std::cout << "ERROR DIVIDE ZERO!!!";
	exit( 1 );
    }
    return rurA / rurB;
}

Money24A Div( const Money24A & a, double x )
{
    if ( x == 0 ) {
	std::cout << "ERROR DIVIDE ZERO!!!";
	exit( 1 );
    }
    Money24A res;
    int64_t rurA = ( a.rub < 0 ) ? ( a.rub * 100 - a.cop ) : ( a.rub * 100 + a.cop );
    int64_t div = rurA / x;
    Init( res, div / 100, std::abs( div % 100 ) );
    return res;
}

bool Eq( const Money24A & a, const Money24A & b )
{
    return ( a.rub == b.rub && a.cop == b.cop );
}

bool NotEqu( const Money24A & a, const Money24A & b )
{
    return !Eq( a, b );
}

bool Less( const Money24A & a, const Money24A & b )
{
    return ( ( a.rub < b.rub ) || ( ( a.rub == b.rub ) && ( a.cop < b.cop ) ) );
}

bool LessOrEq( const Money24A & a, const Money24A & b )
{
    return ( Less( a, b ) || Eq( a, b ) );
}

bool Greater( const Money24A & a, const Money24A & b )
{
    return !LessOrEq( a, b );
}

bool GreaterOrEq( const Money24A & a, const Money24A & b )
{
    return ( !Less( a, b ) || Eq( a, b ) );
}
