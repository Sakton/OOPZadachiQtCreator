#include "numberaccount.h"

#include <stdexcept>

NumberAccount::NumberAccount( const std::string &num ) : number_ { validateNumber( num ) } {}

std::string NumberAccount::validateNumber( const std::string &num ) const {
  if ( num.size( ) != SIZE_NUMBER ) throw std::runtime_error( "ERROR NUM ACC" );
  for ( auto &el : num )
    if ( !std::isdigit( el ) ) throw std::runtime_error( "ERROR NUM ACC NO DIGIT" );
  return num;
}

std::string NumberAccount::number( ) const { return number_; }

std::ostream &operator<<( std::ostream &out, const NumberAccount &na ) {
  out << "NumberAccount = " << na.number( ) << std::endl;
  return out;
}
