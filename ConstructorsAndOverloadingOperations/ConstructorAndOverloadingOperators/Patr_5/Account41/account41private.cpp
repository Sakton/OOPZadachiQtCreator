//#include "account41private.h"

//#include <iomanip>
//#include <iostream>
//#include <sstream>
//#include <stack>

// void Account41Private::Money24::Display( ) {
//  std::cout << static_cast< std::string >( *this ) << std::endl;
//}

// Account41Private::Money24::operator double( ) const {
//  return double( rub ) + double( cop ) / 100.0;
//}

// void Read( Account41Private::Money24& b ) {
//  int32_t aa = 0;
//  int16_t bb = 0;
//  std::cout << "Enter rub cop" << std::endl;
//  std::cin >> aa >> bb;
//  b = Account41Private::Money24( aa, bb );
//}

// Account41Private::Money24::operator std::string( ) const {
//  std::stringstream ss;
//  ss << std::fixed << rub << ",";
//  int x = static_cast< int >( cop );
//  if ( x < 10 ) ss << '0';
//  ss << x;
//  return ss.str( );
//}

// Account41Private::Money24::Money24( int32_t rb, int16_t cp ) {
//  if ( !( 0 <= cp && cp < 100 ) ) {
//    std::cout << "ERROR DATA COP < 0";
//    exit( 1 );
//  }
//  rub = rb;
//  cop = cp;
//}

// Account41Private::Money24::Money24( double sum )
//    : Money24( sum, ( sum - static_cast< int16_t >( sum ) ) * 100 ) {}

// Account41Private::Money24& Account41Private::Money24::operator+=(
//    const Money24& b ) {
//  int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
//  int64_t rurB =
//      ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
//  int64_t summ = rurA + rurB;
//  rub = summ / 100;
//  cop = std::abs( summ % 100 );
//  return *this;
//}

// Account41Private::Money24& Account41Private::Money24::operator-=(
//    const Money24& b ) {
//  int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
//  int64_t rurB =
//      ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
//  int64_t divide = rurA - rurB;
//  rub = divide / 100;
//  cop = std::abs( divide % 100 );
//  return *this;
//}

// Account41Private::Money24& Account41Private::Money24::operator*=( double x )
// {
//  int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
//  int64_t mul = rurA * x;
//  rub = mul / 100;
//  cop = std::abs( mul % 100 );
//  return *this;
//}

// double Account41Private::Money24::operator/=( const Money24& b ) {
//  int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
//  int64_t rurB =
//      ( b.rub < 0 ) ? ( b.rub * 100 - b.cop ) : ( b.rub * 100 + b.cop );
//  if ( rurB == 0 ) {
//    std::cout << "ERROR DIVIDE ZERO!!!";
//    exit( 1 );
//  }
//  return double( rurA ) / double( rurB );
//}

// Account41Private::Money24& Account41Private::Money24::operator/=( double x )
// {
//  if ( x == 0 ) {
//    std::cout << "ERROR DIVIDE ZERO!!!";
//    exit( 1 );
//  }
//  int64_t rurA = ( rub < 0 ) ? ( rub * 100 - cop ) : ( rub * 100 + cop );
//  int64_t div = rurA / x;

//  rub = div / 100;
//  cop = std::abs( div % 100 );
//  return *this;
//}

// Money24 operator+( const Money24& a, const Money24& b ) {
//  Money24 loc = a;
//  loc += b;
//  return loc;
//}

// Account41Private::Money24 operator-( const Account41Private::Money24& a,
//                                     const Account41Private::Money24& b ) {
//  Account41Private::Money24 loc = a;
//  loc -= b;
//  return loc;
//}

// Account41Private::Money24 operator*( const Account41Private::Money24& a,
//                                     double x ) {
//  Account41Private::Money24 loc = a;
//  loc *= x;
//  return loc;
//}

// double operator/( const Account41Private::Money24& a,
//                  const Account41Private::Money24& b ) {
//  Account41Private::Money24 loc = a;
//  return loc /= b;
//}

