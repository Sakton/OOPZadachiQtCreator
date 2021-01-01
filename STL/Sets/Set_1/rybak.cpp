#include "rybak.h"

Rybak::Rybak( ) {}

void Rybak::getFishOut_n( Ozero* o, int8_t colvo ) {
  for ( int8_t i = 0; i < colvo; ++i ) {
    add( o->getFish( ) );
  }
}

void Rybak::add( std::shared_ptr< IFish > fish ) { ulov_.push( fish ); }

size_t Rybak::size( ) const { return ulov_.size( ); }

const Ulov Rybak::getUlov( ) const { return ulov_; }

std::ostream& operator<<( std::ostream& out, const Rybak& r ) { return out << r.ulov_; }
