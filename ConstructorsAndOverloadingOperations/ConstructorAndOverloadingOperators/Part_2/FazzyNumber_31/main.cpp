#include <iostream>

#include "fuzzynumber31.h"

using namespace std;

int main( ) {
  FuzzyNumber31 a( 0.1, 1, 0.1 );
  Display( a );
  FuzzyNumber31 b( 0.1, 1, 0.1 );
  Display( a + b );
  Display( a - b );
  Display( a * b );
  Display( a / b );
}
