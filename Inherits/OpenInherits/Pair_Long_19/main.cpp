#include <iostream>

#include "long.h"

int main( ) {
  Long a( 10, 10 );
  Long b( 10, 10 );
  a += b;
  a.Display( );

  Pair &aa = a;
  Pair &bb = b;

  aa += bb;
  Pair c = aa + bb;
  c.Display( );
  static_cast< Long & >( aa ) -= static_cast< Long & >( bb );
  aa.Display( );

  static_cast< Long & >( aa ) *= static_cast< Long & >( bb );
  aa.Display( );

  Pair d = static_cast< Long & >( aa ) - static_cast< Long & >( bb );
  Pair e = static_cast< Long & >( aa ) * static_cast< Long & >( bb );

  d.Display( );
  e.Display( );
}
