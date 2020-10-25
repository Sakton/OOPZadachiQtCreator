#include "basemoney.h"

#include <iomanip>
#include <iostream>
#include <sstream>

const double BaseMoney::NOMIMALS_BILL[] {
    0.01, 0.05, 0.1, 0.5, 1, 2, 5, 10, 50, 100, 200, 500, 1000, 2000, 5000 };

BaseMoney::BaseMoney( double sum ) {
  if ( sum < 0 ) {
    std::cout << "ERROR SUM INIT";
    exit( 1 );
  }
  ParseSum( sum );
}

void BaseMoney::ParseSum( double sum ) {
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

BaseMoney::operator double( ) const {
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

BaseMoney::operator std::string( ) const {
  std::stringstream ss;
  ss << std::fixed << std::setprecision( 2 ) << static_cast< double >( *this );
  return ss.str( );
}

void Display( const BaseMoney& b ) {
  std::cout << static_cast< std::string >( b ) << std::endl;
}
