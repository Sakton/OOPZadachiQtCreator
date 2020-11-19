#include "rybak.h"

Rybak::Rybak()
{
  
}

void Rybak::getFishOut_n( Ozero* o, int8_t colvo ) {
  for ( int8_t i = 0; i < colvo; ++i ) {
    getFish( o );
  }
}

void Rybak::getFish( Ozero* o ) { ulov_.push( o->getFish( ) ); }

size_t Rybak::size( ) const { return ulov_.size( ); }

const Ulov Rybak::getUlov( ) const { return ulov_; }

std::ostream& operator<<( std::ostream& out, const Rybak& r ) { return out << r.ulov_; }
