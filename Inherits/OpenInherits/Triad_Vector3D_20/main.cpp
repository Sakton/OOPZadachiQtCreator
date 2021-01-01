#include <iostream>

#include "vectopr3d.h"

int main( ) {
  Triad *tr = new Vectopr3D( 10, 10, 10 );
  Triad *tr1 = new Vectopr3D( 20, 20, 20 );

  Triad rr = ( *tr ) + 3;
  rr.Display( );

  Triad r = ( *( static_cast< Vectopr3D * >( tr ) ) +
              *( static_cast< Vectopr3D * >( tr1 ) ) );

  r.Display( );

  Vectopr3D vv( 40, 40, 40 );
  vv += vv;
  vv.Display( );
  std::cout << "&vv = " << &vv << std::endl;
  Triad ttrr = static_cast< Triad >( vv ) += 5;
  vv.Display( );
  ttrr.Display( );
}
