#include "family.h"

#include <stdexcept>

Family::Family( const std::string &fam ) : family_ { validateFamily( fam ) } {}

const std::string &Family::validateFamily( const std::string &fam ) const {
  if ( fam.size( ) == 1 || fam.size( ) == 0 ) throw std::runtime_error( "NO VALID FAMILY ERROR SIZE" );
  for ( auto &el : fam )
    if ( isdigit( el ) || ispunct( el ) ) throw std::runtime_error( "NO VALID FAMILY ERROR CHAR" );
  return fam;
}

std::string Family::family( ) const { return family_; }

void Family::setFamily( const std::string &family ) { family_ = validateFamily( family ); }

std::ostream &operator<<( std::ostream &out, const Family &fam ) { return out << fam.family( ) << std::endl; }
