#include "bankomatprivate.h"

#include <stdexcept>

BankomatPrivate::BankomatPrivate( value_type id, value_type min, value_type max,
                                  SpecArray cassetaMoney )
    : BankomatBase( id, min, max, cassetaMoney ) {}

void BankomatPrivate::AddCash( BankomatBase::SpecArray cassetaMoney ) {
  if ( cassetaMoney ) {
    for ( int i = 0; i < COUNT_ELEMENTS; ++i ) {
      if ( cassetaMoney[ i ] < 0 ) {
        throw std::runtime_error( "" );
      }
      ( *this )[ i ] += cassetaMoney[ i ];
    }
  }
}

void BankomatPrivate::SubCash( BankomatBase::value_type summ ) {
  if ( summ > RemainerCash( ) || summ > getMax( ) || summ < getMin( ) ) {
    throw std::runtime_error( "ERROR SUM SUBS" );
  }
  SpecArray subArray { 0 };
  for ( int i = COUNT_ELEMENTS - 1; i >= 0 && summ; --i ) {
    // 1. Сколько надо купюр и сколько их есть в наличии
    subArray[ i ] =
        std::min< int16_t >( ( summ / NOMIMALS_BILL[ i ] ), ( *this )[ i ] );
    summ -= subArray[ i ] * NOMIMALS_BILL[ i ];
  }

  if ( summ ) {
    throw std::runtime_error( "ENTER ANOTHER SUMM" );
  }
  //выдача купюр
  for ( int i = 0; i < COUNT_ELEMENTS; ++i ) {
    ( *this )[ i ] -= subArray[ i ];
  }
}

void Display( const BankomatPrivate &b ) {
  return Display( static_cast< const BankomatBase & >( b ) );
}

std::string toString( const BankomatPrivate &b ) {
  return toString( static_cast< const BankomatBase & >( b ) );
}
