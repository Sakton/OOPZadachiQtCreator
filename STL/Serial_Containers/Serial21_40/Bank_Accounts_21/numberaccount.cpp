#include "numberaccount.h"

#include <iostream>
#include <stdexcept>

NumberAccount::NumberAccount( const std::string &num ) : number_ { validateNumber( num ) } {}

std::string NumberAccount::validateNumber( const std::string &num ) const {
  if ( num.size( ) > SIZE_NUMBER ) throw std::runtime_error( "ERROR NUM ACC" );
  for ( auto &el : num )
    if ( !std::isdigit( el ) ) throw std::runtime_error( "ERROR NUM ACC NO DIGIT" );
  return num;
}

void NumberAccount::setNumber( const std::string &number ) { number_ = validateNumber( number ); }

std::string NumberAccount::number( ) const { return number_; }

std::ostream &operator<<( std::ostream &out, const NumberAccount &na ) {
  out << na.number( ) << std::endl;
  return out;
}
