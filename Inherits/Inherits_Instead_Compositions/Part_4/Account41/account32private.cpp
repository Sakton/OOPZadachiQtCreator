#include "account32private.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>

Account32private::Account32private( const std::string& name,
                                    const std::string& acc, double proc,
                                    double summ )
    : Money24( summ, ( summ - static_cast< int16_t >( summ ) ) * 100 ),
      name_ { },
      accountNum_ { },
      procent_ { 0 } {
  //проверки всех данных
  name_ = name;
  accountNum_ = acc;
  procent_ = proc;
  // summa_ = Money24( summ );
}

Account32private::operator std::string( ) const {
  std::stringstream ss;
  ss << "   Name: " << name_ << std::endl
     << "Account: " << accountNum_ << std::endl
     << "Procent: " << procent_
     << std::endl
     // << Money24::operator std::string( ) << std::endl;
     << static_cast< std::string >( static_cast< const Money24& >( *this ) )
     << std::endl;
  return ss.str( );
}

void Account32private::Display( ) {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

std::string Account32private::name( ) const { return name_; }

void Account32private::setName( const std::string& name ) { name_ = name; }

Account32private& Account32private::operator+=( double sm ) {
  if ( sm < 0 ) {
    std::cout << "ERROR ADDING SUM < 0";
    exit( 1 );
  }
  Money24::operator+=( Money24( sm ) );
  return *this;
}

Account32private& Account32private::operator-=( double sm ) {
  if ( sm < 0 ) {
    std::cout << "ERROR SUB SUM < 0";
    exit( 1 );
  }
  Money24::operator-=( Money24( sm ) );
  return *this;
}

Account32private operator+( const Account32private& ac1, double sm ) {
  Account32private loc = ac1;
  loc += sm;
  return loc;
}

Account32private operator+( double sm, const Account32private& ac2 ) {
  Account32private loc = ac2;
  loc += sm;
  return loc;
}

Account32private operator-( const Account32private& ac1, double sm ) {
  Account32private loc = ac1;
  loc -= sm;
  return loc;
}

Account32private operator-( double sm, const Account32private& ac2 ) {
  Account32private loc = ac2;
  loc -= sm;
  return loc;
}

void Account32private::AddProcent( ) {
  static_cast< Money24& >( *this ) +=
      static_cast< Money24& >( *this ) * procent_ / 100;
}

double Account32private::ToDollar( double cours ) const {
  return static_cast< double >( static_cast< const Money24& >( *this ) /
                                cours );
}

double Account32private::ToEuro( double cours ) const {
  return static_cast< double >( static_cast< const Money24& >( *this ) /
                                cours );
}

std::string Account32private::ToChislitelnoe( ) const {
  int64_t rur = static_cast< double >( static_cast< const Money24& >( *this ) );
  int16_t cop =
      ( static_cast< double >( static_cast< const Money24& >( *this ) ) -
        rur ) *
      100;

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

std::string Account32private::Sotni( int chislo ) const {
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

std::string Account32private::Desyatki( int chislo ) const {
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

std::string Account32private::Edinitsy( int chislo ) const {
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

std::string Account32private::ParseSotni( int chislo ) const {
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

std::string Account32private::ParseThousand( int chislo ) const {
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