// Account41Private::Money24 operator/( const Account41Private::Money24& a,
//                                     double x ) {
//  Account41Private::Money24 loc = a;
//  loc /= x;
//  return loc;
//}

// bool operator==( const Account41Private::Money24& a,
//                 const Account41Private::Money24& b ) {
//  return ( a.rub == b.rub && a.cop == b.cop );
//}
// bool operator!=( const Account41Private::Money24& a,
//                 const Account41Private::Money24& b ) {
//  return !( a == b );
//}
// bool operator<=( const Account41Private::Money24& a,
//                 const Account41Private::Money24& b ) {
//  return ( a == b ) || ( a < b );
//}
// bool operator>=( const Account41Private::Money24& a,
//                 const Account41Private::Money24& b ) {
//  return a > b || a == b;
//}
// bool operator<( const Account41Private::Money24& a,
//                const Account41Private::Money24& b ) {
//  return ( ( a.rub < b.rub ) || ( ( a.rub == b.rub ) && ( a.cop < b.cop ) ) );
//}

// bool operator>( const Account41Private::Money24& a,
//                const Account41Private::Money24& b ) {
//  return !( a <= b );
//}

// int32_t Account41Private::Money24::GetRub( ) const { return rub; }

// uint8_t Account41Private::Money24::GetCop( ) const { return cop; }

// Account41Private::Account41Private( const std::string& name,
//                                    const std::string& acc, double proc,
//                                    double summ )
//    : name_ { }, accountNum_ { }, procent_ { 0 }, summa_ { 0 } {
//  //проверки всех данных
//  name_ = name;
//  accountNum_ = acc;
//  procent_ = proc;
//  summa_ = Money24( summ );
//}

// Account41Private::operator std::string( ) const {
//  std::stringstream ss;
//  ss << "   Name: " << name_ << std::endl
//     << "Account: " << accountNum_ << std::endl
//     << "Procent: " << procent_ << std::endl
//     << static_cast< std::string >( summa_ ) << std::endl;
//  return ss.str( );
//}

// void Account41Private::Display( ) {
//  std::cout << static_cast< std::string >( *this ) << std::endl;
//}

// std::string Account41Private::name( ) const { return name_; }

// void Account41Private::setName( const std::string& name ) { name_ = name; }

// Account41Private& Account41Private::operator+=( double sm ) {
//  if ( sm < 0 ) {
//    std::cout << "ERROR ADDING SUM < 0";
//    exit( 1 );
//  }
//  summa_ += Money24( sm );
//  return *this;
//}

// Account41Private& Account41Private::operator-=( double sm ) {
//  if ( sm < 0 ) {
//    std::cout << "ERROR SUB SUM < 0";
//    exit( 1 );
//  }
//  summa_ -= Money24( sm );
//  return *this;
//}

// Account41Private operator+( const Account41Private& ac1, double sm ) {
//  Account41Private loc = ac1;
//  loc += sm;
//  return loc;
//}

// Account41Private operator+( double sm, const Account41Private& ac2 ) {
//  Account41Private loc = ac2;
//  loc += sm;
//  return loc;
//}

// Account41Private operator-( const Account41Private& ac1, double sm ) {
//  Account41Private loc = ac1;
//  loc -= sm;
//  return loc;
//}

// Account41Private operator-( double sm, const Account41Private& ac2 ) {
//  Account41Private loc = ac2;
//  loc -= sm;
//  return loc;
//}

// void Account41Private::AddProcent( ) { summa_ += summa_ * procent_ / 100; }

// double Account41Private::ToDollar( double cours ) const {
//  return static_cast< double >( summa_ / cours );
//}

// double Account41Private::ToEuro( double cours ) const {
//  return static_cast< double >( summa_ / cours );
//}

// std::string Account41Private::ToChislitelnoe( ) const {
//  int64_t rur = static_cast< double >( summa_ );
//  int16_t cop = ( static_cast< double >( summa_ ) - rur ) * 100;

//  std::string res = ParseThousand( rur );
//  res += ParseSotni( rur );

