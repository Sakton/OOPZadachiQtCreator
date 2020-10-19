#include "fraction35.h"

#include <iostream>
#include <sstream>

Fraction35B::Fraction35B( int64_t w, int16_t f ) {
  if ( f < 0 || f >= 10000 ) {
    std::cout << "ERROR ARG FRACTIONAL < 0 || >= 10000";
    exit( 1 );
  }
  whole_ = std::abs( w );
  negative = ( w < 0 ) ? true : false;
  fractional_ = std::abs( f );
}

Fraction35B::Fraction35B( const std::string& s_num ) : Fraction35B( 0, 0 ) {
  int16_t frac = 0;
  int64_t whole = 0;
  int64_t tmp = 0;
  bool negative = false;
  for ( std::string::const_iterator it = s_num.cbegin( ); it != s_num.cend( );
        ++it ) {
    if ( *it == '-' ) negative = true;
    if ( std::isdigit( *it ) ) tmp = ( tmp * 10 + ( *it - '0' ) );
    if ( *it == ',' || *it == '.' ) {
      whole = ( negative ) ? -tmp : tmp;
      tmp = 0;
    }
  }

  if ( 0 <= tmp && tmp < 10 ) {
    frac = static_cast< int16_t >( tmp ) * 1000;
  } else if ( 10 <= tmp && tmp < 100 ) {
    frac = static_cast< int16_t >( tmp ) * 100;
  } else if ( 100 <= tmp && tmp < 1000 ) {
    frac = static_cast< int16_t >( tmp ) * 10;
  } else {
    frac = static_cast< int16_t >( tmp );
  }

  *this = Fraction35B( whole, frac );
}

Fraction35B::Fraction35B( double num )
    : Fraction35B( num,
                   std::abs( num - static_cast< int64_t >( num ) ) * 10000 ) {}

Fraction35B::operator std::string( ) const {
  std::stringstream ss;
  if ( negative ) ss << '-';
  ss << whole_ << ",";
  if ( 0 <= fractional_ && fractional_ < 10 ) {
    ss << "000";
  } else if ( 10 <= fractional_ && fractional_ < 100 ) {
    ss << "00";
  } else if ( 100 <= fractional_ && fractional_ < 1000 ) {
    ss << "0";
  }
  ss << fractional_;
  return ss.str( );
}

