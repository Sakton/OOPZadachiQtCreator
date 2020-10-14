#include "money33b.h"
#include <iomanip>
#include <iostream>
#include <sstream>

const double Money33B::NOMIMALS_BILL[] { 0.01, 0.05, 0.1, 0.5, 1, 2, 5, 10, 50, 100, 200, 500, 1000, 2000, 5000 };

void Money33B::Init( double sum )
{
    if ( sum < 0 ) {
	std::cout << "ERROR SUM INIT";
	exit( 1 );
    }
    ParseSum( sum );
}

void Money33B::Display( ) const
{
    std::cout << ToString( ) << std::endl;
}

std::string Money33B::ToString( ) const
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision( 2 ) << ToDouble( );
    return ss.str( );
}

Money33B Money33B::Add( const Money33B & b )
{
    Money33B loc;
    loc.Init( ToDouble( ) + b.ToDouble( ) );
    return loc;
}

Money33B Money33B::Sub( const Money33B & b )
{
    Money33B loc;
    loc.Init( ToDouble( ) - b.ToDouble( ) );
    return loc;
}

Money33B Money33B::Mul( double x )
{
    Money33B loc;
    loc.Init( ToDouble( ) * x );
    return loc;
}

double Money33B::Div( const Money33B & b )
{
    if ( b.ToDouble( ) == 0.0 ) {
	std::cout << "ERROR DIV ZERO";
	exit( 1 );
    }
    return ToDouble( ) / b.ToDouble( );
}

Money33B Money33B::Div( double x )
{
    if ( x == 0.0 ) {
	std::cout << "ERROR DIV ZERO";
	exit( 1 );
    }
    Money33B loc;
    loc.Init( ToDouble( ) / x );
    return loc;
}

bool Money33B::Eq( const Money33B & b )
{
    return ( ToDouble( ) - b.ToDouble( ) ) < 1e-3;
}

bool Money33B::NotEqu( const Money33B & b )
{
    return !Eq( b );
}

bool Money33B::Less( const Money33B & b )
{
    return ToDouble( ) < b.ToDouble( );
}

bool Money33B::LessOrEq( const Money33B & b )
{
    return Less( b ) || Eq( b );
}

bool Money33B::Greater( const Money33B & b )
{
    return !LessOrEq( b );
}

bool Money33B::GreaterOrEq( const Money33B & b )
{
    return !Less( b ) || Eq( b );
}

double Money33B::ToDouble( ) const
{
    int res = 0;
    int copRes = 0;
    for ( int i = 0; i <= INDEX_COP; ++i ) {
	copRes += ( NOMIMALS_BILL[ i ] * 100 ) * summa_[ i ];
    }
    for ( int i = INDEX_COP + 1; i < COUNT_ELEMENTS; ++i ) {

	res += NOMIMALS_BILL[ i ] * summa_[ i ];
    }
    return ( double( res ) + double( copRes ) / 100 );
}

void Money33B::ParseSum( double sum )
{
    int64_t rur = sum;
    int cop = ( sum - rur ) * 1000;
    int pogr = cop % 10;
    cop /= 10;
    //поправка на погрешность
    if ( pogr >= 5 )
	++cop;

    summa_[ NOM_50_COP ]
	= cop / 50;
    cop %= 50;
    summa_[ NOM_10_COP ] = cop / 10;
    cop %= 10;
    summa_[ NOM_5_COP ] = cop / 5;
    cop %= 5;
    summa_[ NOM_1_COP ] = cop;

    summa_[ NOM_5000_RUR ] = rur / 5000;
    rur %= 5000;
    summa_[ NOM_2000_RUR ] = rur / 2000;
    rur %= 2000;
    summa_[ NOM_1000_RUR ] = rur / 1000;
    rur %= 1000;
    summa_[ NOM_500_RUR ] = rur / 500;
    rur %= 500;
    summa_[ NOM_100_RUR ] = rur / 100;
    rur %= 100;
    summa_[ NOM_50_RUR ] = rur / 50;
    rur %= 50;
    summa_[ NOM_10_RUR ] = rur / 10;
    rur %= 10;
    summa_[ NOM_5_RUR ] = rur / 5;
    rur %= 5;
    summa_[ NOM_2_RUR ] = rur / 2;
    rur %= 2;
    summa_[ NOM_1_RUR ] = rur;
}
