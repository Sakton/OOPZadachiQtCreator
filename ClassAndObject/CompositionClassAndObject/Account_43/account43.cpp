#include "account43.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>

void Account43::Init( const std::string & name,
		      const std::string & acc,
		      double proc,
		      double summ,
		      const std::string & open_acc )
{
    name_ = name;
    accountNum_ = acc;
    procent_ = proc;
    summa_ = summ;
    open_acc_.Init( open_acc );
}

void Account43::Display( ) const
{
    std::cout << ToString( ) << std::endl;
}

std::string Account43::ToString( ) const
{
    std::stringstream ss;
    ss << "   Name: " << name_ << std::endl
       << "Account: " << accountNum_ << std::endl
       << "Procent: " << procent_ << std::endl
       << std::fixed << std::setprecision( 2 )
       << "  Summa: " << summa_ << std::endl
       << "   Date: " << open_acc_.ToString( );
    return ss.str( );
}

std::string Account43::name( ) const
{
    return name_;
}

void Account43::setName( const std::string & name )
{
    name_ = name;
}

void Account43::AddSumm( double sm )
{
    if ( sm < 0 ) {
	std::cout << "ERROR ADDING SUM < 0";
	exit( 1 );
    }
    summa_ += sm;
}

void Account43::SubSumm( double sm )
{
    if ( sm < 0 ) {
	std::cout << "ERROR SUB SUM < 0";
	exit( 1 );
    }
    summa_ -= sm;
}

void Account43::AddProcent( )
{
    summa_ += summa_ * procent_ / 100;
}

double Account43::ToDollar( double cours )
{
    return summa_ / cours;
}

double Account43::ToEuro( double cours )
{
    return summa_ / cours;
}

std::string Account43::ToChislitelnoe( )
{
    int64_t rur = summa_;
    int16_t cop = ( summa_ - rur ) * 100;

    std::string res = ParseThousand( rur );
    res += ParseSotni( rur );

    if ( cop ) {
	res += " ������, ";
	res += ParseSotni( cop );
	res += " ������";
    } else {
	res += " ������";
    }

    return res;
}

void Account43::AddProcentOnEveryDay( const std::string & currentDate )
{
    Date29B cur;
    cur.Init( currentDate );
    if ( int16_t k = open_acc_.Interval( cur ) > 0 ) {
	for ( int i = 0; i < k; ++i ) {
	    AddSumm( summa_ * 0.0001 );
	}
    }
}

std::string Account43::Sotni( int chislo )
{
    switch ( chislo ) {
	case 100:
	    return "���";
	case 200:
	    return "������";
	case 300:
	    return "������";
	case 400:
	    return "���������";
	case 500:
	    return "�������";
	case 600:
	    return "��������";
	case 700:
	    return "�������";
	case 800:
	    return "���������";
	case 900:
	    return "���������";
	default:
	    return "";
    }
}

std::string Account43::Desyatki( int chislo )
{
    switch ( chislo ) {
	case 10:
	    return "������";
	case 11:
	    return "�����������";
	case 12:
	    return "����������";
	case 13:
	    return "����������";
	case 14:
	    return "������������";
	case 15:
	    return "����������";
	case 16:
	    return "�����������";
	case 17:
	    return "�����������";
	case 18:
	    return "�������������";
	case 19:
	    return "������������";
	case 20:
	    return "��������";
	case 30:
	    return "��������";
	case 40:
	    return "�����";
	case 50:
	    return "���������";
	case 60:
	    return "����������";
	case 70:
	    return "���������";
	case 80:
	    return "����������";
	case 90:
	    return "���������";
	default:
	    return "";
    }
}

std::string Account43::Edinitsy( int chislo )
{
    switch ( chislo ) {
	case 1:
	    return "����";
	case 2:
	    return "���";
	case 3:
	    return "���";
	case 4:
	    return "������";
	case 5:
	    return "����";
	case 6:
	    return "�����";
	case 7:
	    return "����";
	case 8:
	    return "������";
	case 9:
	    return "������";
	default:
	    return "";
    }
}

std::string Account43::ParseSotni( int chislo )
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

std::string Account43::ParseThousand( int chislo )
{
    if ( chislo < 1000 )
	return { };
    std::string res = ParseSotni( chislo / 1000 );
    if ( ( chislo / 1000 ) % 10 == 1 ) {
	auto it = res.find( "����" );
	res.replace( it, it + 3, "����" );
    }
    if ( ( chislo / 1000 ) % 10 == 2 ) {
	auto it = res.find( "���" );
	res.replace( it, it + 3, "��� " );
    }
    if ( 1000 <= chislo && chislo < 1000000 ) {
	switch ( ( chislo / 1000 ) % 10 ) {
	    case 1:
		res += "������ ";
		break;
	    case 2:
	    case 3:
	    case 4:
		res += "������ ";
		break;
	    case 5:
	    case 6:
	    case 7:
	    case 8:
	    case 9:
	    case 0:
		res += "����� ";
		break;
	}
    }
    return res;
}
