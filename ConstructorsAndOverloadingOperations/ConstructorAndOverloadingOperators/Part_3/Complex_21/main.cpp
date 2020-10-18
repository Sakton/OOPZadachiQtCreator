#include <iostream>

#include "complex21.h"

int main( ) {
  // Methods demonstration
  ComplexA a, b;
  Init( a, 1.1, 2.2 );
  Init( b, 3.3, 4.4 );
  Display( a );
  std::cout << std::endl;
  Display( b );
  std::cout << std::endl;

  ComplexA c = Add( a, b );
  ComplexA d = Sub( a, b );
  ComplexA e = Div( a, b );
  ComplexA f = Mul( a, b );

  Display( c );
  std::cout << std::endl;
  Display( d );
  std::cout << std::endl;
  Display( e );
  std::cout << std::endl;
  Display( f );
  std::cout << std::endl;

  ComplexA l = Conj( a );
  ComplexA m = Conj( b );

  Display( l );
  std::cout << std::endl;
  Display( m );
  std::cout << std::endl;

  //    ComplexA aa;
  //    Read( aa );
  //    Display( aa );
  //    std::cout << std::endl;

  // arrays
  ComplexA arr[ 10 ];
  for ( int i = 0; i < 10; ++i ) {
    Init( arr[ i ], i + 1, -i - 1 );
  }
  for ( int i = 0; i < 10; ++i ) {
    Display( arr[ i ] );
    std::cout << std::endl;
  }
}
