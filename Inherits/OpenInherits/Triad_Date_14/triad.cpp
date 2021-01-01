#include "triad.h"

#include <string>

Triad::Triad( int f, int s, int t ) : first { f }, second { s }, third { t } {}

int &Triad::firstNext( ) { return ++first; }

int &Triad::secondNext( ) { return ++second; }

int &Triad::thirdNext( ) { return ++third; }

std::ostream &Triad::Show( std::ostream &out ) const {
  out << static_cast< std::string >( *this );
  return out;
}

Triad::operator std::string( ) const {
  return "triad string " + std::to_string( Triad::first ) + ":" +
         std::to_string( Triad::second ) + ":" + std::to_string( Triad::third );
}
