#include "bankomat34.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

const double Bankomat34::Money33::NOMIMALS_BILL[] {
    0.01, 0.05, 0.1, 0.5, 1, 2, 5, 10, 50, 100, 200, 500, 1000, 2000, 5000 };

Bankomat34::Money33::Money33( double sum ) {
  if ( sum < 0 ) {
    std::cout << "ERROR SUM INIT";
    exit( 1 );
  }
  ParseSum( sum );
}

Bankomat34::Money33::operator double( ) const {
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

Bankomat34::Money33::operator std::string( ) const {
  std::stringstream ss;
  ss << std::fixed << std::setprecision( 2 ) << static_cast< double >( *this );
  return ss.str( );
}

void Bankomat34::Money33::ParseSum( double sum ) {
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

void Display( const Bankomat34::Money33& b ) {
  std::cout << static_cast< std::string >( b ) << std::endl;
}

Bankomat34::Money33 operator+( const Bankomat34::Money33& b1,
                               const Bankomat34::Money33& b2 ) {
  return Bankomat34::Money33( static_cast< double >( b1 ) +
                              static_cast< double >( b2 ) );
}

Bankomat34::Money33 operator-( const Bankomat34::Money33& b1,
                               const Bankomat34::Money33& b2 ) {
  return Bankomat34::Money33( static_cast< double >( b1 ) -
                              static_cast< double >( b2 ) );
}
Bankomat34::Money33 operator*( const Bankomat34::Money33& b1,
                               const Bankomat34::Money33& b2 ) {
  return Bankomat34::Money33( static_cast< double >( b1 ) *
                              static_cast< double >( b2 ) );
}
Bankomat34::Money33 operator/( const Bankomat34::Money33& b1,
                               const Bankomat34::Money33& b2 ) {
  return Bankomat34::Money33( static_cast< double >( b1 ) /
                              static_cast< double >( b2 ) );
}
Bankomat34::Money33 operator/( const Bankomat34::Money33& b1, double x ) {
  return Bankomat34::Money33( static_cast< double >( b1 ) / x );
}

bool operator<( const Bankomat34::Money33& b1, const Bankomat34::Money33& b2 ) {
  return static_cast< double >( b1 ) < static_cast< double >( b2 );
}
bool operator<=( const Bankomat34::Money33& b1,
                 const Bankomat34::Money33& b2 ) {
  return ( b1 == b2 ) || ( b1 < b2 );
}
bool operator>( const Bankomat34::Money33& b1, const Bankomat34::Money33& b2 ) {
  return !( b1 <= b2 );
}
bool operator>=( const Bankomat34::Money33& b1,
                 const Bankomat34::Money33& b2 ) {
  return ( b1 > b2 ) || ( b1 == b2 );
}
bool operator==( const Bankomat34::Money33& b1,
                 const Bankomat34::Money33& b2 ) {
  return ( std::fabs( static_cast< double >( b1 ) -
                      static_cast< double >( b2 ) ) ) < 1e-3;
}
bool operator!=( const Bankomat34::Money33& b1,
                 const Bankomat34::Money33& b2 ) {
  return !( b1 == b2 );
}

Bankomat34::Bankomat34( int32_t id, int32_t min, int32_t max, Money33 cash )
    : id_ { 0 }, min_ { 0 }, max_ { 0 }, cash_ { 0 } {
  if ( id < 0 || min < 0 || max < 0 ) {
    std::cout << "ERROR ARG INIT";
    exit( 1 );
  }
  id_ = id;
  min_ = min;
  max_ = max;
  cash_ = cash;
}

Bankomat34::operator std::string( ) const {
  return "id: " + std::to_string( id_ ) + "\n" +
         "min: " + std::to_string( min_ ) + "\n" +
         "max: " + std::to_string( max_ ) + "\n" +
         "cash: " + static_cast< std::string >( cash_ );
}

void Bankomat34::Display( ) const {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

Bankomat34::operator double( ) const { return static_cast< double >( cash_ ); }

void Bankomat34::AddCash( double money ) { cash_ = cash_ + Money33( money ); }

void Bankomat34::SubCash( double money ) { cash_ = cash_ - Money33( money ); }
