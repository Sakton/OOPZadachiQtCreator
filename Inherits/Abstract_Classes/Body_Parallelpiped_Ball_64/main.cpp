#include <iostream>

#include "ball.h"
#include "parallelepiped.h"

class Fabrique {
 public:
  Fabrique( ) {}
  Body *getBall( double r ) { return new Ball( r ); }
  Body *getParallelepiped( double a, double b, double c ) {
    return new Parallelepiped( a, b, c );
  }
};

int main( ) {
  Fabrique f;
  Body *arr[ 10 ];
  for ( int i = 0; i < 10; ++i ) {
    if ( i % 2 ) {
      arr[ i ] = f.getBall( i );
    } else {
      arr[ i ] = f.getParallelepiped( i, i, i );
    }
  }

  for ( int i = 0; i < 10; ++i ) {
    std::cout << arr[ i ]->Area( ) << std::endl;
    std::cout << arr[ i ]->Volume( ) << std::endl;
  }
}
