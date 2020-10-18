#include "bankomat34.h"

#include <algorithm>
#include <iostream>

Bankomat34::Bankomat34( int32_t id, int32_t min, int32_t max,
                        Bankomat34::SpecArray cassetaMoney )
    : id_ { 0 }, min_ { 0 }, max_ { 0 }, cash_ { 0 } {
  if ( id < 0 || min < 0 || max < 0 ) {
    std::cout << "ERROR ARG INIT";
    exit( 1 );
  }
  id_ = id;
  min_ = min;
  max_ = max;
  AddCash( *this, cassetaMoney );
}

Bankomat34::operator std::string( ) const {
  int64_t res = RemainerCash( *this );
  return std::to_string( res );
}

void Display( const Bankomat34& bn ) {
  std::cout << static_cast< std::string >( bn ) << std::endl;
}

void AddCash( Bankomat34& bn, Bankomat34::SpecArray cassetaMoney ) {
  if ( cassetaMoney ) {
    for ( int i = 0; i < Bankomat34::COUNT_ELEMENTS; ++i ) {
      if ( cassetaMoney[ i ] < 0 ) {
        std::cout << "BAD CASSETE";
        exit( 1 );
      }
      bn.cash_[ i ] += cassetaMoney[ i ];
    }
  }
}

void SubCash( Bankomat34& bn, int32_t summ ) {
  if ( summ > RemainerCash( bn ) || summ > bn.max_ || summ < bn.min_ ) {
    std::cout << "ERROR SUM SUBS";
    exit( 1 );
  }
  Bankomat34::SpecArray subArray { 0 };
  for ( int i = Bankomat34::COUNT_ELEMENTS - 1; i >= 0 && summ; --i ) {
    subArray[ i ] = std::min< int16_t >(
        ( summ / Bankomat34::NOMIMALS_BILL[ i ] ), bn.cash_[ i ] );
    summ -= subArray[ i ] * Bankomat34::NOMIMALS_BILL[ i ];
  }

  if ( summ ) {
    std::cout << "I can't type bills";
    std::cout << "ENTER ANOTHER SUMM";
    exit( 1 );
  }
  //выдача купюр
  for ( int i = 0; i < Bankomat34::COUNT_ELEMENTS; ++i ) {
    bn.cash_[ i ] -= subArray[ i ];
  }
}

void ParsePoNominals( /*const Bankomat34& bn,*/ int32_t summ,
                      Bankomat34::SpecArray arr ) {
  arr[ Bankomat34::NOM_1000_RUR ] =
      summ / Bankomat34::NOMIMALS_BILL[ Bankomat34::NOM_1000_RUR ];
  summ %= Bankomat34::NOMIMALS_BILL[ Bankomat34::NOM_1000_RUR ];
  arr[ Bankomat34::NOM_500_RUR ] =
      summ / Bankomat34::NOMIMALS_BILL[ Bankomat34::NOM_500_RUR ];
  summ %= Bankomat34::NOMIMALS_BILL[ Bankomat34::NOM_500_RUR ];
  arr[ Bankomat34::NOM_100_RUR ] =
      summ / Bankomat34::NOMIMALS_BILL[ Bankomat34::NOM_100_RUR ];
  summ %= Bankomat34::NOMIMALS_BILL[ Bankomat34::NOM_100_RUR ];
  arr[ Bankomat34::NOM_50_RUR ] =
      summ / Bankomat34::NOMIMALS_BILL[ Bankomat34::NOM_50_RUR ];
  summ %= Bankomat34::NOMIMALS_BILL[ Bankomat34::NOM_1000_RUR ];
  arr[ Bankomat34::NOM_10_RUR ] =
      summ / Bankomat34::NOMIMALS_BILL[ Bankomat34::NOM_10_RUR ];
  summ %= Bankomat34::NOMIMALS_BILL[ Bankomat34::NOM_10_RUR ];
}

int64_t RemainerCash( const Bankomat34& bn ) {
  int64_t res = 0;
  for ( int i = 0; i < Bankomat34::COUNT_ELEMENTS; ++i ) {
    res += bn.cash_[ i ] * Bankomat34::NOMIMALS_BILL[ i ];
  }
  return res;
}
