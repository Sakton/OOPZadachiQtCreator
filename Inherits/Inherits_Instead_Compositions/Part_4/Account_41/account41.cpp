#include "account41.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>

void Account41::Init( std::string name, std::string acc, double proc, double summ )
{
    name_ = name;
    accountNum_ = acc;
    procent_ = proc;
    //summa_ = summ;
    Money24B::Init( summ, ( summ - static_cast< int16_t >( summ ) ) * 100 );
}

void Account41::Display( ) const
{
    std::cout << ToString( ) << std::endl;
}

std::string Account41::ToString( ) const
{
    std::stringstream ss;
    ss << "   Name: " << name_ << std::endl
       << "Account: " << accountNum_ << std::endl
       << "Procent: " << procent_ << std::endl
       << std::fixed << std::setprecision( 2 )
       << "  Summa: " << static_cast< Money24B >( *this ).ToString( ) << std::endl;
    return ss.str( );
}

std::string Account41::name( ) const
{
    return name_;
}

void Account41::setName( const std::string & name )
{
    name_ = name;
}

void Account41::AddSumm( double sm )
{
    if ( sm < 0 ) {
	std::cout << "ERROR ADDING SUM < 0";
	exit( 1 );
    }
    Money24B obj;
    obj.Init( sm, ( sm - static_cast< int >( sm ) ) * 100 );
    //summa_ = summa_.Add( obj );
    Money24B t = static_cast< Money24B >( *this ).Add( obj );
    static_cast< Money24B >( *this ).Init( t.GetRub( ), t.GetCop( ) );
}

void Account41::SubSumm( double sm )
{
    if ( sm < 0 ) {
	std::cout << "ERROR SUB SUM < 0";
	exit( 1 );
    }
    Money24B obj;
    obj.Init( sm, ( sm - static_cast< int >( sm ) ) * 100 );
    //summa_ = summa_.Sub( obj );
    static_cast< Money24B >( *this ) = static_cast< Money24B >( *this ).Sub( obj );
}

void Account41::AddProcent( )
{
    static_cast< Money24B >( *this ) = static_cast< Money24B >( *this ).Add( static_cast< Money24B >( *this ).Mul( procent_ / 100 ) );
}

double Account41::ToDollar( double cours )
{
    Money24B obj;
    obj.Init( cours, ( cours - static_cast< int >( cours ) ) * 100 );
    return static_cast< Money24B >( *this ).Div( obj );
}

double Account41::ToEuro( double cours )
{
    Money24B obj;
    obj.Init( cours, ( cours - static_cast< int >( cours ) ) * 100 );
    return static_cast< Money24B >( *this ).Div( obj );
}

std::string Account41::ToChislitelnoe( )
{
    int64_t rur = static_cast< Money24B >( *this ).GetRub( );
    int16_t cop = static_cast< Money24B >( *this ).GetCop( );

    std::string res = ParseThousand( rur );
    res += ParseSotni( rur );

    if ( cop ) {
	res += " рублей, ";
	res += ParseSotni( cop );
	res += " копеек";
    } else {
	res += " рублей";
    }

    return res;
}

std::string Account41::Sotni( int chislo )
{
    switch ( chislo ) {
	case 100:
	    return "сто";
	case 200:
	    return "двести";
	case 300:
	    return "триста";
	case 400:
	    return "четыреста";
	case 500:
	    return "п¤тьсот";
	case 600:
	    return "шестьсот";
	case 700:
	    return "семьсот";
	case 800:
	    return "восемьсот";
	case 900:
	    return "дев¤тьсот";
	default:
	    return "";
    }
}

std::string Account41::Desyatki( int chislo )
{
    switch ( chislo ) {
	case 10:
	    return "дес¤ть";
	case 11:
	    return "одиннадцать";
	case 12:
	    return "двенадцать";
	case 13:
	    return "тринадцать";
	case 14:
	    return "четырнадцать";
	case 15:
	    return "п¤тнадцать";
	case 16:
	    return "шестнадцать";
	case 17:
	    return "семьнадцать";
	case 18:
	    return "восемьнадцать";
	case 19:
	    return "дев¤тнадцать";
	case 20:
	    return "двадцать";
	case 30:
	    return "тридцать";
	case 40:
	    return "сорок";
	case 50:
	    return "п¤тьдес¤т";
	case 60:
	    return "шестьдес¤т";
	case 70:
	    return "семьдес¤т";
	case 80:
	    return "восемдес¤т";
	case 90:
	    return "дев¤носто";
	default:
	    return "";
    }
}

std::string Account41::Edinitsy( int chislo )
{
    switch ( chislo ) {
	case 1:
	    return "один";
	case 2:
	    return "два";
	case 3:
	    return "три";
	case 4:
	    return "четыре";
	case 5:
	    return "п¤ть";
	case 6:
	    return "шесть";
	case 7:
	    return "семь";
	case 8:
	    return "восемь";
	case 9:
	    return "дев¤ть";
	default:
	    return "";
    }
}

std::string Account41::ParseSotni( int chislo )
{
    chislo %= 1000;
    std::stack< std::string > st;
    if ( 10 <= ( chislo % 100 ) && ( chislo % 100 ) <= 20 ) {
	st.push( Desyatki( chislo % 100 ) );
    } else if ( ( chislo % 100 ) <= 10 ) {
	st.push( Edinitsy( chislo % 10 ) );
    } else {
	st.push( Edinitsy( chislo % 10 ) );
	st.push( Desyatki( chislo % 100 - chislo % 10 ) );
    }
    st.push( Sotni( ( chislo / 100 ) * 100 ) );
    std::string res;
    while ( !st.empty( ) ) {
	res += st.top( );
	res += " ";
	st.pop( );
    }
    return res;
}

std::string Account41::ParseThousand( int chislo )
{
    if ( chislo < 1000 )
	return { };
    std::string res = ParseSotni( chislo / 1000 );
    if ( ( chislo / 1000 ) % 10 == 1 ) {
	auto it = res.find( "один" );
	res.replace( it, it + 3, "одна" );
    }
    if ( ( chislo / 1000 ) % 10 == 2 ) {
	auto it = res.find( "два" );
	res.replace( it, it + 3, "две " );
    }
    if ( 1000 <= chislo && chislo < 1000000 ) {
	switch ( ( chislo / 1000 ) % 10 ) {
	    case 1:
		res += "тыс¤ча ";
		break;
	    case 2:
	    case 3:
	    case 4:
		res += "тыс¤чи ";
		break;
	    case 5:
	    case 6:
	    case 7:
	    case 8:
	    case 9:
	    case 0:
		res += "тыс¤ч ";
		break;
	}
    }
    return res;
}
