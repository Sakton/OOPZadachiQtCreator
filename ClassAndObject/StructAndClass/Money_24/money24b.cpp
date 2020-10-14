#include "money24B.h"
#include <iostream>
#include <sstream>

void Money24B::Init( int32_t rb, int16_t cp )
{
    if ( !( 0 <= cp && cp < 100 ) ) {
	std::cout << "ERROR DATA COP < 0";
	exit( 1 );
    }
    rub = rb;
    cop = cp;
}

void Money24B::Display( ) const
{
    std::cout << ToString( ) << std::endl;
}

void Money24B::Read( )
{
    int32_t a = 0;
    int16_t b = 0;
    std::cout << "Enter rub cop" << std::endl;
    std::cin >> a >> b;
    Init( a, b );
}

std::string Money24B::ToString( ) const
{
    std::stringstream ss;
    ss << std::fixed << rub << ",";
    int x = static_cast< int >( cop );
    if ( x < 10 )
	ss << '0';
    ss << x;
    return ss.str( );
}

Money24B Money24B::Add( const Money24B & b )
{
    Money24B res;
    int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
    int64_t rurB = ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
    int64_t summ = rurA + rurB;
    res.Init( summ / 100, std::abs( summ % 100 ) );
    return res;
}

Money24B Money24B::Sub( const Money24B & b )
{
    Money24B res;
    int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
    int64_t rurB = ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
    int64_t divide = rurA - rurB;
    res.Init( divide / 100, std::abs( divide % 100 ) );
    return res;
}

Money24B Money24B::Mul( double x )
{
    Money24B res;
    int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
    int64_t mul = rurA * x;
    res.Init( mul / 100, std::abs( mul % 100 ) );
    return res;
}

double Money24B::Div( const Money24B & b )
{
    int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
    int64_t rurB = ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
    if ( rurB == 0 ) {
	std::cout << "ERROR DIVIDE ZERO!!!";
	exit( 1 );
    }
    return rurA / rurB;
}

Money24B Money24B::Div( double x )
{
    if ( x == 0 ) {
	std::cout << "ERROR DIVIDE ZERO!!!";
	exit( 1 );
    }
    Money24B res;
    int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
    int64_t div = rurA / x;
    res.Init( div / 100, std::abs( div % 100 ) );
    return res;
}

bool Money24B::Eq( const Money24B & b )
{
    return ( rub == b.rub && cop == b.cop );
}

bool Money24B::NotEqu( const Money24B & b )
{
    return !Eq( b );
}

bool Money24B::Less( const Money24B & b )
{
    return ( ( rub < b.rub ) || ( ( rub == b.rub ) && ( cop < b.cop ) ) );
}

bool Money24B::LessOrEq( const Money24B & b )
{
    return ( Less( b ) || Eq( b ) );
}

bool Money24B::Greater( const Money24B & b )
{
    return !LessOrEq( b );
}

bool Money24B::GreaterOrEq( const Money24B & b )
{
    return ( !Less( b ) || Eq( b ) );
}

int32_t Money24B::GetRub( ) const
{
    return rub;
}

uint8_t Money24B::GetCop( ) const
{
    return cop;
}
