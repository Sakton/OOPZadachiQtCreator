#include "vectopr3d.h"

Vectopr3D::Vectopr3D( int f, int s, int t ) : Triad( f, s, t ) {}

Vectopr3D &Vectopr3D::operator+=( const Vectopr3D &ot ) {
  setFirst( first( ) + ot.first( ) );
  setSecond( second( ) + ot.second( ) );
  setThird( third( ) + ot.third( ) );
  return *this;
}

Vectopr3D &Vectopr3D::operator*=( const Vectopr3D &ot ) {
  setFirst( first( ) * ot.first( ) );
  setSecond( second( ) * ot.second( ) );
  setThird( third( ) * ot.third( ) );
  return *this;
}

Vectopr3D operator+( const Vectopr3D &ot1, const Vectopr3D &ot2 ) {
  Vectopr3D loc = ot1;
  loc += ot2;
  return loc;
}

Vectopr3D operator*( const Vectopr3D &ot1, const Vectopr3D &ot2 ) {
  Vectopr3D loc = ot1;
  loc *= ot2;
  return loc;
}
