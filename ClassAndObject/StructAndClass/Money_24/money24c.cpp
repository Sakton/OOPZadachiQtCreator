#include "money24c.h"
#include <iostream>
#include <sstream>

void DataMoney::Init( int32_t rb, int16_t cp )
{
    if ( !( 0 <= cp && cp < 100 ) ) {
	std::cout << "ERROR DATA data.cop < 0";
	exit( 1 );
    }
    rub = rb;
    cop = cp;
}

void DataMoney::Display( )
{
    std::cout << ToString( ) << std::endl;
}

void DataMoney::Read( )
{
    int32_t a = 0;
    int16_t b = 0;
    std::cout << "Enter data.rub data.cop" << std::endl;
    std::cin >> a >> b;
    Init( a, b );
}

std::string DataMoney::ToString( )
{
    std::stringstream ss;
    ss << std::fixed << rub << ",";
    int x = static_cast< int >( cop );
    if ( x < 10 )
	ss << '0';
    ss << x;
    return ss.str( );
}

void Money24C::Init( int32_t rb, int16_t cp )
{
    data.Init( rb, cp );
}

void Money24C::Display( )
{
    data.Display( );
}

void Money24C::Read( )
{
    data.Read( );
}

std::string Money24C::ToString( )
{
    return data.ToString( );
}

Money24C Money24C::Add( const Money24C & b )
{
    Money24C res;
    int64_t rurA = ( data.rub < 0 ) ? ( data.rub * 100 - data.cop ) : ( data.rub * 100 + data.cop );
    int64_t rurB = ( b.data.rub < 0 ) ? ( b.data.rub * 100 - b.data.cop ) : ( b.data.rub * 100 + b.data.cop );
    int64_t summ = rurA + rurB;
    res.Init( summ / 100, std::abs( summ % 100 ) );
    return res;
}

Money24C Money24C::Sub( const Money24C & b )
{
    Money24C res;
    int64_t rurA = ( data.rub < 0 ) ? ( data.rub * 100 - data.cop ) : ( data.rub * 100 + data.cop );
    int64_t rurB = ( b.data.rub < 0 ) ? ( b.data.rub * 100 - b.data.cop ) : ( b.data.rub * 100 + b.data.cop );
    int64_t divide = rurA - rurB;
    res.Init( divide / 100, std::abs( divide % 100 ) );
    return res;
}

Money24C Money24C::Mul( double x )
{
    Money24C res;
    int64_t rurA = ( data.rub < 0 ) ? ( data.rub * 100 - data.cop ) : ( data.rub * 100 + data.cop );
    int64_t mul = rurA * x;
    res.Init( mul / 100, std::abs( mul % 100 ) );
    return res;
}

double Money24C::Div( const Money24C & b )
{
    int64_t rurA = ( data.rub < 0 ) ? ( data.rub * 100 - data.cop ) : ( data.rub * 100 + data.cop );
    int64_t rurB = ( b.data.rub < 0 ) ? ( b.data.rub * 100 - b.data.cop ) : ( b.data.rub * 100 + b.data.cop );
    if ( rurB == 0 ) {
	std::cout << "ERROR DIVIDE ZERO!!!";
	exit( 1 );
    }
    return rurA / rurB;
}

Money24C Money24C::Div( double x )
{
    if ( x == 0 ) {
	std::cout << "ERROR DIVIDE ZERO!!!";
	exit( 1 );
    }
    Money24C res;
    int64_t rurA = ( data.rub < 0 ) ? ( data.rub * 100 - data.cop ) : ( data.rub * 100 + data.cop );
    int64_t div = rurA / x;
    res.Init( div / 100, std::abs( div % 100 ) );
    return res;
}

bool Money24C::Eq( const Money24C & b )
{
    return ( data.rub == b.data.rub && data.cop == b.data.cop );
}

bool Money24C::NotEqu( const Money24C & b )
{
    return !Eq( b );
}

bool Money24C::Less( const Money24C & b )
{
    return ( ( data.rub < b.data.rub ) || ( ( data.rub == b.data.rub ) && ( data.cop < b.data.cop ) ) );
}

bool Money24C::LessOrEq( const Money24C & b )
{
    return ( Less( b ) || Eq( b ) );
}

bool Money24C::Greater( const Money24C & b )
{
    return !LessOrEq( b );
}

bool Money24C::GreaterOrEq( const Money24C & b )
{
    return ( !Less( b ) || Eq( b ) );
}
