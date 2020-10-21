#include "accountprivate.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>

AccountPrivate::AccountPrivate( const std::string& name, const std::string& acc,
                                double proc, double summ,
                                const std::string& date_open )
    : Date29( date_open ),
      name_ { name },
      accountNum_ { acc },
      procent_ { proc },
      summa_ { summ } {}

AccountPrivate::operator std::string( ) const {
  std::stringstream ss;
  ss << "   Name: " << name_ << std::endl
     << "Account: " << accountNum_ << std::endl
     << "Procent: " << procent_ << std::endl
     << std::fixed << std::setprecision( 2 ) << summa_ << std::endl;
  return ss.str( );
}

void AccountPrivate::Display( ) {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

std::string AccountPrivate::name( ) const { return name_; }

void AccountPrivate::setName( const std::string& name ) { name_ = name; }

AccountPrivate& AccountPrivate::operator+=( double sm ) {
  if ( sm < 0 ) {
    std::cout << "ERROR ADDING SUM < 0";
    exit( 1 );
  }
  summa_ += sm;
  return *this;
}

AccountPrivate& AccountPrivate::operator-=( double sm ) {
  if ( sm < 0 ) {
    std::cout << "ERROR SUB SUM < 0";
    exit( 1 );
  }
  summa_ -= sm;
  return *this;
}

AccountPrivate operator+( const AccountPrivate& ac1, double sm ) {
  AccountPrivate loc = ac1;
  loc += sm;
  return loc;
}

AccountPrivate operator+( double sm, const AccountPrivate& ac2 ) {
  AccountPrivate loc = ac2;
  loc += sm;
  return loc;
}

AccountPrivate operator-( const AccountPrivate& ac1, double sm ) {
  AccountPrivate loc = ac1;
  loc -= sm;
  return loc;
}

AccountPrivate operator-( double sm, const AccountPrivate& ac2 ) {
  AccountPrivate loc = ac2;
  loc -= sm;
  return loc;
}

void AccountPrivate::AddProcent( ) { summa_ += summa_ * procent_ / 100; }

double AccountPrivate::ToDollar( double cours ) const {
  return static_cast< double >( summa_ / cours );
}

double AccountPrivate::ToEuro( double cours ) const {
  return static_cast< double >( summa_ / cours );
}

std::string AccountPrivate::ToChislitelnoe( ) const {
  int64_t rur = static_cast< double >( summa_ );
  int16_t cop = ( static_cast< double >( summa_ ) - rur ) * 100;

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

void AccountPrivate::AddingProcentToDayCount( const Date29& dt ) {
  int day = Date29::Interval( dt );
  for ( int i = 0; i < day; ++i ) {
    summa_ += summa_ * 0.0001;
  }
}

std::string AccountPrivate::Sotni( int chislo ) const {
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

std::string AccountPrivate::Desyatki( int chislo ) const {
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

std::string AccountPrivate::Edinitsy( int chislo ) const {
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

std::string AccountPrivate::ParseSotni( int chislo ) const {
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

std::string AccountPrivate::ParseThousand( int chislo ) const {
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
