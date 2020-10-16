#include <iostream>

#include "vector3dinh.h"

int main( ) {
  Vector3DInh vi( 2, 2, 2 );
  Display( vi );
  vi.setX( 5 );
  vi.setY( 6 );
  vi.setZ( 7 );
  Display( vi );
  Vector3DInh vi1( 10, 10, 10 );
  Display( ( vi += vi1 ) );
  Display( vi -= vi1 );
  Display( vi *= vi1 );
  Display( vi *= 2 );

  Vector3DBase *vec = new Vector3DInh( 3, 3, 3 );

  Display( *vec );

  delete vec;
}
