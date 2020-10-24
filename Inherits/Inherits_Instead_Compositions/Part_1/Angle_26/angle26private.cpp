#include "angle26private.h"

Angle26private::Angle26private( int16_t g, int16_t m ) : Angle26Base( g, m ) {}

Angle26private::Angle26private( double angl ) : Angle26Base( angl ) {}

Angle26private operator+( const Angle26private& an1,
                          const Angle26private& an2 ) {
  Angle26private t = an1;
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

Angle26private operator-( const Angle26private& an1,
                          const Angle26private& an2 ) {
  Angle26private t = an1;
  t.setGrad( t.getGrad( ) - an2.getGrad( ) );
  t.setMin( t.getMin( ) - an2.getMin( ) );
  if ( std::abs( t.getMin( ) ) >= 60 ) {
    t.setGrad( ( t.getGrad( ) < 0 ) ? t.getGrad( ) - 1 : t.getGrad( ) + 1 );
    t.setMin( ( t.getMin( ) < 0 ) ? t.getMin( ) + 60 : t.getMin( ) - 60 );
  }
  return t;
}

bool operator<( const Angle26private& an1, const Angle26private& an2 ) {
  return ( an1.getGrad( ) < an2.getGrad( ) ) ||
         ( ( an1.getGrad( ) == an2.getGrad( ) ) &&
           ( an1.getMin( ) < an2.getMin( ) ) );
}
bool operator<=( const Angle26private& an1, const Angle26private& an2 ) {
  return an1 < an2 || an1 == an2;
}
bool operator>( const Angle26private& an1, const Angle26private& an2 ) {
  return !( an1 <= an2 );
}
bool operator>=( const Angle26private& an1, const Angle26private& an2 ) {
  return an1 > an2 || an1 == an2;
}
bool operator==( const Angle26private& an1, const Angle26private& an2 ) {
  return ( an1.getGrad( ) == an2.getGrad( ) ) &&
         ( an1.getMin( ) == an2.getMin( ) );
}
bool operator!=( const Angle26private& an1, const Angle26private& an2 ) {
  return !( an1 == an2 );
}

void Display( const Angle26private& an ) {
  //ругается но работает
  return ::Display( static_cast< const Angle26Base& >( an ) );
}

std::string ToString( const Angle26private& ang ) {
  //ругается но работает
  return ::ToString( static_cast< const Angle26Base& >( ang ) );
}