//  if ( cop ) {
//    res += " рублей, ";
//    res += ParseSotni( cop );
//    res += " копеек";
//  } else {
//    res += " рублей";
//  }

//  return res;
//}

// std::string Account41Private::Sotni( int chislo ) const {
//  switch ( chislo ) {
//    case 100:
//      return "сто";
//    case 200:
//      return "двести";
//    case 300:
//      return "триста";
//    case 400:
//      return "четыреста";
//    case 500:
//      return "пЯтьсот";
//    case 600:
//      return "шестьсот";
//    case 700:
//      return "семьсот";
//    case 800:
//      return "восемьсот";
//    case 900:
//      return "девЯтьсот";
//    default:
//      return "";
//  }
//}

// std::string Account41Private::Desyatki( int chislo ) const {
//  switch ( chislo ) {
//    case 10:
//      return "десЯть";
//    case 11:
//      return "одиннадцать";
//    case 12:
//      return "двенадцать";
//    case 13:
//      return "тринадцать";
//    case 14:
//      return "четырнадцать";
//    case 15:
//      return "пЯтнадцать";
//    case 16:
//      return "шестнадцать";
//    case 17:
//      return "семьнадцать";
//    case 18:
//      return "восемьнадцать";
//    case 19:
//      return "девЯтнадцать";
//    case 20:
//      return "двадцать";
//    case 30:
//      return "тридцать";
//    case 40:
//      return "сорок";
//    case 50:
//      return "пЯтьдесЯт";
//    case 60:
//      return "шестьдесЯт";
//    case 70:
//      return "семьдесЯт";
//    case 80:
//      return "восемдесЯт";
//    case 90:
//      return "девЯносто";
//    default:
//      return "";
//  }
//}

// std::string Account41Private::Edinitsy( int chislo ) const {
//  switch ( chislo ) {
//    case 1:
//      return "один";
//    case 2:
//      return "два";
//    case 3:
//      return "три";
//    case 4:
//      return "четыре";
//    case 5:
//      return "пЯть";
//    case 6:
//      return "шесть";
//    case 7:
//      return "семь";
//    case 8:
//      return "восемь";
//    case 9:
//      return "девЯть";
//    default:
//      return "";
//  }
//}

// std::string Account41Private::ParseSotni( int chislo ) const {
//  chislo %= 1000;
//  std::stack< std::string > st;
//  if ( 10 <= ( chislo % 100 ) && ( chislo % 100 ) <= 20 ) {
//    st.push( Desyatki( chislo % 100 ) );
//  } else if ( ( chislo % 100 ) <= 10 ) {
//    st.push( Edinitsy( chislo % 10 ) );
//  } else {
//    st.push( Edinitsy( chislo % 10 ) );
//    st.push( Desyatki( chislo % 100 - chislo % 10 ) );
//  }
//  st.push( Sotni( ( chislo / 100 ) * 100 ) );
//  std::string res;
//  while ( !st.empty( ) ) {
//    res += st.top( );
//    res += " ";
//    st.pop( );
//  }
//  return res;
//}

// std::string Account41Private::ParseThousand( int chislo ) const {
//  if ( chislo < 1000 ) return { };
//  std::string res = ParseSotni( chislo / 1000 );
//  if ( ( chislo / 1000 ) % 10 == 1 ) {
//    auto it = res.find( "один" );
//    res.replace( it, it + 3, "одна" );
//  }
//  if ( ( chislo / 1000 ) % 10 == 2 ) {
//    auto it = res.find( "два" );
//    res.replace( it, it + 3, "две " );
//  }
//  if ( 1000 <= chislo && chislo < 1000000 ) {
//    switch ( ( chislo / 1000 ) % 10 ) {
//      case 1:
//        res += "тысЯча ";
//        break;
//      case 2:
//      case 3:
//      case 4:
//        res += "тысЯчи ";
//        break;
//      case 5:
//      case 6:
//      case 7:
//      case 8:
//      case 9:
//      case 0:
//        res += "тысЯч ";
//        break;
//    }
//  }
//  return res;
//}
