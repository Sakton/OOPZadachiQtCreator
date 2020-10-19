#include <iostream>

#include "complex21.h"

int main( ) {
  //*** Methods demonstration
  Complex21 a( 1.1, 2.2 ), b( 3.3, 4.4 );
  a.Display( );
  std::cout << std::endl;
  b.Display( );
  std::cout << std::endl;

  Complex21 c = a + b;
  Complex21 d = a - b;
  Complex21 e = a / b;
  Complex21 f = a * b;

  c.Display( );
  std::cout << std::endl;
  d.Display( );
  std::cout << std::endl;
  e.Display( );
  std::cout << std::endl;
  f.Display( );
  std::cout << std::endl;

  Complex21 l = -a;
  Complex21 m = -b;

  l.Display( );
  std::cout << std::endl;
  m.Display( );
  std::cout << std::endl;

  //    ComplexA aa;
  //    Read( aa );
  //    Display( aa );
  //    std::cout << std::endl;

  //*** arrays
  Complex21 arr[ 10 ];
  for ( int i = 0; i < 10; ++i ) {
    arr[ i ] = Complex21( i + 1, -i - 1 );
  }
  for ( int i = 0; i < 10; ++i ) {
    arr[ i ].Display( );
    std::cout << std::endl;
  }
}