void Fraction35B::Display( ) const {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

Fraction35B operator+( const Fraction35B& a, const Fraction35B& b ) {
  Fraction35B loc = a;
  if ( a.negative && !b.negative ) {
    if ( a.Modul( ).LessMod( b.Modul( ) ) ) {
      loc = b.Modul( ).SubModul( b.Modul( ) );
    } else if ( !a.Modul( ).LessMod( b.Modul( ) ) ) {
      loc = a.Modul( ).SubModul( b.Modul( ) );
      loc.negative = true;
    } else {
      loc.whole_ = 0;
      loc.fractional_ = 0;
    }
  } else if ( !a.negative && b.negative ) {
    if ( a.Modul( ).LessMod( b.Modul( ) ) ) {
      loc = a.Modul( ).SubModul( b.Modul( ) );
    } else if ( !a.Modul( ).LessMod( b.Modul( ) ) ) {
      loc = b.Modul( ).SubModul( a.Modul( ) );
      loc.negative = true;
    } else {
      loc.whole_ = 0;
      loc.fractional_ = 0;
    }
  } else {
    loc = a.Modul( ).AddModul( b.Modul( ) );
    loc.negative = a.negative;
  }
  return loc;
}

Fraction35B operator-( const Fraction35B& a, const Fraction35B& b ) {
  Fraction35B loc = a;
  if ( !a.negative && !b.negative ) {  //оба положительные
    if ( a < b ) {
      loc = b.SubModul( a );
      loc.negative = true;
    } else {
      loc = a.SubModul( b );
    }
  } else if ( a.negative && b.negative ) {  //оба отрицательные
    if ( a.LessMod( b ) ) {
      loc = b.Modul( ).SubModul( a.Modul( ) );
    } else if ( !a.LessMod( b ) ) {
      loc = a.Modul( ).SubModul( b.Modul( ) );
      loc.negative = true;
    }
  } else {  //знаки разные
    if ( a.negative && !b.negative ) {
      loc = a.Modul( ).AddModul( b.Modul( ) );
      loc.negative = true;
    } else if ( !a.negative && b.negative ) {
      loc = a.Modul( ).AddModul( b.Modul( ) );
    }
  }
  return loc;
}

Fraction35B operator*( const Fraction35B& a, const Fraction35B& b ) {
  Fraction35B loc;
  loc = a.MulModul( b );

  if ( a.negative != b.negative ) {
    loc.negative = true;
  } else {
    loc.negative = false;
  }

  return loc;
}

Fraction35B operator/( const Fraction35B& a, const Fraction35B& b ) {
  //деление выдает большую погрешность на больших числах
  //неодходимо увеличивать точность самого класса
  // 5555.5555 / 2222.2222 = 2,5
  //при этой точности 1/10000
  // 5555.5555 / 2222.2222 = 2.2222 ( 1/2222,2222 = 0,0004 в этом случае
  // (0,00045) ) но даже если округлить до 1/2222,2222 = 0,0005, то 5555.5555 /
  // 2222.2222 = 2.7777 поэтому на эту операцию при данной точности надеятся
  //нельзя и в учебнике не просят ее делатть
  //  **
  //    Fraction35B loc = *this;
  //    return loc.Mul( OneDivFrac( b ) );
  //  **

  //или тупо через дабл
  double x = a.whole_ + ( double( a.fractional_ ) / 1000 );
  double y = b.whole_ + ( double( b.fractional_ ) / 1000 );
  double res = x / y;
  Fraction35B loc( res, ( res - static_cast< int64_t >( res ) ) * 10000 );
  return loc;
}

// friend bool operator<=( const Fraction35B& a, const Fraction35B& b );
// friend bool operator>( const Fraction35B& a, const Fraction35B& b );
// friend bool operator>=( const Fraction35B& a, const Fraction35B& b );
// friend bool operator==( const Fraction35B& a, const Fraction35B& b );
// friend bool operator!=( const Fraction35B& a, const Fraction35B& b );

bool operator<( const Fraction35B& a, const Fraction35B& b ) {
  if ( a.negative && !b.negative ) {
    return !a.LessMod( b );
  } else if ( !a.negative && !b.negative ) {
    return a.LessMod( b );
  } else {
    return ( a.whole_ < b.whole_ );
  }
}

Fraction35B Fraction35B::AddModul( const Fraction35B& b ) const {
  Fraction35B loc = *this;
  loc.whole_ += b.whole_;
  loc.fractional_ += b.fractional_;
  if ( loc.fractional_ > 10000 ) {
    loc.fractional_ -= 10000;
    ++loc.whole_;
  }
  return loc;
}

Fraction35B Fraction35B::SubModul( const Fraction35B& b ) const {
  Fraction35B loc = *this;
  loc.whole_ -= b.whole_;
  if ( loc.fractional_ < b.fractional_ ) {
    --loc.whole_;
    loc.fractional_ += ( 10000 - b.fractional_ );
  } else {
    loc.fractional_ -= b.fractional_;
  }
  return loc;
}

Fraction35B Fraction35B::MulModul( const Fraction35B& b ) const {
  //(a + b)*(c + d)
  int64_t ac_t = whole_ * b.whole_;
  double ad_t = whole_ * ( double( b.fractional_ ) / 10000 );
  double bc_t = ( double( fractional_ ) / 10000 ) * b.whole_;
  int64_t bd_t = fractional_ * b.fractional_;

  Fraction35B ac( ac_t, 0 );
  Fraction35B ad( ad_t, ( ad_t - static_cast< int64_t >( ad_t ) ) * 10000 );
  Fraction35B bc( bc_t, ( bc_t - static_cast< int64_t >( bc_t ) ) * 10000 );
  Fraction35B bd( bd_t / 100000000, ( bd_t % 100000000 ) / 10000 );
  Fraction35B res = ac + ad + bc + bd;
  return res;
}

Fraction35B Fraction35B::MulDesyatki( int mul ) const {
  Fraction35B loc = *this;
  int doo = std::min( mul, 10000 );
  loc.whole_ = whole_ * doo + fractional_ / ( 10000 / doo );
  loc.fractional_ = ( fractional_ * doo ) % 10000;
  mul /= doo;
  loc.whole_ *= mul;
  return loc;
}

Fraction35B Fraction35B::MulOneNumber( int num ) const  // num [0 - 9]
{
  Fraction35B loc = *this;
  loc.whole_ *= num;

  int doo = 0;
  int doo1 = 0;

  //при 6 * 9999 = 59994, максимум у short = 65536
  //поэтому приходим к такой формуле y * ( a + ( num - a ) ); разбиваем его на 2
  //части число на сумму 2 чисел, и сразу приведением его к нормальному
  //состоянию <
  // 10000 с выделением целой части
  if ( num > 6 ) {
    doo = 6;
    doo1 = num - doo;
  } else {
    doo = num;
  }
  int t1 = loc.fractional_;
  int t2 = loc.fractional_;
  t1 *= doo;
  t2 *= doo1;
  loc.whole_ += ( t1 / 10000 );
  t1 %= 10000;
  loc.whole_ += ( t2 / 10000 );
  t2 %= 10000;
  loc.fractional_ = ( t1 + t2 );
  loc.whole_ += loc.fractional_ / 10000;
  loc.fractional_ %= 10000;

  return loc;
}

Fraction35B Fraction35B::Modul( ) const {
  Fraction35B loc( std::abs( whole_ ), fractional_ );
  return loc;
}

Fraction35B Fraction35B::OneDivFrac( ) const {
  //Вводим ограничения, если число fraction >= 10000, то при делении мы выйдем
  //за погрешность в 1/10000, и результатом будет 0 а при числах < 10000
  Fraction35B loc = *this;
  if ( whole_ <= 10000 ) {
    double x = whole_ + ( static_cast< double >( fractional_ ) / 10000 );
    double y = 1 / x;
    std::cout << y << std::endl;
    loc = Fraction35B( y, ( y - static_cast< int64_t >( y ) ) * 10000 );
    loc.negative = negative;
  }
  return loc;
}

bool Fraction35B::LessMod( const Fraction35B& b ) const {
  return ( std::abs( whole_ ) < std::abs( b.whole_ ) ) ||
         ( ( std::abs( whole_ ) == std::abs( b.whole_ ) ) &&
           ( fractional_ < b.fractional_ ) );
}

bool Fraction35B::EqModul( const Fraction35B& b ) const {
  return ( std::abs( whole_ ) == std::abs( b.whole_ ) &&
           fractional_ == b.fractional_ );
}

bool Fraction35B::GetNegative( ) const { return negative; }

int16_t Fraction35B::Fractional( ) const { return fractional_; }

int64_t Fraction35B::Whole( ) const { return whole_; }
