#include "account32.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>

Account32::Account32( const std::string& name, const std::string& acc,
                      double proc, double summ )
    : name_ { }, accountNum_ { }, procent_ { 0 }, summa_ { 0 } {
  //проверки всех данных
  name_ = name;
  accountNum_ = acc;
  procent_ = proc;
  summa_ = summ;
}

Account32::operator std::string( ) const {
  std::stringstream ss;
  ss << "   Name: " << name_ << std::endl
     << "Account: " << accountNum_ << std::endl
     << "Procent: " << procent_ << std::endl
     << std::fixed << std::setprecision( 2 ) << "  Summa: " << summa_
     << std::endl;
  return ss.str( );
}

void Display( const Account32& ac ) {
  std::cout << static_cast< std::string >( ac ) << std::endl;
}

std::string name( const Account32& ac ) { return ac.name_; }

void setName( Account32& ac, const std::string& name ) { ac.name_ = name; }

void AddSumm( Account32& ac, double sm ) {
  if ( sm < 0 ) {
    std::cout << "ERROR ADDING SUM < 0";
    exit( 1 );
  }
  ac.summa_ += sm;
}

void SubSumm( Account32& ac, double sm ) {
  if ( sm < 0 ) {
    std::cout << "ERROR SUB SUM < 0";
    exit( 1 );
  }
  ac.summa_ -= sm;
}

void AddProcent( Account32& ac ) { ac.summa_ += ac.summa_ * ac.procent_ / 100; }

double ToDollar( const Account32& ac, double cours ) {
  return ac.summa_ / cours;
}

double ToEuro( const Account32& ac, double cours ) { return ac.summa_ / cours; }

std::string ToChislitelnoe( const Account32& ac ) {
  int64_t rur = ac.summa_;
  int16_t cop = ( ac.summa_ - rur ) * 100;

  std::string res = ParseThousand( ac, rur );
  res += ParseSotni( ac, rur );

  if ( cop ) {
    res += " рублей, ";
    res += ParseSotni( ac, cop );
    res += " копеек";
  } else {
    res += " рублей";
  }

  return res;
}

std::string Sotni( int chislo ) {
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
      return "пятьсот";
    case 600:
      return "шестьсот";
    case 700:
      return "семьсот";
    case 800:
      return "восемьсот";
    case 900:
      return "девятьсот";
    default:
      return "";
  }
}

std::string Desyatki( int chislo ) {
  switch ( chislo ) {
    case 10:
      return "десять";
    case 11:
      return "одиннадцать";
    case 12:
      return "двенадцать";
    case 13:
      return "тринадцать";
    case 14:
      return "четырнадцать";
    case 15:
      return "пятнадцать";
    case 16:
      return "шестнадцать";
    case 17:
      return "семьнадцать";
    case 18:
      return "восемьнадцать";
    case 19:
      return "девятнадцать";
    case 20:
      return "двадцать";
    case 30:
      return "тридцать";
    case 40:
      return "сорок";
    case 50:
      return "пятьдесят";
    case 60:
      return "шестьдесят";
    case 70:
      return "семьдесят";
    case 80:
      return "восемдесят";
    case 90:
      return "девяносто";
    default:
      return "";
  }
}

std::string Edinitsy( int chislo ) {
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
      return "пять";
    case 6:
      return "шесть";
    case 7:
      return "семь";
    case 8:
      return "восемь";
    case 9:
      return "девять";
    default:
      return "";
  }
}

std::string ParseSotni( const Account32&, int chislo ) {
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

std::string ParseThousand( const Account32& ac, int chislo ) {
  if ( chislo < 1000 ) return { };
  std::string res = ParseSotni( ac, chislo / 1000 );
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
        res += "тысяча ";
        break;
      case 2:
      case 3:
      case 4:
        res += "тысячи ";
        break;
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 0:
        res += "тысяч ";
        break;
    }
  }
  return res;
}
