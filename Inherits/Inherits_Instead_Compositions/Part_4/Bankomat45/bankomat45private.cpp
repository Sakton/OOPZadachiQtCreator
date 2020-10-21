#include "bankomat45private.h"

#include <algorithm>
#include <iostream>

Bankomat45private::Bankomat45private( int32_t id, int32_t min, int32_t max,
                                      double cash )
    : Money33( cash ), id_ { 0 }, min_ { 0 }, max_ { 0 } {
  if ( id < 0 || min < 0 || max < 0 ) {
    std::cout << "ERROR ARG INIT";
    exit( 1 );
  }
  id_ = id;
  min_ = min;
  max_ = max;
}

Bankomat45private::operator std::string( ) const {
  return "id: " + std::to_string( id_ ) + "\n" +
         "min: " + std::to_string( min_ ) + "\n" +
         "max: " + std::to_string( max_ ) + "\n" +
         "cash: " + Money33::operator std::string( );
}

void Bankomat45private::Display( ) const {
  std::cout << static_cast< std::string >( *this ) << std::endl;
}

Bankomat45private::operator double( ) const {
  return static_cast< double >( Money33::operator double( ) );
}

void Bankomat45private::AddCash( double money ) {
  static_cast< Money33& >( *this ) =
      static_cast< Money33& >( *this ) + Money33( money );
}

void Bankomat45private::SubCash( double money ) {
  static_cast< Money33& >( *this ) =
      static_cast< Money33& >( *this ) - Money33( money );
}
