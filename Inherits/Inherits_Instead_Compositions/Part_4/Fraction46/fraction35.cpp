#include "fraction35.h"

#include <iostream>
#include <sstream>

Fraction35B::Fraction35B( int64_t w, double f )
    : LongLong38B( std::abs( w ) ), fractional_ { f } {
  if ( f < 0 || f >= 10000 ) {
    std::cout << "ERROR ARG FRACTIONAL < 0 || >= 10000";
    exit( 1 );
  }
  negative = ( w < 0 ) ? true : false;
  fractional_ = std::abs( f );
}

void Fraction35B::Display( ) const {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

Fraction35B::operator std::string( ) const {
  std::stringstream ss;
  if ( negative ) ss << '-';
  ss << LongLong38B::operator std::string( ) << ",";
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

Fraction35B& Fraction35B::operator+=( const Fraction35B& b ) {
  if ( negative && !b.negative ) {
    if ( Modul( *this ) < ( Modul( b ) ) ) {
      *this = SubModul( Modul( b ), Modul( b ) );
    } else if ( !( Modul( *this ) < ( Modul( b ) ) ) ) {
      *this = SubModul( Modul( *this ), Modul( b ) );
      negative = true;
    } else {
      static_cast< LongLong38B& >( *this ) = LongLong38B( 0 );
      fractional_ = 0;
    }
  } else if ( !negative && b.negative ) {
    if ( Modul( *this ) < ( Modul( b ) ) ) {
      *this = SubModul( Modul( *this ), Modul( b ) );
    } else if ( !( Modul( *this ) < ( Modul( b ) ) ) ) {
      *this = SubModul( Modul( b ), Modul( *this ) );
      negative = true;
    } else {
      static_cast< LongLong38B& >( *this ) = LongLong38B( 0 );
      fractional_ = 0;
    }
  } else {
    *this = AddModul( Modul( *this ), Modul( b ) );
    negative = b.negative;
  }
  return *this;
}

Fraction35B operator+( const Fraction35B& a, const Fraction35B& b ) {
  Fraction35B loc = a;
  loc += b;
  return loc;
}

Fraction35B& Fraction35B::operator-=( const Fraction35B& b ) {
  if ( !negative && !b.negative ) {  //оба положительные
    if ( *this < b ) {
      *this = SubModul( b, *this );
      negative = true;
    } else {
      *this = SubModul( *this, b );
    }
  } else if ( negative && b.negative ) {  //оба отрицательные
    if ( LessMod( *this, b ) ) {
      *this = SubModul( Modul( b ), Modul( *this ) );
    } else if ( !LessMod( *this, b ) ) {
      *this = SubModul( Modul( *this ), Modul( b ) );
      negative = true;
    }
  } else {  //знаки разные
    if ( negative && !b.negative ) {
      *this = AddModul( Modul( *this ), Modul( b ) );
      negative = true;
    } else if ( !negative && b.negative ) {
      *this = AddModul( Modul( *this ), Modul( b ) );
    }
  }
  return *this;
}

Fraction35B operator-( const Fraction35B& a, const Fraction35B& b ) {
  Fraction35B loc = a;
  loc -= b;
  return loc;
}

Fraction35B& Fraction35B::operator*=( const Fraction35B& b ) {
  *this = MulModul( *this, b );
  negative = ( negative != b.negative ) ? true : false;
  return *this;
}

Fraction35B operator*( const Fraction35B& a, const Fraction35B& b ) {
  Fraction35B loc = a;
  loc *= b;
  return loc;
}

Fraction35B& Fraction35B::operator/=( const Fraction35B& b ) {
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
  double x = LongLong38B::operator int64_t( ) + fractional_ / 1000;
  double y = b.LongLong38B::operator int64_t( ) + b.fractional_ / 1000;
  double res = x / y;
  *this = Fraction35B( res, ( res - static_cast< int64_t >( res ) ) * 10000 );
  return *this;
}

Fraction35B operator/( const Fraction35B& a, const Fraction35B& b ) {
  Fraction35B loc = a;
  loc /= b;
  return loc;
}


bool operator<( const Fraction35B& a, const Fraction35B& b ) {
  if ( a.negative && !b.negative ) {
    return !LessMod( a, b );
  } else if ( !a.negative && !b.negative ) {
    return LessMod( a, b );
  } else {
    return ( static_cast< int64_t >( a ) < static_cast< int64_t >( b ) );
  }
}

bool operator<=( const Fraction35B& a, const Fraction35B& b ) {
  return a < b || a == b;
}

bool operator>( const Fraction35B& a, const Fraction35B& b ) {
  return !( a <= b );
}

bool operator>=( const Fraction35B& a, const Fraction35B& b ) {
  return a > b || a == b;
}

bool operator==( const Fraction35B& a, const Fraction35B& b ) {
  return ( a.negative == b.negative &&
           static_cast< int64_t >( a ) == static_cast< int64_t >( b ) &&
           a.fractional_ == b.fractional_ );
}

bool operator!=( const Fraction35B& a, const Fraction35B& b ) {
  return !( a == b );
}

Fraction35B Fraction35B::AddModul( const Fraction35B& a,
                                   const Fraction35B& b ) {
  Fraction35B loc = a;
  static_cast< LongLong38B& >( loc ) = static_cast< const LongLong38B& >( a ) +
                                       static_cast< const LongLong38B& >( b );
  loc.fractional_ = a.fractional_ + b.fractional_;
  if ( loc.fractional_ > 10000 ) {
    loc.fractional_ -= 10000;
    static_cast< LongLong38B& >( loc ) += 1;
  }
  return loc;
}

Fraction35B Fraction35B::SubModul( const Fraction35B& a,
                                   const Fraction35B& b ) {
  Fraction35B loc;
  static_cast< LongLong38B& >( loc ) = static_cast< const LongLong38B& >( a ) -
                                       static_cast< const LongLong38B& >( b );
  if ( a.fractional_ < b.fractional_ ) {
    static_cast< LongLong38B& >( loc ) -= 1;
    loc.fractional_ = a.fractional_ + 10000 - b.fractional_;
  } else {
    loc.fractional_ = a.fractional_ - b.fractional_;
  }
  return loc;
}

Fraction35B Fraction35B::MulModul( const Fraction35B& a,
                                   const Fraction35B& b ) {
  //(a + b)*(c + d)
  int64_t ac_t = static_cast< int64_t >( a ) * static_cast< int64_t >( b );
  double ad_t = static_cast< int64_t >( a ) * ( b.fractional_ / 10000 );
  double bc_t = ( a.fractional_ / 10000 ) * static_cast< int64_t >( b );
  int64_t bd_t = a.fractional_ * b.fractional_;

  Fraction35B ac( ac_t, 0 );
  Fraction35B ad( ad_t, ( ad_t - static_cast< int64_t >( ad_t ) ) * 10000 );
  Fraction35B bc( bc_t, ( bc_t - static_cast< int64_t >( bc_t ) ) * 10000 );
  Fraction35B bd( bd_t / 100000000, ( bd_t % 100000000 ) / 10000 );
  Fraction35B res = ac + ad + bc + bd;
  return res;
}

Fraction35B Fraction35B::Modul( const Fraction35B& a ) {
  return Fraction35B( std::abs( static_cast< int64_t >( a ) ), a.fractional_ );
}

bool LessMod( const Fraction35B& a, const Fraction35B& b ) {
  return ( std::abs( static_cast< int64_t >( a ) ) <
           std::abs( static_cast< int64_t >( b ) ) ) ||
         ( ( std::abs( static_cast< int64_t >( a ) ) ==
             std::abs( static_cast< int64_t >( b ) ) ) &&
           ( a.fractional_ < b.fractional_ ) );
}

bool Fraction35B::GetNegative( ) { return negative; }

int16_t Fraction35B::Fractional( ) { return fractional_; }

LongLong38B Fraction35B::Whole( ) {
  return static_cast< LongLong38B >( *this );
}
