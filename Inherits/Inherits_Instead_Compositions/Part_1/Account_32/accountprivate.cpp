#include "accountprivate.h"

#include <iostream>
#include <stack>

AccountPrivate::AccountPrivate( const std::string& name, const std::string& acc,
                                double proc, double summ )
    : BaseAccount( name, acc, proc, summ ) {}

void AccountPrivate::AddSumm( double sm ) {
  if ( sm < 0 ) {
    std::cout << "ERROR ADDING SUM < 0";
    exit( 1 );
  }
  setSumma( getSumma( ) + sm );
}

void AccountPrivate::SubSumm( double sm ) {
  if ( sm < 0 ) {
    std::cout << "ERROR ADDING SUM < 0";
    exit( 1 );
  }
  setSumma( getSumma( ) - sm );
}

void AccountPrivate::AddProcent( ) {
  setSumma( getSumma( ) * getProcent( ) / 100 );
}

double AccountPrivate::ToDollar( double cours ) { return getSumma( ) / cours; }

double AccountPrivate::ToEuro( double cours ) { return getSumma( ) / cours; }

std::string AccountPrivate::ToChislitelnoe( ) {
  int64_t rur = getSumma( );
  int16_t cop = ( getSumma( ) - rur ) * 100;

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

std::string AccountPrivate::Sotni( int chislo ) {
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
      return "пЯтьсот";
    case 600:
      return "шестьсот";
    case 700:
      return "семьсот";
    case 800:
      return "восемьсот";
    case 900:
      return "девЯтьсот";
    default:
      return "";
  }
}

std::string AccountPrivate::Desyatki( int chislo ) {
  switch ( chislo ) {
    case 10:
      return "десЯть";
    case 11:
      return "одиннадцать";
    case 12:
      return "двенадцать";
    case 13:
      return "тринадцать";
    case 14:
      return "четырнадцать";
    case 15:
      return "пЯтнадцать";
    case 16:
      return "шестнадцать";
    case 17:
      return "семьнадцать";
    case 18:
      return "восемьнадцать";
    case 19:
      return "девЯтнадцать";
    case 20:
      return "двадцать";
    case 30:
      return "тридцать";
    case 40:
      return "сорок";
    case 50:
      return "пЯтьдесЯт";
    case 60:
      return "шестьдесЯт";
    case 70:
      return "семьдесЯт";
    case 80:
      return "восемдесЯт";
    case 90:
      return "девЯносто";
    default:
      return "";
  }
}

std::string AccountPrivate::Edinitsy( int chislo ) {
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
      return "пЯть";
    case 6:
      return "шесть";
    case 7:
      return "семь";
    case 8:
      return "восемь";
    case 9:
      return "девЯть";
    default:
      return "";
  }
}

std::string AccountPrivate::ParseSotni( int chislo ) {
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

std::string AccountPrivate::ParseThousand( int chislo ) {
  if ( chislo < 1000 ) return { };
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
        res += "тысЯча ";
        break;
      case 2:
      case 3:
      case 4:
        res += "тысЯчи ";
        break;
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 0:
        res += "тысЯч ";
        break;
    }
  }
  return res;
}

std::string ToString( const AccountPrivate& ap ) {
  return ::ToString( static_cast< const BaseAccount& >( ap ) );
}
void Display( const AccountPrivate& ap ) {
  return ::Display( static_cast< const BaseAccount& >( ap ) );
}
