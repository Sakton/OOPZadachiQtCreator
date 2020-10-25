#include <iostream>

#include "fussyprivate.h"
#include "fuzzupublic.h"

using namespace std;

int main( ) {
  std::cout << "************ FUZZY PUBLIC *********" << std::endl;
  FuzzuPublic a( 0.1, 1, 0.1 );
  Display( a );
  FuzzuPublic b( 0.1, 1, 0.1 );
  Display( a + b );
  Display( a - b );
  Display( a * b );
  Display( a / b );

  std::cout << "************ FUZZY PRIVATE *********" << std::endl;

  FussyPrivate pa( 0.1, 1, 0.1 );
  Display( pa );
  FussyPrivate pb( 0.1, 1, 0.1 );
  Display( pa + pb );
  Display( pa - pb );
  Display( pa * pb );
  Display( pa / pb );
}
