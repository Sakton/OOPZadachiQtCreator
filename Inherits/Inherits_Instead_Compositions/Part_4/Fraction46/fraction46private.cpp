#include "fraction46private.h"

#include <iostream>
#include <sstream>

Fraction46private::Fraction46private( int64_t w, double f )
    : LongLong38B( w ), fractional_ { f } {
  if ( f < 0 || f >= 10000 ) {
    std::cout << "ERROR ARG FRACTIONAL < 0 || >= 10000";
    exit( 1 );
  }
  negative = ( w < 0 ) ? true : false;
  fractional_ = std::abs( f );
}

void Fraction46private::Display( ) const {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

Fraction46private::operator std::string( ) const {
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

Fraction46private& Fraction46private::operator+=( const Fraction46private& b ) {
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

Fraction46private operator+( const Fraction46private& a,
                             const Fraction46private& b ) {
  Fraction46private loc = a;
  loc += b;
  return loc;
}

Fraction46private& Fraction46private::operator-=( const Fraction46private& b ) {
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

Fraction46private operator-( const Fraction46private& a,
                             const Fraction46private& b ) {
  Fraction46private loc = a;
  loc -= b;
  return loc;
}

Fraction46private& Fraction46private::operator*=( const Fraction46private& b ) {
  *this = MulModul( *this, b );
  negative = ( negative != b.negative ) ? true : false;
  return *this;
}

Fraction46private operator*( const Fraction46private& a,
                             const Fraction46private& b ) {
  Fraction46private loc = a;
  loc *= b;
  return loc;
}

Fraction46private& Fraction46private::operator/=( const Fraction46private& b ) {
  //деление выдает большую погрешность на больших числах
  //неодходимо увеличивать точность самого класса
  // 5555.5555 / 2222.2222 = 2,5
  //при этой точности 1/10000
  // 5555.5555 / 2222.2222 = 2.2222 ( 1/2222,2222 = 0,0004 в этом случае
  // (0,00045) ) но даже если округлить до 1/2222,2222 = 0,0005, то 5555.5555 /
  // 2222.2222 = 2.7777 поэтому на эту операцию при данной точности надеятся
  //нельзя и в учебнике не просят ее делатть
  //  **
  //    Fraction46private loc = *this;
  //    return loc.Mul( OneDivFrac( b ) );
  //  **

  //или тупо через дабл
  double x = static_cast< int64_t >( *this ) + fractional_ / 1000;
  double y = static_cast< int64_t >( b ) + b.fractional_ / 1000;
  double res = x / y;
  *this =
      Fraction46private( res, ( res - static_cast< int64_t >( res ) ) * 10000 );
  return *this;
}

Fraction46private operator/( const Fraction46private& a,
                             const Fraction46private& b ) {
  Fraction46private loc = a;
  loc /= b;
  return loc;
}

bool operator<( const Fraction46private& a, const Fraction46private& b ) {
  if ( a.negative && !b.negative ) {
    return !LessMod( a, b );
  } else if ( !a.negative && !b.negative ) {
    return LessMod( a, b );
  } else {
    return ( static_cast< LongLong38B >( a ) <
             static_cast< LongLong38B >( b ) );
  }
}

bool operator<=( const Fraction46private& a, const Fraction46private& b ) {
  return a < b || a == b;
}

bool operator>( const Fraction46private& a, const Fraction46private& b ) {
  return !( a <= b );
}

bool operator>=( const Fraction46private& a, const Fraction46private& b ) {
  return a > b || a == b;
}

bool operator==( const Fraction46private& a, const Fraction46private& b ) {
  return ( a.negative == b.negative &&
           static_cast< LongLong38B >( a ) == static_cast< LongLong38B >( b ) &&
           a.fractional_ == b.fractional_ );
}

bool operator!=( const Fraction46private& a, const Fraction46private& b ) {
  return !( a == b );
}

Fraction46private Fraction46private::AddModul( const Fraction46private& a,
                                               const Fraction46private& b ) {
  Fraction46private loc = a;
  static_cast< LongLong38B& >( loc ) =
      static_cast< LongLong38B >( a ) + static_cast< LongLong38B >( b );
  loc.fractional_ = a.fractional_ + b.fractional_;
  if ( loc.fractional_ > 10000 ) {
    loc.fractional_ -= 10000;
    static_cast< LongLong38B& >( loc ) += 1;
  }
  return loc;
}

Fraction46private Fraction46private::SubModul( const Fraction46private& a,
                                               const Fraction46private& b ) {
  Fraction46private loc;
  static_cast< LongLong38B& >( loc ) =
      static_cast< LongLong38B >( a ) - static_cast< LongLong38B >( b );
  if ( a.fractional_ < b.fractional_ ) {
    static_cast< LongLong38B& >( loc ) -= 1;
    loc.fractional_ = a.fractional_ + 10000 - b.fractional_;
  } else {
    loc.fractional_ = a.fractional_ - b.fractional_;
  }
  return loc;
}

Fraction46private Fraction46private::MulModul( const Fraction46private& a,
                                               const Fraction46private& b ) {
  //(a + b)*(c + d)
  int64_t ac_t = static_cast< int64_t >( a ) * static_cast< int64_t >( b );
  double ad_t = static_cast< int64_t >( a ) * ( b.fractional_ / 10000 );
  double bc_t = ( a.fractional_ / 10000 ) * static_cast< int64_t >( b );
  int64_t bd_t = a.fractional_ * b.fractional_;

  Fraction46private ac( ac_t, 0 );
  Fraction46private ad( ad_t,
                        ( ad_t - static_cast< int64_t >( ad_t ) ) * 10000 );
  Fraction46private bc( bc_t,
                        ( bc_t - static_cast< int64_t >( bc_t ) ) * 10000 );
  Fraction46private bd( bd_t / 100000000, ( bd_t % 100000000 ) / 10000 );
  Fraction46private res = ac + ad + bc + bd;
  return res;
}

Fraction46private Fraction46private::Modul( const Fraction46private& a ) {
  return Fraction46private( std::abs( static_cast< int64_t >( a ) ),
                            a.fractional_ );
}

bool LessMod( const Fraction46private& a, const Fraction46private& b ) {
  return ( static_cast< LongLong38B >( a ).Modul( ) <
           static_cast< LongLong38B >( b ).Modul( ) ) ||
         ( ( static_cast< LongLong38B >( a ).Modul( ) ==
             static_cast< LongLong38B >( b ).Modul( ) ) &&
           ( a.fractional_ < b.fractional_ ) );
}

bool Fraction46private::GetNegative( ) { return negative; }

int16_t Fraction46private::Fractional( ) { return fractional_; }

LongLong38B Fraction46private::Whole( ) {
  return static_cast< LongLong38B >( *this );
}
