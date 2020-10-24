#include "angle26public.h"

Angle26public::Angle26public( int16_t g, int16_t m ) : Angle26Base( g, m ) {}

Angle26public::Angle26public( double angl ) : Angle26Base( angl ) {}

Angle26public operator+( const Angle26public& an1, const Angle26public& an2 ) {
  Angle26public t = an1;
  t.setGrad( t.getGrad( ) + an2.getGrad( ) );
  t.setMin( t.getMin( ) + an2.getMin( ) );
  if ( std::abs( t.getMin( ) ) >= 60 ) {
    t.setGrad( ( t.getGrad( ) < 0 ) ? ( t.getGrad( ) - 1 )
                                    : ( t.getGrad( ) + 1 ) );
    t.setMin( ( t.getMin( ) < 0 ) ? ( t.getMin( ) + 60 )
                                  : ( t.getMin( ) - 60 ) );
  }
  return t;
}

Angle26public operator-( const Angle26public& an1, const Angle26public& an2 ) {
  Angle26public t = an1;
  t.setGrad( t.getGrad( ) - an2.getGrad( ) );
  t.setMin( t.getMin( ) - an2.getMin( ) );
  if ( std::abs( t.getMin( ) ) >= 60 ) {
    t.setGrad( ( t.getGrad( ) < 0 ) ? t.getGrad( ) - 1 : t.getGrad( ) + 1 );
    t.setMin( ( t.getMin( ) < 0 ) ? t.getMin( ) + 60 : t.getMin( ) - 60 );
  }
  return t;
}

bool operator<( const Angle26public& an1, const Angle26public& an2 ) {
  return ( an1.getGrad( ) < an2.getGrad( ) ) ||
         ( ( an1.getGrad( ) == an2.getGrad( ) ) &&
           ( an1.getMin( ) < an2.getMin( ) ) );
}
bool operator<=( const Angle26public& an1, const Angle26public& an2 ) {
  return an1 < an2 || an1 == an2;
}
bool operator>( const Angle26public& an1, const Angle26public& an2 ) {
  return !( an1 <= an2 );
}
bool operator>=( const Angle26public& an1, const Angle26public& an2 ) {
  return an1 > an2 || an1 == an2;
}
bool operator==( const Angle26public& an1, const Angle26public& an2 ) {
  return ( an1.getGrad( ) == an2.getGrad( ) ) &&
         ( an1.getMin( ) == an2.getMin( ) );
}
bool operator!=( const Angle26public& an1, const Angle26public& an2 ) {
  return !( an1 == an2 );
}
