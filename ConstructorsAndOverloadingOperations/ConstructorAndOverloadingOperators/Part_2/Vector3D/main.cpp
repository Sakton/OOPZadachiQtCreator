#include <iostream>

#include "vector3d.h"

int main( ) {
  Vector3D v( 2, 2, 2 );
  Vector3D v1( 10, 10, 10 );
  v.Display( );
  v1.Display( );
  ( v + v1 ).Display( );
  ( v - v1 ).Display( );
  ( v * v1 ).Display( );
  ( v * 3 ).Display( );
}
