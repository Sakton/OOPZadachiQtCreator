#include "bankomat34b.h"
#include <algorithm>
#include <iostream>

void Bankomat34B::Init( int32_t id, int32_t min, int32_t max, SpecArray cassetaMoney )
{
    if ( id < 0 || min < 0 || max < 0 ) {
	std::cout << "ERROR ARG INIT";
	exit( 1 );
    }

    id_ = id;
    min_ = min;
    max_ = max;

    AddCash( cassetaMoney );
}

void Bankomat34B::Display( )
{
    std::cout << ToString( ) << std::endl;
}

std::string Bankomat34B::ToString( )
{
    int64_t res = RemainerCash( );
    return std::to_string( res );
}

void Bankomat34B::AddCash( Bankomat34B::SpecArray cassetaMoney )
{
    if ( cassetaMoney ) {
	for ( int i = 0; i < COUNT_ELEMENTS; ++i ) {
	    if ( cassetaMoney[ i ] < 0 ) {
		std::cout << "BAD CASSETE";
		exit( 1 );
	    }
	    cash_[ i ] += cassetaMoney[ i ];
	}
    }
}

void Bankomat34B::SubCash( int32_t summ )
{
    if ( summ > RemainerCash( ) || summ > max_ || summ < min_ ) {
	std::cout << "ERROR SUM SUBS";
	exit( 1 );
    }
    SpecArray subArray { 0 };
    for ( int i = COUNT_ELEMENTS - 1; i >= 0 && summ; --i ) {
	//int coupure = cash_[ i ];
	//	while ( summ >= NOMIMALS_BILL[ i ] && coupure > 0 ) {
	//	    subArray[ i ]++;
	//	    //cash_[ i ]--; //тут вычитать сразу нельзя, а если сумма не наберется
	//	    //поэтому вычитание будет отдельно.
	//	    --coupure;
	//	    summ -= NOMIMALS_BILL[ i ];
	//	}
	//А МОЖНО и БЕЗ ЦИКЛА !!!!!!!!!!!!!
	//1. Сколько надо купюр и сколько их есть в наличии
	subArray[ i ] = std::min< int16_t >( ( summ / NOMIMALS_BILL[ i ] ), cash_[ i ] );
	summ -= subArray[ i ] * NOMIMALS_BILL[ i ];
    }

    if ( summ ) {
	std::cout << "I can't type bills";
	std::cout << "ENTER ANOTHER SUMM";
	exit( 1 );
    }
    //выдача купюр
    for ( int i = 0; i < COUNT_ELEMENTS; ++i ) {
	cash_[ i ] -= subArray[ i ];
    }
}

void Bankomat34B::ParsePoNominals( int32_t summ, SpecArray arr )
{
    arr[ NOM_1000_RUR ] = summ / NOMIMALS_BILL[ NOM_1000_RUR ];
    summ %= NOMIMALS_BILL[ NOM_1000_RUR ];
    arr[ NOM_500_RUR ] = summ / NOMIMALS_BILL[ NOM_500_RUR ];
    summ %= NOMIMALS_BILL[ NOM_500_RUR ];
    arr[ NOM_100_RUR ] = summ / NOMIMALS_BILL[ NOM_100_RUR ];
    summ %= NOMIMALS_BILL[ NOM_100_RUR ];
    arr[ NOM_50_RUR ] = summ / NOMIMALS_BILL[ NOM_50_RUR ];
    summ %= NOMIMALS_BILL[ NOM_1000_RUR ];
    arr[ NOM_10_RUR ] = summ / NOMIMALS_BILL[ NOM_10_RUR ];
    summ %= NOMIMALS_BILL[ NOM_10_RUR ];
}

int64_t Bankomat34B::RemainerCash( )
{
    int64_t res = 0;
    for ( int i = 0; i < COUNT_ELEMENTS; ++i ) {
	res += cash_[ i ] * NOMIMALS_BILL[ i ];
    }
    return res;
}
