#include "account41n.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>

void Account41N::Money24B::Init( int32_t rb, int16_t cp )
{
    if ( !( 0 <= cp && cp < 100 ) ) {
	std::cout << "ERROR DATA COP < 0";
	exit( 1 );
    }
    rub = rb;
    cop = cp;
}

void Account41N::Money24B::Display( ) const
{
    std::cout << ToString( ) << std::endl;
}

void Account41N::Money24B::Read( )
{
    int32_t a = 0;
    int16_t b = 0;
    std::cout << "Enter rub cop" << std::endl;
    std::cin >> a >> b;
    Init( a, b );
}

std::string Account41N::Money24B::ToString( ) const
{
    std::stringstream ss;
    ss << std::fixed << rub << ",";
    int x = static_cast< int >( cop );
    if ( x < 10 )
	ss << '0';
    ss << x;
    return ss.str( );
}

Account41N::Money24B Account41N::Money24B::Add( const Account41N::Money24B & b )
{
    Account41N::Account41N::Money24B res;
    int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
    int64_t rurB = ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
    int64_t summ = rurA + rurB;
    res.Init( summ / 100, std::abs( summ % 100 ) );
    return res;
}

Account41N::Money24B Account41N::Money24B::Sub( const Account41N::Money24B & b )
{
    Account41N::Money24B res;
    int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
    int64_t rurB = ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
    int64_t divide = rurA - rurB;
    res.Init( divide / 100, std::abs( divide % 100 ) );
    return res;
}

//Account41NN::Account41NN::Money24B Account41NN::Account41NN::Money24B::Mul( const Account41NN::Account41NN::Money24B & a, const Account41NN::Account41NN::Money24B & b )
//{
//    Account41NN::Account41NN::Money24B res;
//    int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
//    int64_t rurB = ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
//    int64_t mul = rurA * rurB;
//    res.Init( mul / 100, std::abs( mul % 100 ) );
//    return res;
//}

Account41N::Money24B Account41N::Money24B::Mul( double x )
{
    Account41N::Account41N::Money24B res;
    int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
    int64_t mul = rurA * x;
    res.Init( mul / 100, std::abs( mul % 100 ) );
    return res;
}

double Account41N::Money24B::Div( const Account41N::Money24B & b )
{
    int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
    int64_t rurB = ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
    if ( rurB == 0 ) {
	std::cout << "ERROR DIVIDE ZERO!!!";
	exit( 1 );
    }
    return rurA / rurB;
}

Account41N::Money24B Account41N::Money24B::Div( double x )
{
    if ( x == 0 ) {
	std::cout << "ERROR DIVIDE ZERO!!!";
	exit( 1 );
    }
    Account41N::Money24B res;
    int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
    int64_t div = rurA / x;
    res.Init( div / 100, std::abs( div % 100 ) );
    return res;
}

bool Account41N::Money24B::Eq( const Account41N::Money24B & b )
{
    return ( rub == b.rub && cop == b.cop );
}

bool Account41N::Money24B::NotEqu( const Account41N::Money24B & b )
{
    return !Eq( b );
}

bool Account41N::Money24B::Less( const Account41N::Money24B & b )
{
    return ( ( rub < b.rub ) || ( ( rub == b.rub ) && ( cop < b.cop ) ) );
}

bool Account41N::Money24B::LessOrEq( const Account41N::Money24B & b )
{
    return ( Less( b ) || Eq( b ) );
}

bool Account41N::Money24B::Greater( const Account41N::Money24B & b )
{
    return !LessOrEq( b );
}

bool Account41N::Money24B::GreaterOrEq( const Account41N::Money24B & b )
{
    return ( !Less( b ) || Eq( b ) );
}

void Account41N::Init( std::string name, std::string acc, double proc, double summ )
{
    name_ = name;
    accountNum_ = acc;
    procent_ = proc;
    //summa_ = summ;
    summa_.Init( summ, ( summ - static_cast< int16_t >( summ ) ) * 100 );
}

void Account41N::Display( ) const
{
    std::cout << ToString( ) << std::endl;
}

std::string Account41N::ToString( ) const
{
    std::stringstream ss;
    ss << "   Name: " << name_ << std::endl
       << "Account: " << accountNum_ << std::endl
       << "Procent: " << procent_ << std::endl
       << std::fixed << std::setprecision( 2 )
       << "  Summa: " << summa_.ToString( ) << std::endl;
    return ss.str( );
}

std::string Account41N::name( ) const
{
    return name_;
}

void Account41N::setName( const std::string & name )
{
    name_ = name;
}

void Account41N::AddSumm( double sm )
{
    if ( sm < 0 ) {
	std::cout << "ERROR ADDING SUM < 0";
	exit( 1 );
    }
    Money24B obj;
    obj.Init( sm, ( sm - static_cast< int >( sm ) ) * 100 );
    summa_ = summa_.Add( obj );
}

void Account41N::SubSumm( double sm )
{
    if ( sm < 0 ) {
	std::cout << "ERROR SUB SUM < 0";
	exit( 1 );
    }
    Money24B obj;
    obj.Init( sm, ( sm - static_cast< int >( sm ) ) * 100 );
    summa_ = summa_.Sub( obj );
}

void Account41N::AddProcent( )
{
    summa_ = summa_.Add( summa_.Mul( procent_ / 100 ) );
}

double Account41N::ToDollar( double cours )
{
    Money24B obj;
    obj.Init( cours, ( cours - static_cast< int >( cours ) ) * 100 );
    return summa_.Div( obj );
}

double Account41N::ToEuro( double cours )
{
    Money24B obj;
    obj.Init( cours, ( cours - static_cast< int >( cours ) ) * 100 );
    return summa_.Div( obj );
}

std::string Account41N::ToChislitelnoe( )
{
    int64_t rur = summa_.GetRub( );
    int16_t cop = summa_.GetCop( );

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

std::string Account41N::Sotni( int chislo )
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

std::string Account41N::Desyatki( int chislo )
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

std::string Account41N::Edinitsy( int chislo )
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

std::string Account41N::ParseSotni( int chislo )
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

std::string Account41N::ParseThousand( int chislo )
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

int32_t Account41N::Money24B::GetRub( ) const
{
    return rub;
}

uint8_t Account41N::Money24B::GetCop( ) const
{
    return cop;
}
