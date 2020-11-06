#include "bankomatbase.h"

#include <iostream>
#include <stdexcept>

BankomatBase::BankomatBase( value_type id, value_type min, value_type max,
                            BankomatBase::SpecArray cassetaMoney )
    : id_ { 0 }, min_ { 0 }, max_ { 0 } {
  if ( id < 0 || min < 0 || max < 0 ) {
    throw std::runtime_error( "ERROR ARG CTOR" );
  }

  id_ = id;
  min_ = min;
  max_ = max;
  std::copy( cassetaMoney, cassetaMoney + COUNT_ELEMENTS, cash_ );
}

int64_t BankomatBase::RemainerCash( ) const {
  int64_t res = 0;
  for ( int i = 0; i < COUNT_ELEMENTS; ++i ) {
    res += cash_[ i ] * NOMIMALS_BILL[ i ];
  }
  return res;
}

BankomatBase::reference BankomatBase::operator[]( int ind ) {
  if ( !( 0 <= ind && ind < COUNT_ELEMENTS ) ) {
    throw std::out_of_range( "OUT OF RANGE" );
  }
  return cash_[ ind ];
}

BankomatBase::const_reference BankomatBase::operator[]( int ind ) const {
  if ( !( 0 <= ind && ind < COUNT_ELEMENTS ) ) {
    throw std::out_of_range( "OUT OF RANGE" );
  }
  return cash_[ ind ];
}

BankomatBase::value_type BankomatBase::getMax( ) const { return max_; }

BankomatBase::value_type BankomatBase::getMin( ) const { return min_; }

std::string toString( const BankomatBase &b ) {
    int64_t res = b.RemainerCash( );
  return std::to_string( res );
}

void Display( const BankomatBase &b ) {
  std::cout << toString( b ) << std::endl;
}
