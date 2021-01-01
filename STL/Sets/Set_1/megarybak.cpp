#include "megarybak.h"

MegaRybak::MegaRybak( ) {}

void MegaRybak::addConcreteFish( Ozero *o, int id ) { add( o->getConkreteFish( id ) ); }

void MegaRybak::megaUlov( Ozero *o ) {
  for ( int i = 0; i < IFish::getIDCOUNT( ); ++i ) {
    addConcreteFish( o, i );
  }
}
