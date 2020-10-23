#include "account32.h"

#include <iomanip>
#include <iostream>
#include <regex>
#include <sstream>
#include <stack>

Account32::Date29::Date29( int16_t y, int16_t m, int16_t d ) {
  if ( y < 0 || m < 0 || d < 0 ) {
    std::cout << "ERROR ARG";
    exit( 1 );
  }
  y_ = y;
  m_ = m;
  d_ = d;
}

Account32::Date29::Date29( const std::string& dt ) {
  std::regex t( R"((\d{2})\.(\d{2})\.(\d{4}))" );
  std::smatch res;
  if ( !std::regex_match( dt, res, t ) ) {
    std::cout << "ERROR ARG STR";
    exit( 1 );
  }

  int y = std::stoi( res[ 3 ] );
  int m = std::stoi( res[ 2 ] );
  int d = std::stoi( res[ 1 ] );

  *this = Date29( y, m, d );
}

Account32::Date29::Date29( const Date29& dt ) { *this = dt; }

void Account32::Date29::Read( ) {
  //***
}

void Account32::Date29::Display( ) const { std::cout << ToString( ); }

std::string Account32::Date29::ToString( ) const {
  std::stringstream ss;
  ss << "\"";
  if ( d_ < 10 ) ss << '0';
  ss << d_ << ".";
  if ( m_ < 10 ) ss << '0';
  ss << m_ << "." << y_ << "\"";
  return ss.str( );
}

Account32::Date29 Account32::Date29::AddDay( int days ) const {
  Date29 t = *this;
  //Переменная отвечает за проверку високосности в году прибытия
  //если будут переходы через года то високосность учтется в годовой
  //корректировке поэтому ее считать в корректировке по месяцам не надо
  bool yearChanged = ( days > 365 );
  days += t.d_;

  while ( days >= 365 ) {
    // WARNING тут была ошибка в порядке следования проверки на високосность!!!
    if ( t.IsVisokosny( ) ) --days;
    ++t.y_;
    //Год меняется и текущий уже не високосный!!! копится ошибка дней по
    //високосным годам!!! 	if ( t.IsVisokosny( ) )
    //	    --days;
    days -= 365;
  }

  int countDayInMonth = monats[ t.m_ - 1 ];
  if ( ( t.m_ - 1 ) == 1 && t.IsVisokosny( ) && !yearChanged )
    ++countDayInMonth;

  while ( days > countDayInMonth ) {
    days -= countDayInMonth;
    if ( ++t.m_ == 13 ) {
      t.m_ = 1;
      ++t.y_;
    }
    countDayInMonth = monats[ t.m_ - 1 ];
  }
  t.d_ = days;

  return t;
}

Account32::Date29 Account32::Date29::SubDay( int days ) const {
  Date29 t = *this;

  int index = t.m_ - 1;
  if ( index < 0 ) index = 11;

  days += ( monats[ index ] - t.d_ );  //загвоздка тут
  bool yearChanged = ( days > 365 );

  if ( days >= 365 ) {
    if ( t.IsVisokosny( ) && t.m_ >= 3 ) {
      --days;
    }
    --t.y_;
    days -= 365;
  }

  while ( days >= monats[ index ] ) {
    days -= monats[ index ];
    if ( index == 1 && t.IsVisokosny( ) && !yearChanged ) --days;
    if ( !--t.m_ ) {
      t.m_ = 12;
      --t.y_;
    }
    index = t.m_ - 1;
  }

  t.d_ = monats[ index ] - days;

  return t;
}

int16_t Account32::Date29::Interval( const Date29& other ) const {
  //считаем что дата other - последующая всегда
  //тоесть интервал от меньшего времени к большему
  int startY = y_;
  int endY = other.y_;
  if ( startY > endY ) std::swap( startY, endY );
  //    for ( int i = startY;  )
  int coutYears = endY - startY;
  int countVisokosnyLet = coutYears / 4;
  //крайние года не попадают в интервал
  int res = countVisokosnyLet * 366 + ( coutYears - countVisokosnyLet ) * 365;

  // MONATS
  if ( y_ != other.y_ ) {
    for ( int i = m_ + 1; i < 12; ++i ) {
      res += monats[ i ];
      if ( i == 1 && IsVisokosny( ) ) ++res;
    }
    for ( int i = 0; i <= other.m_; ++i ) {
      res += monats[ i ];
      if ( i == 1 && IsVisokosny( ) ) ++res;
    }
  } else {
    for ( int i = m_ + 1; i < other.m_; ++i ) {
      res += monats[ i ];
      if ( i == 1 && IsVisokosny( ) ) ++res;
    }
  }

  // DAYS
  if ( m_ != other.m_ ) {
    res += ( monats[ m_ - 1 ] - d_ ) + other.d_;
  } else {
    res += other.d_ - d_;
  }

  return res;
}

bool Account32::Date29::IsVisokosny( ) const {
  return ( ( y_ % 4 == 0 ) || ( ( y_ % 100 == 0 ) && ( y_ % 400 == 0 ) ) );
}

int16_t Account32::Date29::Year( ) const { return y_; }

void Account32::Date29::setYear( const int16_t& y ) { y_ = y; }

int16_t Account32::Date29::Month( ) const { return m_; }

void Account32::Date29::setMonth( const int16_t& m ) { m_ = m; }

int16_t Account32::Date29::Day( ) const { return d_; }

void Account32::Date29::setDay( const int16_t& d ) { d_ = d; }

Account32::Account32( const std::string& name, const std::string& acc,
                      double proc, double summ, const Date29& date_open )
    : name_ { },
      accountNum_ { },
      procent_ { 0 },
      summa_ { 0 },
      date_open_( date_open ) {
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
     << std::fixed << std::setprecision( 2 ) << summa_ << std::endl;
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
  summa_ += sm;
  return *this;
}

Account32& Account32::operator-=( double sm ) {
  if ( sm < 0 ) {
    std::cout << "ERROR SUB SUM < 0";
    exit( 1 );
  }
  summa_ -= sm;
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

void Account32::AddingProcentToDayCount( const Date29& dt ) {
  int day = date_open_.Interval( dt );
  for ( int i = 0; i < day; ++i ) {
    summa_ += summa_ * 0.0001;
  }
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
