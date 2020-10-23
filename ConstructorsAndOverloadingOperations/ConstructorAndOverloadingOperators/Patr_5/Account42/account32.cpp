#include "account32.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>

const double Account32::Money33::NOMIMALS_BILL[] {
    0.01, 0.05, 0.1, 0.5, 1, 2, 5, 10, 50, 100, 200, 500, 1000, 2000, 5000 };

Account32::Money33::Money33( double sum ) {
  if ( sum < 0 ) {
    std::cout << "ERROR SUM INIT";
    exit( 1 );
  }
  ParseSum( sum );
}

void Account32::Money33::Display( ) const {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

Account32::Money33& Account32::Money33::operator+=(
    const Account32::Money33& b1 ) {
  return *this = Account32::Money33( static_cast< double >( *this ) +
                                     static_cast< double >( b1 ) );
}

Account32::Money33& Account32::Money33::operator-=(
    const Account32::Money33& b1 ) {
  return *this = Account32::Money33( static_cast< double >( *this ) -
                                     static_cast< double >( b1 ) );
}

Account32::Money33& Account32::Money33::operator*=(
    const Account32::Money33& b1 ) {
  return *this = Account32::Money33( static_cast< double >( *this ) *
                                     static_cast< double >( b1 ) );
}

Account32::Money33& Account32::Money33::operator*=( double x ) {
  return *this = Account32::Money33( static_cast< double >( *this ) * x );
}

Account32::Money33& Account32::Money33::operator/=(
    const Account32::Money33& b1 ) {
  return *this = Account32::Money33( static_cast< double >( *this ) /
                                     static_cast< double >( b1 ) );
}

Account32::Money33& Account32::Money33::operator/=( double x ) {
  return *this = Account32::Money33( static_cast< double >( *this ) - x );
}

Account32::Money33::operator double( ) const {
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

Account32::Money33::operator std::string( ) const {
  std::stringstream ss;
  ss << std::fixed << std::setprecision( 2 ) << static_cast< double >( *this );
  return ss.str( );
}

void Account32::Money33::ParseSum( double sum ) {
  int64_t rur = sum;
  int cop = ( sum - rur ) * 1000;
  int pogr = cop % 10;
  cop /= 10;
  //поправка на погрешность
  if ( pogr >= 5 ) ++cop;

  summa_[ NOM_50_COP ] = cop / 50;
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

void Display( const Account32::Money33& b ) {
  std::cout << static_cast< std::string >( b ) << std::endl;
}

Account32::Money33 operator+( const Account32::Money33& b1,
                              const Account32::Money33& b2 ) {
  return Account32::Money33( static_cast< double >( b1 ) +
                             static_cast< double >( b2 ) );
}

Account32::Money33 operator-( const Account32::Money33& b1,
                              const Account32::Money33& b2 ) {
  return Account32::Money33( static_cast< double >( b1 ) -
                             static_cast< double >( b2 ) );
}
Account32::Money33 operator*( const Account32::Money33& b1,
                              const Account32::Money33& b2 ) {
  return Account32::Money33( static_cast< double >( b1 ) *
                             static_cast< double >( b2 ) );
}
Account32::Money33 operator/( const Account32::Money33& b1,
                              const Account32::Money33& b2 ) {
  return Account32::Money33( static_cast< double >( b1 ) /
                             static_cast< double >( b2 ) );
}
Account32::Money33 operator/( const Account32::Money33& b1, double x ) {
  return Account32::Money33( static_cast< double >( b1 ) / x );
}

Account32::Money33 operator/( double x, const Account32::Money33& b1 ) {
  return Account32::Money33( static_cast< double >( b1 ) / x );
}

Account32::Money33 operator*( const Account32::Money33& b1, double x ) {
  return Account32::Money33( static_cast< double >( b1 ) * x );
}

Account32::Money33 operator*( double x, const Account32::Money33& b1 ) {
  return Account32::Money33( static_cast< double >( b1 ) * x );
}

bool operator<( const Account32::Money33& b1, const Account32::Money33& b2 ) {
  return static_cast< double >( b1 ) < static_cast< double >( b2 );
}
bool operator<=( const Account32::Money33& b1, const Account32::Money33& b2 ) {
  return ( b1 == b2 ) || ( b1 < b2 );
}
bool operator>( const Account32::Money33& b1, const Account32::Money33& b2 ) {
  return !( b1 <= b2 );
}
bool operator>=( const Account32::Money33& b1, const Account32::Money33& b2 ) {
  return ( b1 > b2 ) || ( b1 == b2 );
}
bool operator==( const Account32::Money33& b1, const Account32::Money33& b2 ) {
  return ( std::fabs( static_cast< double >( b1 ) -
                      static_cast< double >( b2 ) ) ) < 1e-3;
}
bool operator!=( const Account32::Money33& b1, const Account32::Money33& b2 ) {
  return !( b1 == b2 );
}

//*****************************************************************************

Account32::Account32( const std::string& name, const std::string& acc,
                      double proc, double summ )
    : name_ { }, accountNum_ { }, procent_ { 0 }, summa_ { 0 } {
  //проверки всех данных
  name_ = name;
  accountNum_ = acc;
  procent_ = proc;
  summa_ = Money33( summ );
}

Account32::operator std::string( ) const {
  std::stringstream ss;
  ss << "   Name: " << name_ << std::endl
     << "Account: " << accountNum_ << std::endl
     << "Procent: " << procent_ << std::endl
     << static_cast< std::string >( summa_ ) << std::endl;
  return ss.str( );
}

void Account32::Display( ) {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

std::string Account32::name( ) const { return name_; }

void Account32::setName( const std::string& name ) { name_ = name; }

Account32& Account32::operator+=( double sm ) {
  if ( sm < 0 ) {
    std::cout << "ERROR ADDING SUM < 0";
    exit( 1 );
  }
  summa_ += Money33( sm );
  return *this;
}

Account32& Account32::operator-=( double sm ) {
  if ( sm < 0 ) {
    std::cout << "ERROR SUB SUM < 0";
    exit( 1 );
  }
  summa_ -= Money33( sm );
  return *this;
}

Account32 operator+( const Account32& ac1, double sm ) {
  Account32 loc = ac1;
  loc += sm;
  return loc;
}

Account32 operator+( double sm, const Account32& ac2 ) {
  Account32 loc = ac2;
  loc += sm;
  return loc;
}

Account32 operator-( const Account32& ac1, double sm ) {
  Account32 loc = ac1;
  loc -= sm;
  return loc;
}

Account32 operator-( double sm, const Account32& ac2 ) {
  Account32 loc = ac2;
  loc -= sm;
  return loc;
}

void Account32::AddProcent( ) { summa_ += summa_ * procent_ / 100; }

double Account32::ToDollar( double cours ) const {
  return static_cast< double >( summa_ / cours );
}

double Account32::ToEuro( double cours ) const {
  return static_cast< double >( summa_ / cours );
}

std::string Account32::ToChislitelnoe( ) const {
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

std::string Account32::Sotni( int chislo ) const {
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

std::string Account32::Desyatki( int chislo ) const {
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

std::string Account32::Edinitsy( int chislo ) const {
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

std::string Account32::ParseSotni( int chislo ) const {
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

std::string Account32::ParseThousand( int chislo ) const {
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
